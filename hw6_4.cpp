#include <iostream>
using namespace std;

void swap(int *a, int *b) { // O(4!)
    int temp = *a;
    *a = *b;
    *b = temp;
}

int isSafe(int X[], int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (abs(X[i] - X[j]) == abs(i - j)) {
                return 0;   // ชนกัน
            }
        }
    }
    return 1;   // ปลอดภัย
}

void permute(int X[], int start, int end) {
    if (start == end) {
        if (isSafe(X, end)) {
            for (int i = 1; i <= end; i++) {
                cout<<X[i];
            }
            cout<<endl;
        }
        return;
    }

    for (int i = start; i <= end; i++) {
        swap(&X[start], &X[i]);
        permute(X, start + 1, end);
        swap(&X[start], &X[i]);
    }
}

int main() {
    int n = 4;
    int X[] = {-1, 1, 2, 3, 4};
    permute(X, 1, n);

    return 0;
}