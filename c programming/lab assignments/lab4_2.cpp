#include <bits/stdc++.h>
using namespace std;

//////////////////////////////////////////////////////////////////////////////////////////
//count sorting

void count_sort(vector<int> &arr,int size){
    int max_element=arr[0];
    for(int i=0;i<size;i++){
        max_element=max(max_element,arr[i]);
    }
    int temp_arr[max_element+1]={0};
    for(int i =0;i<size;i++){
        temp_arr[arr[i]]++;
    }
    int index_arr=0;
    for(int i =0;i<(max_element+1);i++){
        if(temp_arr[i]==0){
            continue;
        }
        while(temp_arr[i]!=0){
            arr[index_arr]=i;
            index_arr++;
            temp_arr[i]--;
        }
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////
int main(){
    vector<int> arr;
    int size = 0;
    cout<<"Enter total submissions -->"<<endl;
    cin>>size;
    int a ;
    for(int i =0;i<size;i++){
        cout<<"Enter roll no for submission --> "<<i<<endl;
        cin>>a;
        arr.push_back(a);
    }
    cout<<endl;
    

   
    count_sort(arr,size);
   
    
    int curr_freq=0;
    int curr_number=arr[0];
    cout<<endl;
    //finding the most frequent value in array 
    for(int i=0;i<size;i++){
        if(arr[i]!=curr_number && curr_freq>1){
            cout<< "The roll no  "<< curr_number << "  has submitted the test  "<< curr_freq<<"  times. "<<endl;
        }
        if(arr[i]==curr_number){
            curr_freq++;
        }
        
        if(arr[i]!=curr_number){
            curr_number=arr[i];
            curr_freq=1;
        }
    }
    cout<<endl;
    cout<<endl;
    return 0;
}