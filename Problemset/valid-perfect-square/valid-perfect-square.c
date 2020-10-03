
// @Title: 有效的完全平方数 (Valid Perfect Square)
// @Author: opfanswyx@outlook.com
// @Date: 2018-10-22 19:42:26
// @Runtime: 0 ms
// @Memory: N/A

bool isPerfectSquare(int num) {
    unsigned long left =1,middle = num/2,right = num;
    if(num<2) return true;
    while(1)
    {
        if(middle*middle>num)
        {
	   if((middle-1)*(middle-1)<num) return false;
            right = middle;
            middle = (left +right)/2;
        }else if(middle*middle <num){
            if((middle+1)*(middle+1)>num) return false;
            left = middle;
            middle = (left+right)/2;
        }else{
            return true;
        }
       
    }
}
