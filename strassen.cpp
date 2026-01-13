#include <iostream>

using namespace std;

void add(int A[10][10], int B[10][10], int C[10][10], int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] + B[i][j];
}

void subtract(int A[10][10], int B[10][10], int C[10][10], int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] - B[i][j];
}

void strassen(int A[10][10], int B[10][10], int C[10][10], int n) {
    if (n == 1) {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }

    int k = n / 2;
    int a11[10][10], a12[10][10], a21[10][10], a22[10][10];
    int b11[10][10], b12[10][10], b21[10][10], b22[10][10];
    int m1[10][10], m2[10][10], m3[10][10], m4[10][10], m5[10][10], m6[10][10], m7[10][10];
    int temp1[10][10], temp2[10][10];

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            a11[i][j] = A[i][j];
            a12[i][j] = A[i][j + k];
            a21[i][j] = A[i + k][j];
            a22[i][j] = A[i + k][j + k];
            b11[i][j] = B[i][j];
            b12[i][j] = B[i][j + k];
            b21[i][j] = B[i + k][j];
            b22[i][j] = B[i + k][j + k];
        }
    }

    add(a11, a22, temp1, k); add(b11, b22, temp2, k); strassen(temp1, temp2, m1, k);
    add(a21, a22, temp1, k); strassen(temp1, b11, m2, k);
    subtract(b12, b22, temp2, k); strassen(a11, temp2, m3, k);
    subtract(b21, b11, temp2, k); strassen(a22, temp2, m4, k);
    add(a11, a12, temp1, k); strassen(temp1, b22, m5, k);
    subtract(a21, a11, temp1, k); add(b11, b12, temp2, k); strassen(temp1, temp2, m6, k);
    subtract(a12, a22, temp1, k); add(b21, b22, temp2, k); strassen(temp1, temp2, m7, k);

    int c11[10][10], c12[10][10], c21[10][10], c22[10][10];

    add(m1, m4, temp1, k); subtract(temp1, m5, temp2, k); add(temp2, m7, c11, k);
    add(m3, m5, c12, k);
    add(m2, m4, c21, k);
    add(m1, m3, temp1, k); subtract(temp1, m2, temp2, k); add(temp2, m6, c22, k);

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            C[i][j] = c11[i][j];
            C[i][j + k] = c12[i][j];
            C[i + k][j] = c21[i][j];
            C[i + k][j + k] = c22[i][j];
        }
    }
}

int main() {
    int n;
    cin >> n;

    int A[10][10], B[10][10], C[10][10];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> A[i][j];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> B[i][j];

    strassen(A, B, C, n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << C[i][j] << (j == n - 1 ? "" : " ");
        }
        cout << endl;
    }

    return 0;
}