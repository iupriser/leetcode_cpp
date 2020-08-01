/*
 * @lc app=leetcode id=153 lang=cpp
 *
 * [153] Find Minimum in Rotated Sorted Array
 */

// @lc code=start
class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        int l = 0;
        int h = nums.size() - 1;
        int pivot = 0;
        if (nums.at(l) < nums.at(h) || l == h) //not rotated or have single element
        {
            return nums.at(l);
        }
        while (l <= h)
        {
            int m = (l + h) / 2;
            if (nums.at(m) <= nums.at(nums.size() - 1)) //p2
            {
                h = m - 1;
            }
            else //p1
            {
                if (nums.at(m) > nums.at(m + 1))
                {
                    pivot = m;
                    break;
                }

                else
                {
                    l = m + 1;
                }
            }
        }
        return nums[pivot + 1];
    }
};

// @lc code=end
