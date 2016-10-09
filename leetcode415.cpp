//
//  main.cpp
//  Add Strings
//
//  Created by liuyan on 2016/10/9.
//  Copyright © 2016年 liuyan. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

string addStrings(string num1, string num2) {
    int l1=(int)num1.size();
    int l2=(int)num2.size();
    string ans;
    int i1=l1-1;
    int i2=l2-1;
    int carry=0;
    while(i1>=0 || i2>=0){
        int n1; int n2;
        if(i1>=0 && i2>=0){
            n1=num1[i1]-'0';
            n2=num2[i2]-'0';
        }else if(i1>=0 && i2<0){
            n1=num1[i1]-'0';
            n2=0;
        }else{
            n1=0;
            n2=num2[i2]-'0';
        }
        int temp=n1+n2+carry;
        ans=to_string(temp%10)+ans;
        carry=temp/10;
        i1--;i2--;
    }
    if(carry==1) ans='1'+ans;
    return ans;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    string num1="987";
    string num2="35";
    cout<<addStrings(num1, num2)<<endl;
    return 0;
}
