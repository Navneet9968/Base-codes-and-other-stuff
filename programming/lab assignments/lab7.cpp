#include<bits/stdc++.h>
using namespace std;
void displayVector(vector<int>&vec){
    for(int i=0;i<vec.size();i++){
        cout<<vec[i]<<" "<<endl;
    }
}

static int matrixMultiplication(vector<int>&input_vector,int size){
    int dp [size][size]={};
    for(int len=2;len<size;len++){     
                
        for(int row=0,col=len;row<size-len;row++,col++) {
            dp[row][col]=INT_MAX;
            for(int k=row+1;k<col;k++){
                dp[row][col]=min(dp[row][col],
                dp[row][k]+dp[k][col]+
                input_vector[row]*input_vector[k]*input_vector[col]);
            }
        }
    }
    return dp[0][size-1];
}

int main(){
    vector<int>input_vector;
    int size;
    cout<<"Enter the number of matrices you want to multiply :";
    cin>>size;
    cout<<"size = "<<size<<endl;
    int dimension;
    cout<< "Now enter only the first dimension of the matrix "<<endl;
    for(int i=1;i<size+1;i++){
        cout<<"Enter first dimension of matrix : "<< i <<endl;
        cin>>dimension;
        input_vector.push_back(dimension);
    }
    cout<<"Now enter the second dimension of last matrix : "<< endl;
    cin>>dimension;
    input_vector.push_back(dimension);
    cout<<"minimum number of multiplications -> "<< 
            matrixMultiplication(input_vector,input_vector.size());

    return 0;
}