
// @Title: 实现 strStr() (Implement strStr())
// @Author: opfanswyx@outlook.com
// @Date: 2018-09-23 22:54:52
// @Runtime: 4 ms
// @Memory: N/A

int strStr(char* haystack, char* needle) {
    char *h = haystack;
    char *n = needle;
    int idx = 0;
    
    if(*needle == '\0')
        return 0;
    
    while((*h != '\0') && (*needle != '\0'))
    {
        needle = n;
        while((*h != '\0') && (*h == *needle))
        {
            h++;
            needle++;
            if(needle == '\0')
                return idx;
        }
        if(*needle == '\0')
            return idx;
        if(*h == '\0')
            return -1;
        else
        {
            idx++;
            h=&haystack[idx];
        }
    }
    return -1;
}
#if 0
int strStr(char* haystack, char* needle) {
    if(!strcmp(needle,""))
        return 0;
    
    int lenh = strlen(haystack);
    int lenn = strlen(needle);
    
    for(int i = 0; i <= lenh-lenn; i++)
    {
        for(int j = 0; j<lenn; j++)
        {
            if(haystack[i+j]!=needle[j])
            {
                break;
            }
            if(j==lenn-1)
                return i;
        }
    }
    return -1;
    
}
#endif
