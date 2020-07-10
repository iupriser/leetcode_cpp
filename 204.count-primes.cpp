/*
 * @lc app=leetcode id=204 lang=cpp
 *
 * [204] Count Primes
 */

// @lc code=start
class Solution
{
public:
    int countPrimes(int n)
    {
        int count = 0;
        n = n - 1;
        while (n > 1)
        {
            if (isPrime(n))
            {
                count++;
            }
            n--;
        }
        return count;
    }

    bool isPrime(int num)
    {
        if (num == 2 || num == 3)
            return true;
        for (int i = 2; i <= sqrt(num); ++i)
        {
            if (num % i == 0)
                return false;
        }
        return true;
    }
};
// @lc code=end
