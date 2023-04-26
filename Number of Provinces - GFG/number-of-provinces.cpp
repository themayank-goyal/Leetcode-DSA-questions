//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++


// class DisjoinSet {
//     vector<int> size, parent;
    
//     public:
//         DisjoinSet(int n){
//             size.resize(n+1);
//             parent.resize(n+1);
//             for(int i=0; i<=n; i++){
//                 size[i] = 1;
//                 parent[i] = i;
//             }
//         }
        
//         int findUP(int node){
//             if(parent[node] = node) return node;
//             return parent[node] = findUP(parent[node]);
//         }
        
//         void unionBySize(int u, int v){
//             int ulp_u = findUP(u);
//             int ulp_v = findUP(v);
            
//             if(ulp_u == ulp_v) return;
            
//             if(size[ulp_u] > size[ulp_v]){
//                 parent[ulp_v] = ulp_u;
//                 size[ulp_u] += size[ulp_v];
//             }
//             else{
//                 parent[ulp_u] = ulp_v;
//                 size[ulp_v] += size[ulp_u];
//             }
//         }
// };

class DisjointSet {
    vector<int> rank, parent, size; 
public: 
    DisjointSet(int n) {
        rank.resize(n+1, 0); 
        parent.resize(n+1);
        size.resize(n+1); 
        for(int i = 0;i<=n;i++) {
            parent[i] = i; 
            size[i] = 1; 
        }
    }

    int findUPar(int node) {
        if(node == parent[node])
            return node; 
        return parent[node] = findUPar(parent[node]); 
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u); 
        int ulp_v = findUPar(v); 
        if(ulp_u == ulp_v) return; 
        if(rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v; 
        }
        else if(rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u; 
        }
        else {
            parent[ulp_v] = ulp_u; 
            rank[ulp_u]++; 
        }
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u); 
        int ulp_v = findUPar(v); 
        if(ulp_u == ulp_v) return; 
        if(size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v; 
            size[ulp_v] += size[ulp_u]; 
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v]; 
        }
    }
}; 

class Solution {
  public:
    
    int numProvinces(vector<vector<int>> adj, int v) {
        DisjointSet ds(v);
        for(int i=0; i<adj.size(); i++){
            for(int j=0; j<adj[0].size(); j++){
                if(adj[i][j] == 1)
                    ds.unionBySize(i, j);
            }
        }
        
        int res = 0;
        
        for(int i=0; i<v; i++){
            if(ds.findUPar(i) == i) res++;
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