//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
    void f(vector<vector<int>>& grid, vector<vector<int>>& vis, int delRow[], int delCol[], int r, int c){

        vis[r][c] = 1;
        
        for(int i=0; i<4; i++){
            int nr = r + delRow[i], nc = c + delCol[i];
            if(r >= 0 && c >= 0 && r < grid.size() && c < grid[0].size() && grid[r][c] == 1 && !vis[nr][nc])
                f(grid, vis, delRow, delCol, nr, nc);
        }
    }
    
    int numberOfEnclaves(vector<vector<int>> &grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        
        queue<pair<int, int>> q;
        
        int delRow[] = {0, 0, 1, -1};
        int delCol[] = {-1, 1, 0, 0};
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(i == 0 || j == 0 || i == n-1 || j == m-1)
                    if(grid[i][j] == 1 && !vis[i][j]){
                        q.push({i, j});
                        vis[i][j] = 1;
                    }
            }
        }
        
        while(q.size()){
            int r = q.front().first, c = q.front().second;
            q.pop();
            for(int i=0; i<4; i++){
                int nr = r + delRow[i] , nc = c + delCol[i];
                if(nr >= 0 && nc >=0 && nr < n && nc < m && grid[nr][nc] == 1 && !vis[nr][nc]){
                    vis[nr][nc] = 1;
                    q.push({nr, nc});
                }
            }
        }
        
        int res = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!vis[i][j] && grid[i][j] == 1) res++;
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
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends