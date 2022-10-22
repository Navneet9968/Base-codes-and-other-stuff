#include <bits/stdc++.h>
using namespace std;
void arr_display( vector<int> &arr){
    cout<<"displaying the vector now -->"<<endl;
    for(int i =0;i<arr.size();i++){
        cout<<arr[i]<<endl;
    }
}
//////////////////////////////////////////////////////////////////////////////////////////
//count sorting


void count_sort(vector<int> &arr,int size){
    cout<<"eneterd"<<endl;
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
    cout<<"finished"<<endl;
}

/////////////////////////////////////////////////////////////////////////////////////////////
int main(){
    vector<int> arr;
    int size = 0;
    cout<<"Enter the number of values in the array -->"<<endl;
    cin>>size;
    int a ;
    for(int i =0;i<size;i++){
        cout<<"Enter value for index --> "<<i<<endl;
        cin>>a;
        arr.push_back(a);
    }
    cout<<"Vector before sorting-->"<<endl;
    arr_display(arr);
    count_sort(arr,size);
    cout<<"Vector after sorting-->"<<endl;
    arr_display(arr);

    cout<<"The most frequent benzene value is --> "<<endl;
    int curr_freq=0;
    int most_freq=0;
    int most_freq_number=0;
    int curr_number=arr[0];
    //finding the most frequent value in array 
    for(int i=0;i<size;i++){
        
        if(arr[i]==curr_number){
            curr_freq++;
        }
        if(curr_freq>most_freq){
            most_freq=curr_freq;
            most_freq_number=curr_number;
        }
        if(arr[i]!=curr_number){
            curr_number=arr[i];
            curr_freq=1;
        }
    }
    cout<<"The most frequent value is --> "<<most_freq_number<<endl;
    cout<<"the size of array is "<<endl;
    cout<<size<<endl;
    //finding the median value
    float median=0;
    if(arr.size()%2==0){
        median= (float)(((float)((float)arr[(arr.size()-1)/2]+(float)arr[(arr.size()-1)/2+1]))/2);
        
    }
    else{
        median=(float)arr[(arr.size()/2)];
    }
    cout<<"The median value is --> "<<median<<endl;


    cout<<"the difference between the median and the most frequent is "<< abs(median-most_freq_number)<<endl;
    return 0;
}