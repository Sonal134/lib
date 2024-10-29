#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Book {
    int id;
    string title;
    string author;
    string genre;
};

vector<Book> library;

// Function to add a new book to the library
void addBook() {
    Book newBook;
    cout << "Enter Book ID: ";
    cin >> newBook.id;
    cin.ignore(); // To clear the newline left in the buffer
    cout << "Enter Book Title: ";
    getline(cin, newBook.title);
    cout << "Enter Book Author: ";
    getline(cin, newBook.author);
    cout << "Enter Book Genre: ";
    getline(cin, newBook.genre);

    library.push_back(newBook);
    cout << "Book added successfully!\n\n";
}

// Function to display all books in the library
void displayBooks() {
    if (library.empty()) {
        cout << "No books in the library.\n\n";
        return;
    }
    cout << "Books in the Library:\n";
    for (size_t i = 0; i < library.size(); ++i) {
        cout << "ID: " << library[i].id << "\nTitle: " << library[i].title
             << "\nAuthor: " << library[i].author << "\nGenre: " << library[i].genre << "\n\n";
    }
}

// Function to search for a book by title
void searchBook() {
    string title;
    cout << "Enter the title of the book to search: ";
    cin.ignore();
    getline(cin, title);

    bool found = false;
    for (size_t i = 0; i < library.size(); ++i) {
        if (library[i].title == title) {
            cout << "Book found:\n";
            cout << "ID: " << library[i].id << "\nTitle: " << library[i].title
                 << "\nAuthor: " << library[i].author << "\nGenre: " << library[i].genre << "\n\n";
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Book not found.\n\n";
    }
}

// Function to delete a book by ID
void deleteBook() {
    int id;
    cout << "Enter the ID of the book to delete: ";
    cin >> id;

    bool deleted = false;
    for (size_t i = 0; i < library.size(); ++i) {
        if (library[i].id == id) {
            library.erase(library.begin() + i);
            cout << "Book deleted successfully!\n\n";
            deleted = true;
            break;
        }
    }
    if (!deleted) {
        cout << "Book not found.\n\n";
    }
}

// Main function with menu
int main() {
    int choice;

    while (true) {
        cout << "Library Management System\n";
        cout << "1. Add Book\n";
        cout << "2. Display Books\n";
        cout << "3. Search Book\n";
        cout << "4. Delete Book\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                displayBooks();
                break;
            case 3:
                searchBook();
                break;
            case 4:
                deleteBook();
                break;
            case 5:
                cout << "Exiting the program.\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n\n";
        }
    }
}

