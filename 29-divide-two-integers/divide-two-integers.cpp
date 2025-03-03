class Solution {
public:
    int divide(int dividend, int divisor) {
       
        if(dividend == INT_MIN && divisor == -1) return INT_MAX;
        if(dividend == INT_MIN && divisor == 1) return INT_MIN;

       
        bool flag = (dividend < 0) ^ (divisor < 0);

      
        int dd = dividend, dv = divisor;
        if(dd > 0) dd = -dd;
        if(dv > 0) dv = -dv;

        int res = 0;

       
        while(dd <= dv) {
            int mul = dv, power = 1;
            

         
            while(mul >= INT_MIN / 2 && dd <= (mul << 1)) {
                mul <<= 1;      
                power <<= 1;   
            }

            res += power;
            dd -= mul;
        }

        return flag ? -res : res;
    }
};