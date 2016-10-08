//
//  main.cpp
//  Palindrome Partitioning
//
//  Created by liuyan on 2016/10/8.
//  Copyright © 2016年 liuyan. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool isPalindrome(string s){
    int left=0;
    int right=(int)s.size()-1;
    while(left<right){
        if( s[left]!=s[right] ) return false;
        left++;right--;
    }
    return true;
}

void helper(string s, vector<vector<string>> &res, vector<string>& temp, int index){
    if(s.size()==index){
        res.push_back(temp);
        return;
    }
    for(int i=index;i<s.size();i++){
        string sub_s=s.substr(index, i-index+1);
        if(isPalindrome(sub_s)){
            temp.push_back(sub_s);
            helper(s, res, temp, i+1);
            temp.pop_back();
        }
    }
}

vector<vector<string>> partition(string s) {
    vector<vector<string>> res;
    if(s.empty()) return res;
    vector<string> temp;
    helper(s,res, temp, 0);
    return res;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    string s = "abaa";
    vector<vector<string>> res= partition(s);
    for(int i=0; i<res.size(); i++){
        for(int j=0; j<res[i].size(); j++){
            cout<<res[i][j]<<", ";
        }
        cout<<endl;
    }
    return 0;
}
