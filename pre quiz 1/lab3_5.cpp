#include <bits/stdc++.h>

using namespace std;

int merge(vector<int>& arr, int l, int m, int r){
    int nl = m - l + 1;
    int nr = r-m;
    int L[nl];
    int R[nr];
    for(int i = 0; i<nl; i++){
        L[i] = arr[l+i];
    }
    for(int i = 0; i<nr; i++){
        R[i] = arr[m+i+1];
    }
    int i, j, count;
    i = j = count = 0;
    int k = l;
    while(i < nl && j < nr){
        if(L[i] <= R[j]){
            arr[k] = L[i++];
        } else {
            arr[k] = R[j++];
            count += (nl - i);
        }
        k++;
    }

    while(i < nl || j < nr){
        if(i < nl){
            arr[k] = L[i++];
        } else {
            arr[k] = R[j++];
        }
        k++;
    }
    return count;
}

int mergeSort(vector<int>& arr, int l, int r){
    int count = 0;
    if(l >= r){
        return 0;
    }
    int m = (l+r)/2;
    count += mergeSort(arr, l, m);
    count += mergeSort(arr, m+1, r);
    count += merge(arr, l, m, r);
    return count;
}

int main(){
    vector<int> A = {1, 9, 6, 4, 5};
    cout<<mergeSort(A, 0, A.size()-1);
    return 0;
}