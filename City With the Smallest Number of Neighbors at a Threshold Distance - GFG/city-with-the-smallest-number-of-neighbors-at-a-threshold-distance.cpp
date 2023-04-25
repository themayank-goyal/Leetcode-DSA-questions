//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    
    void f(int i, vector<int>cost[], vector<vector<vector<int>>>& adj, int dt){
        vector<int>dist(adj.size(), 1e9);
        dist[i] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        q.push({0, i});
        while(q.size()){
            int d = q.top().first, node = q.top().second;
            q.pop();
            for(auto it: adj[node]){
                int adjNode = it[0], edw = it[1];
                if(d + edw < dist[adjNode]){
                    dist[adjNode] = d + edw;
                    q.push({d+edw, adjNode});
                }
            }
        }
        
        for(int j=0; j<dist.size(); j++){
            if(j == i) continue;
            if(dist[j] <= dt)
                cost[i].push_back(j);
        }
    }
    
    int findCity(int n, int m, vector<vector<int>>& edges,
    int dt) {
        vector<vector<vector<int>>> adjList(n);
        for(auto it: edges){
            adjList[it[0]].push_back({it[1], it[2]});
            adjList[it[1]].push_back({it[0], it[2]});
        }
        vector<int>cost[n];
        
        for(int i=0; i<n; i++){
            f(i, cost, adjList, dt);
        }
        int res = 0, minSize = 1e9;
        for(int i=0; i<n; i++){
            if(cost[i].size() <= minSize){
                res = i;
                minSize = cost[i].size();
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
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;
        // n--;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        int dist;
        cin >> dist;
        Solution obj;
        cout << obj.findCity(n, m, adj, dist) << "\n";
    }
}

// } Driver Code Ends