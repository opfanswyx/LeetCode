
// @Title: 丑数 (Ugly Number)
// @Author: opfanswyx@outlook.com
// @Date: 2018-10-18 11:54:43
// @Runtime: 4 ms
// @Memory: N/A

bool isUgly(int num) {
    if(num==0)
        return false;
    int data[3]={2,3,5};
    while(num!=1)
    {
        for(int i=0;i<3;i++)
        {
            if(num%data[i]==0)
            {
                num/=data[i];
                break;
            }
            else if(i==2)
                return false;
        }
    }
    if(num==1)
        return true;
    else 
        return false;
}
