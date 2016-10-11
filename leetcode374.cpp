// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int left=1;
        int right=n;
        int mid=(right-left)/2+left;
        
        while(left<=right){
            int res=guess(mid);
            if(0==res) return mid;
            else if(-1==res) right=mid-1;
            else left=mid+1;
            mid=(right-left)/2+left;
        }
        return -1;
    }
};