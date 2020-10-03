
// @Title: 计数质数 (Count Primes)
// @Author: opfanswyx@outlook.com
// @Date: 2018-10-13 12:46:18
// @Runtime: 12 ms
// @Memory: N/A

int countPrimes(int n){
    if(n<=2)
        return 0;
    unsigned  count = n - 1; 
    
    bool *isPrime=malloc(sizeof(bool)*(n+1));
    memset(isPrime, true, sizeof(bool)*(n+1));
    
    for (int i = 2; i*i <= n; i++)
    {
        if (isPrime[i])
        {
            int j = i*i;
            while (j < n)
            {
                if (isPrime[j])     //只有没被去除，才做去除操作。避免重复统计
                {
                    isPrime[j] = false;
                    count--;           //减少1个
                }
                j += i;
            }
        }
    }
    
    return count;
}

#if 0
int countPrimes(int n){
    if(n<=2)
        return 0;
    
    bool *isPrime=malloc(sizeof(bool)*n);
    memset(isPrime, true, n);
    
    int primeCount = 1;
    
    for(int i=3; i<n; i+=2){
        if(isPrime[i]){
            primeCount++;
            for(int j=i;j<n;j+=i){
                isPrime[j]=false;
            }
        }
    }
     return primeCount;
}
#endif
#if 0
bool isPrime(int x)
{
    for(int i=2;i*i<=x;++i)
    {
        if(x%i==0)
            return false;
    }
    return true;
}
int countPrimes(int n) {
    int res=0;
    
    if(n<=2)
        return 0;
    
    for(int i=2;i<n;i++)
    {
        if(isPrime(i))
            ++res;
    }
    return res;
}
#endif
