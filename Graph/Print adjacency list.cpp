class Solution {
  public:
    // Function to return the adjacency list for each vertex.
    vector<vector<int>> printGraph(int V, vector<pair<int, int>>& edges) {
        // Code here
        /*vector<vector<int>>adj;
        for(int i=0;i<V;i++){
            vector<int>level;
            adj.push_back(level);
        }*/
        vector<vector<int>>adj(V);
        for(int i=0;i<edges.size();i++){
            adj[edges[i].first].push_back(edges[i].second);
            adj[edges[i].second].push_back(edges[i].first);
        }
        return adj;
    }
};
