#include<bits/stdc++.h>
using namespace std;

/* 
Given two integers dividend and divisor, divide two integers without using multiplication, division, and mod operator.

The integer division should truncate toward zero, which means losing its fractional part. For example, 8.345 would be truncated to 8, and -2.7335 would be truncated to -2.

Return the quotient after dividing dividend by divisor.

Note: Assume we are dealing with an environment that could only store integers within the 32-bit signed integer range: [−231, 231 − 1]. For this problem, if the quotient is strictly greater than 231 - 1, then return 231 - 1, and if the quotient is strictly less than -231, then return -231.

*/

class Solution {
public:
    int divide(int dividend, int divisor) {
        // Edge case: if dividend equals divisor, the result is always 1
        if(dividend == divisor) return 1;
        bool sign = true;   // true -> +ve, false-> -ve

        // Check if the signs of dividend and divisor are different
        if(dividend >= 0 && divisor < 0) sign = false;
        if(dividend <= 0 and divisor > 0) sign = false;

        // Convert both dividend and divisor to their absolute values
        long n = abs(dividend);
        long d = abs(divisor);

        long quotient = 0;  // Initialize the quotient to 0
        
        while(n >= d){
            int count = 0;
            // Find the maximum value of count such that (divisor << count) is still less than or equal to the dividend
            while(n >= (d << (count+1))){
                count += 1;
            }
            quotient += 1 << count; // Add the corresponding power of 2 to the quotient
            n -= (d << count);  // Subtract the largest shifted divisor from the current dividend
        }

        // Handle overflow cases: if quotient exceeds the range of an integer
        if(quotient == (1<<31) && sign) return INT_MAX;
        if(quotient == (1<<31) && !sign) return INT_MIN;

        return sign ? quotient : -quotient;
    }
};