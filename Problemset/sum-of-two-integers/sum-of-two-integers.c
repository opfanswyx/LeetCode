
// @Title: 两整数之和 (Sum of Two Integers)
// @Author: opfanswyx@outlook.com
// @Date: 2018-10-22 19:46:13
// @Runtime: 0 ms
// @Memory: N/A

int getSum(int a, int b) {
    while (b!=0){
        int c = a&b;
        a= a^b;
        b=c<<1;
    }
    return a;
}
