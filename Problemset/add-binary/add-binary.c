
// @Title: 二进制求和 (Add Binary)
// @Author: opfanswyx@outlook.com
// @Date: 2018-09-24 12:27:01
// @Runtime: 0 ms
// @Memory: N/A

char* addBinary(char* a, char* b) {
    int lena = strlen(a), lenb = strlen(b), carry = 0;
    int lenc = lena > lenb?lena:lenb;
    char * c = malloc(lenc+2);
    c[lenc+1] = '\0';
    while(lena || lenb ){
        if(lena) carry += (a[--lena]-'0');
        if(lenb) carry += (b[--lenb]-'0');
        c[lenc--] = (carry&1)+'0';
        carry >>= 1;
    }
    c[0] = carry+'0';
    return c+(carry^1);
}
