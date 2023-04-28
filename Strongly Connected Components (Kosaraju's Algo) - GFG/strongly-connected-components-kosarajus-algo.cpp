//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	
	void sortEdges(int i, stack<int>& s, vector<int>& vis, vector<vector<int>>& adj){
	    vis[i] = 1;
	    
	    for(auto it: adj[i]){
	        if(!vis[it]){
	            sortEdges(it, s, vis, adj);
	        }
	    }
	    s.push(i);
	}
	
	void dfs(int node, vector<int>& vis, vector<int> adjListR[]){
	    vis[node] = 1;
	    
	    for(auto it: adjListR[node]){
	        if(!vis[it]){
	            dfs(it, vis, adjListR);
	        }
	    }
	}
	
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        stack<int> s;
        vector<int> vis(V, 0);
        vector<int> adjListR[V];
        
        for(int i=0; i<V; i++){
            if(!vis[i]){
                sortEdges(i, s, vis, adj);
            }
        }
        
        for(int i=0; i<V; i++){
            vis[i] = 0;
            for(auto it: adj[i]){
                adjListR[it].push_back(i);
            }
        }
        
        
        ;
        int res = 0;
        while(s.size()){
            int node = s.top();
            s.pop();
            if(!vis[node]){
                dfs(node, vis, adjListR);    
                res++;
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
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<vector<int>> adj(V);

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends