#include <iostream>
#include <climits>
using namespace std;

int Best[100];
int X[100];
int maxv = INT_MIN;
int bestw = 0;
int n = 4;
int count = 0;

void knapsack(int l, int A[], int W[], int w, int sumw, int sumv) {

    if (l == n) {
    	count++;
        if (sumv > maxv) {
            maxv = sumv;
            bestw = sumw;
            for (int i = 0; i < n; i++)
                Best[i] = X[i];
        }
        return;
    }
	if (sumw + W[l] <= w) {		
        X[l] = 1;
        knapsack(l + 1, A, W, w, sumw + W[l], sumv + A[l]);
    }
	
    X[l] = 0;
    knapsack(l + 1, A, W, w, sumw, sumv);
}

int main() {
    int A[] = {10, 20, 25, 8};
    int W[] = {5, 3, 6, 4};

    knapsack(0, A, W, 13, 0, 0);

    cout << "Best Value: " << maxv << endl;
    cout << "Best Weight: " << bestw << endl;
    cout << "Items: ";
    
    for (int i = 0; i < n; i++) {
        if (Best[i])
            cout << A[i] << " ";
    }
    cout <<endl<< count;
    return 0;
}

