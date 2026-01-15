#include<iostream>
#include<cmath>
using namespace std;

void Search(int arr[], int n, int M, int k){
    int l_bs = 0, r_bs = 0;
    int i = 0;
    while(l_bs <= r_bs){
        int mid = (l_bs + r_bs)/2;
        if(arr[mid] == M){
            i = mid;
            break;
        } else if(arr[mid] < M){
            l_bs = mid + 1;
            i = mid + 1;
        } else{
            r_bs = mid - 1;
            i = mid;
        }
    }

    int left = i - 1;
    int right = i;
    int count = 0;

    while(count < k){
        cout<<"left = "<< left<<", right = "<<right<<endl;
        if (left < 0)
        {
            right++;
            count++;
        } else if(right >= n){
            left++;
            count++;
        } else if(abs(arr[left] - M) > abs(arr[right] - M)){
            right++;
            count++;
        } else {
            left++;
            count++;
        }
        
    }
    cout<<"Result : ";
    for (int  i = left + 1 ; i < right; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    
}

int main(){
    int A[] = {10, 12, 15, 17, 18, 20, 25};
    int n = sizeof(A) / sizeof(A[0]);
    int M = 8;
    int k = 2;
    Search(A, n, M, k);
    return 0;
}