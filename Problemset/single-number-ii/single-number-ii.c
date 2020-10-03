
// @Title: 只出现一次的数字 II (Single Number II)
// @Author: opfanswyx@outlook.com
// @Date: 2018-11-16 11:59:46
// @Runtime: 0 ms
// @Memory: N/A

int singleNumber(int* nums, int numsSize) {

int ones = 0, twos = 0, threes;
int i;

for (i = 0; i < numsSize; i++)
{
    twos |= (ones & nums[i]);
			
    ones ^= nums[i];
    
    threes = (twos & ones);
    
    if(threes != 0)
    {
        ones ^= threes;
        twos ^= threes;
    }
}

return ones;
}
#if 0
int singleNumber(int* nums, int numsSize) {
    int array[32]={0};
    int ret=0;
    for(int i=0;i<numsSize;i++){
        for(int j=0;j<32;j++){
            if(nums[i]==0){
                break;
            }
            if(nums[i]%2<0){
                array[j]-=nums[i]%2;
            }else{
                array[j]+=nums[i]%2;
            }
            
            nums[i]>>=1;
        }
    }
    for(int i=31;i>=0;i--){
        array[i]%=3;
        ret=ret<<1;
        if(array[i]!=0){
           ret=ret+1;
        }
    }
    return ret;
}
#endif
