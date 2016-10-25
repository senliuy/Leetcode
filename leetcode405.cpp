//
//  main.cpp
//  Convert a Number to Hexadecimal
//
//  Created by 岩 刘 on 25/10/2016.
//  Copyright © 2016 岩 刘. All rights reserved.
//

#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <stack>

using namespace std;

string toHex(int num) {
    if(num==0) return "0";
    string s;
    string res;
    stack<int> stk;
    for(int i=0; i<8; i++){
        int t=num & 0xf;
        if(t>=0){
            if(t<10) s += '0'+t;
            else s+= 'a'+t-10;
        }
        num=num>>4;
    }
    bool firstZero = true;
    for(int i=0;i<8;i++){
        stk.push( s[i]-'0' );
    }
    while (!stk.empty()) {
        if(stk.top()!=0 || firstZero == false){
            res += stk.top()+'0';
            firstZero=false;
        }
        stk.pop();
    }
    return res;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    cout<<toHex(0)<<endl;
    return 0;
}
