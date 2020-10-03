
// @Title: 验证回文串 (Valid Palindrome)
// @Author: opfanswyx@outlook.com
// @Date: 2018-10-10 22:44:19
// @Runtime: 4 ms
// @Memory: N/A

bool isPalindrome(char* s) {
    int len = strlen(s);
    if(!len) return true;
    char *p1 = s, *p2 = s + len - 1;
    while(p1 < p2){
        if(!isalnum(*p1)){p1++;continue;}
        if(!isalnum(*p2)){p2--;continue;}
        if(tolower(*p1++) != tolower(*p2--)) return false;
    }
    return true;  
}
