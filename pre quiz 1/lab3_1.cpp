#include<bits/stdc++.h>
using namespace std;

int n = 0;

void targetk(vector<int>& arr, int l, int r, int k){
    if(l > r) return;
    int m = (l+r)/2;
    if(arr[m] == k){
        n++;
    }
    targetk(arr, l, m-1, k);
    targetk(arr, m+1, r, k);
}

int main(){
    vector<int> arr = {5,2,5,6,6,5};
    int k;
    cin>>k;
    targetk(arr, 0, arr.size()-1, k);
    cout<<n;
}