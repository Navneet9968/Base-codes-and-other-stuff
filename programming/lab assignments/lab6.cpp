#include<bits/stdc++.h>
using namespace std;

int minfind(vector<int>&vec,int si ,int ei){
    if(si==ei)  return vec[si];
    int size=(ei-si+1);
    
    int left=minfind(vec,si,(size/2)-1+si);
    int right=minfind(vec,(size/2)+si,ei);
    int mini=min(left,right);
    return mini;
}
int maxfind(vector<int>&vec,int si ,int ei){
    if(si==ei)  return vec[si];
    int size=(ei-si+1);
    
    int left=maxfind(vec,si,(size/2)-1+si);
    int right=maxfind(vec,(size/2)+si,ei);
    int maxi=max(left,right);
    return maxi;
}
int main(){
    vector<int>vec={42,56,34,14,3,98,74};
    int maxBP=maxfind(vec,0,vec.size()-1);
    cout<<"The MAXIMUM Blood Pressure is "<<maxBP<<endl;
    int minBP=minfind(vec,0,vec.size()-1);
    cout<<"The MINIMUM Blood Pressure is "<<minBP<<endl;
    return 0;
}