
// @Title: 有效的字母异位词 (Valid Anagram)
// @Author: opfanswyx@outlook.com
// @Date: 2018-10-16 16:16:58
// @Runtime: 0 ms
// @Memory: N/A

bool isAnagram(char* s, char* t) {
    if(s==NULL && t==NULL) return true;
    if(strlen(s) != strlen(t)) return false;
    
    int a[26]={0};
    int len=strlen(s);
    for(int i=0;i<len;i++){
        a[s[i]-'a']++;
        a[t[i]-'a']--;
    }

    for(int i=0;i<26;i++){
        if(a[i]!=0) return false;
    }
    return true;
}
