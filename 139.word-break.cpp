/*
 * @lc app=leetcode id=139 lang=cpp
 *
 * [139] Word Break
 */

// @lc code=start
/*
// recursive solution - 1
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        //unordered_set<string> set(wordDict.begin(), wordDict.end());
        if(s.length() == 0) {
            return true;
        }
        for(auto it = wordDict.begin(); it!=wordDict.end(); ++it) {
            string prefix = s.substr(0,(*it).length());
            bool result = false;
            if(prefix.compare(*it) == 0) {
                result = wordBreak(s.substr((*it).length()), wordDict);
            }
            if(result) {
                return true;
            }
        }
        return false;
    }
};
*/

/*
// recursive-solution - 2
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> set(wordDict.begin(), wordDict.end());
        return wb(s, set);
    }
private:
    bool wb(string s, unordered_set<string>&set) {
        int len = s.length();
        if(len == 0) {
            return true;
        }
        for(int i = 1; i <= len; ++i) {
            if((set.find(s.substr(0,i)) != set.end()) && wb(s.substr(i,len-i),set)) {
                return true;
            }
        }
        return false;
    }
};
*/

/*
// recursion with memoizarion
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string,bool>memo;
        return helper(s,wordDict,memo);
    }
private:
    bool helper(string s, vector<string>& dict, unordered_map<string,bool> &memo) {
        if(s.length() == 0) {
            return true;
        }
        else if(memo.find(s)!=memo.end()) {
            return memo[s];
        }
        for(auto it = dict.begin(); it!=dict.end(); ++it) {
            string prefix = s.substr(0,(*it).length());
            bool result = false;
            if(prefix.compare(*it) == 0) {
                result = helper(s.substr((*it).length()), dict,memo);
            }
            if(result) {
                memo[s] = true;
                return true;
            }
        }
        memo[s] = false;
        return false;
    }
};
*/

// dp approach (bottom-up approach)
class Solution
{
public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        unordered_set<string> uset(wordDict.begin(), wordDict.end());
        vector<bool> dp(s.length() + 1, false);
        dp[0] = true;
        for (int i = 1; i < s.length() + 1; ++i)
        {
            for (int j = i - 1; j >= 0; j--)
            {
                if (dp[j] && uset.count(s.substr(j, i - j)))
                {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.length()];
    }
};

// video for reference - https://www.youtube.com/watch?v=1U4jQusbeJc

// @lc code=end
