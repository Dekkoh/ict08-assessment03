#pragma once

#include <string>

using namespace std;

class Book
{
public:
    string title;
    string author;
    string isbn;
    bool availability;
    Book(string title, string author, string isbn, bool availability);
    Book();
};
