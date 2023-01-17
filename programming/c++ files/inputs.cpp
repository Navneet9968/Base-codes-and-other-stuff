#include<iostream>
using namespace std;

int main(){

    //for integer or a character we may use cin 
    int a ;
    cout<< "enter value of a : ";
    cin>>a;
    cout<<"the value of a is "<<a<<endl;    

    //for getting a line of strings we use getline() function
    string name;
    cout<<"enter name :";
    getline(cin, name);
    cout<< "hello "<<name<<endl;

    
    return 0;
}








