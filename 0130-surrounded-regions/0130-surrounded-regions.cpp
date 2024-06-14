class Solution {
    
private: 
    void dfs(int i, int j, vector<vector<char>> &board, int n, int m, 
             vector<vector<int>> &vis){
        
        vis[i][j] = 1;
        
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};
        
        for(int z=0; z<4; z++){
            
            int nrow = i+drow[z];
            int ncol = j+dcol[z];
            
            if(nrow >=0 && nrow <n && ncol >= 0 && ncol <m && board[nrow][ncol] == 'O'
              && vis[nrow][ncol] == 0){
                dfs(nrow,ncol,board,n,m,vis);
            }
        }
        
        return;
    }
public:
    void solve(vector<vector<char>>& board) {
            
        int n = board.size();
        int m = board[0].size();
        
        vector<vector<int>> vis(n,vector<int>(m,0));
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if((i == 0 || i == n-1 || j == 0 || j == m-1) && board[i][j] == 'O' 
                  && vis[i][j] == 0){
                    dfs(i,j,board,n, m, vis);
                }
            }
        }
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(vis[i][j] == 1){
                    board[i][j] = 'O';
                }
                else{
                    board[i][j] = 'X';
                }
                
            }
        }
        
        return;
    }
};