class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
      int r = grid.size(), c = grid[0].size();
      vector<vector<vector<int>>> dp(r, vector<vector<int>>(c, vector<int>(c, 0)));
      for(int i=0; i<c; i++){
        for(int j=0; j<c; j++){
          if(i == j)
            dp[r-1][i][j] = grid[r-1][i];
          else
            dp[r-1][i][j] = grid[r-1][i] + grid[r-1][j];
        }
      }
      for(int i=r-2; i>=0; i--){
        for(int j1=0; j1<c; j1++){
          for(int j2=0; j2<c; j2++){
            for(int k1=j1-1; k1<=j1+1; k1++){
              for(int k2=j2-1; k2<=j2+1; k2++){
                if(k1 < 0 || k1 >= c || k2 < 0 || k2 >= c) continue;
                if(j1 == j2)
                  dp[i][j1][j2] = max(dp[i][j1][j2], dp[i+1][k1][k2] + grid[i][j1]);
                else
                  dp[i][j1][j2] = max(dp[i][j1][j2], dp[i+1][k1][k2] + grid[i][j1] + grid[i][j2])  ;
              }
            }
          }
        }
      }
      return dp[0][0][c-1];
    }
};