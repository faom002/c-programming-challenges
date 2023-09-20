#include <mysql/mysql.h>
#include <stdbool.h>
#include <stdio.h>

#include <stdlib.h>
#include <string.h>

extern MYSQL *conn;
extern MYSQL_RES *res;
extern MYSQL_ROW row;

char *inputAccept = NULL;
int arrayOfBooks, input = 0;


//  find out why i cant select book 1
void loan_a_book(void) {
    printf("Enter book ID to loan (or any other input to exit): ");
    if (scanf("%d", &input)) {
        arrayOfBooks--;

           if (arrayOfBooks < 0) {
            printf("No more books left for that row\n");
            exit(1);  
        }else {
            printf("Remaining books: %d\n", arrayOfBooks);
        }

        char updateQuery[100];
        snprintf(updateQuery, sizeof(updateQuery), "UPDATE books SET availiblebooks = %d WHERE id = %d", arrayOfBooks, input);
        if (mysql_query(conn, updateQuery)) {
            fprintf(stderr, "Update query error: %s\n", mysql_error(conn));
            exit(1);
        }
     
    }


 
        
    
}

void return_a_book(void){
      printf("Enter book ID to return (or any other input to exit): ");
    if (scanf("%d", &input)) {
        arrayOfBooks++;

           if (arrayOfBooks < 0) {
            printf("No more books left for that row\n");
            exit(1);  
        }else {
            printf("Remaining books: %d\n", arrayOfBooks);
        }

        char updateQuery[100];
        snprintf(updateQuery, sizeof(updateQuery), "UPDATE books SET availiblebooks = %d WHERE id = %d", arrayOfBooks, input);
        if (mysql_query(conn, updateQuery)) {
            fprintf(stderr, "Update query error: %s\n", mysql_error(conn));
            exit(1);
        }
     
    }

    }

void register_a_user(void) {
    printf("Hello there and welcome to our library. Would you like to check out our book collection?\n");
    printf("In order for you to loan a book for yourself, you have to register :)\n");
    printf("Type yes/no for registering\n");

    char *inputYes = "yes", *input = NULL, *userNameInput = NULL, *inputNo = "no";
    int *userPasswordInput = NULL;

    input = malloc(4 * sizeof(char));
    userNameInput = malloc(16 * sizeof(char));
    userPasswordInput = malloc( 3 * sizeof(int)); // Just allocate enough for one integer

    if (scanf("%3s", input) != 1) {
        printf("Error reading input\n");
        free(input);
        exit(1);
    }

    if (strcmp(input, inputYes) == 0) {
        printf("Write your username\n");
        
        if(scanf("%8s", userNameInput) != 1){
            printf("Error reading username input \n");
            free(userNameInput);
            exit(1);
        }else {
        
        

        printf("And password (as an integer)\n");
            
         if ( scanf("%6d", userPasswordInput) != 1)
            {
                printf("Error reading userPasswordInput \n");
                free(userPasswordInput);
                exit(1);
            } 
            
        }
        char insertQuery[100];
        snprintf(insertQuery, sizeof(insertQuery), "INSERT INTO users (personname, password) VALUES ('%s', %d)", userNameInput, *userPasswordInput);
        if (mysql_query(conn, insertQuery)) {
            fprintf(stderr, "Insert query error: %s\n", mysql_error(conn));
            exit(1);
        }
    } else if (strcmp(input, inputNo) == 0) {
        printf("No books on you then | :(- |\n");
        exit(0);
    } else {
        printf("Invalid input\n");
        exit(1);
    }

    free(userPasswordInput);
    free(input);
    free(userNameInput);
}
  



extern void show_books(void) {
    if (mysql_query(conn, "SELECT * FROM books")) {
        fprintf(stderr, "Query error: %s\n", mysql_error(conn));
        exit(1);
    }

    res = mysql_store_result(conn);

    if (res == NULL) {
        fprintf(stderr, "Result set error: %s\n", mysql_error(conn));
        exit(1);
    }

   register_a_user();

    printf("Type (yes) to loan a book | (no) for return a book: \n");

    inputAccept = malloc(4 * sizeof(char));
     
    
    if (scanf("%3s", inputAccept) != 1) {
    fprintf(stderr, "Error reading input\n");
    free(inputAccept);
    exit(1);
    }




  

    char *accept = "yes";
    char *reject = "no";

  



    while (1) {
    
    if (strcmp(inputAccept, accept) == 0) {
        while ((row = mysql_fetch_row(res)) != NULL) {
            printf("Book ID: %s, Book Name: %s, Author: %s, Available: %s\n", row[0], row[1], row[2], row[3]);
            sscanf(row[3], "%d", &arrayOfBooks);


        }


            loan_a_book();

    }else if(strcmp(inputAccept,reject) == 0) {
            return_a_book();

    }
    }

    free(inputAccept);
    mysql_free_result(res);
}

