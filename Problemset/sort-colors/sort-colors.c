
// @Title: 颜色分类 (Sort Colors)
// @Author: opfanswyx@outlook.com
// @Date: 2018-11-05 10:02:17
// @Runtime: 0 ms
// @Memory: N/A

void
sortColors(int *nums, int numsSize)
{
	int i, j;
	
	for (i = j = 0; j < numsSize;)
		switch (nums[j]) {
			case 2:
				nums[j] = nums[--numsSize];
				nums[numsSize] = 2;
				break;
			case 0:
				nums[j] = nums[i];
				nums[i++] = 0;
				/* FALLTHROUGH */
			default:
				++j;
		}
}
