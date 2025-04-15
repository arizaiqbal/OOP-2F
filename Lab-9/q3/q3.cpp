#include <iostream>
#include "Book.h"
#include "Library.h"
using namespace std;

int main() {
    Library lib;

    Book b1("1984", "George Orwell", "978-0451524935");
    Book b2("Brave New World", "Aldous Huxley", "978-0060850524");

    lib.addBook(b1);
    lib.addBook(b2);

    lib.displayAllBooks();

    cout << "\nSearching for '1984':\n";
    lib.searchBookByTitle("1984");

    cout << "\nSearching for 'The Alchemist':\n";
    lib.searchBookByTitle("The Alchemist");

    return 0;
}