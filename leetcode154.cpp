//
//  main.cpp
//  Find Minimum in Rotated Sorted Array II
//
//  Created by liuyan on 2016/10/12.
//  Copyright © 2016年 liuyan. All rights reserved.
//

// Analysis:
// Take an array A = {0,1,2,3,4,5,6} with its all rotated conditions as an example
// A ={0,1,2,3,4,5,6}   nums[mid] < nums[right], minimal value is at mid or its left part
// A1={6,0,1,2,3,4,5}   nums[mid] < nums[right], minimal value is at mid or its left part
// A2={5,6,0,1,2,3,4}   nums[mid] < nums[right], minimal value is at mid or its left part
// A3={4,5,6,0,1,2,3}   nums[mid] < nums[right], minimal value is at mid or its left part
// A4={3,4,5,6,0,1,2}   nums[mid] > nums[right], minimal value is at its right part
// A5={2,3,4,5,6,0,1}   nums[mid] > nums[right], minimal value is at its right part
// A6={1,2,3,4,5,6,0}   nums[mid] > nums[right], minimal value is at its right part

//Sepcial Condtion
// B ={1,3,3,3}     nums[mid] == nums[left], minimal is at left part
// B1={3,1,3,3}
// B2={3,3,1,3}     nums[mid] == nums[left], minimal is at right part
// B3={3,3,3,1}
//
// Solution: when we meet the condition of nums[mid] == nums[left], move right pointer to its left with one step
#include <iostream>
#include <vector>

using namespace std;

int findMin(vector<int>& nums) {
    int right = (int)nums.size()-1;
    int left = 0;
    int mid;
    while(left<right){
        mid = (right-left)/2+left;
        if (nums[mid]<nums[right]) {
            right=mid;
        }else if(nums[mid] == nums[right]){
            right--;
        }
        else{
            left=mid+1;
        }
    }
    return nums[left];
}
int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> nums={3,3,1,3};
    cout<<findMin(nums)<<endl;
    return 0;
}
