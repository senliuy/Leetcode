//
//  main.cpp
//  atoi
//
//  Created by liuyan on 16/9/20.
//  Copyright © 2016年 liuyan. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;
bool isDigit(char c){
    return c>='0' && c<='9';
}
int myAtoi(string s){
    long long ret=0;
    int positive=1;
    for(int i=0;i<s.length();){
        while(s[i]==' ') i++;
        if(s[i]=='-'){
            positive=-1;
            i++;
        }
        if(s[i]=='+'){
            i++;
        }
        while(isDigit(s[i]) && i<s.length()){
            ret=ret*10+(s[i]-'0');
            if(ret>=INT_MAX && positive) return INT_MAX;
            if(!positive && -ret<=INT_MIN) return INT_MIN;
            i++;
        }
        return (int)positive*ret;
    }
    return (int)positive*ret;
}
    int main(int argc, const char * argv[]) {
    // insert code here...
    cout << myAtoi("-+2")<<endl;;
    return 0;
}
