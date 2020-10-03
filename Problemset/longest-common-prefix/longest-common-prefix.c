
// @Title: 最长公共前缀 (Longest Common Prefix)
// @Author: opfanswyx@outlook.com
// @Date: 2018-09-20 22:37:50
// @Runtime: 0 ms
// @Memory: N/A

char* longestCommonPrefix(char** strs, int strsSize) {
    if(strsSize == 0)
        return "";
    int i = 0;
    int len = strlen(strs[0]);
    for(;i<len;i++)
    {
        int j = 1;
        for(;j<strsSize;j++)
            if(strs[j][i] != strs[0][i])
                break;
        if(j<strsSize)
            break;
    }
    strs[0][i]='\0';
    return strs[0];
}
