#include <bits/stdc++.h>
using namespace std;
void display(vector<vector<int>>&adjacenyMatrix,int size) {
    for(int i =0;i<size;i++){
        for(int j =0;j<size;j++){
            cout<<adjacenyMatrix[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;

}
int main() {
        cout<<"Enter number of nodes in graph: ";
        int n=0;
        cin>>n;
        vector<vector<int>>adjacenyMatrix(n,vector<int>(n,0));
        cout<<"If node is not connected to any more nodes then enter -1 "<<endl;
        for(int i =0;i<n;i++){
            int number=-2;
            while(number!=-1){
                cout<<"to which node is " << i << " connected to ";
                cin>>number;
                adjacenyMatrix[i][number]=1;
            }
        }
        cout<<endl;
        cout<<"The adjacenyMatrix formed is -->"<<endl;
        display(adjacenyMatrix,n);
        cout<<endl;
        //visiting the root node 
        unordered_map<int,int>visitedNodes;
        visitedNodes[0]++;
        cout<<" DFS : 0";
        stack<int>s;
        s.push(0);
        while(!s.empty()){
            int temp=s.top();
            for(int i=0;i<n;i++){
                
                if(adjacenyMatrix[temp][i]==1 && !visitedNodes[i]){
                    cout<<" "<<i<<" ";
                    visitedNodes[i]++;
                    s.push(i);
                    break;
                }
            }
            if(s.top()==temp){
                s.pop();
            }
        }

    return 0;
}