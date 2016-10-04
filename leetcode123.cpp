//
//  main.cpp
//  Best Time Buy and Sell the Stocks 3
//
//  Created by liuyan on 2016/10/4.
//  Copyright © 2016年 liuyan. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

//Solution 1: Divide the array into two parts, calculate the profit of each part and add them together
//              Until find the best division method and the largest profit.
//Can Not Solve Big Data Problem


//int maxRangeProfit(vector<int> &prices, int start, int end){
//    if(start==end) return 0;
//    int maxP=0;
//    int minV=prices[start];
//    for (int i=start; i<end; i++) {
//        minV=min(minV, prices[i]);
//        maxP=max(maxP, prices[i]-minV);
//    }
//    return maxP;
//}
//
//int maxProfit(vector<int> &prices){
//    int maxP=0;
//    for(int i=0;i<prices.size();i++){
//        maxP=max(maxP, maxRangeProfit(prices,0,i)+maxRangeProfit(prices, i, prices.size()));
//    }
//    return maxP;
//}


//Solution 2
//双向遍历，用数组纪录遍历到当前元素对应一次交易的最大收益
//最大收益就是两数组的和的最大值

int maxProfit(vector<int> &prices) {
    if(prices.size()==0) return 0;
    vector<int> left(prices.size(),0);
    vector<int> right(prices.size(),0);
    //traverse from left to right
    int minV=prices[0];
    int maxP=0;
    for (int i=0; i<prices.size(); i++) {
        minV=min(minV, prices[i]);
        maxP=max(maxP, prices[i]-minV);
        left[i]=maxP;
    }
    maxP=0;
    int maxV=prices[prices.size()-1];
    for (int j=prices.size()-1; j>=0; j--) {
        maxV=max(maxV, prices[j]);
        maxP=max(maxP, maxV-prices[j]);
        right[j]=maxP;
    }
    int res=0;
    for (int i=0; i<prices.size(); i++) {
        res=max(res, left[i]+right[i]);
    }
    return res;
    
}
int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> prices={1,3,7,9,2,5};
    int res=maxProfit(prices);
    cout<<res<<endl;
    return 0;
}
