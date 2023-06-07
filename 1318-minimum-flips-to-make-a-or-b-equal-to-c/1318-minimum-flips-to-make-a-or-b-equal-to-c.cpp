class Solution {
public:
    int minFlips(int a, int b, int c) {
        int counter = 0;

        for(int i = 0;i < 32;i++){
            int a1 = a%2;
            int b1 = b%2;
            int c1 = c%2;

            a = a/2;
            b = b/2;
            c = c/2;

            if((a1|b1) != c1){
                if(c1 == 0){
                    if(a1 == 1 && b1 == 1) counter += 2;
                    else counter += 1;
                }
                else{
                    // c1 is one
                    counter+=1;
                }
            }
        }

        return counter;
    }
};