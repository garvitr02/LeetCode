class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        
        int m = mat.size();
        int n = mat[0].size();
        
        vector<vector<int>> vis(m, vector<int>(n,-1));
        
        queue<pair<pair<int,int>,int>> q;
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(mat[i][j] == 0){
                    q.push({{i,j},0});
                    vis[i][j] = 0;
                }
            }  
        }
        
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};
        
        while(!q.empty()){
            
            int r = q.front().first.first;
            int c = q.front().first.second;
            int d = q.front().second;
            q.pop();
            
            for(int i=0; i<4; i++){
                
                int nrow = r + drow[i];
                int ncol = c + dcol[i];
                
                if(nrow >=0 && nrow <m && ncol >= 0 && ncol <n && vis[nrow][ncol] == -1){
                    if(mat[nrow][ncol] == 0){
                        q.push({{nrow,ncol},0});
                        vis[nrow][ncol] = 0;
                    }
                    else{
                        q.push({{nrow,ncol}, d+1});
                        vis[nrow][ncol] = d+1;
                    }
                }
            }
        }
        
        return vis;
    }
};