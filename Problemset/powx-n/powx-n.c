
// @Title: Pow(x, n) (Pow(x, n))
// @Author: opfanswyx@outlook.com
// @Date: 2018-10-30 11:50:32
// @Runtime: 4 ms
// @Memory: N/A

double myPow(double x, int n) {
	if (n == 0 || x == 1) return 1;
	if (x == 0) return 0;
	if (n == INT_MIN) return myPow(x*x, INT_MIN / 2);
	if (n < 0) return 1 / myPow(x, -n);
	if (x < 0 && n % 2 == 0) return myPow(-x, n);
	if (x < 0 && n % 2 != 0) return -myPow(-x, n);
	int s = n;
	double res = 1, tmp = x;
	while (s / 2)
	{
		if (s % 2)
			res = res*tmp;		
		tmp = tmp*tmp;
		s = s / 2;
	}
	if (s % 2)
		res = res*tmp;
	return res;
}
