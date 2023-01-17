#include <bits/stdc++.h>
using namespace std;

void printvec(vector<int> &v){
    for(int i =0;i<v.size();i++){
        cout<<" i = "<<  i << " value= "<< v[i]<<endl;
    }
    cout<<endl;
}

int fpe(vector<int> &v){
    int low=0;
    int high=v.size()-1;
    int mid=(low+high)/2;
    if(v[0]>v[1]){
        return 0;
    }
    if(v[high]>v[high-1]){
        return high;
    }
    while(low<=high){
        mid=(low+high)/2;
        if(mid==0 ||mid==high){
            break;
        }
        if((v[mid]>v[mid-1]) && (v[mid]>v[mid+1])){
            return mid;
        }
        if((v[mid]<v[mid+1]) && (v[mid]>v[mid-1])){
            low=mid+1;
            if(v[low]>v[low+1]){
                return low;
            }
        }
        else{
            high=mid-1;
            if(v[high]>v[high-1]){
                return high;
            }
        }
    }
    return mid;
}

int main() {
    vector<int> v;
    int count = 0;
    cout<<"enter how many characters to add to the array"<<endl;
    cin >> count;
    for(int i=0;i<count;i++){
        cout<<"enter value for  i = "<<i <<endl;
        int temp;
        cin>>temp;
        v.push_back(temp);
    }
    printvec(v);
    
    cout<<"the peak element is "<<v[fpe(v)]<<endl;

    return 0;
}