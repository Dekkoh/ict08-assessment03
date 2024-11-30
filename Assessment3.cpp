#pragma once

#include <iostream>
#include "vector"
#include "Book.h"
#include "BookManager.h"

using namespace std;

vector<Book> initBooks()
{
    Book book1("Harry Potter and the Sorcerer's Stone", "Rowling, J. K.", "9781338878929", true);
    Book book2("Clean Code: A Handbook of Agile Software Craftsmanship", "Robert C. Martin", "9780132350884", true);
    Book book3("The Lord Of The Rings Deluxe Edition", "J.R.R. Tolkien", "9780544273443", true);
    Book book4("Percy Jackson and the Olympians: Wrath of the Triple Goddess", "Riordan, Rick", "9781368107631", true);
    Book book5("The Witcher: Classic Collection", "Sapkowski, Andrzej - Parowski, Maciej", "9781506744001", true);

    return { book1, book2, book3, book4, book5 };
}

int main()
{
    vector<Book> books = initBooks();
    BookManager bookManager(books);
    vector<Book> orderedBooks = bookManager.getBooksBy(0);

    for (int i = 0; i < orderedBooks.size(); i++) {
        cout << orderedBooks[i].title << endl;
        cout << orderedBooks[i].author << endl;
        cout << orderedBooks[i].isbn << endl;
        cout << orderedBooks[i].availability << endl;
        cout << endl;
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
