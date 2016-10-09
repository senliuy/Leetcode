//
//  main.cpp
//  Count Primes
//
//  Created by liuyan on 2016/10/9.
//  Copyright © 2016年 liuyan. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;
int countPrimes(int n){
    if(n<=2) return 0;
    int res=0;
    vector<int> arr(n+1,0);
    for(int i=2; i<=n;i++){
        if(arr[i]==0){
            int cur=i;
            int k=2;
            while(cur*k<=n){
                arr[cur*k]=1;
                k++;
            }
        }
    }
    for (int i=2; i<n; i++) {
        if(arr[i]==0) res++;
    }
    return res;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    int n=100;
    int res=countPrimes(n);
    cout<<res<<endl;
    return 0;
}
