#include <bits/stdc++.h>
using namespace std;
unordered_set<string> st;
void generateAllDistinctSubsequence(string t ,int i ,int n ,string s){
    if(i==n){
        st.insert(t);
    }
    else{
        generateAllDistinctSubsequence(t,i+1,n,s);
        t=t+s[i];
        generateAllDistinctSubsequence(t,i+1,n,s);
    }
}
int main() {
    string str ="abc";
    generateAllDistinctSubsequence("",0,str.length(),str);
    for(auto it : st){
        cout<<it<<endl;
    }

    return 0;
}