
// @Title: 字符串转换整数 (atoi) (String to Integer (atoi))
// @Author: opfanswyx@outlook.com
// @Date: 2018-10-23 10:57:56
// @Runtime: 12 ms
// @Memory: N/A

int myAtoi(char* str) {
    
    int len = strlen(str);
    
    int i =0;
    int cs = 0;
    int ce = 0;
    while(i<len){
        
        if (str[i] != ' '){            
            if ((str[i]=='+' | str[i]=='-') | (str[i]>=48 & str[i]<=57))     
                break;
            else
                return 0;            
        }
        
        i++;
    }
    
    cs = i;
    
    bool flag = false;
    if (str[cs]=='+' | str[cs]=='-'){
        if (str[cs]=='-')
            flag = true;
        cs++;
    }
    
    for(i=cs; i<len; i++){
        if (str[i]<48 | str[i]>57)
            break;
    }
    
    ce = i;
        
    long long ans = 0;

    if (flag == true){
        for (i=cs;i<ce;i++){
            ans = ans*10 - (str[i]-'0');
            if (ans <= INT_MIN)
                return INT_MIN;
            else if (ans >= INT_MAX)
                return INT_MAX;
        }
    }
    else{
        for (i=cs; i<ce; i++){
            ans = ans*10 + (str[i]-'0');
            if (ans <= INT_MIN)
                return INT_MIN;
            else if (ans >= INT_MAX)
                return INT_MAX;
        }        
    }
                
    
    return ans;
}
#if 0
#define ATOINT(x) ((x) - 48)
#define MAX_INT   0x7FFFFFFF
#define MIN_INT   0x80000000

int myAtoi(char* str)
{
    char *s = str;
    char sign = '+';
    int val = 0;
    long long tval = 0;

    /* Maintain sanity */
    if (!s)
        return 0;

    /* Ignore white space */
    while (*s == ' ')
        ++s;

    /* Account for the sign */
    sign = (*s == '-') || (*s == '+') ?  *s++ : '+';

    /* Loop creating the integer while the character is valid and
       the value is within the bounds */
    while ((*s >= 48 && *s <= 57) && (tval < MAX_INT))
    {
        tval *= 10;
        tval += ATOINT(*s);
        ++s;
    }

    /* Handle any possible overflow/underflow */
    if (tval > MAX_INT)
        val = (sign == '+') ? MAX_INT : MIN_INT;
    else
    {
        val = tval;
        val = (sign == '-') ? -val : val;
    }

    /* Return the integer */
    return val;
}
#endif
