#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int Partition(int A[], int l, int r) {
    int p = A[l];
    int i = l;
    int j = r + 1;

    while (i < j) {
        do {
            i++;
        } while (i < r && A[i] < p);
        do {
            j--;
        } while (A[j] > p);
        swap(A[i], A[j]);
    }
    swap(A[i], A[j]);
    swap(A[l], A[j]);
    return j;
}

void Quicksort(int A[], int l, int r) {
    if (l < r) {
        int s = Partition(A, l, r);
        Quicksort(A, l, s - 1);
        Quicksort(A, s + 1, r);
    }
}

int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];

    Quicksort(a, 0, n - 1);
    string s = "";
    for (int i = 0; i < n; i++) {
        s += to_string(a[i]);
    }
    cout << s << endl;

    int count[10] = {0};
    int current_run = 1;
    int max_run = 0;

    for (int i = 1; i <= s.length(); i++) {
        if (i < s.length() && s[i] == s[i-1]) {
            current_run++;
        } else {
            int digit = s[i-1] - '0';
            if (current_run > 1) {
                if (current_run > max_run) {
                    max_run = current_run;
                }
                if (current_run > count[digit]) count[digit] = current_run;
            }
            current_run = 1;
        }
    }

    bool first = true;
    for (int d = 0; d <= 9; d++) {
        if (max_run > 1 && count[d] == max_run) {
            if (!first) cout << " ";
            cout << d;
            first = false;
        }
    }
    cout << endl;

    string reduced = "";
    if (s.length() > 0) {
        reduced += s[0];
        for (size_t i = 1; i < s.length(); i++) {
            if (s[i] != s[i-1]) {
                reduced += s[i];
            }
        }
    }
    cout << reduced << endl;

    return 0;
}