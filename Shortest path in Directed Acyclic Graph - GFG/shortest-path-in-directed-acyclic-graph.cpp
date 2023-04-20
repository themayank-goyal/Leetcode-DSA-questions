//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> topoSort(int n, vector<vector<pair<int, int>>>& adj){
        vector<int> indeg(n, 0);
        
        for(int i=0; i<n; i++){
            for(auto it: adj[i]){
                indeg[it.first]++;
            }
        }
        queue<int> q;
        int k = 0;
        for(auto it: indeg){
            if(it == 0) q.push(k);
            k++;
        }
        
        vector<int> res;
        while(q.size()){
            int front = q.front();
            q.pop();
            res.push_back(front);
            
            for(auto it: adj[front]){
                indeg[it.first]--;
                if(indeg[it.first] == 0){
                    q.push(it.first);
                }
            }
        }
        
        return res;        
    }
    vector<int> shortestPath(int n,int m, vector<vector<int>>& edges){
        vector<vector<pair<int, int>>> adj(n);
        
        for(auto it: edges){
           adj[it[0]].push_back({it[1], it[2]}); 
        }
       
        
        vector<int> top = topoSort(n, adj);
        vector<int> dis(n, 1e9);
        dis[top[0]] = 0;
        for(int i=0; i<top.size(); i++){
            for(auto it: adj[top[i]]){
                if(dis[top[i]] + it.second < dis[it.first])
                    dis[it.first] = dis[top[i]] + it.second;
            }
        }
        int j=0;
        for(auto it: dis){
            if(it == 1e9) dis[j] = -1;
            j++;
        }
        return dis;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends