#pragma once

#include <string>
#include "Book.h"

using namespace std;

Book::Book(string title, string author, string isbn, bool availability)
{
	this->title = title;
	this->author = author;
	this->isbn = isbn;
	this->availability = availability;
}

Book::Book() {}