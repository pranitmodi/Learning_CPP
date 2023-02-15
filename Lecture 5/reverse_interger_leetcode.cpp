//Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.
//Assume the environment does not allow you to store 64-bit integers (signed or unsigned).
//My Solution
class Solution {
public:
    int reverse(int x) {
        int d;
        long r = 0;
        while( x!=0 )
        {
            d = x%10;
            r = (r*10) + d;
            x = x/10;
        }
        if(r<=(2147483647) && (r>=(-2147483648)))
        {
            int r1 = (int) r;
            return r1;
        }
        else 
            return 0;
    }
};