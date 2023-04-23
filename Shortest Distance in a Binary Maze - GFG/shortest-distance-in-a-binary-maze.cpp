//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> src,
                     pair<int, int> des) {
        
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        dist[src.first][src.second] = 0;
        
        int delRow[] = {0, 0, 1, -1};
        int delCol[] = {1, -1, 0, 0};
        
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> q;
        q.push({0, src.first, src.second});
        
        int ans = 0;
        while(q.size()){
            
            int d = q.top()[0], r = q.top()[1], c = q.top()[2];
            q.pop();
            
            if(r == des.first && c == des.second) return d;
            
            for(int i=0; i<4; i++){
                int nr = r + delRow[i], nc = c + delCol[i];
                if(nr >= 0 && nc >= 0 && nr < n && nc < m && dist[nr][nc] > d+1 && grid[nr][nc] == 1){
                    q.push({d+1, nr, nc});
                    dist[nr][nc] = 1;
                }
            }
        }
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
        vector<vector<int>> grid(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends