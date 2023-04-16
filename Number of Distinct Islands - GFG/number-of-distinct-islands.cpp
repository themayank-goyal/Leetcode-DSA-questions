//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void dfs(vector<vector<int>>& grid, vector<vector<int>>& vis, int delRow[], int delCol[], int r,
    int c, int rb, int cb, vector<vector<int>>& vec){
        vis[r][c] = 1;
        vec.push_back({r-rb, c-cb});
        for(int i=0; i<4; i++){
            int nr = r + delRow[i], nc = c + delCol[i];
            if(nr >= 0 && nc >= 0 && nr < grid.size() && nc < grid[0].size() && !vis[nr][nc]
            && grid[nr][nc] == 1){
                dfs(grid, vis, delRow, delCol, nr, nc, rb, cb, vec);
            }
        }
    }
    int countDistinctIslands(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        set<vector<vector<int>>> st;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        
        int delRow[] = {0, 0, 1, -1};
        int delCol[] = {-1,1, 0, 0};
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1 && !vis[i][j]){
                    vector<vector<int>> vec;
                    dfs(grid, vis, delRow, delCol, i, j, i, j, vec);
                    st.insert(vec);
                }
            }
        }
        return st.size();
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends