class Solution {
public:
    int addDigits(int num) {
        while(num >= 10){
            // find digits sum.
            int sum = 0;
            while(num != 0){
                int lastDigit = num%10;
                num = num/10;
                sum += lastDigit;
            }
            num = sum;
        }

        return num;
    }
};