//
//  main.cpp
//  Simplify Path
//
//  Created by liuyan on 2016/10/17.
//  Copyright © 2016年 liuyan. All rights reserved.
//


// 1. 等于“/”，跳过，直接开始寻找下一个element
// 2. 等于“.”，什么都不需要干，直接开始寻找下一个element
// 3. 等于“..”，弹出栈顶元素，寻找下一个element
// 4. 等于其他，插入当前elemnt为新的栈顶，寻找下一个element

#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <sstream>

using namespace std;

string simplifyPath(string path) {
    stringstream ss(path);
    string t;
    string res;
    vector<string> vec;
    while (getline(ss, t, '/')) {
        if(t=="." || t=="") continue;
        if(t==".." && !vec.empty()) vec.pop_back();
        else if(t!="..") vec.push_back(t);
    }
    for (string s:vec) res+="/"+s;
    if(res.empty()) return "/";
    return res;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    string path="/a/./b/../../c/";
    cout<<simplifyPath(path)<<endl;
    return 0;
}
