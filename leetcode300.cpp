class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size()==0) return 0;
        int n=nums.size();
        vector<int> dp(n,0);
        dp[0]=1;
        
        for(int i=0; i<n;i++){
            int max_temp=1;
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i]){
                    max_temp=max(max_temp, dp[j]+1);
                }
            }
            dp[i]=max_temp;
        }
        int maxV=1;
        for(int i=0;i<n;i++){
            maxV=max(dp[i],maxV);
        }
        return maxV;
    }
};