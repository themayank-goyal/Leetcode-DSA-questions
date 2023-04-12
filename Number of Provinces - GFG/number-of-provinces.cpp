//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    void dfs(vector<vector<int>>&adjLs,vector<int>&vis, int i){
        vis[i] = 1;
        
        for(auto it: adjLs[i]){
            if(!vis[it]){
                dfs(adjLs, vis, it);
            }
        }
    }
    int numProvinces(vector<vector<int>> adj, int v) {
        vector<vector<int>> adjLs(v);
        for(int i=0; i<v; i++){
            for(int j=0; j<v; j++){
                if(adj[i][j] == 1 && i != j){
                    adjLs[i].push_back(j);
                    adjLs[j].push_back(i);
                }
            }
        }
        vector<int>vis(v, 0);
        int res = 0;
        for(int i=0; i<v; i++){
            if(!vis[i]){
                dfs(adjLs, vis, i);
                res++;
            }
        }
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends