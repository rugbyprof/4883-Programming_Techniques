#include <iostream>
#include <vector>

using namespace std;

// KADANE(array, len)
// 	sum = 0
// 	maxSum = -\infty 
// 	for x = 0 to len
// 		sum += array[x]
// 		maxSum = MAX(sum, maxSum)
// 		if(sum < 0)
// 			sum = 0
// 	return maxSum
 
#define MAX(X, Y) (X > Y) ? X : Y
#define POS(X) (X > 0) ? X : 0
 
#define N 11
 
//int arr[N] = { 1, -6, 2, -1, 4, -1, 2, 1 };
//int arr[N] = { 1, 2, 3, 4, -1, 4, 3, 2 };
int arr[N] = { -2, 1, -3, 4, -1, 2, 1, -5, 4}; //[4, −1, 2, 1],
 
int maxSum = INT_MIN;
 
int kadane(int* row, int len) {
    int x, sum, maxSum = INT_MIN;
    for (sum = POS(row[0]), x = 0; x < N; ++x, sum = POS(sum + row[x]))
        maxSum = MAX(sum, maxSum);
    return maxSum;
}
 
int main() {
    cout << kadane(arr, N) << endl;
    return 0;
}

/*
int main(){
    int n = 10;
    int max = -99999999;
    int sum = 0;

    vector<int> a(10,0);

    for (int i = 0; i < n; i++){
        a[i] = rand() % 10;
        if (rand() % 2 ==0){
            a[i] *= -1;
        }
    }

    max = -99999999;
    sum = 0;
    for (int i = 0; i < n; i++){
        for (int j = i; j < n; j++) {
            int sum = 0;
            for (int k = i; k <= j; k++){
                sum += a[k];
            }
            if (sum > max){
                max = sum;
            }
        }
    }

    max = -99999999;
    sum = 0;
    for(int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i; j < n; j++) {
            sum += a[j];
            if (sum > max)
                max = sum;
        }
    }
    return 0;
}
*/
