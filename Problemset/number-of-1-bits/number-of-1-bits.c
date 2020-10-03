
// @Title: 位1的个数 (Number of 1 Bits)
// @Author: opfanswyx@outlook.com
// @Date: 2018-10-12 11:21:02
// @Runtime: 0 ms
// @Memory: N/A

int hammingWeight(uint32_t n) {
    int res = 0;
    while(n)
    {
        if(n & 1)
            res++;
        n >>= 1;
    }
    return res;
}
