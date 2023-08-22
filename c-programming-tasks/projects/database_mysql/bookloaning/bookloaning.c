#include <mysql/mysql.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern MYSQL *conn;
extern MYSQL_RES *res;
extern MYSQL_ROW row;

char *avialibleBooks;
int arrayOfBooks;

// Loaning a book from the database
extern void show_books(void) {

    avialibleBooks = malloc(100 * sizeof(char));


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
        // Process and print the row data, for example:
        printf("Book ID: %s, Book Name: %s, Author: %s, Available: %s\n", row[0], row[1], row[2], row[3]);
        
        // copying the books into char pointer array
        strcpy(avialibleBooks, row[3]);

        
    }


        //converting the books to integers array
        sscanf(avialibleBooks, "%d", &arrayOfBooks );


       

        	 printf("%i\n", arrayOfBooks);
   

    // free availible books from books
    free(avialibleBooks);

    // free mysql res
    mysql_free_result(res);
}


// tomorrow i will try and find out how i can update the database by creating a function that does something