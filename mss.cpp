#include <iostream>
#include <algorithm>

using namespace std;

int Max_Subarray_Sum(int A[], int n) {
    if (n == 1) {
        return A[0];
    }

    int m = n / 2;
    int Lmss = Max_Subarray_Sum(A, m);
    int Rmss = Max_Subarray_Sum(A + m, n - m);

    int lsum = -1000, rsum = -1000, sum = 0;

    for (int i = m; i < n; i++) {
        sum += A[i];
        rsum = max(rsum, sum);
    }

    sum = 0;
    for (int i = m - 1; i >= 0; i--) {
        sum += A[i];
        lsum = max(lsum, sum);
    }

    return max(max(Lmss, Rmss), lsum + rsum);
}

int main() {
    int arr[] = {16, -25, 2, -54, 36, 9, -12, 66};
    int n = sizeof(arr) / sizeof(arr[0]);

    int result = Max_Subarray_Sum(arr, n);

    cout << result << endl;

    return 0;
}