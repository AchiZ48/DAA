#include<iostream>

using namespace std;

int count = 0;

int bts(int l, int r, int target){
    if(l > r) return -1;
    int mid = (l + r) / 2;
    int sum = (mid*(mid+1) )/ 2;
    if(sum == target) return mid;
    if( sum > target ) return bts(l, mid-1, target);
    else return bts(mid+1, r, target);
}

int main(){
    int x;
    cin>>x;
    if(x <= 0){
        cout<< -1;
    } else {
        cout<<bts(1, x, x);
    }
    return 0;
}
