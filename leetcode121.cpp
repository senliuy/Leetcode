//
//  main.cpp
//  Best Time to Buy and Sell Stock
//
//  Created by 岩 刘 on 10/3/16.
//  Copyright © 2016 岩 刘. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;
int maxProfit(vector<int>& prices) {
    if(prices.size()==0) return 0;
    vector<int> dp;
    int minV=prices[0];
    int maxP=0;
    for (int i=0; i<(int)prices.size(); i++) {
        minV=min(minV, prices[i]);
        maxP=max(maxP, prices[i]-minV);
    }
    return maxP;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> prices={7, 1, 5, 3, 6, 4};
    int res=maxProfit(prices);
    cout<<res<<endl;
    return 0;
}
