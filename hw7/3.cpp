#include <bits/stdc++.h>
using namespace std;

typedef struct{
    double in;
    double out;
} train;

bool compare(train a,train b){
    return a.out <= b.out;
}

void printArr(vector<train> &arr){
    for(int i=0;i<arr.size();i++){
        cout<<arr[i].in<<" "<<arr[i].out<<endl;
    }
}

int main(){
    int n;
    cin>>n;
    vector<train> arr(n);
    queue<train> q;
    for(int i=0;i<n;i++){
        cin>>arr[i].in>>arr[i].out;
    }

    int stationCount = 0;

    sort(arr.begin(),arr.end(),compare);

    q.push(arr[0]);
    for(int i=1;i<arr.size();i++){
        while (!q.empty() && q.back().out <= arr[i].in){
            q.pop();
        }
        q.push(arr[i]);
        stationCount = max(stationCount,(int)q.size());
    }

    cout<<"station = "<<stationCount;

    return 0;
}


// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;

// typedef struct {
//     double in;
//     double out;
// } train;

// bool compare(train a, train b) {
//     return a.in < b.in;
// }

// int main() {
//     int n;
//     cin >> n;
//     vector<train> arr(n);
//     for (int i = 0; i < n; i++) {
//         cin >> arr[i].in >> arr[i].out;
//     }

//     sort(arr.begin(), arr.end(), compare);

//     vector<double> v;
//     int stationCount = 0;

//     for (int i = 0; i < n; i++) {
//         while (!v.empty() && v.front() <= arr[i].in) {
//             v.erase(v.begin());
//         }
//         v.push_back(arr[i].out);
//         sort(v.begin(), v.end());
//         stationCount = max(stationCount, (int)v.size());
//     }

//     cout << stationCount << endl;

//     return 0;
// }
