/*
 * @lc app=leetcode id=66 lang=cpp
 *
 * [66] Plus One
 */

// @lc code=start
class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        int n = digits.size();
        int sum = 0, carry = 1;
        if (digits[n - 1] != 9)
        {
            digits[n - 1]++;
            return digits;
        }

        for (int i = n - 1; i >= 0; i--)
        {
            sum = carry + digits[i];
            carry = sum / 10;
            digits[i] = sum % 10;
        }

        if (digits[0] == 0)
        {
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};
// @lc code=end
