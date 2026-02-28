class Solution {
public:
    int o[4] = {1,-1,0,0};
    int t[4] = {0,0,1,-1};
    int minimumObstacles(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>dist(n,vector<int>(m,INT_MAX));
        priority_queue<
            pair<int, pair<int,int>>,
            vector<pair<int, pair<int,int>>>,
            greater<pair<int, pair<int,int>>>
        > pq;

        pq.push({0,{0,0}});
        dist[0][0] = 0;
        
        while(!pq.empty()){
            int d = pq.top().first;
            int r = pq.top().second.first;
            int c = pq.top().second.second;
            pq.pop();
            if(r == n-1 && c == m-1) return d;
            if(d > dist[r][c]) continue;
            for(int i = 0 ;  i<4 ; i++){
                int nr = r + o[i];
                int nc = c + t[i];

                if(nr >=0 && nr <n && nc >=0 && nc < m){
                    int d_ = d + grid[nr][nc];
                    if(d_ < dist[nr][nc]){
                        dist[nr][nc] = d_;
                        pq.push({d_,{nr,nc}});
                    }
                }
            }

        }

        return dist[n-1][m-1];
    }
};