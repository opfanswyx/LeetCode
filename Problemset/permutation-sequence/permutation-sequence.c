
// @Title: 第k个排列 (Permutation Sequence)
// @Author: opfanswyx@outlook.com
// @Date: 2018-11-01 11:31:38
// @Runtime: 4 ms
// @Memory: N/A

char* getPermutation(int n, int k) {
    int *total_count = (int *) malloc(sizeof(int) * (n + 1));
    char *answer = (char *) malloc(sizeof(char) * (n + 1));
    bool *used = (bool *) malloc(sizeof(bool) * n);
    int i, j, index, temp_count;
       
    total_count[n] = 1;
    total_count[n - 1] = 1;
    for(i = n - 1 ; i >= 0 ; i --){
        if(i != n - 1)
            total_count[i] = total_count[i + 1] * (n - i);
        
        used[i] = false;
    }
    
    k --;
    for(i = 0 ; i < n ; i ++){
        index = k / total_count[i + 1] + 1;
        k %= total_count[i + 1];
        
        temp_count = 0;
        for(j = 0 ; j < n ; j ++){
            if(used[j] == false)
                temp_count ++;
            
            if(temp_count == index){
                answer[i] = j + 1 + '0';
                used[j] = true;
                break;
            }
        }
    }
    
    answer[n] = '\0';
    
    return answer;
}
