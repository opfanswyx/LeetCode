
// @Title: 简化路径 (Simplify Path)
// @Author: opfanswyx@outlook.com
// @Date: 2018-11-05 09:41:47
// @Runtime: 4 ms
// @Memory: N/A

// note that "/.../" is also considered as a valid path name
char* simplifyPath(char* path) {
    char *stack[1024] = {0}; // a simple stack
    int bottom = -1;

    int len = strlen(path);
    int i = 0;
    while (i < len) {
        if (path[i] != '/') {
            if (i + 1 < len && path[i] == '.' && path[i+1] == '.' && (path[i+2] == '\0' || path[i+2] == '/')) {
                // we have found a '..\0' or '../'
                if (bottom >= 0) {
                    printf("pop stack [%s]\n", stack[bottom]);
                    free(stack[bottom]);
                    bottom--;
                } else {
                    printf("already the / path\n");
                }
                i += 2;
            } else if (path[i] == '.' && (path[i+1] == '\0' || path[i+1] == '/')) {
                // we have found a '.\0' or './'
                // do nothing
                i += 1;
            } else {
                // '/' is followed by a normal string
                // we try to find a next '/' or '\0'
                int start = i;
                while (path[i] != '\0' && path[i] != '/') {
                    i++;
                }
                // now between [start, i) is a valid path string name
                // stack it
                char *tmp = (char *)malloc(sizeof(char) * (i - start + 1));
                memset(tmp, 0, sizeof(char) * (i - start + 1));
                memcpy(tmp, &path[start], i - start);
                bottom += 1;
                stack[bottom] = tmp;                    
                printf("push stack [%s] @%d\n", tmp, bottom);
            }
        } else {
            // keep moving forward, then we ignored any redundant '/'
            i += 1;
        }
    }
    
    printf("parse finish, bottom @%d\n", bottom);
    
    // now output the result
    char *ret = (char *)malloc(sizeof(char) * (len+1));
    memset(ret, 0, sizeof(char) * (len+1));
    
    ret[0] = '/'; // default, in case we have nothing in the stack
    int index = 0;
    i = 0;
    while (i <= bottom) {
        ret[index] = '/';
        index++;
        printf("[%s] to be add to result, bottom = %d\n", stack[i], bottom);
        int copy_len = strlen(stack[i]);
        memcpy(&ret[index], stack[i], copy_len);
        free(stack[i]);
        i++;
        index += copy_len;
    }
    return ret;
}
