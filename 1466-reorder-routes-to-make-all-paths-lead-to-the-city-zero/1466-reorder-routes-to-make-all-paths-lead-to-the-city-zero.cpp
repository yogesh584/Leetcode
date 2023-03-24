class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        // step 1 : create a undirected graph.
        vector<int> adj[n];
        for(auto it : connections){
            int u = it[0];
            int v = it[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // step 2 : run a bfs on graph and find the number of every node.
        vector<int> nodeNumber(n);
        vector<int> vis(n,false);
        queue<pair<int,int>> q;     // {node,node number}

        q.push({0,1});
        vis[0] = 1;
        while(!q.empty()){
            auto front = q.front();
            q.pop();

            int node = front.first;
            int number = front.second;
            nodeNumber[node] = number;

            for(auto neb : adj[node]){
                if(!vis[neb]){
                    q.push({neb,number+1});
                    vis[neb] = true;
                }
            }
        }

        int ans = 0;
        for(auto it : connections){
            int u = it[0];
            int v = it[1];

            if(nodeNumber[u] < nodeNumber[v]){
                ans++;
            }
        }

        return ans;

    }
};