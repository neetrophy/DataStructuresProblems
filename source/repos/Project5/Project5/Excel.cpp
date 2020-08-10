class Solution {
public:
    
    /*
    A 1 
    B 2
    C 3
    z 26
    AA 27 26 +1 
    Ab 28 26 +2
    AC 29 26 +3
    AZ 52 26 + 26 
    BA    26 + 26 + 1
    BB    26 + 26 + 2
    CA    26 + 26 + 26 + 1  
    ZY    (26) + 25  
    
    AAZ    26       + 26    
For every additional digit of the string, we multiply the value of the digit by 26^n where n is the number of digits it is away from the one's place. This is similar to how the number 254 could be broken down as this: (2 x 10 x 10) + (5 x 10) + (4). The reason we use 26 instead of 10 is because 26 is our base.

For s = "BCM" the final solution would be (2 x 26 x 26) + (3 x 26) + (13)

We could do this process iteratively. Start at looking at the first digit "B". Add the int equivalent of "B" to the running sum and continue. Every time we look at the following digit multiply our running sum by 26 before adding the next digit to signify we are changing places. Example below:

"B" = 2
"BC" = (2)26 + 3
"BCM" = (2(26) + 3)26 + 13
BCCA    = ((2 *26 + 3)26 + 3)26 + 1
    */
    int titleToNumber(string s) {
        int sum =0;
        for(int i=0 ; i<s.length();i++){
            sum *= 26;
            sum += s[i] - 'A' + 1;
        }
        return sum;
    }
};
