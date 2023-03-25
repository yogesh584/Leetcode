class Solution {
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<int> adj[n];

        for(auto it : edges){
            int u = it[0];
            int v = it[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }


        int remaningVisits = n;

        vector<bool> vis(n,false);
        long long ans = 0;

        for(int v = 0;v < n;v++){
            if(!vis[v]){
                int tnodes = 0;

                queue<int> q;
                q.push(v);
                vis[v] = true;
                remaningVisits--;
                tnodes++;

                while(!q.empty()){
                    int front = q.front();
                    q.pop();

                    for(auto neb: adj[front]){
                        if(!vis[neb]){
                            q.push(neb);
                            vis[neb] = true;
                            tnodes++;
                            remaningVisits--;
                        }
                    }
                }
                ans += remaningVisits*1LL*tnodes;
            }
        }

        return ans;
    }
};