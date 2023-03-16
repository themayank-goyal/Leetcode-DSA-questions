class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<int>dp(m, 0);
        for(int i=0; i<n; i++){
          vector<int> temp(m, 0);
          for(int j=0; j<m; j++){
            if(i == 0 && j == 0) temp[j] = grid[i][j];
            else{
              int left = INT_MAX, right = INT_MAX;
              if(i > 0) left = dp[j];
              if(j > 0) right = temp[j-1];
              temp[j] = min(left, right) + grid[i][j];
            }
          }
          dp = temp;
        }
        return dp[m-1];
    }
};