#include <iostream>

using namespace std;

long long power10(int n) {
    long long res = 1;
    for (int i = 0; i < n; i++) res *= 10;
    return res;
}

long long multiply(long long a, long long b, int n) {
    if (n <= 1) {
        return a * b;
    }

    long long p = power10(n / 2);
    long long a1 = a / p;
    long long a2 = a % p;
    long long b1 = b / p;
    long long b2 = b % p;

    cout << "Divide n=" << n << ": " << a << " * " << b << endl;
    cout << "  -> a1=" << a1 << ", a2=" << a2 << ", b1=" << b1 << ", b2=" << b2 << endl;

    long long A = multiply(a1, b1, n / 2);
    long long B = multiply(a2, b1, n / 2);
    long long C = multiply(a1, b2, n / 2);
    long long D = multiply(a2, b2, n / 2);

    long long res = A * power10(n) + (B + C) * p + D;

    cout << "Combine n=" << n << ": A=" << A << ", B=" << B << ", C=" << C << ", D=" << D << endl;
    cout << "  -> Result = " << A << "*10^" << n << " + (" << B << "+" << C << ")*10^" << n/2 << " + " << D << " = " << res << endl << endl;

    return res;
}

int main() {
    long long a = 4568;
    long long b = 3275;
    int n = 4;

    cout << "Starting Multiply " << a << " and " << b << " (n=" << n << ")" << endl << endl;
    
    long long final_result = multiply(a, b, n);

    cout << "-----------------------------------" << endl;
    cout << "Final Result: " << final_result << endl;

    return 0;
}