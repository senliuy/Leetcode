class Solution {
public:
    bool isPerfectSquare(int num) {
        double i=0;
        while(i*i<=num){
            if( i*i == num) return true;
            i++;
        }
        return false;
    }
};