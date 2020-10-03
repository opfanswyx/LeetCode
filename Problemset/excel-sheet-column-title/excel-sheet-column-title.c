
// @Title: Excel表列名称 (Excel Sheet Column Title)
// @Author: opfanswyx@outlook.com
// @Date: 2018-10-11 20:19:10
// @Runtime: 0 ms
// @Memory: N/A

char* convertToTitle(int n) {
    char* result1 = (char*)malloc(sizeof(char)*10);
    char* result2 = (char*)malloc(sizeof(char)*10);
    int i = 0, j = 0;
    while(n>0){
        if((n % 26) != 0){
            result1[i++] = (n % 26) + 64;
            n = n / 26;
        }  
        else{
            result1[i++] = 90;  
            n = n / 26 -1; 
        }   
    }
    result1[i]='\0';
    for(i=strlen(result1)-1;i>=0;i--){
        result2[i] = result1[j++];
    }
    return result2;   
}
