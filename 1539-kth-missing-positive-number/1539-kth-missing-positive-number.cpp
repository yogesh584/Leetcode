class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int count = 0;
        int first = 0;
        int last = arr[0];
        for(int i = 0;i < arr.size();i++){
            if(last - first - 1 > 0){
                if(count + last - first - 1 >= k){
                    return first + k-count;
                }
                else{
                    count += last-first - 1;
                }
            }
            first = last;
            if(i+1 < arr.size())
                last = arr[i+1];
        }
        
        while(count < k){
            last++;
            count++;
        }
        
        return last;
    }
};