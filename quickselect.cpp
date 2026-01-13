#include<iostream>

using namespace std;

int arr[] = {1, 5, 10, 4, 8, 2, 6, 9, 20};
int k = 4;
int n = sizeof(arr)/sizeof(arr[0]);

int partition(int l, int r){
    int mid = (l+r) /2;
    int pivot = arr[mid];
    
    int temp = arr[mid];
    arr[mid] = arr[r];
    arr[r] = temp;

    int i = l - 1 ;

    for (int j = l ; j < r; j++)
    {
        if(arr[j] <= pivot){
            i++;
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    temp = arr[i + 1];
    arr[i + 1]  = arr[r];
    arr[r] = temp;
    return i + 1;
    
}

int quickselect(int low, int high, int k){
    if(low == high){
        return arr[low];
    }
    int p = partition(low, high);

    if(p == k - 1) return arr[p];
    else if(k - 1 < p) return quickselect(low ,p - 1, k);
    else return quickselect(p + 1, high, k);
}

int main(){
    cout<<quickselect(0, n-1, k);
    return 0;
}