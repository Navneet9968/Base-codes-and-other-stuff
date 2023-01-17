#include <bits/stdc++.h>
using namespace std;

int main() {
    
    return 0;
}
class Solution{
    public:
    
    
    
    
    void f(vector<vector<int>> &m,int i ,int j , string temp,vector<vector<int>>&visited,int n,vector<string>&ans){
        
        //base case
        if(i==n-1 && j==n-1){
            ans.push_back(temp);
            return;
        }
        
        //down
        if(visited[i+1][j]==0 && m[i+1][j]==1 && i+1>=0 && j>=0 && i+1<n && j<n){
            
            visited[i][j]=1;
            f(m,i+1,j,temp+'D',visited,n,ans);
            visited[i][j]=0;
            
        }
        
        //left
        if(visited[i][j-1]==0 && m[i][j-1]==1 && i>=0 && j-1>=0 && i<n && j-1<n){
            
            visited[i][j]=1;
            f(m,i,j-1,temp+'L',visited,n,ans);
            visited[i][j]=0;
            
        }
        
        
        //right
        if(visited[i][j+1]==0 && m[i][j+1]==1 && i>=0 && j+1>=0 && i<n && j+1<n){
            
            visited[i][j]=1;
            f(m,i,j+1,temp+'R',visited,n,ans);
            visited[i][j]=0;
            
        }
        
        //up
        if(visited[i-1][j]==0 && m[i-1][j]==1 && i-1>=0 && j>=0 && i-1<n && j<n){
            
            visited[i][j]=1;
            f(m,i-1,j,temp+'U',visited,n,ans);
            visited[i][j]=0;
            
        }
            
        
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        
        string temp;
        vector<string>ans;
        vector<vector<int>>visited(n,vector<int>(n,0));
        visited[0][0]=1;
        f(m,0,0,temp,visited,n,ans);
        // if(ans.size()==0){
        //     return "-1";
        // }
        return ans;
    }
};

    