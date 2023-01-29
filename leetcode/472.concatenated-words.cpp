/*
 * @lc app=leetcode id=472 lang=cpp
 *
 * [472] Concatenated Words
 */

// @lc code=start
class Solution {
public:

    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        //first creating unordered map
        unordered_map<string,int>myMap;
        for(int i =0;i<words.size();i++){
            myMap[words[i]]++;
        }
        vector<string>ans;

        for(auto word : words){
            int n=word.size();
            //this will keep track of which words have been found
            vector<int> dp(n+1,0);

            //if prefix is not present then we won't check suffix 

            dp[0]=1;

            for(int i=0;i<n;i++){
                if(!dp[i]){
                    continue;
                }

                for(int j=i+1;j<=n;j++){
                    if(j-i<n && myMap[word.substr(i,j-i)]>0){
                        dp[j]=1;
                    }
                }

                if(dp[n]){
                    ans.push_back(word);
                    break;
                }
            }
        }
        return ans;
    }
};
// @lc code=end

