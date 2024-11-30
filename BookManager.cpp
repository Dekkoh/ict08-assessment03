#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "BookManager.h"

using namespace std;

enum BOOK_COMPARATOR {
    TITLE = 0,
    AUTHOR = 1,
    ISBN = 2,
    AVAILABILITY = 3
};

void merge(vector<Book>& vec, int leftIdx, int midIdx, int rightIdx, int book_comparator) {
    int i, j, k;
    int n1 = midIdx - leftIdx + 1;
    int n2 = rightIdx - midIdx;

    // Create temporary vectors
    vector<Book> leftVec(n1), rightVec(n2);

    // Copy data to temporary vectors
    for (i = 0; i < n1; i++)
        leftVec[i] = vec[leftIdx + i];
    for (j = 0; j < n2; j++)
        rightVec[j] = vec[midIdx + 1 + j];

    // Merge the temporary vectors back into vec[left..right]
    i = 0;
    j = 0;
    k = leftIdx;
    while (i < n1 && j < n2) {
        switch (book_comparator) {
        case TITLE:
            if (leftVec[i].title <= rightVec[j].title) {
                vec[k] = leftVec[i];
                i++;
            }
            else {
                vec[k] = rightVec[j];
                j++;
            }
            break;
        case AUTHOR:
            if (leftVec[i].author <= rightVec[j].author) {
                vec[k] = leftVec[i];
                i++;
            }
            else {
                vec[k] = rightVec[j];
                j++;
            }
            break;
        case ISBN:
            if (leftVec[i].isbn <= rightVec[j].isbn) {
                vec[k] = leftVec[i];
                i++;
            }
            else {
                vec[k] = rightVec[j];
                j++;
            }
            break;
        case AVAILABILITY:
            if (leftVec[i].availability <= rightVec[j].availability) {
                vec[k] = leftVec[i];
                i++;
            }
            else {
                vec[k] = rightVec[j];
                j++;
            }
            break;
        default:
            if (leftVec[i].title <= rightVec[j].title) {
                vec[k] = leftVec[i];
                i++;
            }
            else {
                vec[k] = rightVec[j];
                j++;
            }
            break;
        }

        k++;
    }

    // Copy the remaining elements of leftVec[], if any
    while (i < n1) {
        vec[k] = leftVec[i];
        i++;
        k++;
    }

    // Copy the remaining elements of rightVec[], if any
    while (j < n2) {
        vec[k] = rightVec[j];
        j++;
        k++;
    }
}

// The subarray to be sorted is in the index range [left..right]
void mergeSort(vector<Book>& vec, int leftIdx, int rightIdx, int bookAttribute) {
    if (leftIdx < rightIdx) {

        // Calculate the midpoint
        int midIdx = leftIdx + (rightIdx - leftIdx) / 2;

        // Sort first and second halves
        mergeSort(vec, leftIdx, midIdx, bookAttribute);
        mergeSort(vec, midIdx + 1, rightIdx, bookAttribute);

        // Merge the sorted halves
        merge(vec, leftIdx, midIdx, rightIdx, bookAttribute);
    }
}

int BookManager::findBookIdxByISBN(string isbn)
{
    int bookIdx = -1;

    for (int i = 0; i < this->books.size(); i++)
    {
        if (this->books[i].isbn.compare(isbn) == 0)
        {
            bookIdx = i;
            break;
        }
    }

    return bookIdx;
};

int BookManager::setBookDetails(string isbn, string title, string author, int availability)
{
    int bookIdx = this->findBookIdxByISBN(isbn);

    if (bookIdx == -1)
    {
        cout << "[Error]: Book with ISBN " << isbn << " not found!" << endl << endl;
        return -1;
    }

    this->books[bookIdx].title = (title != "") ? title : this->books[bookIdx].title;
    this->books[bookIdx].author = (author != "") ? author : this->books[bookIdx].author;
    this->books[bookIdx].availability = (availability != -1) ? (bool)availability : this->books[bookIdx].availability;

    cout << "Book with ISBN " << isbn << " successfully updated!" << endl << endl;
    return 0;
};

int BookManager::displayBookDetails(string isbn)
{
    int bookIdx = this->findBookIdxByISBN(isbn);

    if (bookIdx == -1)
    {
        cout << "[Error]: Book with ISBN " << isbn << " not found!" << endl << endl;
        return -1;
    }

    Book book = this->books[bookIdx];

    cout << "Displaying book details" << endl;

    cout << "Title: " << book.title << endl;
    cout << "Author: " << book.author << endl;
    cout << "ISBN: " << book.isbn << endl;
    cout << "Availability: " << book.availability << endl << endl;

    return 0;
}

int BookManager::borrowBook(string isbn)
{
    int bookIdx = this->findBookIdxByISBN(isbn);

    if (bookIdx == -1)
    {
        cout << "[Error]: Book with ISBN " << isbn << " not found!" << endl << endl;
        return -1;
    }

    if (this->books[bookIdx].availability == false)
    {
        cout << "[Error]: Book with ISBN " << isbn << " not available!" << endl << endl;
        return -1;
    }

    this->books[bookIdx].availability = false;
    cout << "Book with ISBN " << isbn << " successfully borrowed!" << endl << endl;

    return 0;
}

int BookManager::returnBook(string isbn)
{
    int bookIdx = this->findBookIdxByISBN(isbn);

    if (bookIdx == -1)
    {
        cout << "[Error]: Book with ISBN " << isbn << " not found!" << endl << endl;
        return -1;
    }

    if (this->books[bookIdx].availability == true)
    {
        cout << "[Error]: Book with ISBN " << isbn << " already returned!" << endl << endl;
        return -1;
    }

    this->books[bookIdx].availability = true;
    cout << "Book with ISBN " << isbn << " successfully returned!" << endl << endl;

    return 0;
}

vector<Book> BookManager::getBooksBy(int bookAttribute = TITLE) {
    mergeSort(this->books, 0, this->books.size() - 1, bookAttribute);

    return this->books;
}

BookManager::BookManager(vector<Book> books) {
    this->books = books;
}

BookManager::BookManager() {
    this->books = books;
}