
// @Title: 回文数 (Palindrome Number)
// @Author: opfanswyx@outlook.com
// @Date: 2018-09-19 13:07:55
// @Runtime: 205 ms
// @Memory: N/A

class Solution {
    public boolean isPalindrome(int x) {
        if(x<0||(x!=0 && x%10==0))
            return false;
        int buf=0;
        while(x>buf)
        {
            buf=buf*10+x%10;
            x/=10;
        }
        return (x==buf||buf/10==x);
    }
}
