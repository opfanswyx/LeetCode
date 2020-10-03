
// @Title: 赎金信 (Ransom Note)
// @Author: opfanswyx@outlook.com
// @Date: 2018-11-16 14:06:41
// @Runtime: 4 ms
// @Memory: N/A

void GetAlphbetFreq(char *p, int *t){
    while(*p != '\0'){
        t[*p - 'a']++;
        p++;
    }
    return;
}
bool canConstruct(char* ransomNote, char* magazine) {
    int NoteFreq[26] = {0};
    int MagFreq[26] = {0};
    GetAlphbetFreq(ransomNote, NoteFreq);
    GetAlphbetFreq(magazine, MagFreq);
    for(int i = 0; i < 26; i++){
        if(NoteFreq[i] > MagFreq[i]) return false;
    }
    return true;
}
