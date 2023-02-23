class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = capital.size();

        // step 1 : create a combined array with profits and capital.
        vector<pair<int,int>> projects; // {capital,profit}
        for(int i = 0;i < n;i++){
            projects.push_back({capital[i],profits[i]});
        }

        // step 2 : sort the capital array.
        sort(projects.begin(),projects.end());


        // step 3 : create a priority queue which stores required work projects.
        priority_queue <int> pq;        // max profit work is on top.


        // step 4 : traverse through projects array find best projects.
        int i = 0;
        while(k--){
            // find the works that require less or equal capital then we have.
            while(i < n && projects[i].first <= w){
                pq.push(projects[i].second);
                i++;
            }

            // now if we founded works that require less or equal capital, we have now so we are doing the max profit task.
            if(!pq.empty()){
                w += pq.top();
                pq.pop();       // because we done the work so remove it from priority queue.
            }
        }

        return w;
    }
};