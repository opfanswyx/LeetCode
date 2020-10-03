
// @Title: 买卖股票的最佳时机 III (Best Time to Buy and Sell Stock III)
// @Author: opfanswyx@outlook.com
// @Date: 2018-05-03 15:40:26
// @Runtime: 4 ms
// @Memory: N/A

int maxProfit(int* prices, int pricesSize) {
    int res=0;
    
    if(pricesSize <= 1)
    {
        return res;
    }
    
    //分前后两段  
    int *pre = NULL;  
    int *aft = NULL;  
    pre = (int *)malloc(sizeof(int)*pricesSize);
    aft = (int *)malloc(sizeof(int)*pricesSize);
    //pre iterator  
    int curmin=prices[0];
    for(int i=1;i<pricesSize;i++)
    {  
        if(curmin>prices[i])
            curmin=prices[i];  
        pre[i]=max(prices[i]-curmin,pre[i-1]);  
    }  
    //after   
    int curmax=prices[pricesSize-1];  
    for(int i=pricesSize-2;i>=0;i--)
    {  
        if(curmax<prices[i])
            curmax=prices[i];  
        aft[i]=min(prices[i]-curmax,aft[i+1]);//负数  
    }  
    //merge  
    for(int i=0;i<pricesSize;i++)
    {
        if(res<pre[i]-aft[i])
            res=pre[i]-aft[i];//负数，所以减去aft
    }
    /*
    free(pre);
    pre = NULL;
    free(aft);
    aft = NULL;
    */
    return res;  
}
int min(int a, int b)
{
    if(a < b)
    {
        return a;
    }
    else
    {
        return b;
    }
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
