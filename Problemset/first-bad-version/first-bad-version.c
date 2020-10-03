
// @Title: 第一个错误的版本 (First Bad Version)
// @Author: opfanswyx@outlook.com
// @Date: 2018-10-18 14:27:09
// @Runtime: 0 ms
// @Memory: N/A

// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

int firstBadVersion(int n) {
    int lo = 1, hi = n, mid;
    while (lo < hi) {
        mid = lo + ((hi - lo) >> 1);
        isBadVersion(mid) ? (hi = mid) : (lo = mid + 1);
    }
    return hi;
}

