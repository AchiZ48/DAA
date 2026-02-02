#include <iostream>
using namespace std;

int main() { // O(n)
    int n;
    cin >> n;

    int a[3];
    for (int i = 0; i < 3; i++) {
        cin >> a[i];
    }

    const int INF = 1000000;
    int dp[1001];

    for (int i = 0; i <= n; i++) {
        dp[i] = INF;
    }

    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 3; j++) {
            if (i >= a[j] && dp[i - a[j]] != INF) {
                if (dp[i] > dp[i - a[j]] + 1) {
                    dp[i] = dp[i - a[j]] + 1;
                }
            }
        }
    }

    cout << dp[n] << endl;
    return 0;
}