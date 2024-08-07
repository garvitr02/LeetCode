class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& grid) {
        
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> effort(n, vector<int>(m, INT_MAX));
        
        effort[0][0] = 0;
        
        pq.push({0, {0,0}});
        
        int r[] = {-1, 0, +1, 0};
        int c[] = {0, +1, 0, -1};
        
        
        while(!pq.empty()){
            auto it = pq.top();
            int d = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();
            
            if(x == n-1 && y == m-1){
                return d;
            }
            
            for(int i=0; i<4; i++){
                
                    int row = x + r[i];
                    int col = y + c[i];
                    if(row<n && row>=0 && col<m && col>= 0){
                        int newEffort = max(d, abs(grid[row][col] - grid[x][y]));
                            if (newEffort < effort[row][col]) {
                                effort[row][col] = newEffort;
                                pq.push({effort[row][col], {row, col}});
                            }
                    }
                
            }
        }
        
        return effort[n-1][n-1];
        
        
        
        
    }
};

