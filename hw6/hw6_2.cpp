#include <iostream>
using namespace std;

int main() { // O(2ⁿ)
    int k;
    cin >> k;

    int A[5];
    for (int i = 0; i < 5; i++)
        cin >> A[i];

    for (int mask = 1; mask < (1 << 5); mask++) {
        int sum = 0;

        for (int i = 0; i < 5; i++) {
            if (mask & (1 << i))
                sum += A[i];
        }

        if (sum == k) {
            for (int i = 0; i < 5; i++) {
                if (mask & (1 << i))
                    cout << A[i] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}