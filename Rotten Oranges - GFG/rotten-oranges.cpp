//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:

    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};
        queue<vector<int>> q;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int time = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 2){
                    vis[i][j] = 2;
                    q.push({i,j,0});
                }
            }
        }
        int res = 0;
        while(q.size()){
            int r = q.front()[0], c = q.front()[1];
            int t = q.front()[2];
            res = max(res, t);
            q.pop();
            for(int i=0; i<4; i++){
                int nr = r + delRow[i], nc = c + delCol[i];
                if(nr >= 0 && nc >= 0 && nr < n && nc < m && 
                vis[nr][nc] == 0 && grid[nr][nc] == 1){
                    vis[nr][nc] = 2;
                    q.push({nr, nc, t+1});
                }
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(vis[i][j] != 2 && grid[i][j] == 1) return -1;
            }
        }
        return res;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends