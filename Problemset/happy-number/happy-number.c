
// @Title: 快乐数 (Happy Number)
// @Author: opfanswyx@outlook.com
// @Date: 2018-10-12 15:03:23
// @Runtime: 0 ms
// @Memory: N/A

int getother(int n)
{
    int temp=0;
    while(n)
    {
        temp += pow(n % 10,2);
        n /= 10;
    }
    return temp;
}
bool isHappy(int n) {
    int temp=0;
    if(n==1)
        return true;    
    while(n>6)
    {
        n=getother(n);
    }
    return n==1;
}
//Using fact all numbers in [2, 6] are not happy (and all not happy numbers end on a cycle that hits this interval)
