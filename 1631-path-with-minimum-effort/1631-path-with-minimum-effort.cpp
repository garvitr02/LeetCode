class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        
        int n = heights.size();
        int m = heights[0].size();
        
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        
        vector<vector<int>> effort(n, vector<int>(m, INT_MAX));
        
        effort[0][0] = 0;
        
        pq.push({0, {0, 0}});
        
        int r[] = {-1, 0, +1, 0};
        int c[] = {0, +1, 0, -1};
        
        while (!pq.empty()) {
            auto it = pq.top();
            int d = it.first;
            int x = it.second.first;
            int y = it.second.second;
            pq.pop();
            
            if (x == n-1 && y == m-1) {
                return d;
            }
            
            for (int i = 0; i < 4; i++) {
                int row = x + r[i];
                int col = y + c[i];
                if (row >= 0 && row < n && col >= 0 && col < m) {
                    int newEffort = max(d, abs(heights[row][col] - heights[x][y]));
                    if (newEffort < effort[row][col]) {
                        effort[row][col] = newEffort;
                        pq.push({newEffort, {row, col}});
                    }
                }
            }
        }
        
        return effort[n-1][n-1];
    }
};
