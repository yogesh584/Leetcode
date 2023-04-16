#define M 1000000007
class Solution {
public:
    // my solution with dp.
    int solve(vector<string>& words,string& target,int index,int k,vector<vector<int>>& dp){
        // base case 
        if(index >= target.length()){
            return 1;
        }
        if(dp[index][k] != -1){
            return dp[index][k];
        }

        int ans = 0;

        for(auto word : words){
            for(int i = k;i < word.length();i++){
                if(word[i] == target[index]){
                    // pick 
                    ans = (ans%M + solve(words,target,index+1,i+1,dp)%M)%M;
                }
            }
        }

        return dp[index][k] = ans%M;
    }

    // memoization + optimization (by pre calculating frequency) 
    vector<vector<int>>dp;
    vector<vector<int>>freq;
    
    long getWords(vector<string>&words, string &target, int i, int j){
        if(j == target.size())return 1;
        if(i == words[0].size() || words[0].size() - i < target.size() - j) return 0;
        
        if(dp[i][j] != -1)return dp[i][j];
        
        long count = 0;
        int  curPos = target[j] - 'a';
        count += getWords(words, target, i + 1, j);
        count += freq[i][curPos] * getWords(words, target, i + 1, j + 1);
        
        return dp[i][j] = count % 1000000007;
    }

    

    int numWays(vector<string>& words, string target) {
        // vector<vector<int>> dp(target.length()+1,vector<int>(words[0].length()+1,-1));
        // return solve(words,target,0,0,dp);

        dp.resize(words[0].size(), vector<int>(target.size(), -1));
        freq.resize(words[0].size(), vector<int>(26, 0));
        
        for(int i=0; i<words.size(); i++){
            for(int j = 0; j < words[0].size(); j++){
                int  curPos = words[i][j] - 'a';
                freq[j][curPos]++;
            }
        }
        return getWords(words,target,0,0);
    }
};