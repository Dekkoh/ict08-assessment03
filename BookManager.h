#pragma once

#include <string>
#include <vector>
#include "Book.h"

using namespace std;

class BookManager
{
public:
    int setBookDetails(string isbn, string author = "", string title = "", int availability = -1);
    int displayBookDetails(string isbn);
    int borrowBook(string isbn);
    int returnBook(string isbn);
    vector<Book> getBooksBy(int bookAttribute);
    BookManager(vector<Book> books);
    BookManager();

private:
    vector<Book> books;
    int findBookIdxByISBN(string isbn);
};