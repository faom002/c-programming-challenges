#include <mysql/mysql.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern MYSQL *conn;
extern MYSQL_RES *res;
extern MYSQL_ROW row;

char *inputAccept = NULL;
int arrayOfBooks, input = 0, bookId = 0;

void update_rows() {
    printf("Enter book ID to loan (or any other input to exit): ");
    if (scanf("%d", &input)) {
        arrayOfBooks--;
        printf("Remaining books: %d\n", arrayOfBooks);

        char updateQuery[100];
        snprintf(updateQuery, sizeof(updateQuery), "UPDATE books SET availiblebooks = %d WHERE id = %d", arrayOfBooks, 1);
        if (mysql_query(conn, updateQuery)) {
            fprintf(stderr, "Update query error: %s\n", mysql_error(conn));
            exit(1);
        }
        if (arrayOfBooks <= 0) {
            printf("No more books left for that row\n");
            exit(0);  
        }
    } else {
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

    if (inputAccept == NULL) {
        fprintf(stderr, "Memory allocation error\n");
        exit(1);
    }

    scanf("%s", inputAccept);

    char *test = "yes";

    while (1) {
    
    if (strcmp(inputAccept, test) == 0) {
        while ((row = mysql_fetch_row(res)) != NULL) {
            printf("Book ID: %s, Book Name: %s, Author: %s, Available: %s\n", row[0], row[1], row[2], row[3]);
            sscanf(row[3], "%d", &arrayOfBooks);
            sscanf(row[0], "%d", &bookId);
            printf("Initial Available: %d\n", arrayOfBooks);


        }


            update_rows();

    }
    }
    printf("%d", bookId);

    free(inputAccept);
    mysql_free_result(res);
}
