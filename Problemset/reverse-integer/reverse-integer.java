
// @Title: 整数反转 (Reverse Integer)
// @Author: opfanswyx@outlook.com
// @Date: 2018-09-17 16:51:18
// @Runtime: 22 ms
// @Memory: N/A

class Solution {
    public int reverse(int x)
    {
        int result = 0;

        while (x != 0)
        {
            int tail = x % 10;
            int newResult = result * 10 + tail;
            if ((newResult - tail) / 10 != result)
            { return 0; }
            result = newResult;
            x = x / 10;
        }

        return result;
    }
}
