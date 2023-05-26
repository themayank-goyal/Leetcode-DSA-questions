//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool isBoundaryCell(int i, int j, int n, int m){
        return i==0||i==n-1||j==0||j==m-1;
    }
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pair<int, int>> q;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(isBoundaryCell(i, j, n, m) && mat[i][j] == 'O'){
                    q.push({i, j});
                    vis[i][j] = 1;
                }
            }
        }
        int delRow[] = {0, 0, 1, -1};
        int delCol[] = {1, -1, 0, 0};
        while(q.size()){
            int r = q.front().first, c = q.front().second;
            q.pop();
            for(int i=0; i<4; i++){
                int nr = r + delRow[i], nc = c + delCol[i];
                if(nr >= 0 && nc >= 0 && nr < n && nc < m && !vis[nr][nc] && mat[nr][nc] == 'O'){
                    q.push({nr, nc});
                    vis[nr][nc] = 1;
                }
            }
        }
        vector<vector<char>> res(n, vector<char>(m, 'O'));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!vis[i][j]){
                    res[i][j] = 'X';
                }
            }
        }
        return res;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends