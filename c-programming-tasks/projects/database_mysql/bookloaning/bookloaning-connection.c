#include <mysql/mysql.h>
#include <stdio.h>

MYSQL *conn;	
MYSQL_RES *res;
 MYSQL_ROW row;



void show_books(void);

int main(void)
{
	
	
	// my connection details 
	char *server = "localhost";
    char *user = "admin";     
    char *password = "nerd123";  
    char *database = "bookloaning";


    // establishing connection
        conn = mysql_init(NULL);


 /* Connect to database */
    if (!mysql_real_connect(conn, server, user, password, database, 0, NULL, 0)) {
        fprintf(stderr, "%s\n", mysql_error(conn));
        exit(1);
    }

    show_books();


   res = mysql_use_result(conn);

   
    mysql_free_result(res);

/* close connection */
    mysql_close(conn);

	return 0;
}