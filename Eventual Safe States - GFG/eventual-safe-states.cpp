//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    bool dfs(int i, vector<int> adj[], vector<int>&vis, vector<int>&pathVis) {
        vis[i] = 1;
        pathVis[i] = 1;
        
        for(auto it: adj[i]){
            if(vis[it] && pathVis[it]) return true;
            else if(!vis[it]){
                if(dfs(it, adj, vis, pathVis)){
                    return true;
                }
            }
        }
        pathVis[i] = 0;
        return false;
    }
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        vector<int>vis(V, 0);
        vector<int>pathVis(V, 0);
        for(int i=0; i<V; i++){
            if(!vis[i]){
                dfs(i, adj, vis, pathVis);
            }
        }
        
        vector<int> res;
        for(int i=0; i<V; i++){
            if(vis[i] && !pathVis[i])
                res.push_back(i);
        }
        return res;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int V, E;
        cin >> V >> E;
        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends