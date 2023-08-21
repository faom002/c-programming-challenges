#include <mysql/mysql.h>
#include <stdio.h>
#include <stdlib.h> // Include this for the exit() function

int main() {
    MYSQL *conn;
    MYSQL_RES *res;
    MYSQL_ROW row;

    char *server = "localhost";
    char *user = "username";      // Replace with the actual username you created
    char *password = "password";  // Replace with the actual password for the user
    char *database = "test";

    conn = mysql_init(NULL);

    /* Connect to database */
    if (!mysql_real_connect(conn, server, user, password, database, 0, NULL, 0)) {
        fprintf(stderr, "%s\n", mysql_error(conn));
        exit(1);
    }

    /* Create a table */
    if (mysql_query(conn, "CREATE TABLE IF NOT EXISTS employees (id INT AUTO_INCREMENT PRIMARY KEY, name VARCHAR(255), age INT)")) {
        fprintf(stderr, "Table creation error: %s\n", mysql_error(conn));
        exit(1);
    }

    /* Insert data into the table */
if (mysql_query(conn, "INSERT INTO employees (name, age) VALUES ('John Doe', 30)")) {
    fprintf(stderr, "Insertion error: %s\n", mysql_error(conn));
    exit(1);
}


    /* Create a table */
    if (mysql_query(conn, "")) {
        fprintf(stderr, "Table creation error: %s\n", mysql_error(conn));
        exit(1);
    }


    /* send SQL query */
    // here we show the databases
    if (mysql_query(conn, "show tables")) {
        fprintf(stderr, "%s\n", mysql_error(conn));
        exit(1);
    }

    res = mysql_use_result(conn);

    /* output table name */

    printf("MySQL Tables in test database:\n");
    while ((row = mysql_fetch_row(res)) != NULL){
        printf("%s\n", row[0]);
    }

    /* close connection */
    mysql_free_result(res);
    mysql_close(conn);

    return 0;
}
