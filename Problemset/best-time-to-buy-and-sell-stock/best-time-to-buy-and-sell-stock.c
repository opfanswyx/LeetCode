
// @Title: 买卖股票的最佳时机 (Best Time to Buy and Sell Stock)
// @Author: opfanswyx@outlook.com
// @Date: 2018-05-03 11:30:00
// @Runtime: 0 ms
// @Memory: N/A

int maxProfit(int* prices, int pricesSize) {
    int res=0;
    int curmin = prices[0];
    
    if(pricesSize <= 1)
    {
        return res; 
    }
    
    for(int i = 0; i < pricesSize; i++)  
    {
        if(curmin > prices[i])
        {
            curmin = prices[i];
        }
        if(res < (prices[i]-curmin))
        {
            res = (prices[i]-curmin);
        }
    }//只要大于前者就是收益  
    return res; 
}
