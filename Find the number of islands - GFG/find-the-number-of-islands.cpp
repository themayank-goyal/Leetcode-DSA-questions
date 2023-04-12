//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
    void bfs(vector<vector<char>>& grid, vector<vector<int>>&vis, int r, int c){
        queue<pair<int, int>> q;
        int n = grid.size(), m = grid[0].size();
        vis[r][c] = 1;
        q.push({r,c});
        while(q.size()){
                int rowNum = q.front().first , colNum = q.front().second;
                
            q.pop();
                for(int i=-1; i<=1; i++){
                    for(int j=-1; j<=1; j++){
                        int nbrRow = rowNum + i;
                        int nbrCol = colNum + j;
                        if(nbrRow >= 0 && nbrCol >= 0 &&
                        nbrRow < n && nbrCol < m 
                        && (grid[nbrRow][nbrCol] == '1' && !vis[nbrRow][nbrCol])){
                            q.push({nbrRow, nbrCol});
                            vis[nbrRow][nbrCol] = 1;
                        }
                    }    
                }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size(), res = 0;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == '1' && !vis[i][j]){
                    bfs(grid, vis, i, j);
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