#include<iostream>

using namespace std;

int A[] = {25,10,9,2};
int k = 12;
int count = 0;

void print_sol(int x[], int n){
	for(int j = 1; j <= n; j++){
		if(x[j] == 1) cout<<A[j-1]<<" ";
		
	}
	cout<<endl;
}

void Subset1(int x[], int l, int r, int sum){
	if(sum == k){
		print_sol(x, r);
		return;
	}
	if(l == r){
		return;
	};
	if(sum > k) return;
	count++;
	x[l+1] = 1;
	sum += A[l];
	Subset1(x, l+1, r, sum);
	x[l + 1] = 0;
	sum -= A[l];
	Subset1(x, l+1, r, sum);
}

int main(){
	int n = 4;
	int x[n+1];
	Subset1(x, 0, n, 0);
	cout<<count;
	return 0;
}
