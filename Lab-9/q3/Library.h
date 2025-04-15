#ifndef LIBRARY
#define LIBRARY

#include <string>
#include "Book.h"
using namespace std;

class Library{
    private:
    Book* books[100];
    int bookCount;

    public:
    Library();

    ~Library();

   void addBook(const Book& book);
    void searchBookByTitle(const string& title) const;
    void displayAllBooks() const;
};

#endif