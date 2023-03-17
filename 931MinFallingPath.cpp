class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
      int n = matrix.size();
      vector<vector<int>> dp(n, vector<int>(n, 0));

      for(int i=0; i<n; i++){
        dp[n-1][i] = matrix[n-1][i];
      }

      for(int i=n-2; i>=0; i--){
        for(int j=0; j<n; j++){
          int ans = INT_MAX;
          for(int k = j-1; k<=j+1; k++){
            if(k >= n || k < 0) continue;
            ans = min(ans, dp[i+1][k] + matrix[i][j]);
          }
          dp[i][j] = ans;
        }
      }
      int result = INT_MAX;
      for(int i=0; i<n; i++){
        result = min(result, dp[0][i]);
      }
      return result;
    }
};