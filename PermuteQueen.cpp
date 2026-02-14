#include<iostream>
#include<cmath>

using namespace std;

int count = 0;

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void permute(int X[], int start, int end){
	if(start == end){
		int flag = 0;
		for(int j = 1; j<=start; j++){
			for(int p = 1; p<j; p++){
				if(abs(p-j) == abs(X[p]-X[j]) || (X[j] == X[p])) flag = 1;
			}
		}
		for(int i = 1; i<=end; i++){
				cout<<X[i];
			}
		if(flag == 0){
			
			cout<<" *";
		}
		count++;
		cout<<endl;
		return;
	}
	for(int i = start; i<= end; i++){
		swap(&X[start], &X[i]);
		permute(X, start + 1, end);
		swap(&X[start], &X[i]);
	}
}

int main(){
	int n = 4;
	int x[] = {-1, 1, 2, 3, 4};
	permute(x,1,n);
	cout<<count;
	return 0;
}
