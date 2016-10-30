class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int len = A.size();
        if(len <= 1) return 0;
        vector<int> dp(len, 0);
        for(int i=2; i<len; i++){
            int k=i;
            int slice = A[i]-A[i-1];
            while(A[k-1]-A[k-2] == slice && k-2 >= 0) k--;
            dp[i] = dp[i-1] + (i-k);
        }
        return dp[len-1];
    }
};