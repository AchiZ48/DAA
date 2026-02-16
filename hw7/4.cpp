#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

typedef struct{
    int r1;
    int r2;
    int sum;
} reward;

bool compare(reward a,reward b){
    return a.sum >= b.sum;
}


int main(){
    int n;
    cin>>n;
    vector<reward> arr(n);

    for(int i=0;i<n;i++){
        cin>>arr[i].r1>>arr[i].r2;
        arr[i].sum = arr[i].r1 + arr[i].r2;
    }

    sort(arr.begin(),arr.end(),compare);

    int c1 , c2;
    c1 = c2 = 0;

    for(int i=0;i<n;i++){
        int first;
        int second;
        if (arr[i].r1 >= arr[i].r2){
            first = arr[i].r1;
            second = arr[i].r2;
        } else {
            first = arr[i].r2;
            second = arr[i].r1;
        }
        
        if (c1 <= c2){
            c1 += first;
            c2 += second;
        }else{
            c2 += first;
            c1 += second;
        }
    }

    cout<<abs(c1-c2);

    return 0;
}