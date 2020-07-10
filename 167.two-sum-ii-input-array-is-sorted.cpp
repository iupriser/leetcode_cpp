/*
 * @lc app=leetcode id=167 lang=cpp
 *
 * [167] Two Sum II - Input array is sorted
 */

// @lc code=start
class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        int n = numbers.size();
        if (n < 2)
        {
            return {};
        }

        int start = 0, end = n - 1;
        while (start < end)
        {
            int sum = numbers[start] + numbers[end];
            if (sum < target)
            {
                start++;
            }
            else if (sum > target)
            {
                end--;
            }
            else
            {
                start += 1;
                end += 1;
                return {start, end};
            }
        }
        return {};
    }
};
// @lc code=end
