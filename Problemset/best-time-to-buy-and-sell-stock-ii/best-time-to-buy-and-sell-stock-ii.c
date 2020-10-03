
// @Title: 买卖股票的最佳时机 II (Best Time to Buy and Sell Stock II)
// @Author: opfanswyx@outlook.com
// @Date: 2018-05-03 12:01:01
// @Runtime: 0 ms
// @Memory: N/A

int maxProfit(int* prices, int pricesSize) {
    int res = 0;
    
    if(pricesSize <= 1)
        return res;
    
    for(int i = 0; i < pricesSize;)
    {  
        int j=i;  
        while(j+1 < pricesSize && prices[j+1] > prices[j])
        {
            j++;
        }
        /*
        if(j == i)
        {
            i++;
        }//一开始就不增加  
        else
        {
        */
            res+=prices[j]-prices[i];
            i=j+1;
        //}//增加若干  
    }  
    return res;  
}  

