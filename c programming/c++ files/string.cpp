#include<iostream>
using namespace std;

int main(){
    string name="navneet";
    cout<< name << endl;
    name[0]='N';
    cout<< name << endl;

    //for finding the length of the string we can do .length() function

    cout<< name.length()<<endl;

    //accessing can be done via name[index position]

    cout<< name[2]<<endl;  

    //for finding where a character or a substring exists inside the string we can use .find() function 
    //syntax is phrase.find(substring or character, index from where it has to start looking mostly 0);
    cout<<name.find("avne",0)<<endl;

    //to extract out any substring we use the .substr(index position , length ) 

    string newstr=name.substr(3,2);
    cout<<newstr<<endl;
    return 0;
}








