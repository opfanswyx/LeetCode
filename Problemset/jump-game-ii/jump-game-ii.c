
// @Title: 跳跃游戏 II (Jump Game II)
// @Author: opfanswyx@outlook.com
// @Date: 2018-05-03 14:11:46
// @Runtime: 4 ms
// @Memory: N/A

int jump(int* nums, int numsSize) {
    int reach=0;//全局最远可达位置  
    int last=0;//上一步最远能到达位置  
    int step=0;//i需要超过上一步最远位置时加1  
    for(int i=0;i<=reach&&i<numsSize;i++)  
    {  
        if(i>last){step++;last=reach;}  
        reach=max(reach,nums[i]+i);  
    }  
    return reach>=(numsSize-1)?step:0;   
}
int max(int a, int b)
{
    if(a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
}
