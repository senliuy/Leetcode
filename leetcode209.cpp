//
//  main.cpp
//  Minimum Size Subarray Sum
//
//  Created by liuyan on 2016/10/12.
//  Copyright © 2016年 liuyan. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int minSubArrayLen(int s, vector<int>& nums) {
    if(nums.size()==0) return 0;
    int ans=INT_MAX;
    for(int left=0;left<nums.size();left++){
        int right=left;
        int sum=0;
        while(sum<s && right<nums.size()){
            sum+=nums[right];
            right++;
        }
        if(sum >= s) ans=min(ans, right-left);
    }
    return ans;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> nums={1,5,7};
    int s=7;
    cout<<minSubArrayLen(s, nums)<<endl;
    //std::cout << "Hello, World!\n";
    return 0;
}
