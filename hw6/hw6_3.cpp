#include <iostream>
using namespace std;

int main() { // O(2ⁿ)
    int k;
    cin >> k;

    int V[4], W[4];
    for (int i = 0; i < 4; i++) {
        cin >> V[i];
    }
    for (int i = 0; i < 4; i++) {
        cin >> W[i];
    }

    int maxValue = 0;
    for (int mask = 0; mask < (1 << 4); mask++) {
        int totalW = 0, totalV = 0;

        for (int i = 0; i < 4; i++) {
            if (mask & (1 << i)) {
                totalW += W[i];
                totalV += V[i];
            }
        }
        if (totalW <= k && totalV > maxValue) {
            maxValue = totalV;
        }
    }

    cout << maxValue << endl;
    return 0;
}