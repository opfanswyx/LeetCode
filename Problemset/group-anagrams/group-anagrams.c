
// @Title: 字母异位词分组 (Group Anagrams)
// @Author: opfanswyx@outlook.com
// @Date: 2018-10-30 11:42:15
// @Runtime: 16 ms
// @Memory: N/A

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int analog(char* s1, char* s2)
{
	int len1 = strlen(s1), len2 = strlen(s2);
	if (len1 == 0 && len2 == 0) return 1;
	if (len1 == 0 || len2 == 0 || len1 != len2) return 0;
	char* s = (char*)malloc(sizeof(char)*len2);
	for (int i = 0;i < len2;i++)
		s[i] = s2[i];
	for (int i = 0;i < len1;i++)
	{
		for (int j = i;j<len2;j++)
		{
			if (s1[i] == s[j]) { s[j] = s[i];break; }
			if (j==len2-1)
			{
				free(s);
				return 0;
			}
		}
	}
	free(s);
	return 1;
}

char*** groupAnagrams(char** strs, int strsSize, int** columnSizes, int* returnSize) {
	columnSizes[0] = (int*)malloc(sizeof(int)*strsSize);
	char*** res = (char***)malloc(sizeof(char**)*strsSize);
	for (int i = 0;i < strsSize;i++)
	{
		columnSizes[0][i] = 1;
		res[i] = (char**)malloc(sizeof(char*)*columnSizes[0][i]);
	}
	int k = 0;
	int** map = (int**)malloc(sizeof(int*)*strsSize);
	for (int i = 0;i < strsSize;i++)
	{
		map[i] = (int*)malloc(sizeof(int) * 1);
		map[i][0] = 0;
	}
	int tmp;
	for (int i = 0;i < strsSize;i++)
	{
		tmp = 0;
		for (int j = 0;strs[i][j] != '\0';j++)
			tmp += strs[i][j]*strs[i][j];
		tmp = tmp%strsSize;
		if (map[tmp][0] == 0) {
			map[tmp][0] = 1;
			map[tmp] = (int*)realloc(map[tmp], sizeof(int) * 3);
			map[tmp][1] = i;
			map[tmp][2] = k;
			res[k][0] = (char*)malloc(sizeof(char)*(strlen(strs[i]) + 1));
			res[k][0] = strs[i];
			k++;
		}
		else
		{
			for (int m = 1;m <= map[tmp][0];m++)
			{
				int sindex = map[tmp][2 * m - 1];
				int rindex = map[tmp][2 * m];
				if (analog(strs[i], strs[sindex]))
				{
					columnSizes[0][rindex]++;
					res[rindex] = (char**)realloc(res[rindex], sizeof(char*)*columnSizes[0][rindex]);
					res[rindex][columnSizes[0][rindex] - 1] = (char*)malloc(sizeof(char)*(strlen(strs[i]) + 1));
					res[rindex][columnSizes[0][rindex] - 1] = strs[i];
					break;
				}
				if (m == map[tmp][0])
				{
					map[tmp][0] ++;
					map[tmp] = (int*)realloc(map[tmp], sizeof(int) * (2*map[tmp][0]+1));
					map[tmp][2 * map[tmp][0] - 1] = i;
					map[tmp][2 * map[tmp][0]] = k;
					res[k][0] = (char*)malloc(sizeof(char)*(strlen(strs[i]) + 1));
					res[k][0] = strs[i];
					k++;
					break;
				}
			}
		}
	}
	*returnSize = k;
	return res;
}
#if 0
#define KEYLEN 128
typedef struct {
    char key[KEYLEN];
    int listSize;
    char **list;
    UT_hash_handle hh;
} Map;

int cmpFunc(const void *a, const void *b) { return *(char *)a - *(char *)b; }

char*** groupAnagrams(char** strs, int strsSize, int** columnSizes, int* returnSize) {
    Map *map = NULL, *elem = NULL, *tmp;
    char strBuf[KEYLEN], ***result;
    int mapIndx = 0;
    if (strsSize <= 0) return NULL;
    for (int i = 0; i < strsSize; i++) {
        strncpy(strBuf, strs[i], KEYLEN);
        qsort(strBuf, strlen(strs[i]), sizeof(char), cmpFunc);
        HASH_FIND_STR(map, strBuf, elem);
        if (!elem) {
            elem = malloc(sizeof(Map));
            strncpy(elem->key, strBuf, KEYLEN);
            elem->listSize = 1;
            elem->list = malloc(sizeof(char **));
            elem->list[0] = strs[i];
            HASH_ADD_STR(map, key, elem);
        } else {
            elem->listSize++;
            elem->list = realloc(elem->list, elem->listSize * sizeof(char **));
            elem->list[elem->listSize - 1] = strs[i];
        }
    }
    *returnSize = HASH_COUNT(map);
    result = malloc(*returnSize * sizeof(char **));
    *columnSizes = malloc(*returnSize * sizeof(int));
    HASH_ITER(hh, map, elem, tmp) {
        (*columnSizes)[mapIndx] = elem->listSize;
        result[mapIndx++] = elem->list;
    }
    return result;
}
#endif
