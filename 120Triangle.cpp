class Solution {
public:
    int helper(vector<vector<int>>& triangle, int i, int j, int**dp){
      if(i == triangle.size()-1){
        return triangle[i][j];
      }
      if(dp[i][j] != INT_MAX) return dp[i][j];
      int ans1 = helper(triangle, i+1, j, dp) + triangle[i][j];
      int ans2 = helper(triangle, i+1, j+1, dp) + triangle[i][j];

      return dp[i][j] = min(ans1, ans2);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
      int m = triangle.size();
      vector<vector<int>>dp(m, vector<int>(m, 0));
      for(int i=0; i<m; i++){
        dp[m-1][i] = triangle[m-1][i];
      }
      for(int i=m-2; i>=0; i--){
        for(int j=i; j>=0; j--){
          int left = dp[i+1][j] + triangle[i][j];
          int right = dp[i+1][j+1] + triangle[i][j];
          dp[i][j] = min(left, right);
        }
      }
      return dp[0][0];
    }
};