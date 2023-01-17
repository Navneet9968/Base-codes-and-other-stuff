#include <bits/stdc++.h>
using namespace std;


void printvec(vector<int> &v){
    cout<<endl;
    for(int i =0;i<v.size();i++){
        cout<<" "<<v[i];
    }
    
}

int cnt=0;
void f(int ind,vector<int>&temp,vector<int>&v){
    if(ind>=v.size()){
        printvec(temp);
        cnt++;
        return;
    }
    temp.push_back(v[ind]);
    f(ind+1,temp,v);
    temp.pop_back();
    f(ind+1,temp,v);
}

int main() {
    vector<int> v{3,1,2};
    vector<int>temp;

    f(0,temp,v);
    cout<<"the number of subsequences are "<<cnt<<endl;
    return 0;
}