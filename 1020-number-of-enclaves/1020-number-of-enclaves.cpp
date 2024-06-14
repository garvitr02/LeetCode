class Solution {
    

private:
    
    void dfs(int i, int j, int n, int m, vector<vector<int>> &grid, 
             vector<vector<int>> &vis){
        
        vis[i][j] = 1;
        
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};
        
        for(int z=0; z<4; z++){
            
            int nrow = i + drow[z];
            int ncol = j + dcol[z];
            
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m 
              && vis[nrow][ncol] == 0 && grid[nrow][ncol] == 1){
                dfs(nrow,ncol,n,m,grid,vis);
                
            }
        }
        
        return;
    }
    
public:
    int numEnclaves(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> vis(n, vector<int>(m,0));
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                
                if((i==0 || i==n-1 || j==0 || j==m-1) && grid[i][j] == 1 && vis[i][j] == 0){
                    dfs(i,j,n,m,grid,vis);
                }
            }
        }
        
        int cnt=0;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                
                if(vis[i][j] == 0 && grid[i][j] == 1)
                    cnt++;
                
            }
        }
        
        
        return cnt;
    }
};