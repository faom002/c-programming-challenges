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

void *errorchecked_malloc(unsigned int);

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
     
    }else {
        exit(0);
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
     
    }else {
        exit(0);
    } 
}

void register_a_user(void){
   printf("Hello there and welcome to our library. Would you like to check out our book collection?\n");
            printf("in order for you to loan a book for yourself, you have to register :)\n");
            printf("type yes/no for registering\n");


            char *inputYes = "yes", *input = NULL, *userNameInput = NULL;
            
                int *userPasswordInput = NULL;
                
              input = malloc(4 *sizeof(char));
              userNameInput = malloc(16 * sizeof(char));    
              userPasswordInput = malloc(16 * sizeof(int));
     
                    
                    scanf("%s", input);

              printf("write your username");
              
             

              scanf("%s", userNameInput);
              
              printf("and password");

              scanf("%d",userPasswordInput);
              
              
  

            if (strcmp(input, inputYes) == 0)
            {
                     char insertQuery[100];
            snprintf(insertQuery, sizeof(insertQuery), "INSERT INTO users (username, password) VALUES ('%s', %d)", userNameInput, *userPasswordInput);
                    if (mysql_query(conn, insertQuery)) {
            fprintf(stderr, "Insert query error: %s\n", mysql_error(conn));
            exit(1);
        }
            }else {
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

   printf("Type (yes/no) for return a book: ");

    inputAccept = malloc(4 * sizeof(char));
     
      errorchecked_malloc(*inputAccept);

    scanf("%s", inputAccept);

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

void *errorchecked_malloc(unsigned int size) { // An error-checked malloc() function
void *ptr;
ptr = malloc(size);
if(ptr == NULL) {
fprintf(stderr, "Error: could not allocate heap memory.\n");
exit(-1);
}
return ptr;
}
