class Solution {
public:
    int findNthDigit(int n) {
        long numlen=1;
        long numCount=9;
        long start=1;
        while( n > numlen*numCount){
            n -= numlen*numCount;
            numlen++;
            numCount*=10;
            start *= 10;
        }
        start += (n-1)/numlen;
        string num_s = to_string(start);
        int index = (n-1)%numlen;
        return num_s[index]-'0';
    }
};