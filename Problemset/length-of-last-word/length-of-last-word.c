
// @Title: 最后一个单词的长度 (Length of Last Word)
// @Author: opfanswyx@outlook.com
// @Date: 2018-09-24 12:04:46
// @Runtime: 0 ms
// @Memory: N/A

int lengthOfLastWord(char* s) {
    int len = 0, lastlen = 0;
    while(*s != '\0')
    {
        if(*s++ == ' ')
        {
            if(len)
            {
                lastlen = len;
                len = 0;
            }
        }
        else
        {
            len += 1;
        }
    }
    if(!len)
        len = lastlen;
    return len;
}
