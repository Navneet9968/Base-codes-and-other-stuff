
#include <iostream>
#include <string>
#include<stdio.h>
#include<fstream>
using namespace std;
typedef struct employee{
    string name;
    int id;
    char dept[20];
    int salary;
    string address;
    int contact;
    string email;
    string position;
    int experience;
}emp;
void enterdata(int arrind, emp *arr ){
    cout<<"enter emp no "<< arrind<<" name "<<endl;
    cin>>arr[arrind].name;
    cout<<"enter emp no "<< arrind<<" id "<<endl;
    cin>>arr[arrind].id;
    cout<<"enter emp no "<< arrind<<"department"<<endl;
    cin>>arr[arrind].dept;
    cout<<"enter emp no "<< arrind<<" salary "<<endl;
    cin>>arr[arrind].salary;
    cout<<"enter emp no "<< arrind<<"address"<<endl;
    cin>>arr[arrind].address;
    cout<<"enter emp no "<< arrind<<" contact "<<endl;
    cin>>arr[arrind].contact;
    cout<<"enter emp no "<< arrind<<" email "<<endl;
    cin>>arr[arrind].email;
    cout<<"enter emp no "<< arrind<<" position "<<endl;
    cin>>arr[arrind].position;
    cout<<"enter emp no "<< arrind<<" experience"<<endl;
    cin>>arr[arrind].experience;
}
void printdata(emp *arr,int arrind){
    cout<<"The emp no "<< arrind<<" name is "<<endl;
    cout<<arr[arrind].name<<endl;
    cout<<"The emp no "<< arrind<<" id is "<<endl;
    cout<<arr[arrind].id<<endl;
    cout<<"The emp no "<< arrind<<" dept is "<<endl;
    cout<<arr[arrind].dept<<endl;
    cout<<"The emp no "<< arrind<<" salary is "<<endl;
    cout<<arr[arrind].salary<<endl;
    cout<<"The emp no "<< arrind<<" address is "<<endl;
    cout<<arr[arrind].address<<endl;
    cout<<"The emp no "<< arrind<<" contact is "<<endl;
    cout<<arr[arrind].contact<<endl;
    cout<<"The emp no "<< arrind<<" email is "<<endl;
    cout<<arr[arrind].email<<endl;
    cout<<"The emp no "<< arrind<<" position is "<<endl;
    cout<<arr[arrind].position<<endl;
    cout<<"The emp no "<< arrind<<" experience is "<<endl;
    cout<<arr[arrind].experience<<endl;
}
int main() {
   
    //allocating memory to the array
    emp* arr=new emp[50];
    
  
    //getting the data for 2 employees
    enterdata(0,arr);
    enterdata(1,arr);
    printdata(arr,0);
    printdata(arr,1);

    //searching for the fourth person 
    for(int i=0;i<50;i++){
        if(arr[i].id==4){
            cout<<"fourth id is found at "<<i+1<<"position"<<endl;
        }
    }

    //for deleting the element at first position we need to replace ith element by i+1 th element
    for(int i=0;i<49;i++){
        arr[i]=arr[i+1];
    }

    //for deleting the third element 
    for(int i=3;i<50;i++){
        arr[i]=arr[i+1];
    }

    //inserting data at last position
    enterdata(49,arr);



    //inserting data at first position we need to first shift all the data forward by one element so we dont lose our prev first data
    for(int i=49;i=1;i--){
        arr[i]=arr[i-1];
    }
    //now we'll enter the data
    enterdata(0,arr);



    //inserting data at second position we need to first shift all the data forward by one element so we dont lose our prev first data
    for(int i=49;i=2;i--){
        arr[i]=arr[i-1];
    }
    //now we'll enter the data
    enterdata(1,arr);







    
    


    // to get specific data
    cout<<arr[1].id<<endl;

    //print data for last emp
    printdata(arr,49);
    return 0;
}