#include <iostream>
#include <string>
using namespace std;
// Node structure to represent a book
struct Book {
    string title;
    string author;
    int year;
    Book* next;

    // Constructor
    Book(string _title, string _author, int _year) : title(_title), author(_author), year(_year), next(nullptr) {}
};
// Library catalog class
class LibraryCatalog {
private:
    Book* head;
public:
    // Constructor
    LibraryCatalog() : head(nullptr) {}
    // Destructor to free memory
    ~LibraryCatalog() {
        Book* current = head;
        while (current != nullptr) {
            Book* next = current->next;
            delete current;
            current = next;
        }
    }

    // Function to add a book to the catalog
    void addBook() {
        string title, author;
        int year;
        cout << "Enter book title: ";
        cin.ignore();
        getline(cin, title);
        cout << "Enter author name: ";
        getline(cin, author);
        cout << "Enter publication year: ";
        cin >> year;

        Book* newBook = new Book(title, author, year);
        if (head == nullptr) {
            head = newBook;
        } else {
            Book* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newBook;
        }
        cout << "Book added successfully.\n";
    }

    // Function to search for a book by title
    void searchByTitle() {
        string title;
        cout << "Enter title to search: ";
        cin.ignore();
        getline(cin, title);

        Book* current = head;
        bool found = false;
        while (current != nullptr) {
            if (current->title == title) {
                cout << "Book found:\n";
                cout << "Title: " << current->title << "\n";
                cout << "Author: " << current->author << "\n";
                cout << "Year: " << current->year << "\n";
                found = true;
                break;
            }
            current = current->next;
        }
        if (!found) {
            cout << "Book not found.\n";
        }
    }

    // Function to search for a book by author
    void searchByAuthor() {
        string author;
        cout << "Enter author name to search: ";
        cin.ignore();
        getline(cin, author);

        Book* current = head;
        bool found = false;
        while (current != nullptr) {
            if (current->author == author) {
                cout << "Book found:\n";
                cout << "Title: " << current->title << "\n";
                cout << "Author: " << current->author << "\n";
                cout << "Year: " << current->year << "\n";
                found = true;
            }
            current = current->next;
        }
        if (!found) {
            cout << "No books found by this author.\n";
        }
    }

    // Function to display all books in the catalog
    void displayCatalog() {
        Book* current = head;
        cout << "Library Catalog:\n";
        while (current != nullptr) {
            cout << "Title: " << current->title << ", Author: " << current->author << ", Year: " << current->year << "\n";
            current = current->next;
        }
    }
};

int main() {
    LibraryCatalog catalog;
    int choice;

    do {
        cout << "\nMenu:\n";
        cout << "1. Add a book\n";
        cout << "2. Search by title\n";
        cout << "3. Search by author\n";
        cout << "4. Display catalog\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                catalog.addBook();
                break;
            case 2:
                catalog.searchByTitle();
                break;
            case 3:
                catalog.searchByAuthor();
                break;
            case 4:
                catalog.displayCatalog();
                break;
            case 5:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}
