
// @Title: 爬楼梯 (Climbing Stairs)
// @Author: opfanswyx@outlook.com
// @Date: 2018-09-25 23:01:59
// @Runtime: 0 ms
// @Memory: N/A

int climbStairs(int n) {
    if(n>0&&n<=2)
        return n;
    int old=1;
    int now=2;
    int res=0;
    for(int i=3;i<=n;i++)
    {
        res=old+now;
        old=now;
        now=res;
    }
    return res;
}
#if 0
int climbStairs(int n) {
    if(n>0&&n<=2)
        return n;
    return climbStairs(n-1)+climbStairs(n-2)；
}
#endif

