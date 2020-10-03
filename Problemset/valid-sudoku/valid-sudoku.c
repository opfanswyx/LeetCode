
// @Title: 有效的数独 (Valid Sudoku)
// @Author: opfanswyx@outlook.com
// @Date: 2018-10-29 10:36:16
// @Runtime: 8 ms
// @Memory: N/A

void initNums(int *nums, int numsSize){
    for(int i=0;i<numsSize;i++){
        nums[i]=0;
    }
}
bool isValidSudoku(char** board, int boardRowSize, int boardColSize) {
    int *rows = (int *)malloc(sizeof(int) * 9);
    int *cols = (int *)malloc(sizeof(int) * 9);
    int *boxs = (int *)malloc(sizeof(int) * 9);
    initNums(rows, 9);
    initNums(cols, 9);
    initNums(boxs, 9);
    for(int i=0;i<boardRowSize;i++){
        for(int j=0;j<boardColSize;j++){
            if(board[i][j]<='9'&&board[i][j]>='1')
                rows[board[i][j]-'1']++;
            if(board[j][i]>='1'&&board[j][i]<='9')
                cols[board[j][i]-'1']++;
            
            if(i%3==0&&j%3==0){
                for(int m=0;m<3;m++){
                    for(int n=0;n<3;n++){
                        if(board[i+m][j+n]<='9'&&board[i+m][j+n]>='1')
                            boxs[board[i+m][j+n]-'1']++;
                    }
                }
                for(int k=0;k<9;k++)
                if(boxs[k]>1)
                    return false;
                initNums(boxs, 9);
            }
        }
        for(int k=0;k<9;k++)
            if(cols[k]>1||rows[k]>1)
                return false;
        initNums(rows, 9);
        initNums(cols, 9);
    }
        
    return true;
}
#if 0
bool isValidSudoku( char** board, int boardRowSize, int boardColSize ) {
    for (int i = 0; i < 9; i++) {
        int row = 0, column = 0, block = 0;
        for (int j = 0; j < 9; j++) {
            if (board[i][j] != '.') {
                int num = 1 << (board[i][j] - '0');
                if (num & row) return false;
                row |= num;
            }

            if (board[j][i] != '.') {
                int num = 1 << (board[j][i] - '0');
                if (num & column) return false;
                column |= num;
            }

            int x = i / 3 * 3 + j / 3;
            int y = i % 3 * 3 + j % 3;
            if (board[x][y] != '.') {
                int num = 1 << (board[x][y] - '0');
                if (num & block) return false;
                block |= num;
            }
        }
    }
    return true;
}
#endif
