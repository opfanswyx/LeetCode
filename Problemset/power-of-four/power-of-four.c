
// @Title: 4的幂 (Power of Four)
// @Author: opfanswyx@outlook.com
// @Date: 2018-10-21 11:32:00
// @Runtime: 4 ms
// @Memory: N/A

bool isPowerOfFour(int num) {
    if(num==0)
        return false;
    while(num!=1)
    {
        if(num%4==0)
            num/=4;
        else
            break;
    }
    if(num==1)
        return true;
    else
        return false;
}
