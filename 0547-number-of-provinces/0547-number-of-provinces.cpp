class Solution {
    

private: 
    
    void dfs(int i, vector<int> &vis, vector<vector<int>> &adj){
        
        vis[i] = 1;
        
        for(auto it : adj[i]){
            if(!vis[it]){
                dfs(it, vis, adj);
            }
        }
        
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        int n = isConnected.size();
        
        vector<vector<int>> adj(n+1);
        
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(isConnected[i][j] == 1 && i != j){
                    adj[i+1].push_back(j+1);
                    adj[j+1].push_back(i+1);
                }
            }
        }
        
        
        vector<int> vis(n+1,0);
        int cnt = 0;
        
        for(int i=1; i<=n; i++){
            
            if(!vis[i]){
                cnt++;
                dfs(i,vis,adj);
            }
        }
        
        return cnt;
    }
};