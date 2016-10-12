//
//  main.cpp
//  3Sum
//
//  Created by liuyan on 2016/10/12.
//  Copyright © 2016年 liuyan. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

bool binarySearch(vector<int>& nums, int index, int target){
    int left=index;
    int right=(int)nums.size();
    int mid=0;
    while(left <= right){
        mid=left+(right-left)/2;
        if(nums[mid] == target) return true;
        else if(nums[mid] > target) right=mid-1;
        else left=mid+1;
    }
    if(nums[mid] == target) return true;
    else return false;
    
}
vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;
    for (int i=0; i<nums.size()-1; i++) {
        for (int j=i+1; j<nums.size()-1; j++) {
            int target=-(nums[i]+nums[j]);
            if(binarySearch(nums, j+1, target)){
                vector<int> temp={nums[i],nums[j],target};
                res.push_back(temp);
            }
            while(nums[j] == nums[j+1]) j++;
        }
        while(nums[i]==nums[i+1]) i++;
    }
    return res;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> nums={0,0};
    vector<vector<int>> res=threeSum(nums);
    //cout<< binarySearch(nums,0,5)<<endl;
    for (int i=0; i<res.size(); i++) {
        for (int j=0; j<res[i].size(); j++) {
            cout<<res[i][j]<<", ";
        }
        cout<<endl;
    }
    return 0;
}
