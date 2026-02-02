#include <iostream>
#include <algorithm>
using namespace std;

int main() { // O(n!)
    int n;
    cin >> n;

    char book[26];
    for (int i = 0; i < n; i++) {
        cin >> book[i];
    }

    sort(book, book + n);

    do {
        for (int i = 0; i < n; i++) {
            cout << book[i] << " ";
        }
        cout << endl;
    } while (next_permutation(book, book + n));

    return 0;
}