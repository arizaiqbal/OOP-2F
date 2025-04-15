#include "Book.h"
#include <iostream>
using namespace std;


Book::Book (string t, string a, string i){
    title = t;
    author = a;
    ISBN = i;
}

string Book::getTitle() const {
    return title;
}

string Book::getAuthor() const {
    return author;
}

string Book::getISBN() const {
    return ISBN;
}
