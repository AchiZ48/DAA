#include <iostream>
#include <cmath>

using namespace std;

long long power10(int n) {
    long long res = 1;
    for (int i = 0; i < n; i++) res *= 10;
    return res;
}

long long multiply_karatsuba(long long a, long long b, int n) {
    if (n <= 1) {
        return a * b;
    }

    int m = n / 2;
    long long p = power10(m);
    
    long long a1 = a / p;
    long long a2 = a % p;
    long long b1 = b / p;
    long long b2 = b % p;

    cout << "Step Partition (n=" << n << "):" << endl;
    cout << "  a -> a1=" << a1 << ", a2=" << a2 << endl;
    cout << "  b -> b1=" << b1 << ", b2=" << b2 << endl;

    long long A = multiply_karatsuba(a1, b1, m);
    long long B = multiply_karatsuba(a2, b2, m);
    long long C = multiply_karatsuba(a1 + a2, b1 + b2, m);

    long long midTerm = C - A - B;
    long long res = A * power10(2 * m) + midTerm * p + B;

    cout << "Step Combine (n=" << n << "):" << endl;
    cout << "  A (a1*b1) = " << A << endl;
    cout << "  B (a2*b2) = " << B << endl;
    cout << "  C (a1+a2)*(b1+b2) = " << C << endl;
    cout << "  Middle Term (C-A-B) = " << midTerm << endl;
    cout << "  Result = " << A << "*10^" << 2*m << " + " << midTerm << "*10^" << m << " + " << B << " = " << res << endl << endl;

    return res;
}

int main() {
    long long a = 4568;
    long long b = 3275;
    int n = 4;

    cout << "Starting Karatsuba Multiplication: " << a << " * " << b << endl << endl;

    long long result = multiply_karatsuba(a, b, n);

    cout << "--------------------------------------------" << endl;
    cout << "Final Result: " << result << endl;

    return 0;
}