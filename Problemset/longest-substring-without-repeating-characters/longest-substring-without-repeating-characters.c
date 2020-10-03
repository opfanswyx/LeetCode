
// @Title: 无重复字符的最长子串 (Longest Substring Without Repeating Characters)
// @Author: opfanswyx@outlook.com
// @Date: 2018-02-19 23:27:07
// @Runtime: 12 ms
// @Memory: N/A

int lengthOfLongestSubstring(char* s) {
  int len=0;
    char *end=s,*temp;
    //ascii 有128个
    //含有128个字符型指针的数组，并初始化各位为null
	char* addressTable[128]={NULL}; 
	while(*end){
		temp = addressTable[*end]; //temp赋值位该位置的指针(一般为null,遇到相同的字符后有值)
		addressTable[*end]=end; //字符串的第一个字符为为指针数组的标识位
		if(temp>=s){
        //end-s为一个无重复字符的子字符串长度
		len=end-s>len?end-s:len;
        //下一个不重复字符开始
		s = temp+1;
		}end++;
	}
	len=end-s>len?end-s:len;
	return len;  
}
