#include "Library.h"
#include <iostream>
using namespace std;

Library::Library() {
    bookCount = 0;
}

Library::~Library() {
    for (int i = 0; i < bookCount; ++i) {
        delete books[i];
    }
}

void Library::addBook(const Book& book) {
    if (bookCount < 100) {
        books[bookCount++] = new Book(book);
    } else {
        cout << "Library is full!\n";
    }
}

void Library::searchBookByTitle(const string& title) const {
    bool found = false;
    for (int i = 0; i < bookCount; ++i) {
        if (books[i]->getTitle() == title) {
            cout << "\nBook Found:\n";
            cout << "Title: " << books[i]->getTitle() << endl;
            cout << "Author: " << books[i]->getAuthor() << endl;
            cout << "ISBN: " << books[i]->getISBN() << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Book titled \"" << title << "\" not found.\n";
    }
}

void Library::displayAllBooks() const {
    if (bookCount == 0) {
        cout << "No books in the library.\n";
        return;
    }

    cout << "\nLibrary Collection:\n";
    for (int i = 0; i < bookCount; ++i) {
        cout << "Title: " << books[i]->getTitle() << ", ";
        cout << "Author: " << books[i]->getAuthor() << ", ";
        cout << "ISBN: " << books[i]->getISBN() << endl;
    }
}
