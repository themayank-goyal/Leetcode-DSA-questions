//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int MinimumEffort(vector<vector<int>>& heights) {
        int n = heights.size(), m = heights[0].size();
        int delRow[] = {0,0,1,-1};
        int delCol[] = {1, -1, 0, 0};
        vector<vector<int>>dist(n, vector<int>(m, 1e9));
        
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0,0,0});
        
        dist[0][0] = 0;
        
        while(pq.size()){
            int e = pq.top()[0], r = pq.top()[1], c = pq.top()[2];
            int hi = heights[r][c];
            if(r == n-1 && c == m-1) return dist[r][c];
            pq.pop();
            for(int i=0; i<4; i++){
                int nr = r + delRow[i], nc = c + delCol[i];
                if(nr >= 0 && nc >= 0 && nr < n && nc < m){
                    int hf = heights[nr][nc];
                    if((max(e ,abs(hi - hf))) < dist[nr][nc]){
                        dist[nr][nc] = max(e ,abs(hi - hf));
                        pq.push({dist[nr][nc], nr, nc});
                    }
                }
            }
        }
        return -1;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n,m; cin>>n>>m;
        vector<vector<int>> heights;
       
        for(int i=0; i<n; ++i){
            vector<int> temp;
            for(int j=0; j<m; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            heights.push_back(temp);
        }
       
        Solution obj;
        cout<<obj.MinimumEffort(heights)<<"\n";
    }
    return 0;
}
// } Driver Code Ends