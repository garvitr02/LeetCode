class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        if(grid[0][0] != 0 ) return -1;
        int n = grid.size();
        queue<pair<int,pair<int,int>>> q;
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        
        dist[0][0] = 0;
        
        q.push({0, {0,0}});
        
        int r[] = {-1,-1, 0, +1, +1, +1, 0, -1};
        int c[] = {0, +1, +1, +1, 0, -1, -1, -1};
        
        
        while(!q.empty()){
            auto it = q.front();
            int d = q.front().first;
            int x = q.front().second.first;
            int y = q.front().second.second;
            q.pop();
            
            for(int i=0; i<8; i++){
                for(int j=0; j<8; j++){
                    int row = x + r[i];
                    int col = y + c[j];
                    if(row<n && row>=0 && col<n && col>= 0 && grid[row][col] == 0){
                        if(dist[row][col] > d + 1){
                            dist[row][col] = d + 1;
                            q.push({dist[row][col],{row,col}});
                        }
                    }
                }
            }
        }
        
        if(dist[n-1][n-1] == INT_MAX) return -1;
        return dist[n-1][n-1] + 1;
        
        
        
        
    }
};