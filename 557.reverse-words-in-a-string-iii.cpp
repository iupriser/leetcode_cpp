/*
 * @lc app=leetcode id=557 lang=cpp
 *
 * [557] Reverse Words in a String III
 */

// @lc code=start
class Solution
{
public:
    string reverseWords(string s)
    {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        int n = s.length();
        if (s.empty() || n == 1)
            return s;

        int j = 0;
        s.insert(s.end(), ' ');

        for (int i = 0; i <= n; ++i)
        {
            if (s[i] == ' ')
            {
                reverse(s.begin() + j, s.begin() + i);
                j = i + 1;
            }
        }
        s.pop_back();
        return s;
    }
};

/*

public:
    string reverseWords(string s) {
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != ' ') {
                int start = i;
                int end = start;
                while (end < s.size() && s[end] != ' ') {
                    end++;
                }
                reverse(s, start,end - 1);
                i = end;
            }
        }
        return s;
    }
    void reverse (string& s, int start, int end) {
        while (start < end) {
            swap(s[start++], s[end--]);
        }
    }
};

*/
// @lc code=end
