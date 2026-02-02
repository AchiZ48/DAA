#include <iostream>
#include <algorithm>
using namespace std;

int main() { // O(n!)
    int n;
    cin >> n;

    int a[10];
    for (int i = 0; i < n; i++)
        a[i] = i + 1;

    int count = 0;

    do {
        for (int i = 0; i < n - 1; i++) {
            if ((a[i] == 1 && a[i + 1] == 2) ||
                (a[i] == 2 && a[i + 1] == 1)) {
                count++;
                break;
            }
        }
    } while (next_permutation(a, a + n));

    cout << count << endl;
    return 0;
}