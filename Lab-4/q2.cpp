// A library system allows users to borrow and return books. The system should:
// 1. Add new books to the collection.
// 2. Borrow books (check availability).
// 3. Return books.
// 4. Display all available books.
// Requirements:
//  Implement a Book class with attributes: ID, title, author, availability.
//  Implement a Library class with:
// 1. Method to add a book (with unique ID).
// 2. Method to borrow a book (updates availability).
// 3. Method to return a book (marks it available).
// 4. Method to display all available books.
//  Store book records dynamically using pointers and DMA.
//  Use constructor overloading to initialize books with or without availability status.

#include <iostream>
#include <string>
using namespace std;


class Book {
private:
    int ID;
    string title;
    string author;
    bool available;

public:
    
    Book(int id, string t, string a, bool av = true) : ID(id), title(t), author(a), available(av) {}


    int getID() const { 
        return ID; 
        }
    string getTitle() const { 
        return title;
         }
    string getAuthor() const {
         return author;
          }
    bool isAvailable() const { 
        return available; 
        }

  
    void setAvailability(bool av) {
         available = av; 
         }

    void display() const {
        cout << "ID: " << ID << ", Title: " << title << ", Author: " << author
             << ", Available: " << (available ? "Yes" : "No") << endl;
    }
};


class Library {
private:
    Book** books; 
    int capacity; 
    int count;   

public:
  
    Library(int cap = 100) : capacity(cap), count(0) {
        books = new Book*[capacity];
    }

   
    ~Library() {
        for (int i = 0; i < count; i++) {
            delete books[i];
        }
        delete[] books;
    }

   
    void addBook(int id, string title, string author, bool available = true) {
        if (count >= capacity) {
            cout << "Library is full. Cannot add more books." << endl;
            return;
        }

        
        for (int i = 0; i < count; i++) {
            if (books[i]->getID() == id) {
                cout << "Book with ID " << id << " already exists." << endl;
                return;
            }
        }

      
        books[count] = new Book(id, title, author, available);
        count++;
        cout << "Book added successfully." << endl;
    }


    void borrowBook(int id) {
        for (int i = 0; i < count; i++) {
            if (books[i]->getID() == id) {
                if (books[i]->isAvailable()) {
                    books[i]->setAvailability(false);
                    cout << "Book borrowed successfully." << endl;
                } else {
                    cout << "Book is not available." << endl;
                }
                return;
            }
        }
        cout << "Book with ID " << id << " not found." << endl;
    }

   
    void returnBook(int id) {
        for (int i = 0; i < count; i++) {
            if (books[i]->getID() == id) {
                if (!books[i]->isAvailable()) {
                    books[i]->setAvailability(true);
                    cout << "Book returned successfully." << endl;
                } else {
                    cout << "Book is already available." << endl;
                }
                return;
            }
        }
        cout << "Book with ID " << id << " not found." << endl;
    }

    
    void displayAvailableBooks() const {
        cout << "Available Books:" << endl;
        bool found = false;
        for (int i = 0; i < count; i++) {
            if (books[i]->isAvailable()) {
                books[i]->display();
                found = true;
            }
        }
        if (!found) {
            cout << "No available books." << endl;
        }
    }
};


int main() {
    Library library;

    
    library.addBook(1, "1984", "George Orwell");
    library.addBook(2, "To Kill a Mockingbird", "Harper Lee");
    library.addBook(3, "The Great Gatsby", "F. Scott Fitzgerald");

    
    library.displayAvailableBooks();

    
    library.borrowBook(1);
    library.displayAvailableBooks();

    
    library.returnBook(1);
    library.displayAvailableBooks();

    return 0;
}