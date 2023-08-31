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

void update_rows() {
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

    printf("Hello there and welcome to our library. Would you like to check out our book collection?\n");
    printf("Type yes/no: ");

    inputAccept = malloc(4 * sizeof(char));
 
      errorchecked_malloc(*inputAccept);

    scanf("%s", inputAccept);

    char *accept = "yes";

    while (1) {
    
    if (strcmp(inputAccept, accept) == 0) {
        while ((row = mysql_fetch_row(res)) != NULL) {
            printf("Book ID: %s, Book Name: %s, Author: %s, Available: %s\n", row[0], row[1], row[2], row[3]);
            sscanf(row[3], "%d", &arrayOfBooks);


        }


            update_rows();

    }else {
        break;
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
