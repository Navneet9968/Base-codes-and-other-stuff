#include<bits/stdc++.h>
using namespace std;
    int gR(){
        return rand()%10+1;
    }
 int main(){
     
     
     
     //this is already allocated
     int alloc[5][3] = { { gR(), gR(), gR() }, // P0 process
                     { gR(), gR(), gR() }, // P1
                     { gR(), gR(), gR() }, // P2
                     { gR(), gR(), gR() }, // P3
                     { gR(), gR(), gR() } }; // P4
    //this is the total requirement
    int max[5][3] = { { 7, 5, 3 }, // P0 // MAX Matrix
                   { 3, 2, 2 }, // P1
                   { 9, 0, 2 }, // P2
                   { 2, 2, 2 }, // P3
                   { 4, 3, 3 } }; // P4
    
    //now we have to make the need matrix
    int n=5;
    int m=3;
    int need[n][m];
    
    for(int i =0;i<n;i++){
        for(int j=0;j<m;j++){
            need[i][j]=max[i][j]-alloc[i][j];
        }
    }
    
    // cout<<need[0][1];
    
    
    // Available Resources
    int avail[3] = { 3, 3, 2 };
    
    int f[n], ans[n], ind = 0;
    //initializing f by 0;
    for (int k = 0; k < n; k++) {
        f[k] = 0;
    }
    
    
    int y = 0;
  for (int process = 0; process < 5; process++) {
    for (int i = 0; i < n; i++) {
        //process not yet done
      if (f[i] == 0) {  

        int flag = 0;
        //iterating over each resources
        for (int j = 0; j < m; j++) {
            //any of the resource can't be allocated
          if (need[i][j] > avail[j]){
            flag = 1;
            break;
          }
        }
        //can allocate resources to that process
        if (flag == 0) {
          ans[ind++] = i;
          for (y = 0; y < m; y++)
            avail[y] += alloc[i][y];
          f[i] = 1;
        }
      }
    }
  }
   
  int flag = 1;
   
  // To check if sequence is safe or not
  for(int i = 0;i<n;i++){
        if(f[i]==0){
        flag = 0;
        cout << "not safe sequence";
        break;
      }
  }
 
  if(flag==1){
    cout << "SAFE Sequence" << endl;
      for (int i = 0; i < n - 1; i++)
        cout << " P" << ans[i] << " ->";
      cout << " P" << ans[n - 1] <<endl;
  }
     return 0;
 }
