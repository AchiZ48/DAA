#include<iostream>
#include<cmath>

using namespace std;

int n = 4, x[4];
int count;
void n_queen(int k){
	if(k == n){		
		for(int i = 0; i<k; i++){
				cout<<x[i];
			}
			cout<<endl;
		
	}else{
		
		for(int row = 0; row < n; row++){
			x[k] = row;
			int flag = 0;
			for(int j = 0; j<k; j++){
				if(abs(k-j) == abs(x[k]-x[j]) || (x[k] == x[j])) flag = 1;		
			}	
			if(flag == 0){
				count++;
				n_queen(k+1);
		}
		}
		
	}
}

int main(){
	n_queen(0);
	cout<<count;
	return 0;
}
