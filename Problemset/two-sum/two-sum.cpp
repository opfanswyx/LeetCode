
// @Title: 两数之和 (Two Sum)
// @Author: opfanswyx@outlook.com
// @Date: 2019-12-30 18:37:24
// @Runtime: 12 ms
// @Memory: 9.8 MB

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // 使用哈希表存储数组中的数值，key为数组中的数值，value为数组中数值对应下标 
        unordered_map<int, int> hash;
        vector<int> result;
        for (int i = 0; i < nums.size(); i++) 
        {
            int numberToFind = target - nums[i];
    
            // 查找，若找到，则返回下标
            if (hash.find(numberToFind) != hash.end()) 
            {
                result.push_back(hash[numberToFind]);
                result.push_back(i);            
                return result;
            }
    
            //若没有找到，则将该值加入哈希表
            hash[nums[i]] = i;
        }
        return result;
    }
};

