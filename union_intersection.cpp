#include <iostream>
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
    int N;
    cin >> N;
    int A[N], B[N];
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < N; i++) cin >> B[i];
    Quicksort(A, 0, N - 1);
    Quicksort(B, 0, N - 1);
    int i = 0, j = 0;
    while (i < N && j < N) {
        if (A[i] < B[j]) i++;
        else if (B[j] < A[i]) j++;
        else {
            cout << A[i] << " ";
            i++; j++;
        }
    }
    cout << endl;

    i = 0; j = 0;
    while (i < N && j < N) {
        if (A[i] < B[j]) {
            cout << A[i++] << " ";
        } else if (B[j] < A[i]) {
            cout << B[j++] << " ";
        } else {
            cout << A[i] << " ";
            i++; j++;
        }
    }

    while (i < N) cout << A[i++] << " ";
    while (j < N) cout << B[j++] << " ";
    cout << endl;


    return 0;
}