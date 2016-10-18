class Solution {
public:
    bool search(vector<int> nums, int target){
        int left=0;
        int right=(int)nums.size()-1;
        int mid;
        while(left<=right){
            mid=(right-left)/2+left;
            if(nums[mid]==target) return true;
            if(nums[mid]>nums[left]){
                if(target<nums[mid] && target>=nums[left]){
                    right=mid-1;
                }
                else{
                    left=mid+1;
                }
            }
            else if(nums[mid] < nums[left]){
                if(target>nums[mid] && target<=nums[right]){
                    left=mid+1;
                }else{
                    right=mid-1;
                }
            }else{
                left++;
            }
        }
        return false;
    }
};