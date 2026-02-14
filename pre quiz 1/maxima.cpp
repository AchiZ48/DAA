#include <bits/stdc++.h>
using namespace std;

struct Point
{
    int x;
    int y;
    bool operator<(const Point& other) const {
        if (x != other.x) return x < other.x;
        return y < other.y;
    }
};


int main(){
    int n;
    cin>>n;
    vector<Point> arr(n);
    for(int i=0;i<arr.size();i++){
        cin>>arr[i].x>>arr[i].y;
    }
    sort(arr.begin(), arr.end());
    int maxY = INT_MIN;
    for (int i = n - 1; i >= 0; i--) {
    if (arr[i].y > maxY) {
        maxY = arr[i].y;
        cout<<arr[i].x<<" "<<arr[i].y<<endl;
    } 
}
    return 0;
}