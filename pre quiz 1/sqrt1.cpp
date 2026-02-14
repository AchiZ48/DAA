#include <iostream>
using namespace std;

void findSquareRoot(int n) {
    int low = 0, high = n, ans = 0, count = 0;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        count++; // นับจำนวนรอบทุกครั้งที่คำนวณ mid
        
        if (mid * mid <= n) {
            ans = mid;
            low = mid + 1; // เคลื่อน low ไปข้างหน้า
        } else {
            high = mid - 1; // เคลื่อน high ไปข้างหลัง
        }
    }
    
    cout << ans << " " << count;
}

int main() {
    int n;
    cin >> n;
    findSquareRoot(n);
    return 0;
}