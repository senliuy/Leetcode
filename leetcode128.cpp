//
//  main.cpp
//  Longest Consecutive Sequence
//
//  Created by liuyan on 2016/10/4.
//  Copyright © 2016年 liuyan. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;


int longestConsecutive(vector<int>& nums) {
    unordered_set<int> hashmap;
    int res=0;
    for (int i=0; i<nums.size(); i++) {
        if(hashmap.find(nums[i])==hashmap.end())    hashmap.insert(nums[i]);
    }
    
    for (int i=0; i<nums.size(); i++) {
        int count=1;
        if(hashmap.find(nums[i])!=hashmap.end()){
            int cur=nums[i]+1;
            while(hashmap.find(cur)!=hashmap.end()){
                hashmap.erase(cur);
                count++;
                cur++;
            }
            cur=nums[i]-1;
            while(hashmap.find(cur)!=hashmap.end()){
                hashmap.erase(cur);
                count++;
                cur--;
            }
            res=max(res,count);
        }
        hashmap.erase(nums[i]);
    }
    return res;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> nums={1,2,100,2,3,200,101,4};
    int res=longestConsecutive(nums);
    cout<<res<<endl;
    return 0;
}
