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
    
    int findUPar(int node){
        if(node == parent[node]) return node;
        
        return parent[node] = findUPar(parent[node]);
    }
    
    void unionBySize(int u, int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        
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
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        int k = operators.size();
        DisjointSet ds(n*m);
        vector<vector<int>> mat(n, vector<int>(m, 0));
        
        int delRow[] = {0, 0, 1, -1};
        int delCol[] = {1, -1, 0, 0};
        
        int cnt = 0;
        vector<int> ans;
        for(int i=0; i<k; i++){
            int r = operators[i][0], c = operators[i][1];
            int node = r*m + c;
            
            if(mat[r][c] == 1){ ans.push_back(cnt); continue;}
            
            mat[r][c] = 1;
            
            for(int j=0; j<4; j++){
                int nr = r + delRow[j], nc = c + delCol[j];
                int adjNode = nr*m + nc;
                if(nr >= 0 && nc >= 0 && nr < n && nc < m && mat[nr][nc] == 1){
                    if(ds.findUPar(adjNode) != ds.findUPar(node)){
                        ds.unionBySize(adjNode, node);
                        cnt--;
                    }
                }
            }
            cnt++;
            ans.push_back(cnt);
        }
        
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,k; cin>>n>>m>>k;
        vector<vector<int>> a;
        
        for(int i=0; i<k; i++){
            vector<int> temp;
            for(int j=0; j<2; j++){
                int x; cin>>x;
                temp.push_back(x);
            }
            a.push_back(temp);
        }
    
        Solution obj;
        vector<int> res = obj.numOfIslands(n,m,a);
        
        for(auto x : res)cout<<x<<" ";
        cout<<"\n";
    }
}

// } Driver Code Ends