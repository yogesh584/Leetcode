class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        for(int i = 0;i < flowerbed.size();i++){
            if(flowerbed[i] == 0){
                bool left = true;
                bool right = true;
                if(i-1 >= 0 && flowerbed[i-1] != 0)
                    left = false;
                if(i+1 < flowerbed.size() && flowerbed[i+1] != 0)
                    right = false;
                
                if(left && right){
                    n--;
                    flowerbed[i] = 1;
                }
            }
        }

        if(n <= 0)  return true;
        return false;
    }
};