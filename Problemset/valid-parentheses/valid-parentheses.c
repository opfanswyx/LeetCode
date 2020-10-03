
// @Title: 有效的括号 (Valid Parentheses)
// @Author: opfanswyx@outlook.com
// @Date: 2018-09-21 22:25:20
// @Runtime: 0 ms
// @Memory: N/A

bool isValid(char* s) {
    int slen = 0;
    int idx = 0;
    slen = strlen(s);
    char *stack = (char *)malloc(sizeof(char)*slen);
    
    for(;*s != '\0'; ++s)
    {
        switch(*s)
        {
            case '(':
            case '[':
            case '{':
                stack[idx++] = *s;
                break;
            case ')':
                if(idx == 0)
                    return false;
                if(stack[--idx]!='(')
                    return false;
                break;
            case ']':
                if(idx == 0)
                    return false;
                if(stack[--idx]!='[')
                    return false;
                break;
            case '}':
                if(idx == 0)
                    return false;
                if(stack[--idx]!='{')
                    return false;
                break;
        }
    }
    free(stack);
    return idx == 0;
}
