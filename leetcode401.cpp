//
//  main.cpp
//  BinaryWatch
//
//  Created by 岩 刘 on 10/10/16.
//  Copyright © 2016 岩 刘. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;
void helper(vector<vector<int>> &res, vector<int> &temp, int index, int k){
    if(0 == k){
        res.push_back(temp);
        return;
    }
    for (int i=index; i<=9; i++) {
        temp.push_back(i);
        helper(res, temp, i+1, k-1);
        temp.pop_back();
    }
}
vector<string> decoding(vector<vector<int>> nums){
    vector<string> res;
    for (int i=0; i<nums.size(); i++) {
        int hour=0;
        int min=0;
        for (int j=0; j<nums[i].size(); j++) {
            if(nums[i][j]<=3) hour+=pow(2, nums[i][j]);
            else min+=pow(2,(nums[i][j]-4));
        }
        if(hour<=11 && min<=59){
            string s_min = min>=10 ? to_string(min) : "0"+to_string(min);
            res.push_back(to_string(hour)+":"+s_min);
        }
    }
    return res;
}
vector<string> readBinaryWatch(int num){
    vector<vector<int>>  ans;
    vector<int> temp;
    helper(ans, temp, 0, num);
    vector<string> res = decoding(ans);
    return res;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int num=4;
    vector<string> res=readBinaryWatch(num);
    for (int i=0; i<res.size(); i++) {
        cout<<res[i]<<endl;
    }
    return 0;
}
