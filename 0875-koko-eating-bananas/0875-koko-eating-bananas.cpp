class Solution {
public:
    bool checkCanEat(vector<int>& piles,int h,int k){
        for(int i = 0;i < piles.size();i++){
            int requiredHours = ceil(piles[i]*1.0/k);
            if(requiredHours <= h){
                h = h-requiredHours;
            }
            else{
                return false;
            }
        }

        return true;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int start = 1;
        int end = INT_MIN;
        
        // finding the max.
        for(auto it : piles){
            end = max(end,it);
        }

        if(piles.size() == h)
            return end;

        while(start < end){
            int mid = start + (end - start)/2;
            bool canEat = checkCanEat(piles,h,mid);
            if(canEat){
                end = mid;
            }
            else{
                start = mid+1;
            }
        }

        return end;

    }
};