class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxi = 0;
        int n = candies.size();
        for(auto it : candies){
            maxi = max(it,maxi);
        }

        vector<bool> ans(n,false);
        for(int i = 0;i < n;i++){
            if(candies[i]+extraCandies >= maxi){
                ans[i] = true;
            }
        }

        return ans;
    }
};