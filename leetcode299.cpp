//
//  main.cpp
//  Bulls and Cows
//
//  Created by 岩 刘 on 26/10/2016.
//  Copyright © 2016 岩 刘. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

string getHint(string secret, string guess) {
    int len=secret.size();
    vector<int> hash(10, 0);
    int count_bull=0;
    int count_cow=0;
    for(int i=0; i<len; i++){
        if(secret[i] == guess[i]) count_bull++;
        hash[ secret[i]-'0' ]++;
    }
    for(int i=0; i<len; i++) if(hash[ guess[i]-'0' ]>0) hash[ guess[i]-'0' ]--;
    for(int i=0; i<10; i++) count_cow += hash[i];
    return to_string(count_bull)+'A'+to_string(len-count_cow-count_bull)+'B';
}

int main(int argc, const char * argv[]) {
    // insert code here...
    string secret="1";
    string guess="0";
    cout<<getHint(secret, guess)<<endl;
    std::cout << "Hello, World!\n";
    return 0;
}
