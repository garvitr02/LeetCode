class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        
        vector<pair<int,int>> adj[n];
        
        for(auto it : roads){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;
        
        // {time, node}
        pq.push({0,0});
        
        vector<long long> time(n,LLONG_MAX);
        vector<int> ways(n,0);
        
        time[0] = 0;
        ways[0] = 1;
        int mod = 1e9 + 7;

        while(!pq.empty()){
            
            auto it = pq.top();
            pq.pop();
            
            long long t = it.first;
            int node = it.second;
            
            for(auto iter : adj[node]){
                int dt = iter.second;
                int adjNode = iter.first;
                if(t + dt < time[adjNode]){
                    time[adjNode] = t + dt;
                    ways[adjNode] = ways[node];
                    pq.push({time[adjNode], adjNode});
                }
                else if (t + dt == time[adjNode]){
                    ways[adjNode] += ways[node];
                    ways[adjNode] %= mod;
                }
            }
        }
        
        return ways[n-1];
    }
};
