
// @Title: 解码方法 (Decode Ways)
// @Author: opfanswyx@outlook.com
// @Date: 2018-11-09 11:17:19
// @Runtime: 0 ms
// @Memory: N/A

int numDecodings(char* s) {
  if(s[0] == 48) return 0;
  int len = strlen(s);
  int* dp = calloc(len, sizeof(int));
  dp[0] = 1;
  for(int i = 1; i < len; i++) {
    if(s[i] >= 49) dp[i] = dp[i - 1]; // If the current digit is not '0', add dp[i - 1]
    if(s[i - 1] == 49 || (s[i - 1] == 50 && s[i] <= 54)) dp[i] += i >= 2 ? dp[i - 2] : 1;
    // If the previous digit is 1 or 2, and in the second case the current digit
    // is less than or equal to 6, add dp[i - 2]
  }
  return dp[len - 1];
}
