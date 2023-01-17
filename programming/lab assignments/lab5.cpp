#include <bits/stdc++.h>
#include<stdlib.h>
#include <math.h>

using namespace std;


// this is manhattan distance comment one of the distance to get the other one

float dist(pair<int,int>p1, pair<int,int>p2) 
{ 
    return abs(p1.first-p1.second)+abs(p2.first-p2.second); 
}

// this is euclidean distance 
// float dist(pair<float,float>p1, pair<float,float>p2) 
// { 
//     return sqrt( (p1.first - p2.first)*(p1.first - p2.first) + 
//                 (p1.second - p2.second)*(p1.second - p2.second) 
//             ); 
// } 

float bruteForce(vector<pair<float,float>>&myvec , int si,int ei,int size) 
{ 
    float min = FLT_MAX; 
    for (int i = si; i <ei; ++i) 
        for (int j = i+1; j <=ei ; ++j) 
            if (dist(myvec[i], myvec[j]) < min) 
                min = dist(myvec[i], myvec[j]); 
    return min; 
}

// Driver function to sort the vector elements
// by second element of pairs
bool sort_by_sec(const pair<float,float> &a,
              const pair<float,float> &b)
{
    return (a.second < b.second);
}
float closest_distance_inside_strip(vector<pair<float,float>> &close_to_mid,float d ){
    //initializing
    float min =d;
    //now soritng all the points in the array with respect to y coordinate
    sort(close_to_mid.begin(), close_to_mid.end(),sort_by_sec);

    for(int i=0;i<close_to_mid.size();i++){
        for(int j=i+1;j<close_to_mid.size() && (close_to_mid[j].second-close_to_mid[i].second) < min ;j++){
            if(dist(close_to_mid[i],close_to_mid[j])<min){
                min = dist(close_to_mid[i],close_to_mid[j]);
            }
        }
    }
    return min;
}
float recursive_func(vector<pair<float,float>> &myvec,int si,int ei){
    
    int size=ei-si+1;
    // If there are 2 or 3 points, then use brute force 
    if (size <= 3) 
        return bruteForce(myvec,si,ei,size); 
  
    
    int mid=(size)/2;
    pair<float,float> mid_point=myvec[mid];

    //dl is min distance on left side of mid point
    //dr is min distance on right side of mid point

    float dl=recursive_func(myvec,0,mid);
    float dr=recursive_func(myvec,mid+1,ei);
    
    // d will be minimum of dl and dr
    float d=min(dl,dr); 

    // now we have to make a vector which will contain all the points that 
    // are close to the middle line within distance d 
    vector<pair<float,float>> close_to_mid;
    for(int i=si;i<ei;i++){
        if(abs(myvec[i].first-myvec[mid].first)<d){
            close_to_mid.push_back(myvec[i]);
        }
    }

    return min(d,closest_distance_inside_strip(close_to_mid,d));

}
int main(){
    vector<pair<float,float>> myvec = {{2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4}};
    sort(myvec.begin(), myvec.end());
    int size=6;
    cout<<"the smallest distance is " << recursive_func(myvec,0,size-1)<< endl;;
    return 0;

}