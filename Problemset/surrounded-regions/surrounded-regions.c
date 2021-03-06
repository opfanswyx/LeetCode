
// @Title: 被围绕的区域 (Surrounded Regions)
// @Author: opfanswyx@outlook.com
// @Date: 2018-11-16 11:43:30
// @Runtime: 12 ms
// @Memory: N/A

int stck[655350],top;
void dfs(int x,int y,char ** board,const int row,const int col,const char tag)
{
top = 0;
stck[top++] = x; stck[top++] = y;
while(top)
{
    y = stck[--top]; x = stck[--top];
    if(x < 0 || y < 0 || x >= row || y >= col || board[x][y] != 'O')
        continue;
    board[x][y] = tag;
    stck[top++] = x; stck[top++] = y - 1;
    stck[top++] = x; stck[top++] = y + 1;
    stck[top++] = x - 1; stck[top++] = y;
    stck[top++] = x + 1; stck[top++] = y;
}
}
void solve(char** board, int row, int col) {
for(int i = 0; i < row; i++)
    dfs(i,0,board,row,col,'#'),dfs(i,col-1,board,row,col,'#');
for(int j = 0; j < col; j++)
    dfs(0,j,board,row,col,'#'),dfs(row-1,j,board,row,col,'#');
for(int i = 1; i < row - 1; i++)
    for(int j = 1; j < col - 1; j++)
        dfs(i,j,board,row,col,'X');
for(int i = 0; i < row; i++)
    for(int j = 0; j < col; j++)
        if(board[i][j] == '#')
            board[i][j] = 'O';
 }
