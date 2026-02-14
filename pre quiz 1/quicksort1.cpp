#include<bits/stdc++.h>

using namespace std;

int partion(vector<int>& arr, int l, int r){
    int m = (l+r)/2;

    swap(arr[m], arr[r]);
    int i = l - 1;
    for(int j = l; j < r; j++){
        if(arr[j] <= arr[r]){
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    swap(arr[i+1], arr[r]);
    return i+1;
}
void quicksort(vector<int>& arr, int l, int r){
    if(l<r){
        int s = partion(arr, l, r);
        quicksort(arr, l, s-1);
        quicksort(arr, s+1, r);
    }
}

int main(){
    vector<int> arr = {1, 5, 8, 7, 11, 9};
    quicksort(arr, 0, arr.size()-1);
    for(int i = 0; i<arr.size(); i++){
        cout<<arr[i]<<endl;
    }
}