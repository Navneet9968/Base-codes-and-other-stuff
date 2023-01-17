#include <bits/stdc++.h>
using namespace std;
int dp[20][20];

// Function for matrix chain multiplication
int utilityfunc(vector<int> &arr, int i, int j)
{   
	if (i == j){
        return 0;
    }
	
	if (dp[i][j] != -1){
        return dp[i][j];
    }
	
	dp[i][j] = INT_MAX;

	for (int k = i; k < j; k++){
        dp[i][j] = min(dp[i][j], utilityfunc(arr, i, k) + utilityfunc(arr, k + 1, j) + arr[i - 1] * arr[k] * arr[j]);
    }

	return dp[i][j];
}

int main()
{
	vector<int>arr { 5,4,6,2,7};
	int n = sizeof(arr) / sizeof(arr[0]);
	memset(dp, -1, sizeof dp);
    int size=arr.size();
	cout << "minimum multiplication done is = "
		<< utilityfunc(arr,1,size-1) << endl;
}


