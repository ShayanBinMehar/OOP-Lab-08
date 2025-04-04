#include <iostream>
#include <string>

class Book {
private:
    std::string title;
    double price;

public:
    Book(const std::string& t, double p) : title(t), price(p) {}

    std::string getTitle() const {
        return title;
    }

    double getPrice() const {
        return price;
    }

    friend class Librarian;
};

class Librarian {
public:
    void displayBookDetails(const Book& book) const {
        std::cout << "Book Title: " << book.title << std::endl;
        std::cout << "Book Price: $" << book.price << std::endl;
    }

    void applyDiscount(Book& book, double discountPercentage) {
        if (discountPercentage >= 0 && discountPercentage <= 100) {
            book.price *= (1 - discountPercentage / 100.0);
            std::cout << "Discount of " << discountPercentage << "% applied to '" << book.title << "'" << std::endl;
        } else {
            std::cout << "Invalid discount percentage." << std::endl;
        }
    }
};

int main() {

    Book myBook("The Great Adventure", 25.99);

    Librarian librarian;

    std::cout << "Initial Book Details:" << std::endl;
    librarian.displayBookDetails(myBook);
    std::cout << std::endl;

    librarian.applyDiscount(myBook, 10.0);
    std::cout << std::endl;

    std::cout << "Updated Book Details:" << std::endl;
    librarian.displayBookDetails(myBook);

    return 0;
}