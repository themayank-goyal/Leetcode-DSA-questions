//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
    void dfs(vector<vector<char>>& grid, int r, int c){
        if(r < 0 || c < 0 || r == grid.size() || c == grid[0].size() || grid[r][c] == ' ' || grid[r][c] == '0'){
            return;
        }
        grid[r][c] = ' ';
        dfs(grid, r+1, c+1);
        dfs(grid, r+1, c-1);
        dfs(grid, r, c-1);
        dfs(grid, r, c+1);
        dfs(grid, r-1, c);
        dfs(grid, r+1, c);
        dfs(grid, r-1, c-1);
        dfs(grid, r-1, c+1);
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size(), res = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == '1'){
                    dfs(grid, i, j);
                    res++;
                }
            }
        }
        return res;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends