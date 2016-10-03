//
//  main.cpp
//  addBinary
//
//  Created by liuyan on 16/9/29.
//  Copyright © 2016年 liuyan. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

string addBinary(string a, string b){
    int la=(int)a.length()-1;
    int lb=(int)b.length()-1;
    string res;
    int carry=0;
    while(la>=0 || lb>=0){
        int sum;
        if(la>=0 && lb>=0){
            sum=(a[la]-'0')+(b[lb]-'0')+carry;
            la--;lb--;
        }else if(la>=0 && lb<0){
            sum=(a[la]-'0')+carry;
            la--;
        }else{
            sum=(b[lb]-'0')+carry;
            lb--;
        }
        carry=sum/2;
        res+='0'+sum%2;
    }
    if(carry==1) res+='1';
    string ans;
    for(int i=(int)res.length()-1;i>=0;i--){
        ans+=res[i];
    }
    return ans;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    string a="1110";
    string b="11";
    string res=addBinary(a, b);
    cout<<res<<endl;
    return 0;
}
