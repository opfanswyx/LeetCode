
// @Title: x 的平方根 (Sqrt(x))
// @Author: opfanswyx@outlook.com
// @Date: 2018-09-25 22:34:48
// @Runtime: 12 ms
// @Memory: N/A

int mySqrt(int x) {
    if(x == 0)
         return 0;
     long low = 1;
     long high = x;
     long mid;
     while (low < high) {
         mid = (low + high) / 2;
         if (mid == low)
             return mid;
         if (mid * mid > x)
             high = mid;
         else if (mid * mid < x)
             low = mid;
         else
             return mid;
     }

     return low;
}
