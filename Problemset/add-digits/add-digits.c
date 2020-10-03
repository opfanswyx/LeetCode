
// @Title: 各位相加 (Add Digits)
// @Author: opfanswyx@outlook.com
// @Date: 2018-10-17 15:46:18
// @Runtime: 4 ms
// @Memory: N/A

int addDigits(int num) {
    int temp=0;
    while(num){
        temp+=num%10;
        num=num/10;
        if(num==0&&temp<10)
            return temp;
        if(num==0){
            num=temp;
            temp=0;

        }
    }
    return 0;
}
