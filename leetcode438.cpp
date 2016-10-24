//
//  main.cpp
//  Longest Palindrome
//
//  Created by liuyan on 2016/10/9.
//  Copyright © 2016年 liuyan. All rights reserved.
//

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    bool isAnagrams(vector<int> hash){
        for(int i=0; i < hash.size(); i++)  if(hash[i] != 0) return false;
        return true;
    }
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        vector<int> hash(26, 0);
        if(s.size() < p.size()) return res;
        for(int i=0; i < p.size(); i++)    hash[ p[i]-'a' ]++;
        for(int i=0; i< s.size()-p.size()+1; i++){
            if( 0 == i){
                for(int i=0; i < p.size(); i++)    hash[ s[i]-'a' ]--;
            }
            else{
                hash[ s[ i-1 ] -'a' ]++;
                hash[ s[ i+p.size()-1 ] -'a' ]--;
            }
            if(isAnagrams( hash )) res.push_back(i);
        }
        return res;
    }
};