#include <mysql/mysql.h>
#include <stdbool.h>
#include <stdio.h>

#include <stdlib.h>
#include <string.h>

// connection for mysql
extern MYSQL *conn;
extern MYSQL_RES *res;
extern MYSQL_ROW row;

char *inputAccept = NULL;
int arrayOfBooks, input = 0;

// this method takes in username and loans a book
void loan_a_book(char *userNameInput) {
  printf("Enter book ID to loan (or any other input to exit): ");
  if (scanf("%d", &input)) {
    arrayOfBooks--;

    // if books is zero then there are no more books left
    if (arrayOfBooks < 0) {
      printf("No more books left for that row\n");
      exit(1);

    } else {

      // else keep on printing ramaining books left
      printf("Remaining books: %d\n", arrayOfBooks);
    }

    // update the books query in our database
    char updateBooksQuery[100];

    // copy the query into update books query abd send it to table books
    snprintf(updateBooksQuery, sizeof(updateBooksQuery),
             "UPDATE books SET availiblebooks = %d WHERE id = %d", arrayOfBooks,
             input);
    if (mysql_query(conn, updateBooksQuery)) {

      // catch error for query
      fprintf(stderr, "Update query error: %s\n", mysql_error(conn));
      exit(1);
    }

    // update current user bookloan register
    char updateUserBooksQuery[100];
    snprintf(updateUserBooksQuery, sizeof(updateUserBooksQuery),
             "UPDATE users SET booksloaned = booksloaned + 1 WHERE personname "
             "= '%s'",
             userNameInput);
    if (mysql_query(conn, updateUserBooksQuery)) {

      // catch error if query doesnt go so well
      fprintf(stderr, "Update query error: %s\n", mysql_error(conn));
      exit(1);
    }
  }
}

void login_user(char *userNameInput) {
  printf("Login to loan a book\n");
  printf("Enter the username: ");

  if (scanf("%31s", userNameInput) != 1) {
    printf("Error reading username input\n");
    exit(1);
  }

  printf("Enter the password: ");

  char passwordInput[64];
  if (scanf("%63s", passwordInput) != 1) {
    printf("Error reading password input\n");
    exit(1);
  }

  // Hash the entered password (you should use a secure hashing library like
  // bcrypt) For demonstration purposes, we'll assume passwordInput is already
  // hashed.
  char hashedInputPassword[64]; // Assuming passwordInput is already hashed.
  strcpy(hashedInputPassword, passwordInput);

  // Create and execute the SQL query to fetch the hashed password for the
  // entered username
  char selectQuery[256];
  snprintf(selectQuery, sizeof(selectQuery),
           "SELECT password FROM users WHERE personname = '%s'", userNameInput);

  if (mysql_query(conn, selectQuery)) {
    fprintf(stderr, "Select query error: %s\n", mysql_error(conn));
    exit(1);
  }

  MYSQL_RES *result = mysql_store_result(conn);
  if (!result) {
    fprintf(stderr, "Error fetching result: %s\n", mysql_error(conn));
    exit(1);
  }

  // Check if the username exists in the database
  if (mysql_num_rows(result) == 0) {
    printf("Invalid username\n");
    mysql_free_result(result);
    exit(1);
  }

  MYSQL_ROW row = mysql_fetch_row(result);
  char storedPassword[64];
  strcpy(storedPassword, row[0]);

  mysql_free_result(result);

  // Compare the hashed input password with the stored hashed password
  if (strcmp(hashedInputPassword, storedPassword) == 0) {
    printf("User is real. Login successful!\n");
  } else {
    printf("Invalid password\n");
  }
}

// return a book back to books
void return_a_book(char *userNameInput) {
  printf("Enter book ID to return (or any other input to exit): ");
  if (scanf("%d", &input)) {
    arrayOfBooks++;

    if (arrayOfBooks >= 10) {
      printf("No more books left for that row\n");
      exit(1);
    } else {
      printf("Remaining books: %d\n", arrayOfBooks);
    }

    // copy the query into update books query abd send it to table books
    char updateBooksQuery[100];
    snprintf(updateBooksQuery, sizeof(updateBooksQuery),
             "UPDATE books SET availiblebooks = %d WHERE id = %d", arrayOfBooks,
             input);
    if (mysql_query(conn, updateBooksQuery)) {
      fprintf(stderr, "Update query error: %s\n", mysql_error(conn));
      exit(1);
    }

    // copy the query into update user loaned books query abd send it to table
    // books
    char updateUserBooksQuery[100];
    snprintf(updateUserBooksQuery, sizeof(updateUserBooksQuery),
             "UPDATE users SET booksloaned = booksloaned - 1 WHERE personname "
             "= '%s'",
             userNameInput);
    if (mysql_query(conn, updateUserBooksQuery)) {
      fprintf(stderr, "Update query error: %s\n", mysql_error(conn));
      exit(1);
    }
  }
}

void register_a_user() {
  printf("Hello there and welcome to our library. Would you like to check out "
         "our book collection?\n");
  printf("In order for you to loan a book for yourself, you have to register "
         ":)\n");
  printf("Type 'yes' or 'no' to register\n");

  char input[10];         // Allocate enough space for longer input.
  char userNameInput[32]; // Allocate enough space for longer usernames.
  char passwordInput[64]; // Allocate enough space for hashed passwords.

  if (scanf("%9s", input) != 1) {
    printf("Error reading input\n");
    exit(1);
  }

  if (strcmp(input, "yes") == 0) {
    printf("Write your username\n");

    if (scanf("%31s", userNameInput) != 1) {
      printf("Error reading username input\n");
      exit(1);
    }

    printf("And password (as a string)\n");

    if (scanf("%63s", passwordInput) != 1) {
      printf("Error reading password input\n");
      exit(1);
    }

    // TODO: Hash and salt the passwordInput before storing it in the database
    // using a secure hashing library (e.g., bcrypt).

    // Create and execute the SQL query
    char insertQuery[256];
    snprintf(insertQuery, sizeof(insertQuery),
             "INSERT INTO users (personname, password, booksloaned) VALUES "
             "('%s', '%s', 0) ON DUPLICATE KEY UPDATE personname=personname",
             userNameInput, passwordInput);
    if (mysql_query(conn, insertQuery)) {
      fprintf(stderr, "Insert query error: %s\n", mysql_error(conn));
      exit(1);
    }

    printf("User registered successfully!\n");

  } else if (strcmp(input, "no") == 0) {
    printf("No books for you then :(-\n");
    exit(1);
  } else {
    printf("Invalid input\n");
    exit(1);
  }
}

// show books availible function in database
extern void show_books(void) {

  char userNameInput[32];

  if (mysql_query(conn, "SELECT * FROM books")) {
    fprintf(stderr, "Query error: %s\n", mysql_error(conn));
    exit(1);
  }

  // preparing connection to database
  res = mysql_store_result(conn);

  if (res == NULL) {
    fprintf(stderr, "Result set error: %s\n", mysql_error(conn));
    exit(1);
  }

  // register user first before loaning book
  register_a_user();

  // logging required before loaning book passing usernameinput so that we can
  // store the user name and use in while
  login_user(userNameInput);

  printf("Type (yes) to loan a book | (no) for return a book: \n");

  inputAccept = malloc(4 * sizeof(char));

  if (scanf("%3s", inputAccept) != 1) {
    fprintf(stderr, "Error reading input\n");
    free(inputAccept);
    exit(1);
  }

  // option for user
  char *accept = "yes";
  char *reject = "no";

  while (1) {

    printf("current user logged in %s\n", userNameInput);

    if (strcmp(inputAccept, accept) == 0) {
      while ((row = mysql_fetch_row(res)) != NULL) {
        printf("Book ID: %s, Book Name: %s, Author: %s, Available: %s\n",
               row[0], row[1], row[2], row[3]);
        sscanf(row[3], "%d", &arrayOfBooks);
      }

      loan_a_book(userNameInput);

    } else if (strcmp(inputAccept, reject) == 0) {
      return_a_book(userNameInput);
    }
  }

  free(inputAccept);
  mysql_free_result(res);
}
