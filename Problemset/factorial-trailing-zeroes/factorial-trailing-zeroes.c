
// @Title: 阶乘后的零 (Factorial Trailing Zeroes)
// @Author: opfanswyx@outlook.com
// @Date: 2018-10-12 10:14:00
// @Runtime: 4 ms
// @Memory: N/A

int trailingZeroes(int n) {
    int num=0;
    int res=0;
    while(n>4)
    {
        res += (n=n/5);
    }
    return res;
}
#if 0
int trailingZeroes(int n) {
    long long int num=1;
    int res=0;
    while(n>1)
    {
        num=num*n;
        n--;
    }
    while(num)
    {
        if(num%10==0)
            res++;
        else
            break;
        num /=10;
    }
    return res;
}
#endif
