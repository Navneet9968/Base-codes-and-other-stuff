class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        
        vector<int> group1(n,-1);
        vector<int> group2(n,-1);
        sort(dislikes.begin(),dislikes.end());

        group1[dislikes[0][0]]=1;
        group2[dislikes[0][1]]=1;

        for(int i =1;i<dislikes.size();i++){
            if(group1[dislikes[i][0]]==1){
                group2[dislikes[i][1]]=1;
                continue;
            }
            if(group2[dislikes[i][0]]==1){
                group1[dislikes[i][1]]=1;
                continue;
            }
            if(group1[dislikes[i][1]]==1){
                group2[dislikes[i][0]]=1;
                continue;
            }
            if(group2[dislikes[i][1]]==1){
                group1[dislikes[i][0]]=1;
                continue;
            }
            // else{
            //     group1[dislikes[i][0]]=1;
            //     group2[dislikes[i][1]]=1;
            // }
        }

        for(int i=0;i<n;i++){
            if(group1[i]==1 && group2[i]==1){
                return false;
            }
        }

        return false;

    }
};