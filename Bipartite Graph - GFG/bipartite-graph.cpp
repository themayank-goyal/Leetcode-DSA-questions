//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool f(int v, int start,  vector<int>adj[], vector<int>&vis){
        queue<int> q;
        q.push(start);
        vis[start] = 0;
        while(q.size()){
            int i = q.front();
            q.pop();
            for(auto j: adj[i]){
                if(vis[j] == -1){
                    q.push(j);
                    vis[j] = !vis[i]; 
                }
                else if(vis[j] == vis[i]) return false;
            }
        }
        return true;
    }
	bool isBipartite(int v, vector<int>adj[]){
        vector<int> vis(v, -1);
        for(int i=0; i<v; i++){
            if(vis[i] == -1)
                if(!f(v, i, adj, vis)) return false;
        }
        return true;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends