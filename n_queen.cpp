#include<iostream>
#include<cmath>

using namespace std;

int n = 4, x[4];

void n_queen(int k){
	if(k == n){
		int flag = 0;
		for(int j = 1; j<k; j++){
			for(int p = 0; p<j; p++){
				if(abs(p-j) == abs(x[p]-x[j]) || (x[j] == x[p])) flag = 1;
			}
		}
//		for(int i = 0; i<k; i++){
//				cout<<x[i];
//			}
//		if(flag == 0){
//			
//			cout<<" *";
//		}
//	cout<<endl;
		
		if(flag == 0){
			for(int i = 0; i<k; i++){
				cout<<x[i];
			}
			cout<<endl;
		}
		
	}else{
		for(int row = 0; row < n; row++){
			x[k] = row;
			n_queen(k+1);
		}
	}
}

int main(){
	n_queen(0);
	return 0;
}
