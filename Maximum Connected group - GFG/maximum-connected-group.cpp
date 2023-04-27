//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class DisjointSet {
  public:
  vector<int> size, parent;
  
  DisjointSet(int n){
      size.resize(n+1, 1);
      parent.resize(n+1);
      for(int i=0; i<=n; i++){
          parent[i] = i;
      }
  }
  
  int findUPar(int node) {
      if(node == parent[node]) return node;
      
      return parent[node] = findUPar(parent[node]);
  }
  
  void unionBySize(int u, int v) {
      int ulp_u = findUPar(u);
      int ulp_v = findUPar(v);
      
      if(ulp_u == ulp_v) return;
      
      if(size[ulp_u] > size[ulp_v]){
          parent[ulp_v] = ulp_u;
          size[ulp_u] += size[ulp_v];
      }
      else{
          parent[ulp_u] = ulp_v;
          size[ulp_v] += size[ulp_u];
      }
  }
  
};

class Solution {
  public:
    int MaxConnection(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n*n);
        int delRow[] = {0, 0, 1, -1};
        int delCol[] = {1, -1, 0, 0};
        
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1){
                    for(int k=0; k<4; k++){
                        int nr = i + delRow[k], nc = j + delCol[k];
                        if(nr >= 0 && nc >= 0 && nr < n && nc < n && grid[nr][nc] == 1){
                            int adjNode = nr*n + nc, node = i*n + j;
                            ds.unionBySize(adjNode, node);
                        }
                    }            
                }
            }
        }
        int ans = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                int count = 0;
                set<int> s;
                if(grid[i][j] == 0){
                    for(int k=0; k<4; k++){
                        int nr = i + delRow[k], nc = j + delCol[k];
                        if(nr >= 0 && nc >= 0 && nr < n && nc < n && grid[nr][nc] == 1){
                            int adjNode = nr*n + nc, node = i*n + j;
                            if(grid[nr][nc] == 0) continue;
                            int ulp_adjNode = ds.findUPar(adjNode);
                            
                            s.insert(ulp_adjNode);
                        }
                    }            
                }
                for(auto it: s){
                    count += ds.size[it];
                }
                count++;
                ans = max(count, ans);
            }
        }
        
        for(int col=0; col<n*n; col++){
            ans = max(ans, ds.size[ds.findUPar(col)]);
        }
        
        return ans;
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> grid(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> grid[i][j];
            }
        }

        Solution obj;
        cout<<obj.MaxConnection(grid)<<"\n";
    }
}

// } Driver Code Ends