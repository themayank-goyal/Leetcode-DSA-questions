//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class DisjointSet {
  
  public: 
  vector<int> size, parent;
   DisjointSet(int n){
       parent.resize(n+1);
       size.resize(n+1, 1);
       for(int i=0; i<=n; i++){
           parent[i] = i;
       }
   }
   
   int findUPar(int node){
       if(node == parent[node]) return node;
       
       return parent[node] = findUPar(parent[node]);
   }
   
   void unionBySize(int u, int v){
       int ulp_u = findUPar(u);
       int ulp_v = findUPar(v);
       
       if(ulp_u == ulp_v) return;
       
       if(size[ulp_u] > size[ulp_v]) {
           parent[ulp_v] = ulp_u;
           size[ulp_u] += size[ulp_v];
       }
       else{
           parent[ulp_u] = ulp_v;
           size[ulp_v] += size[ulp_v];
       }
   }
   
};

class Solution {
    
  public:
    int Solve(int n, vector<vector<int>>& edge) {
        DisjointSet ds(n);
        
        int extra = 0;
        for(auto it: edge){
            if(ds.findUPar(it[0]) == ds.findUPar(it[1])){
                extra++;
            }
            else{
                ds.unionBySize(it[0], it[1]);
            }
        }
        int comps = 0;
        for(int i=0; i<n; i++){
            if(ds.findUPar(i) == i) comps++;
        }
        
        if(comps-1 <= extra) return comps-1;
        return -1;
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

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 2; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution Obj;
        cout << Obj.Solve(n, adj) << "\n";
    }
    return 0;
}
// } Driver Code Ends