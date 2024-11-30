#pragma once

#include <iostream>
#include <vector>
#include "Book.h"
#include "BookManager.h"

using namespace std;

vector<Book> initBooks()
{
	Book book1("Harry Potter and the Sorcerer's Stone", "Rowling, J. K.", "9781338878929", true);
	Book book2("Clean Code: A Handbook of Agile Software Craftsmanship", "Robert C. Martin", "9780132350884", true);
	Book book3("The Lord Of The Rings Deluxe Edition", "J.R.R. Tolkien", "9780544273443", true);

	return { book1, book2, book3 };
}

vector<Book> initBooksIncorrectly()
{
	Book book1("Rowling, J. K.", "Harry Potter and the Sorcerer's Stone", "978133887892", true);
	Book book2("Robert C. Martin", "Clean Code: A Handbook of Agile Software Craftsmanship", "978013235088", true);
	Book book3("J.R.R. Tolkien", "The Lord Of The Rings Deluxe Edition", "978054427344", true);

	return { book1, book2, book3 };
}

void printBooks(vector<Book> books) 
{
	for (int i = 0; i < books.size(); i++) {
		cout << "Title: " << books[i].title << endl;
		cout << "Author: " << books[i].author << endl;
		cout << "ISBN: " << books[i].isbn << endl;
		cout << "Availability: " << books[i].availability << endl;
		cout << endl;
	}
}

void part1()
{
	// Import class implementation and sort function implementation are at the begining of the file
	cout << "Part 1" << endl;
	cout << "Importing class implementation and importing sorting function. The import statement are at the begining of the file." << endl << endl;
	cout << "--------------------------------------------" << endl << endl;
}

void part2()
{
	cout << "Part 2" << endl;
	cout << "Initialising books with corret information and incorrect information." << endl << endl;

	vector<Book> books = initBooks();
	vector<Book> incorrectBooks = initBooksIncorrectly();

	cout << "Books with correct information" << endl;
	printBooks(books);

	cout << "Books with incorrect information" << endl;
	printBooks(incorrectBooks);

	cout << "--------------------------------------------" << endl << endl;
}

void part3()
{
	cout << "Part 3" << endl;
	cout << "Creating array with ascending, descending and mixed title order." << endl << endl;

	Book book1("Clean Code: A Handbook of Agile Software Craftsmanship", "Robert C. Martin", "9780132350884", true);
	Book book2("Harry Potter and the Sorcerer's Stone", "Rowling, J. K.", "9781338878929", true);
	Book book3("The Lord Of The Rings Deluxe Edition", "J.R.R. Tolkien", "9780544273443", true);

	vector<Book> booksAsc = { book1, book2, book3 };
	vector<Book> booksDesc = { book3, book2, book1 };
	vector<Book> booksMixed = {book2, book3, book1 };

	cout << "Books with ascending order" << endl;
	printBooks(booksAsc);

	cout << "Books with descending order" << endl;
	printBooks(booksDesc);

	cout << "Books with mixed order" << endl;
	printBooks(booksMixed);

	cout << "--------------------------------------------" << endl << endl;
}

void part4()
{
	cout << "Part 4" << endl;
	cout << "Calling sort function on all three arrays." << endl << endl;

	Book book1("Clean Code: A Handbook of Agile Software Craftsmanship", "Robert C. Martin", "9780132350884", true);
	Book book2("Harry Potter and the Sorcerer's Stone", "Rowling, J. K.", "9781338878929", true);
	Book book3("The Lord Of The Rings Deluxe Edition", "J.R.R. Tolkien", "9780544273443", true);

	vector<Book> booksAsc = { book1, book2, book3 };
	vector<Book> booksDesc = { book3, book2, book1 };
	vector<Book> booksMixed = { book2, book3, book1 };

	BookManager bookManagerAsc(booksAsc);
	vector<Book> orderedBooksAsc = bookManagerAsc.getBooksBy(0);
	cout << "Previously ascending order books" << endl;
	printBooks(orderedBooksAsc);

	BookManager bookManagerDesc(booksDesc);
	vector<Book> orderedBooksDesc = bookManagerDesc.getBooksBy(0);
	cout << "Previously descending order books" << endl;
	printBooks(orderedBooksDesc);

	BookManager bookManagerMixed(booksMixed);
	vector<Book> orderedBooksMixed = bookManagerMixed.getBooksBy(0);
	cout << "Previously mixed order books" << endl;
	printBooks(orderedBooksMixed);

	cout << "--------------------------------------------" << endl << endl;
}

int main()
{
	part1();
	part2();
	part3();
	part4();
}
