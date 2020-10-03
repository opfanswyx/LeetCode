
// @Title: 3的幂 (Power of Three)
// @Author: opfanswyx@outlook.com
// @Date: 2018-10-19 17:29:15
// @Runtime: 52 ms
// @Memory: N/A

bool isPowerOfThree(int n) {
    if(n==0)
        return false;
    while(n!=1)
    {
        if(n%3==0)
            n/=3;
        else
            return false;
    }
    return true;
}
