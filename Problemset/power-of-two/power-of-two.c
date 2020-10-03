
// @Title: 2的幂 (Power of Two)
// @Author: opfanswyx@outlook.com
// @Date: 2018-10-15 16:35:15
// @Runtime: 4 ms
// @Memory: N/A

#if 0
bool isPowerOfTwo(int n) {
    if(n==0)    return false;
    while(1){
        if(n==1)    return true;
        if(n%2!=0)  return false;
        n = n/2;
    }
}
#endif

#if 1
bool isPowerOfTwo(int n) {
    return (n>0&&2147483648%n==0);
}
//2147483648=2^31
#endif


#if 0
bool isPowerOfTwo(int n) {
    if(n<=0) return false;
    int bitOneCount = 0;
    int tmp;
    for(int i=0; i<32; i++){
        tmp = n>>i;
        tmp = tmp & 0x01;
        if(tmp==0x01){ 
            bitOneCount++;
            if(bitOneCount>1) return false;
        }
    }
    if(bitOneCount==0) return false;
    return true;
}
#endif
