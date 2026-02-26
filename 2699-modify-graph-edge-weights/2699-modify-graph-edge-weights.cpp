class Solution {
public:
    typedef long long ll;
    long long Large = 2e9;
    ll dist(int V, vector<vector<int>> &edges, int src,int dest) {

        // Create adjacency list
        vector<vector<pair<int,int>>> adj(V);

        for(auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            if(w == -1) continue;
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        priority_queue<pair<int,int>, 
                       vector<pair<int,int>>, 
                       greater<pair<int,int>>> pq;

        vector<ll> dist(V, Large);

        dist[src] = 0;
        pq.push({0, src});

        while(!pq.empty()) {
            auto top = pq.top();
            pq.pop();

            int d = top.first;
            int u = top.second;

            if(d > dist[u]) continue;

            for(auto &p : adj[u]) {
                int v = p.first;
                int w = p.second;

                if(dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }

        return dist[dest];
    }

    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int source, int destination, int target) {
        ll currd = dist( n ,edges, source , destination);
        
        if(currd < target) return {};
        
        bool check = (currd == target);
        
        // if(check == true){
        //     for(vector<int>&arr : edges){
        //         if(arr[2] == -1) edges[2] = Large;
        //     }

        //     return edges;
        // }

        for(vector<int>&arr : edges){
            if(arr[2] == -1){
                arr[2] = (check == true) ? Large : 1;

                if(!check){
                    ll newd = dist(n,edges,source,destination);
                    if(newd  <= target){
                        check = true ;
                        arr[2] += (target - newd);
                    }
                }
            }
        }

        if(!check) return {};
        return edges;
    }
};