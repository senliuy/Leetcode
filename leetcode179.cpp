bool comp(int big, int small){
    string s_b=to_string(big);
    string s_m=to_string(small);
    return s_b+s_m > (s_m+s_b);
}
class Solution {
public:
    string largestNumber(vector<int> &nums){
        string res="";
        sort(nums.begin(), nums.end(), comp);
        for (int i=0; i<nums.size(); i++) {
            res+=to_string(nums[i]);
        }
        if (res[0] == '0')  return "0";
        return res;
    }
};