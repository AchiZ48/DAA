#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
using namespace std;

typedef struct
{
    int idx;
    int W;
    int V;
} inventory;

bool compare(inventory a, inventory b)
{
    return (double)a.V / a.W > (double)b.V / b.W;
}

void fractionalKnapsack(double M, vector<inventory> &arr)
{
    double sumProfit = 0;
    double sumW = 0;
    int i = 0;
    vector<double> tempRatio(arr.size(), 0.00);

    while (arr[i].W <= M)
    {
        sumProfit += arr[i].V;
        M -= arr[i].W;
        sumW += arr[i].W;
        tempRatio[arr[i].idx] = 1.00;
        i++;
    }

    double fraction = M / arr[i].W;
    sumProfit += arr[i].V * fraction;
    sumW += arr[i].W * fraction;
    tempRatio[arr[i].idx] = fraction;

    for (int i = 0; i < tempRatio.size(); i++)
    {
        cout << fixed << setprecision(2) << tempRatio[i] << " ";
    }

    cout << endl;

    cout << fixed << setprecision(2) << sumProfit << endl;
}
int main()
{
    int n;
    double M;
    cin >> n >> M;
    vector<inventory> arr(n);
    for (int i = 0; i < n; i++)
    {
        arr[i].idx = i;
        cin >> arr[i].W;
    }

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].V;
    }

    sort(arr.begin(), arr.end(), compare);

    fractionalKnapsack(M, arr);

    return 0;
}