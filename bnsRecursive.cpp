#include<iostream>
#include<cmath>
using namespace std;

int bnsRecursive(int A[], int low, int high, int M){
    if(low == high) return low;
    int mid = (low + high)/2;
    cout<<"low "<<low<<" mid "<<mid<<" high "<<high<<endl;
    if(A[mid] == M) return mid;
    else if(A[mid] < M) return bnsRecursive(A, mid+1, high, M);
    else return bnsRecursive(A, low, mid, M);
}

void dacSearch(int A[], int n, int M, int k){
    int i = bnsRecursive(A, 0, n, M);
    int left = i-1;
    int right = i;
    int count = 0;

    while(count < k){
        cout<<"left = "<< left<<", right = "<<right<<endl;
        if(left < 0){
            right++;
            count++;
        }else if (right >= n){
            left--;
            count++;
        }else if (abs(A[left]-M) > abs(A[right]-M)){
            right++;
            count++;
        } else{
            left--;
            count++;
        }
        
    }
    cout<<"Result : ";
    for (int  i = left + 1 ; i < right; i++)
    {
        cout<<A[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int A[] = {10, 12, 15, 17, 18, 20, 25};
    int n = sizeof(A) / sizeof(A[0]);
    int M = 8;
    int k = 2;
    dacSearch(A, n, M, k);
    return 0;
}