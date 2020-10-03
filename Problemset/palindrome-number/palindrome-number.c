
// @Title: 回文数 (Palindrome Number)
// @Author: opfanswyx@outlook.com
// @Date: 2018-09-18 20:57:54
// @Runtime: 112 ms
// @Memory: N/A

bool isPalindrome(int x) {
    int buf=0;
    if(x<0||(x!=0 && x%10==0))
        return false;
#if 0
    else if(copy/10==0)
        return true;
#endif
    else
    {
        while(x>buf)
        {
            buf=buf*10+x%10;
            x/=10;
        }
        return (buf==x||buf/10==x);
    }
}
