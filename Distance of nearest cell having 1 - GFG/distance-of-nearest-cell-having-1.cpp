//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    int n = grid.size(), m = grid[0].size();
	    vector<vector<int>> vis(n, vector<int>(m, 0));
	    queue<pair<pair<int, int>, int>> q;
	    for(int i=0; i<n; i++){
	        for(int j=0; j<m; j++){
	            if(grid[i][j] == 1){
	                q.push({{i, j}, 0});
	                vis[i][j] = 1;
	            }
	        }
	    }
	    vector<vector<int>> ans(n, vector<int>(m, 0));
	    int delRow[] = {0, 0, -1, 1};
	    int delCol[] = {1, -1, 0, 0};
	    while(q.size()){
	        auto c = q.front().first;
	        int d = q.front().second;
	        ans[c.first][c.second] = d;
	        q.pop();
	        
	        for(int i=0; i<4; i++){
	            int nr = c.first + delRow[i], nc = c.second + delCol[i];
	            
	            if(nr >= 0 && nc >= 0 && nr < n && nc < m && !vis[nr][nc]){
	                q.push({{nr, nc}, d+1});
	                vis[nr][nc] = 1;
	            }
	        }
            
	    }
	    return ans;
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
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends