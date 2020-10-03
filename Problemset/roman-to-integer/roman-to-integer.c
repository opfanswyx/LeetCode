
// @Title: 罗马数字转整数 (Roman to Integer)
// @Author: opfanswyx@outlook.com
// @Date: 2018-09-19 22:43:16
// @Runtime: 40 ms
// @Memory: N/A

int romanToInt(char* s) {
    int res = 0;
        while(*s!='\0')
        {
            switch(*s)
            {
                case 'M':
                    res += 1000;
                    s++;
                    break;
                case 'D':
                    res += 500;
                    s++;
                    break;
                case 'C':
                    (*(s+1)=='D'||*(s+1)=='M')?(res-=100):(res+=100);
                    s++;
                    break;
                case 'L':
                    res += 50;
                    s++;
                    break;
                case 'X':
                    (*(s+1)=='L'||*(s+1)=='C')?(res-=10):(res+=10);
                    s++;
                    break;
                case 'V':
                    res += 5;
                    s++;
                    break;
                case 'I':
                    (*(s+1)=='I'||*(s+1)==0)?(res++):(res--);
                    s++;
                    break;
            }
            
        }
    return res;
    
}
