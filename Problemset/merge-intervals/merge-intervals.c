
// @Title: 合并区间 (Merge Intervals)
// @Author: opfanswyx@outlook.com
// @Date: 2018-11-01 10:08:21
// @Runtime: 4 ms
// @Memory: N/A

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 * };
 */
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
typedef struct Interval pair;

int comparator(const void* v1, const void* v2) {
  pair* p1 = (pair*) v1;
  pair* p2 = (pair*) v2;
  return (p1 -> start) - (p2 -> start);
}

int max(int n, int m) {
  return n > m ? n : m;
}

pair* merge(pair* pairs, int size, int* returnSize) {
  if(size == 0) {
    *returnSize = 0;
    return NULL;
  }
  qsort((void*) pairs, size, sizeof(pair), comparator);
  int curr = 0;
  for(int i = 1; i < size; i++) {
    if(pairs[curr].end >= pairs[i].start) pairs[curr].end = max(pairs[curr].end, pairs[i].end);
    else {
      curr++;
      pairs[curr] = pairs[i];
    }
  }
  *returnSize = curr + 1;
  return pairs;
}
