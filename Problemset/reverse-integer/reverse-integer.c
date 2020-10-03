
// @Title: 整数反转 (Reverse Integer)
// @Author: opfanswyx@outlook.com
// @Date: 2018-09-17 16:17:20
// @Runtime: 12 ms
// @Memory: N/A

int reverse(int x) {
    int b=0;
    do{
        b=b*10+x%10;
        x/=10;
    }while(x);
    return (b>INT_MAX||b<INT_MIN)?0:b;
}

#if 0
int reverse(int x) {
    int a;
    long int b;
    
    b=x%10;
    a=x/10;
    while(a!=0)
    {
        b=b*10+a%10;
        a/=10;
    }
    return (b>INT_MAX||b<INT_MIN)?0:b;
}
#endif

