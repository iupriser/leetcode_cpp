/*
 * @lc app=leetcode id=208 lang=cpp
 *
 * [208] Implement Trie (Prefix Tree)
 */

 // @lc code=start
class Trie {
    Trie * children[26];
    bool isEndOfWord;
public:
    /** Initialize your data structure here. */
    Trie() {
        isEndOfWord = false;
        for (int i =0; i<26; ++i) {
            children[i] = nullptr;
        }
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie * curr = this;
        for (char ch:word) {
            if (!(curr->children[ch-'a'])) {
                curr->children[ch-'a'] = new Trie;
            }
            curr = curr->children[ch-'a'];
        }
        curr->isEndOfWord = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie*curr = this;
        for (char ch:word) {
            if (!curr->children[ch-'a']) {
                return false;
            }
            curr=curr->children[ch-'a'];
        }
        return curr->isEndOfWord;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie*curr = this;
        for (char ch:prefix) {
            if (!curr->children[ch-'a']) {
                return false;
            }
            curr=curr->children[ch-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
 // @lc code=end

