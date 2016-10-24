class Solution {
public:
    string originalDigits(string s) {
        vector<int> hash(26,0);
        vector<int> nums(10,0);
        string res;
        for(int i=0; i<s.size(); i++) hash[ s[i]-'a' ]++;
        nums[0] = hash['z'-'a'];
        nums[1] = hash['o'-'a']-hash['z'-'a']-hash['w'-'a']-hash['u'-'a'];
        nums[2] = hash['w'-'a'];
        nums[3] = hash['r'-'a']-hash['z'-'a']-hash['u'-'a'];
        nums[4] = hash['u'-'a'];
        nums[5] = hash['f'-'a']-hash['u'-'a'];
        nums[6] = hash['x'-'a'];
        nums[7] = hash['s'-'a']-hash['x'-'a'];
        nums[8] = hash['g'-'a'];
        nums[9] = hash['i'-'a']-hash['x'-'a']-hash['g'-'a']-hash['f'-'a']+hash['u'-'a'];
        for(int i=0; i<nums.size();i++){
            for(int j=1;j<=nums[i];j++){
                res += '0' + i;
            }
        }
        return res;
    }
};