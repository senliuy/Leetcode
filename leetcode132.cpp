//
//  main.cpp
//  Palindrome Partitioning 2
//
//  Created by liuyan on 2016/10/8.
//  Copyright © 2016年 liuyan. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

void isPalindrome(vector<vector<bool>> &res, string s){
    int n=(int)s.size();
    for (int i=n-1; i>=0; i--) {
        for (int j=i; j<n; j++) {
            if((i+1>j-1 || res[i+1][j-1]) && s[i]==s[j])
                res[i][j]=true;
        }
    }
}

int minCut(string s){
    int n=(int)s.size();
    vector<vector<bool>> res(n, vector<bool>(n, false));
    isPalindrome(res,s);
    vector<int> dp(n,0);
    for (int i=1; i<n; i++) {
        int minV=INT_MAX;
        for (int j=0; j<=i; j++) {
            if(res[j][i]){
                if(j==0)    minV=0;
                else{
                    minV=min(minV,dp[j-1]+1);
                }
            }
            dp[i]=minV;
        }
    }
    return dp[n-1];
}
int main(int argc, const char * argv[]) {
    // insert code here...
    string s = "aabab";
    cout<<minCut(s)<<endl;
    return 0;
}
