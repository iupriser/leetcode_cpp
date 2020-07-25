/*
 * @lc app=leetcode id=344 lang=cpp
 *
 * [344] Reverse String
 */

// @lc code=start
class Solution
{
public:
    void reverseString(vector<char> &s)
    {
        ios_base::sync_with_stdio(0);
        cin.tie(NULL);
        reverse(s.begin(), s.end());
    }
};

/*
class Solution {
public:
    void reverseString(vector<char>& s) {
        for(int i=0, j=s.size()-1; i<s.size()/2; ++i,--j ){
            swap(s[i],s[j]);
        }   
        for(auto &x:s)
            cout<<x<<" ";
    }
};
*/

// @lc code=end
