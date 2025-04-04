#include <iostream>

using namespace std;

class Currency {
private:
    double amount;

public:
    Currency(double amt = 0.0) : amount(amt) {}

    Currency operator-() const {
        return Currency(-amount);
    }

    Currency operator+(const Currency& other) const {
        return Currency(amount + other.amount);
    }

    Currency operator-(const Currency& other) const {
        return Currency(amount - other.amount);
    }

    Currency& operator+=(const Currency& other) {
        amount += other.amount;
        return *this;
    }

    Currency& operator-=(const Currency& other) {
        amount -= other.amount;
        return *this;
    }

    friend ostream& operator<<(ostream& os, const Currency& c) {
        os << "$" << c.amount;
        return os;
    }
};

int main() {
    Currency c1(100.50), c2(50.25), discount(10.00);

    cout << "Initial Values:" << endl;
    cout << "Currency 1: " << c1 << endl;
    cout << "Currency 2: " << c2 << endl;
    cout << "Discount: " << discount << endl;
    cout << "---------------------------------\n";

    cout << "Negation of Currency 1: " << -c1 << endl;

    Currency sum = c1 + c2;
    cout << "Sum (c1 + c2): " << sum << endl;

    Currency diff = c1 - c2;
    cout << "Difference (c1 - c2): " << diff << endl;

    c1 += c2;
    cout << "After c1 += c2: " << c1 << endl;

    c1 -= discount;
    cout << "After applying discount (c1 -= discount): " << c1 << endl;

    return 0;
}
