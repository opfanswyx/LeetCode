
// @Title: 复原IP地址 (Restore IP Addresses)
// @Author: opfanswyx@outlook.com
// @Date: 2018-11-10 16:11:52
// @Runtime: 0 ms
// @Memory: N/A

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define INRANGE(c, m, n) ((c) >= (m) && c <= (n))

char** restoreIpAddresses(char* s, int* returnSize);
char* getAddr(char* s, int l, int a, int b, int c);
int isValidPart(char* s, int l);

/**
 * Loop through all combinations of 3 dot positions and check if each part is
 * valid IP address part
 */
char** restoreIpAddresses(char* s, int* returnSize)
{
    *returnSize = 0;

    int l = strlen(s);
    if (l < 4 || l > 12) return NULL;

    char** addrs = malloc(sizeof(char*) * ((l-1) * (l-2) * (l-3) / 6));
    char* addr;

    int a, b, c;

    for (a = 1; a < 4; a++) {
        if (a > l - 3 || a < l - 9) continue;
        for (b = a + 1; b < a + 4; b++) {
            if (b > l - 2 || b < l - 6) continue;
            for (c = b + 1; c < b + 4; c++) {
                if (c > l - 1 || c < l - 3) continue;
                if (addr = getAddr(s, l, a, b, c))
                    addrs[(*returnSize)++] = addr;
            }
        }
    }

    return addrs;
}

char* getAddr(char* s, int l, int a, int b, int c)
{
    if (isValidPart(s, a) &&
        isValidPart(s+a, b-a) &&
        isValidPart(s+b, c-b) &&
        isValidPart(s+c, l-c))
    {
        char* addr = malloc(sizeof(char) * (l + 4));
        memcpy(addr, s, a);
        memcpy(addr+a+1, s+a, b-a);
        memcpy(addr+b+2, s+b, c-b);
        memcpy(addr+c+3, s+c, l-c);
        addr[a] = addr[b+1] = addr[c+2] = '.';
        addr[l+3] = '\0';
        return addr;
    } else
        return NULL;
}

int isValidPart(char* s, int l)
{
    if (l == 1)
        return INRANGE(s[0], '0', '9');
    else if (l == 2)
        return INRANGE(s[0], '1', '9') && INRANGE(s[1], '0', '9');
    else if (l == 3)
        return (s[0] == '1' && INRANGE(s[1], '0', '9') && INRANGE(s[2], '0', '9')) ||
               (s[0] == '2' && (
                   INRANGE(s[1], '0', '4') && INRANGE(s[2], '0', '9') ||
                   s[1] == '5' && INRANGE(s[2], '0', '5')
               ));
    else return 0;
}
