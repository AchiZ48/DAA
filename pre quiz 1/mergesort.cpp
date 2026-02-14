#include <bits/stdc++.h>
using namespace std;

int merge(vector<int>& arr, int l, int m, int r){
    int n1 = m-l+1;
    int n2 = r-m;
    int L[n1];
    int R[n2];
    for (int i = 0; i < n1; i++)
    {
        L[i] = arr[l+i];
    }
    for (int i = 0; i < n2; i++)
    {
        R[i] = arr[m +i+1];
    }
    int i,j,k;
    i=j=0;
    k=l;
    while (i < n1 && j < n2)
    {
       if(L[i] <= R[j]){
        arr[k++] = L[i++];
       } else {
        arr[k++] = R[j++];
       }
    }
    while (i < n1 || j < n2)
    {
       if(i < n1){
        arr[k++] = L[i++];
       } else {
        arr[k++] = R[j++];
       }
    }
}

void mergesort(vector<int>& arr, int l, int r){
    if(l < r){
        int m = (l+r)/2;
        mergesort(arr, l, m);
        mergesort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}

int main(){
    vector<int> arr = {6, 5, 8, 7, 11, 9};
    mergesort(arr, 0, arr.size()-1);
    for(int i = 0; i<arr.size(); i++){
        cout<<arr[i]<<endl;
    }
}