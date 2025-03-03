#include <iostream>

using namespace std;

class Fraction {
private:
    int numerator;   
    int denominator; 

public:

    //сокрощает дробь                          
    int gcd(int a, int b) const {                   
        while (b != 0) {                             
            int temp = b;                              
            b = a % b;
            a = temp;
        }
        return a < 0 ? -a : a;                 
    }
    // применяет сокрощение
    void reduce() {
        int gcd_value = gcd(numerator, denominator);
        numerator /= gcd_value , denominator /= gcd_value;
        
        if (denominator < 0) {
            numerator = -numerator , denominator = -denominator;
        }
    }

    Fraction(int num, int den) : numerator(num), denominator(den) {
        if (den == 0) {
            cout << "Знаменатель не может быть нулем. Завершение программы." <<endl;
        }
        reduce(); 
    }

    Fraction() : Fraction(0, 0) {}

    void display() const {
        cout << numerator << "/" << denominator;
    }

    Fraction operator+(const Fraction& other) const 
    {
        return Fraction(numerator * other.denominator + other.numerator * denominator,denominator * other.denominator);
    }

    Fraction operator-(const Fraction& other) const
    {
        return Fraction(numerator * other.denominator - other.numerator * denominator,denominator * other.denominator);
    }

    Fraction operator*(const Fraction& other) const 
    {
        return Fraction(numerator * other.numerator,denominator * other.denominator);
    }                                                                                       

    // это равбота с целыми числами
    Fraction operator+(int whole) const 
    {        // это указатель на адресс обьект , утрировано работа с копией класса 
        return *this + Fraction(whole, 1);
    }

    Fraction operator-(int whole) const 
    {
        return *this - Fraction(whole, 1);
    }

    Fraction operator*(int whole) const {
        return *this * Fraction(whole, 1);
    }

    // нужен для вывода / 
    friend ostream& operator<<(ostream& out, const Fraction& frac) {
        out << frac.numerator << "/" << frac.denominator;
        return out;
    }
};

int main() {
    // ввод дроби
    Fraction a(5, 45); 
    Fraction b(50, 60); 
    Fraction c = a + b;
    Fraction d = a - b; 
    Fraction e = a * b; 
    Fraction f = a + 8;
    Fraction r = a - 4;
    Fraction y = a * 9;

    // вывод
    cout << "a: " << a << endl;
    cout << "b: " << b << endl;
    cout << "c (a + b): " << c << endl;
    cout << "d (a - b): " << d << endl;
    cout << "e (a * b): " << e << endl;
    cout << "f (a + 1): " << f << endl;
    cout << "r (a - 1): " << r << endl;
    cout << "y (a * 1): " << y << endl; 


    return 0;
}
