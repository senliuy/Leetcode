class Solution {
private:
    int find(vector<int> nums, int target){
        int res=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==target) return i;
        }
        return res;
    }
public:
    vector<int> twoSum(vector<int> &nums, int target){
        vector<int> res;
        set<int> hash;
        for(int i=0;i<nums.size();i++){
            if(hash.count(target-nums[i])==0){
                hash.insert(nums[i]);
            }else{
                res.push_back(find(nums, target-nums[i]));
                res.push_back(i);
            }
        }
        return res;
    }
};