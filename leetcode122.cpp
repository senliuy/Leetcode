//
//  main.cpp
//  Best Time to Buy and Sell Stock II
//
//  Created by 岩 刘 on 10/3/16.
//  Copyright © 2016 岩 刘. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;
int maxProfit(vector<int> &prices){
    if (prices.size()<=1) return 0;
    prices.push_back(0);
    for (int i=0; i<prices.size(); i++) {
        cout<<prices[i]<<", ";
    }
    cout<<endl;
    int buyPrice=0;
    int sellPrice=0;
    if(prices[0]<prices[1]){//左侧边界
        buyPrice+=prices[0];
    }
    for (int i=1; i<prices.size()-1; i++) {
        if(prices[i]<=prices[i-1] && prices[i]<prices[i+1]){ //类似[6,3,3,6]这种情况，只取第二个3
            buyPrice+=prices[i];
        }
        if(prices[i]>prices[i-1] && prices[i]>=prices[i+1]){ //类似[1,3,3,1]这种情况，只取第一个3
            sellPrice+=prices[i];
        }
    }
    cout<<buyPrice<<endl;
    cout<<sellPrice<<endl;
    return sellPrice-buyPrice;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> prices={3,3};
    int res=maxProfit(prices);
    cout<<res<<endl;
    return 0;
}
