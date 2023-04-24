//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        vector<vector<vector<int>>> adj(n+1);
        
        for(auto it: edges){
            int node1 = it[0],
            node2 = it[1],
            w = it[2];
            
            adj[node1].push_back({node2, w});
            adj[node2].push_back({node1, w});
        }
        
        set<pair<int, vector<int>>> st;
        vector<int> dis(n+1, 1e9);
        dis[1] = 0;
        st.insert({0, {1}});
        
        vector<int> res;
        int minPath = 1e9;
        
        while(st.size()){
            auto it = *(st.begin());
            vector<int> seq = it.second;
            int d = it.first;
            int node = seq.back();
            
            st.erase(it);
            
            if(node == n){
                return seq;
                // if(minPath > d){
                //     minPath = d;
                //     res = seq;
                // }
            }
            
            for(auto it: adj[node]){
                int adjNode = it[0];
                int cost = it[1];
                
                if(dis[node] + cost < dis[adjNode]){
                    dis[adjNode] = dis[node] + cost;
                    seq.push_back(adjNode);
                    st.insert({dis[adjNode], seq});
                    seq.pop_back();
                }
            }
        }
        return vector<int>(1, -1);
    }
};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
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