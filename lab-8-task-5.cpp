#include <iostream>
#include <string>

using namespace std;

class Fraction {
private:
    int numerator;
    int denominator;

    int gcd(int a, int b) {
        while (b) {
            a %= b;
            swap(a, b);
        }
        return abs(a);
    }

    void simplify() {
        int commonDivisor = gcd(numerator, denominator);
        numerator /= commonDivisor;
        denominator /= commonDivisor;
        if (denominator < 0) {
            numerator *= -1;
            denominator *= -1;
        }
    }

public:
    Fraction(int num = 0, int den = 1) : numerator(num), denominator(den) {
        if (denominator == 0) {
            cerr << "Error: Denominator cannot be zero." << endl;
            denominator = 1;
        }
        simplify();
    }

    Fraction operator+(const Fraction& other) const {
        int newNumerator = (numerator * other.denominator) + (other.numerator * denominator);
        int newDenominator = denominator * other.denominator;
        return Fraction(newNumerator, newDenominator);
    }

    Fraction operator-(const Fraction& other) const {
        int newNumerator = (numerator * other.denominator) - (other.numerator * denominator);
        int newDenominator = denominator * other.denominator;
        return Fraction(newNumerator, newDenominator);
    }

    Fraction operator*(const Fraction& other) const {
        int newNumerator = numerator * other.numerator;
        int newDenominator = denominator * other.denominator;
        return Fraction(newNumerator, newDenominator);
    }

    Fraction operator/(const Fraction& other) const {
        if (other.numerator == 0) {
            cerr << "Error: Cannot divide by zero fraction." << endl;
            return *this;
        }
        int newNumerator = numerator * other.denominator;
        int newDenominator = denominator * other.numerator;
        return Fraction(newNumerator, newDenominator);
    }

    friend ostream& operator<<(ostream& os, const Fraction& fraction) {
        os << fraction.numerator << "/" << fraction.denominator;
        return os;
    }
};

int main() {
    Fraction f1(1, 2);
    Fraction f2(3, 4);
    Fraction f3(2, 3);
    Fraction f4(1, -2);
    Fraction f5(0, 5);
    Fraction f6(5);

    cout << "f1 = " << f1 << endl;
    cout << "f2 = " << f2 << endl;
    cout << "f3 = " << f3 << endl;
    cout << "f4 = " << f4 << endl;
    cout << "f5 = " << f5 << endl;
    cout << "f6 = " << f6 << endl;
    cout << endl;

    Fraction sum = f1 + f2;
    cout << f1 << " + " << f2 << " = " << sum << endl;

    Fraction difference = f2 - f1;
    cout << f2 << " - " << f1 << " = " << difference << endl;

    Fraction product = f1 * f3;
    cout << f1 << " * " << f3 << " = " << product << endl;

    Fraction quotient = f2 / f3;
    cout << f2 << " / " << f3 << " = " << quotient << endl;

    Fraction divisionByZero(1, 0);

    Fraction f7(5, 10);
    cout << "f7 (before simplification) = " << f7 << endl;

    Fraction divideByZeroFraction(1, 2);
    Fraction zeroFraction(0, 3);
    Fraction resultDivideByZero = divideByZeroFraction / zeroFraction;
    cout << divideByZeroFraction << " / " << zeroFraction << " = " << resultDivideByZero << endl;

    return 0;
}