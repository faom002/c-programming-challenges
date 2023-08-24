#include <mysql/mysql.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern MYSQL *conn;
extern MYSQL_RES *res;
extern MYSQL_ROW row;

char *availableBooks;
int arrayOfBooks, input = 0;

extern void show_books(void) {
    availableBooks = malloc(100 * sizeof(char));

    if (mysql_query(conn, "SELECT * FROM books")) {
        fprintf(stderr, "Query error: %s\n", mysql_error(conn));
        exit(1);
    }

    res = mysql_store_result(conn);

    if (res == NULL) {
        fprintf(stderr, "Result set error: %s\n", mysql_error(conn));
        exit(1);
    }

    while ((row = mysql_fetch_row(res)) != NULL) {
        printf("Book ID: %s, Book Name: %s, Author: %s, Available: %s\n", row[0], row[1], row[2], row[3]);
        strcpy(availableBooks, row[3]);

        sscanf(availableBooks, "%d", &arrayOfBooks);
        printf("Initial Available: %d\n", arrayOfBooks);

        while (1) {
            printf("Enter book ID to loan (or anything else to exit): ");
            if (scanf("%d", &input)) {
                arrayOfBooks--;
                printf("Remaining books: %i\n", arrayOfBooks);

               
                    char updateQuery[100];
                    snprintf(updateQuery, sizeof(updateQuery), "UPDATE books SET availiblebooks = %d WHERE id = %s", arrayOfBooks, row[0]);
                    if (mysql_query(conn, updateQuery)) {
                        fprintf(stderr, "Update query error: %s\n", mysql_error(conn));
                        exit(1);
                    }
                     if (arrayOfBooks == 0) {
                    printf("No more books left\n");
                    break;
                }
            } else {
                break;
            }
        }
    }

    free(availableBooks);
    mysql_free_result(res);
}
