//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Disjoint_Set {
 vector<int> size, parent;
 public:
    Disjoint_Set(int n){
        size.resize(n+1, 1);
        parent.resize(n+1);
        for(int i=0; i<=n; i++){
            parent[i] = i;
        }
    }
    
    int parentUL(int u){
        if(parent[u] == u) return u;
        return parent[u] = parentUL(parent[u]);
    }
    
    void DS_Union(int u, int v){
        int ulp_u = parentUL(u);
        int ulp_v = parentUL(v);
        
        if(ulp_u == ulp_v) return;
        
        if(size[ulp_u] > size[ulp_v]){
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
        else {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_v];
        }
    }
 
};

class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<vector<int>> edges;
        Disjoint_Set ds(V);
        for(int i=0; i<V; i++){
            for(auto it: adj[i]){
                int adjNode = it[0], wt = it[1];
                edges.push_back({wt, i, adjNode});
            }
        }
        
        sort(edges.begin(), edges.end());
        int res = 0;
        for(auto it: edges){
            int wt = it[0], u = it[1], v = it[2];
            if(ds.parentUL(u) != ds.parentUL(v)){
                res += wt;
                ds.DS_Union(u, v);
            }
        }
        
        return res;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends