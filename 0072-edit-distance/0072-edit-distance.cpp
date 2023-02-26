class Solution {
public:
    int solve(string word1,string word2,int index1,int index2,vector<vector<int>>& dp){
        if(index1 == word1.length()){
            return word2.length() - index2;
        }
        if(index2 == word2.length()){
            return word1.length() - index1;
        }
        if(dp[index1][index2] != -1){
            return dp[index1][index2];
        }

        int ans = 0;
        if(word1[index1] == word2[index2]){
            ans = solve(word1,word2,index1+1,index2+1,dp);
        }
        else{
            int insertAns = 1 + solve(word1,word2,index1,index2+1,dp);
            int deleteAns = 1 + solve(word1,word2,index1+1,index2,dp);
            int replaceAns= 1 + solve(word1,word2,index1+1,index2+1,dp);
            ans = min(insertAns,min(deleteAns,replaceAns));
        }
        return dp[index1][index2] = ans;
    }

    int solveSO(string word1,string word2){
        vector<int> curr(word2.length()+1,0);
        vector<int> next(word2.length()+1,0);

        for (int j=0;j < word2.length();j++){
            next[j] = word2.length() - j;
        }
        
        for (int index1 = word1.length()-1;index1 >= 0;index1--){
            for (int index2 = word2.length()-1;index2 >= 0;index2--){

                // catch here -> base case se mila h.
                curr[word2.length()] = word1.length() - index1;


                int ans = 0;
                if(word1[index1] == word2[index2]){
                    ans = next[index2+1];
                }
                else{
                    int insertAns = 1 + curr[index2+1];
                    int deleteAns = 1 + next[index2];
                    int replaceAns= 1 + next[index2+1];
                    ans = min(insertAns,min(deleteAns,replaceAns));
                }
                curr[index2] = ans;
            }
            next = curr;
        }
        return curr[0];
    }


    int minDistance(string word1, string word2) {
        // vector<vector<int>> dp(word1.length()+1,vector<int> (word2.length()+1,-1));
        // return solve(word1,word2,0,0,dp);

        if(word1.length() == 0){
            return word2.length();
        }
        if(word2.length() == 0 ){
            return word1.length();
        }

        return solveSO(word1,word2);
    }
};