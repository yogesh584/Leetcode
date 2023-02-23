class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        queue<int> lesselements;
        queue<int> graterelement;
        int pivotCount = 0;

        for(auto it : nums){
            if(it == pivot){
                pivotCount++;
            }
            else if(it < pivot){
                lesselements.push(it);
            }
            else{
                graterelement.push(it);
            }
        }

        vector<int> ans;

        // pushing less elements;
        while(!lesselements.empty()){
            int elem = lesselements.front();
            lesselements.pop();
            ans.push_back(elem);
        }

        // appending pivot elem.
        while(pivotCount--){
            ans.push_back(pivot);
        }

        // appending grater elements.
        while(!graterelement.empty()){
            int elem = graterelement.front();
            graterelement.pop();
            ans.push_back(elem);
        }

        return ans;
    }
};