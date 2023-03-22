class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<pair<int,int>> adj[n+1];       // {node,dist}
        for(auto it : roads){
            int u = it[0];
            int v = it[1];
            int d = it[2];

            adj[u].push_back({v,d});
            adj[v].push_back({u,d});
        }
        
        // bfs
        vector<bool> canGo(n+1,false);
        queue<int> q;   // {node}
        q.push(1);
        canGo[1] = true;

        while(!q.empty()){
            int front = q.front();
            q.pop();

            for(auto neb : adj[front]){
                if(!canGo[neb.first]){
                    canGo[neb.first] = true;
                    q.push(neb.first);
                }
            }
        }

        // find min path
        int min_path = INT_MAX;
        for(auto it : roads){
            if(canGo[it[0]] && it[2] < min_path){
                min_path = it[2];
            }
        }
        
        return min_path;
    }
};