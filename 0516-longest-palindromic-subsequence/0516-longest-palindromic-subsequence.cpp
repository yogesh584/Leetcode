class Solution {
public:
    int solve(string& s1,string& s2,int index1,int index2,vector<vector<int>>& dp){
        if(index1 > s1.length() || index2 > s2.length()){
            return 0;
        }
        if(dp[index1][index2] != -1){
            return dp[index1][index2];
        }


        int ans1 = 0;
        int ans2 = 0;
        int ans3 = 0;


        if(s1[index1] == s2[index2]){
            ans1 = 1 + solve(s1,s2,index1+1,index2+1,dp);
        }
        else{
            ans2 = solve(s1,s2,index1+1,index2,dp);
            ans3 = solve(s1,s2,index1,index2+1,dp);
        }

        return dp[index1][index2] = max(ans1,max(ans2,ans3));
    }

    int longestPalindromeSubseq(string s) {
        string rev = s;
        reverse(rev.begin(),rev.end());

        vector<vector<int>> dp(s.length()+1,vector<int> (s.length()+1,-1));

        return solve(s,rev,0,0,dp)-1;
    }
};