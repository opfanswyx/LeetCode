
// @Title: 反转字符串 (Reverse String)
// @Author: opfanswyx@outlook.com
// @Date: 2018-10-21 16:18:40
// @Runtime: 4 ms
// @Memory: N/A

char* reverseString(char* s) {
    int count = strlen(s);
    for (int i = 0; i < count / 2; i++) {
        s[i] ^= s[count - i - 1];
        s[count - i - 1] ^= s[i];
        s[i] ^= s[count - i - 1];
    }
    
    return s;
}
