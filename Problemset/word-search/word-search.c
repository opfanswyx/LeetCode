
// @Title: 单词搜索 (Word Search)
// @Author: opfanswyx@outlook.com
// @Date: 2018-11-06 10:43:03
// @Runtime: 8 ms
// @Memory: N/A

int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int ptr = 0;
bool dfs(int x,int y,char **board,const int row,const int col, const char * word)
{
if(!word[ptr]) return true;
if(x < 0 || y < 0 || x >= row || y >= col || board[x][y]!=word[ptr])
    return false;
ptr++;
board[x][y] |= 128;
bool ret = false;
for(int i = 0; i < 4; i++)
{
    ret = dfs(x+dx[i],y+dy[i],board,row,col,word);
    if(ret) break;
}
board[x][y] ^= 128;
ptr--;
return ret;
}

bool exist(char** board, int row, int col, char* word) {
for(int i = 0; i < row; i++)
    for(int j = 0; j < col; j++)
        if(dfs(i,j,board,row,col,word))
                return true;
return false;
}
