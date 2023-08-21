-- create database 
CREATE DATABASE bookloaning;

-- create the table with different datatypes and a check for if the database already exist or not 
CREATE TABLE IF NOT EXISTS books (id INT AUTO_INCREMENT PRIMARY KEY, bookname VARCHAR(255), authorname VARCHAR(100), availiblebooks INT);

-- insert into book table
INSERT INTO books (name, auhtorname) VALUES ('John Doe', 'JK rowling', 10);