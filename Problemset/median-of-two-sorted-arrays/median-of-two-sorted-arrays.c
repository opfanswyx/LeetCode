
// @Title: 寻找两个正序数组的中位数 (Median of Two Sorted Arrays)
// @Author: opfanswyx@outlook.com
// @Date: 2018-11-16 12:01:46
// @Runtime: 24 ms
// @Memory: N/A

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int* p=nums1;
    int* q=nums2;
    int b=nums1Size+nums2Size;
    double a[b];
    memset(a,0.0,sizeof(a));
    double x=0;
    int y=0;
    int z=0;
    for(int i=0; i<b; i++) {
        if( *p <= *q ) {
            if (y<nums1Size) {
                a[i] = *p;
                p++;
                y++;
            }else {
                a[i] = *q;
                q++;
                z++;
            }

        }else if( *p > *q){
            if (z<nums2Size) {
                a[i] = *q;
                q++;
                z++;
            } else {
                a[i] = *p;
                p++;
                y++;
            }
        }
    }
    if (b%2 == 0) {
        x = (a[b/2-1] +a[b/2])/2;
    } else {
        x =  a[(b-1)/2];
    }
    return x;
}
