/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

// @lc code=start
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> indices;
        for (int i = 0; i < nums.size(); i++)
        {
            int complement = target - nums[i];
            if (indices.find(complement) != indices.end())
            {
                return {i, indices[complement]};
            }
            indices[nums[i]] = i;
        }
        return {};
    }
};
// @lc code=end
