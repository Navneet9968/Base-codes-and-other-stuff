#include <bits/stdc++.h>
using namespace std;
# define NO_OF_CHARS 256

/////////////////////////////////////////////////////////////////////////////////////////////////////////////

//  BRUTE FORCE
int bruteForcePatternMatching(string &str,string &pattern){
    int ans1=0;
    
    for(int  i =0;i<str.length();i++){
        if(pattern[0]==str[i]){
            for(int j =1;j<pattern.length();j++){
                if(pattern[j]!=str[i+j]){
                    break;
                }
                if(j==pattern.length()-1){
                    return i;
                }
            }
        }
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

// KMP SEARCH

vector<int>lps;

void KMPUtilForminLPSArray(string &pattern){
    //length of the previous longest prefix
    int len=0;
    //as lps[0] is always 0
    lps.push_back(0);
    int M=pattern.length();
    //now iterating through 1 to length-1
    int i =1;
    while(i<M){
        //this will just match two consecutive characters
        if(pattern[i]==pattern[len]){
            len++;
            lps.push_back(len);
            i++;
        }
        else{
            if(len!=0){
                len=lps[len-1];
            }
            //if len=0
            else{
                lps.push_back(0);
                i++;
            }
        }
    }
}


int KMPSearch(string &str,string &pattern){
    int M=pattern.size();
    int N=str.size();
    KMPUtilForminLPSArray(pattern);
    int i =0;   //index for string
    int j=0;    //index for pattern
    while((N-i)>=(M-j)){
        if(pattern[j]==str[i]){
            i++;j++;
        }
        if(j==M){           //in case j is equal to pattern length that mean all characters have matched and the starting point will be i-j
            return i-j;
        }
        else if (i<N && pattern[j]!=str[i]){
            if(j!=0){
                j=lps[j-1];
            }
            else{
                i++;
            }
        }
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////

// BOYER MOORE (by bad character heuristic)

//utility function
void badCharHeuristic( string str, int size, int badchar[NO_OF_CHARS])
{
    int i;
 
    // Initialize all occurrences as -1
    for (i = 0; i < NO_OF_CHARS; i++)
        badchar[i] = -1;
 
    // Fill the actual value of last occurrence
    // of a character
    for (i = 0; i < size; i++)
        badchar[(int) str[i]] = i;
}

void search( string txt, string pat)
{
    int m = pat.size();
    int n = txt.size();
 
    int badchar[NO_OF_CHARS];
 
    //filling the badchar array with utility function
    badCharHeuristic(pat, m, badchar);
    
    //s acrively count the shift of the pattern wrt text
    int s = 0;
    while(s <= (n - m))
    {
        int j = m - 1;
 
        /* Keep reducing index j of pattern while
        characters of pattern and text are
        matching at this shift s */
        while(j >= 0 && pat[j] == txt[s + j])
            j--;
 
        /* If the pattern is present at current
        shift, then index j will become -1 after
        the above loop */
        if (j < 0)
        {
            cout << "By Boyer Moore algorithm the pattern is found at index = " <<  s << endl;
            // s += (s + m < n)? m-badchar[txt[s + m]] : 1;
            if(s+m < n){
                s+=m-badchar[txt[s+m]];
            }
            else{
                s+=1;
            }
 
        }
 
        else
            s += max(1, j - badchar[txt[s + j]]);
    }
}
 








int main() {
    string str ="THIS IS A TEST TEXT"   ;
    string pattern="TEST" ;
    cout<<endl;
    cout<<"By the brute force algorithm the pattern is found at the index = "<<bruteForcePatternMatching(str,pattern)<<endl;
    cout<<endl;
    cout<<"By KMP Search Algorithm the pattern is found at the index = "<<KMPSearch(str,pattern)<<endl;
    cout<<endl;
    search(str,pattern);
    cout<<endl;
    return 0;
}