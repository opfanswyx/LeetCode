
// @Title: 同构字符串 (Isomorphic Strings)
// @Author: opfanswyx@outlook.com
// @Date: 2018-10-13 14:23:31
// @Runtime: 0 ms
// @Memory: N/A

bool isIsomorphic(char* s, char* t) {
    static int ab[256],ba[256];
    int a,b;
    
    (void)memset(ab,0,sizeof(ab));
    (void)memset(ba,0,sizeof(ba));
    do{
        a=*(unsigned char *)s++;
        b=*(unsigned char *)t++;
        if(ab[a]==0)
            ab[a]=b;
        if(ba[b]==0)
            ba[b]=a;
    }while(a!=0&&b!=0&&ab[a]==b&&ba[b]==a);
    return a==0&&b==0;
}
