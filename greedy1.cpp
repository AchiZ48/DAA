#include <iostream>

using namespace std;

void greedy(int A[], int pos, int sum, int target){
    if( pos < 0){        
        return;
    }
    if((sum + A[pos]) > target){       
        cout << sum << endl;
        greedy(A, pos - 1, A[pos], target);
    } else {
        sum += A[pos];
        greedy(A, pos-1, sum, target);
    }
}

int main(){
    int A[] = {3, 12, 13, 29, 31, 32, 50};
    int size = sizeof(A) / sizeof(A[0]);
    greedy(A, size-1, 0, 84);
}