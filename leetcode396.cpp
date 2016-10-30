class Solution {
public:
    //F(i) = F(i-1) + Sum - n*A[n-i];
    int maxRotateFunction(vector<int>& A) {
        int n=A.size();
        if( n<=1 ) return 0;
        int res=0;
        int sum = accumulate(A.begin(), A.end(),0);
        for(int i=0; i<n; i++)   res+=i*A[i];
        int max_res=res;
        for(int i=1; i<n; i++){
            res += (sum - n*A[n-i]);
            max_res = max(max_res, res);
        }
        return max_res;
    }
};