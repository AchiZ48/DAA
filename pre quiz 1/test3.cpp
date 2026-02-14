#include <bits/stdc++.h>

using namespace std;

int gcd(int x, int y){
    if(y == 0) return x;
    return gcd(y, x%y);
}

int bigcd(vector<int>& arr, int l, int r){
    if(l >= r) return arr[l];
    int m = (l+r) / 2;
    int r1 = bigcd(arr, l, m);
    int r2= bigcd(arr, m+1, r);
    return gcd(r1,r2);
}

int main(){
    vector<int> A = {6,12,24,36,60,48};
    int value = bigcd(A, 0, A.size()-1);
    cout<<"value = "<<value<<endl;
    return 0;
}