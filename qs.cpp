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
    int n;
    cin>>n;
    int data[n];
    for(int i = 0; i<n; i++){
        cin>>data[i];
    }  
    Quicksort(data, 0, n - 1);
    for (int i = 0; i < n; i++) {
        cout << data[i] << " ";
    }
    cout << "\n";
    return 0;
}