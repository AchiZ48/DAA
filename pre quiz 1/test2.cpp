#include <bits/stdc++.h>

using namespace std;

void merge(vector<int>& arr, int l, int m, int r){
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
    int i, j;
    i = j = 0;
    int k = l;
    while(i < nl && j < nr){
        if(L[i] <= R[j]){
            arr[k] = L[i++];
        } else {
            arr[k] = R[j++];
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
}

void mergeSort(vector<int>& arr, int l, int r){
    if(l >= r){
        return;
    }
    int m = (l+r)/2;
    mergeSort(arr, l, m);
    mergeSort(arr, m+1, r);
    merge(arr, l, m, r);
}

int bts(vector<int>& arr, int l, int r, int target){
    if( l >  r){
        return -1;
    }
    int m = (l+r)/2;
    if(arr[m] == target){
        return m;
    }
    if(arr[m] > target){
        return bts(arr, l, m -1, target);
    } else {
        return bts(arr, m+1, r, target);
    }
}

int findStep(vector<int>& arr, int target, int start){
    int idx = bts(arr, start, arr.size(), target);
    if(idx == -1) return -1;
    int first, current, last;
    first = current = last = idx;
    while(current != -1){
        first = current;
        current = bts(arr, start, current-1, target);
    }
    current = idx;
    while(current != -1){
        last = current;
        current = bts(arr, current+1, arr.size(), target);
    }

    return last - first + 1;
}

int main(){
    vector<int> A = {5, 5, 5, 5, 8, 8, 8, 10, 2, 1, 100, 30, 17, 13, 6, 6, 9};
    mergeSort(A, 0, A.size()-1);
    int modeCount = INT_MIN;
    int value = A[0];
    for(int i = 0; i < A.size();){
        int target = A[i];
        int step = findStep(A, target, i);
        if(step > modeCount && step != -1){
            modeCount = step;
            value = A[i];
        }
        i += step;
    }
    cout<<"value = "<<value<<" Count = "<<modeCount<<endl;
    return 0;
}