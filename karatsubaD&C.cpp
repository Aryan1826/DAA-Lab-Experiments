#include <iostream>
#include <cmath>
using namespace std;

long long karatsuba(long long x, long long y) {
    // base case: single digit multiplication
    if (x < 10 || y < 10) 
        return x * y;

    int n = max((int)log10(x) + 1, (int)log10(y) + 1); // number of digits
    int m = n / 2; // split position

    long long power = pow(10, m);

    long long a = x / power;
    long long b = x % power;
    long long c = y / power;
    long long d = y % power;

    long long p1 = karatsuba(a, c);
    long long p2 = karatsuba(b, d);
    long long p3 = karatsuba(a + b, c + d);

    return p1 * pow(10, 2 * m) + (p3 - p1 - p2) * pow(10, m) + p2;
}

int main() {
    long long num1 = 1234;
    long long num2 = 5678;

    cout << "Num1: " << num1 << endl;
    cout << "Num2: " << num2 << endl;
    cout << "Product (Karatsuba): " << karatsuba(num1, num2) << endl;

    return 0;
}
