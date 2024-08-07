class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        
        int V = graph.size();
        
        vector<int> adjRev[V];
        
        for(int i = 0; i<V; i++){
            for(int j=0; j<graph[i].size(); j++){
                adjRev[graph[i][j]].push_back(i);
            }
        }
        
        vector<int> indegree(V);
	    
	    for (int i=0; i<V; i++){
	        for(auto it : adjRev[i]){
	            indegree[it]++;
	        }
	    }
	    
	    queue<int> q;
	    
	    for(int i=0; i<V; i++){
	        if(indegree[i] == 0){
	            q.push(i);
	        }
	    }
	    
	    vector<int> topo;
	    
	    while(!q.empty()){
	        int node = q.front();
	        q.pop();
	        topo.push_back(node);
	        
	        for(auto it : adjRev[node]){
	            indegree[it]--;
	            if(indegree[it] == 0) q.push(it);
	        }
	    }
        
        sort(topo.begin(), topo.end());
        
        return topo;
        
        
    }
};