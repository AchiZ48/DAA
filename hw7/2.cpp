#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <iomanip>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    vector<int> prefixSum(n+1,0);
        
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    sort(arr.begin(),arr.end());

    for(int i=0;i<n;i++){
        prefixSum[i+1] = prefixSum[i] + arr[i];
    }

    double sum = 0;
    for(int i=0;i<prefixSum.size();i++){
        sum+=prefixSum[i];
    }

    cout<<fixed<<setprecision(2)<<sum/(double)(n);

    return 0;
}