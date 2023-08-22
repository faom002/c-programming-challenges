-- make sure to open up mysql workbench

-- create a user for bookloaningsystem
CREATE USER 'admin'@'localhost' IDENTIFIED BY 'nerd123';

-- grant privelage to users
GRANT ALL PRIVILEGES ON books.* TO 'admin'@'localhost';

-- make changes immediately
FLUSH PRIVILEGES;



-- create database 
CREATE DATABASE bookloaning;

-- create the table with different datatypes and a check for if the database already exist or not 
CREATE TABLE IF NOT EXISTS books (id INT AUTO_INCREMENT PRIMARY KEY, bookname VARCHAR(255), authorname VARCHAR(100), availiblebooks INT);

-- insert into book table
INSERT INTO books (bookname, authorname, availiblebooks) VALUES ('The Great Gatsby', 'F. Scott Fitzgerald', 10);