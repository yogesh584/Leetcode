class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(),potions.end());

        vector<int> ans;
        for(auto spell : spells){
            int start = 0;
            int end = potions.size() - 1;
            int pos = -1;
            while(start <= end){
                int mid = start + (end-start)/2;

                if(spell*1LL*potions[mid] >= success){
                    pos = mid;
                    end = mid-1;
                }
                else{
                    start = mid+1;
                }
            }
            if(pos != -1)
                ans.push_back(potions.size()-pos);
            else
                ans.push_back(0);
        }

        return ans;
    }
};