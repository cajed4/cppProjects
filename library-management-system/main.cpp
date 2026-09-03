// Project 1: Library Management System: A simple library management system that allows users to add, delete, and view books in the library.
// The program will keep track of the Full Name, Address, Phone Number, Library Card Number, and the books that are checked out by the user.
// There will be one of the following genres: Non-fiction, Fantasy, Romance, Sci-Fi, Mystery, Horror, Other.
// By Amare Johnson

#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <sstream>
#include <string>
#include <map>

// Enum for book genres
enum Genre {
    NON_FICTION,
    FANTASY,
    ROMANCE,
    SCI_FI,
    MYSTERY,
    HORROR,
    OTHER
};

// Convert genre enum to string
std::string genreToString(Genre genre) {
    switch (genre) {
        case NON_FICTION: return "Non-fiction";
        case FANTASY: return "Fantasy";
        case ROMANCE: return "Romance";
        case SCI_FI: return "Sci-Fi";
        case MYSTERY: return "Mystery";
        case HORROR: return "Horror";
        case OTHER: return "Other";
        default: return "Unknown";
    }
}

// Convert string to genre enum
Genre stringToGenre(const std::string& genreStr) {
    if (genreStr == "Non-fiction") return NON_FICTION;
    if (genreStr == "Fantasy") return FANTASY;
    if (genreStr == "Romance") return ROMANCE;
    if (genreStr == "Sci-Fi") return SCI_FI;
    if (genreStr == "Mystery") return MYSTERY;
    if (genreStr == "Horror") return HORROR;
    return OTHER;
}

struct User {
    std::string fullName;
    std::string address;
    std::string phoneNumber;
    std::string libraryCardNumber;
    std::vector<std::string> booksCheckedOut;
};

struct Book {
    std::string title;
    std::string author;
    std::string idNumber;
    Genre genre;
    bool isCheckedOut;
    std::string checkedOutBy; // Library card number of the user who checked out the book
};

std::vector<User> users;
std::vector<Book> books;

// Function to add a new user
void addUser() {
    User newUser;
    std::cout << "Enter full name: ";
    std::getline(std::cin, newUser.fullName);
    std::cout << "Enter address: ";
    std::getline(std::cin, newUser.address);
    std::cout << "Enter phone number: ";
    std::getline(std::cin, newUser.phoneNumber);
    std::cout << "Enter library card number: ";
    std::getline(std::cin, newUser.libraryCardNumber);
    users.push_back(newUser);
    std::cout << "User added successfully.\n";
}

// Function to add a new book
void addBook() {
    Book newBook;
    std::cout << "Enter title: ";
    std::getline(std::cin, newBook.title);
    std::cout << "Enter author: ";
    std::getline(std::cin, newBook.author);
    std::cout << "Enter ID number: ";
    std::getline(std::cin, newBook.idNumber);
    std::string genreStr;
    std::cout << "Enter genre (Non-fiction, Fantasy, Romance, Sci-Fi, Mystery, Horror, Other): ";
    std::getline(std::cin, genreStr);
    newBook.genre = stringToGenre(genreStr);
    newBook.isCheckedOut = false;
    books.push_back(newBook);
    std::cout << "Book added successfully.\n";
}

// Function to remove a book by ID
void removeBook() {
    std::string id;
    std::cout << "Enter the ID number of the book to remove: ";
    std::getline(std::cin, id);
    for (auto it = books.begin(); it != books.end(); ++it) {
        if (it->idNumber == id) {
            books.erase(it);
            std::cout << "Book removed successfully.\n";
            return;
        }
    }
    std::cout << "Book not found.\n";
}

// Function to view information of a book by ID
void viewBookInfo() {
    std::string id;
    std::cout << "Enter the ID number of the book: ";
    std::getline(std::cin, id);
    for (const auto& book : books) {
        if (book.idNumber == id) {
            std::cout << "Title: " << book.title << "\n";
            std::cout << "Author: " << book.author << "\n";
            std::cout << "Genre: " << genreToString(book.genre) << "\n";
            std::cout << "Checked out: " << (book.isCheckedOut ? "Yes" : "No") << "\n";
            if (book.isCheckedOut) {
                std::cout << "Checked out by: " << book.checkedOutBy << "\n";
            }
            return;
        }
    }
    std::cout << "Book not found.\n";
}

// Function to view all borrowed books
void viewBorrowedBooks() {
    for (const auto& book : books) {
        if (book.isCheckedOut) {
            std::cout << "Title: " << book.title << ", Checked out by: " << book.checkedOutBy << "\n";
        }
    }
}

// Function to view books by genre or author
void viewBooksByGenreOrAuthor() {
    std::string input;
    std::cout << "Enter genre or author: ";
    std::getline(std::cin, input);
    for (const auto& book : books) {
        if (genreToString(book.genre) == input || book.author == input) {
            std::cout << "Title: " << book.title << ", Author: " << book.author << ", Genre: " << genreToString(book.genre) << "\n";
        }
    }
}

// Function to borrow a book
void borrowBook() {
    std::string cardNumber, bookId;
    std::cout << "Enter your library card number: ";
    std::getline(std::cin, cardNumber);
    std::cout << "Enter the ID number of the book to borrow: ";
    std::getline(std::cin, bookId);

    for (auto& user : users) {
        if (user.libraryCardNumber == cardNumber) {
            if (user.booksCheckedOut.size() >= 10) {
                std::cout << "You have already checked out 10 books. Please return a book before borrowing another.\n";
                return;
            }
            for (auto& book : books) {
                if (book.idNumber == bookId && !book.isCheckedOut) {
                    book.isCheckedOut = true;
                    book.checkedOutBy = cardNumber;
                    user.booksCheckedOut.push_back(bookId);
                    std::cout << "Book borrowed successfully.\n";
                    return;
                }
            }
            std::cout << "Book not found or already checked out.\n";
            return;
        }
    }
    std::cout << "User not found.\n";
}

// Function to return a book
void returnBook() {
    std::string cardNumber, bookId;
    std::cout << "Enter your library card number: ";
    std::getline(std::cin, cardNumber);
    std::cout << "Enter the ID number of the book to return: ";
    std::getline(std::cin, bookId);

    for (auto& user : users) {
        if (user.libraryCardNumber == cardNumber) {
            for (auto it = user.booksCheckedOut.begin(); it != user.booksCheckedOut.end(); ++it) {
                if (*it == bookId) {
                    user.booksCheckedOut.erase(it);
                    for (auto& book : books) {
                        if (book.idNumber == bookId) {
                            book.isCheckedOut = false;
                            book.checkedOutBy = "";
                            std::cout << "Book returned successfully.\n";
                            return;
                        }
                    }
                }
            }
            std::cout << "Book not found in your checked out list.\n";
            return;
        }
    }
    std::cout << "User not found.\n";
}

// Function to view books checked out by a user
void viewUserBooks() {
    std::string cardNumber;
    std::cout << "Enter your library card number: ";
    std::getline(std::cin, cardNumber);

    for (const auto& user : users) {
        if (user.libraryCardNumber == cardNumber) {
            std::cout << "Books checked out by " << user.fullName << ":\n";
            for (const auto& bookId : user.booksCheckedOut) {
                for (const auto& book : books) {
                    if (book.idNumber == bookId) {
                        std::cout << "Title: " << book.title << ", Author: " << book.author << "\n";
                    }
                }
            }
            return;
        }
    }
    std::cout << "User not found.\n";
}

// Admin menu
void adminMenu() {
    int choice;
    do {
        std::cout << "Admin Menu\n";
        std::cout << "1. Add User\n";
        std::cout << "2. Add Book\n";
        std::cout << "3. Remove Book\n";
        std::cout << "4. View Book Info\n";
        std::cout << "5. View Borrowed Books\n";
        std::cout << "6. View Books by Genre or Author\n";
        std::cout << "0. Exit Admin Menu\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        std::cin.ignore(); // To ignore the newline character left in the buffer

        switch (choice) {
            case 1:
                addUser();
                break;
            case 2:
                addBook();
                break;
            case 3:
                removeBook();
                break;
            case 4:
                viewBookInfo();
                break;
            case 5:
                viewBorrowedBooks();
                break;
            case 6:
                viewBooksByGenreOrAuthor();
                break;
            case 0:
                std::cout << "Exiting Admin Menu...\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 0);
}

// User menu
void userMenu() {
    int choice;
    do {
        std::cout << "User Menu\n";
        std::cout << "1. Borrow Book\n";
        std::cout << "2. Return Book\n";
        std::cout << "3. View User Books\n";
        std::cout << "0. Exit User Menu\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        std::cin.ignore(); // To ignore the newline character left in the buffer

        switch (choice) {
            case 1:
                borrowBook();
                break;
            case 2:
                returnBook();
                break;
            case 3:
                viewUserBooks();
                break;
            case 0:
                std::cout << "Exiting User Menu...\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 0);
}

// Main function
int main() {
    int choice;
    do {
        std::cout << "Library Management System\n";
        std::cout << "1. Admin Menu\n";
        std::cout << "2. User Menu\n";
        std::cout << "0. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        std::cin.ignore(); // To ignore the newline character left in the buffer

        switch (choice) {
            case 1:
                adminMenu();
                break;
            case 2:
                userMenu();
                break;
            case 0:
                std::cout << "Exiting...\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 0);

    return 0;
}
