
// @Title: 颠倒二进制位 (Reverse Bits)
// @Author: opfanswyx@outlook.com
// @Date: 2018-10-12 11:16:30
// @Runtime: 0 ms
// @Memory: N/A

uint32_t reverseBits(uint32_t n) {
    uint32_t m = 0;
    for(int i = 0; i < 32; i++, n >>= 1)
    {
        m <<= 1;
        m |= n & 1;
        
    }
    return m;
}
