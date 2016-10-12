//
//  main.cpp
//  Median of Two Sorted Arrays
//
//  Created by liuyan on 2016/10/12.
//  Copyright © 2016年 liuyan. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

double findKthNumber(vector<int>& nums1, vector<int> &nums2, int n1, int n2, int k ){
    int l1=(int)nums1.size()-n1;
    int l2=(int)nums2.size()-n2;
    if (0 == l1) return nums2[n2+k-1];
    if (0 == l2) return nums1[n1+k-1];
    if (1 == k) return min(nums1[n1], nums2[n2]);
    int n=min(min(l1,l2),k/2);
    if(nums1[n1+n-1]<nums2[n2+n-1]) return findKthNumber(nums1, nums2, n1+n, n2, k-n);
    else if(nums1[n1+n-1]>nums2[n2+n-1]) return findKthNumber(nums1, nums2, n1, n2+n, k-n);
    else return nums1[n1+n-1];
}

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int len1=(int)nums1.size();
    int len2=(int)nums2.size();
    int sum_len=len1+len2;
    if(sum_len%2==0){
        return (findKthNumber(nums1, nums2, 0, 0, sum_len/2)+findKthNumber(nums1, nums2, 0, 0, sum_len/2+1))/2;
    }else return findKthNumber(nums1, nums2, 0, 0, sum_len/2+1);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> nums1={1,4};
    vector<int> nums2={2,3};
    cout<<findMedianSortedArrays(nums1, nums2)<<endl;
    return 0;
}
