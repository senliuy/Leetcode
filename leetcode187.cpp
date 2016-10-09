//
//  main.cpp
//  Repeated DNA Sequences
//
//  Created by liuyan on 2016/10/9.
//  Copyright © 2016年 liuyan. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int decoding(string s){
    int res=0;
    for(int i=0;i<s.size();i++){
        char c=s[i];
        res<<=2;
        switch (c) {
            case 'A':
                res+=0;
                break;
            case 'C':
                res+=1;
                break;
            case 'G':
                res+=2;
                break;
            case 'T':
                res+=3;
                break;
            default:
                break;
        }
    }
    return res;
}

vector<string> findRepeatedDnaSequences(string s) {
    vector<int> hash(1048576, 0);
    vector<string> res;
    if(s.size()<10) return res;
    for(int i=0;i<s.size()-9;i++){
        //cout<<"====="<<endl;
        string temp_s=s.substr(i,10);
        int code=decoding(temp_s);
        if(hash[code]==1)   res.push_back(temp_s);
        hash[code]++;
    }
    return res;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    string s = "AAAAAAAAAAAA";
    vector<string> res=findRepeatedDnaSequences(s);
    for (int i=0; i<res.size(); i++) {
        cout<<res[i]<<endl;
    }
    return 0;
}
