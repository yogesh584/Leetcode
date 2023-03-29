class Solution {
public:
    int solve(vector<int>& sati,int index,int time,vector<vector<int>>& dp){
        if(index >= sati.size()){
            return 0;
        }
        if(dp[index][time] != -1)
            return dp[index][time];

        // pick
        int ans1 = time*sati[index] + solve(sati,index+1,time+1,dp);

        // notpick
        int ans2 = 0 + solve(sati,index+1,time,dp);

        return dp[index][time] = max(ans1,ans2);
    }

    int solveTab(vector<int>& sati){
        int n = sati.size();
        vector<vector<int>> dp(n+1,vector<int> (n+2,0));

        for(int index = n-1;index >= 0;index--){
            for(int time = n;time >= 0;time--){
                dp[index][time] = max(time*sati[index] + dp[index+1][time+1],dp[index+1][time]);
            }
        }

        return dp[0][1];
    }

    int solveSO(vector<int>& sati){
        int n = sati.size();
        vector<int> curr(n+2);
        vector<int> next(n+2);

        for(int index = n-1;index >= 0;index--){
            for(int time = n;time >= 0;time--){
                curr[time] = max(time*sati[index] + next[time+1],next[time]);
            }
            next = curr;
        }

        return curr[1];
    }

    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(),satisfaction.end());
        return solveSO(satisfaction);
    }
};