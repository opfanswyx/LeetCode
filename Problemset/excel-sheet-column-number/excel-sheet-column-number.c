
// @Title: Excel表列序号 (Excel Sheet Column Number)
// @Author: opfanswyx@outlook.com
// @Date: 2018-10-11 20:58:15
// @Runtime: 4 ms
// @Memory: N/A

int titleToNumber(char* s) {
    int len=strlen(s);
    int num=0;
    int i;
    int j=0;
    for(i=len-1;i>=0;i--,j++)
    {
        num+=((int)s[i]-64)*(pow(26,j));
    }
    return num;
}
