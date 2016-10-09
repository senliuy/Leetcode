//
//  main.cpp
//  Longest Palindrome
//
//  Created by liuyan on 2016/10/9.
//  Copyright © 2016年 liuyan. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int longestPalindrome(string s) {
    vector<int> hash_table(52,0);
    for (int i=0; i<s.size(); i++) {
        if(s[i]>='A' && s[i]<='Z')  hash_table[s[i]-'A'+26]++;
        else hash_table[s[i]-'a']++;
    }
    int ans=0;
    bool exist_single=false;
    for (int i=0; i<52; i++) {
        if(exist_single==false && hash_table[i]%2==1) exist_single=true;
        ans+=(hash_table[i]/2)*2;
    }
    return ans+exist_single;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    string s="ABCDBCDA";
    cout<<longestPalindrome(s)<<endl;
    return 0;
}
