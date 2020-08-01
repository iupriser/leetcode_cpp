/*
 * @lc app=leetcode id=70 lang=cpp
 *
 * [70] Climbing Stairs
 */

// @lc code=start

// https://leetcode.com/articles/climbing-stairs/

// dp based solution
class Solution
{
public:
    int climbStairs(int n)
    {
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= n; ++i)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};

/*
// recursive approach
class Solution {
public:
    int climbStairs(int n) {
        int count = 0;
        help(n,count);
        return count;
    }
    void help(int n, int &count) {
        if(n<0) {
            return;
        }
        if(n == 0) {
            count++;
            return;
        }
        help(n-1,count);
        help(n-2,count);
    }
};

*/

/*
// using constant space
class Solution {
public:
    int climbStairs(int n) {
        vector<int> steps(3, 0);
        steps[0] = 1;
        steps[1] = 1;
        for (int i = 2; i <= n; ++i) {
            steps[i % 3] = steps[(i - 1) % 3] + steps[(i - 2) % 3];
        }
        return steps[n % 3];
    }
};

*/
// @lc code=end
