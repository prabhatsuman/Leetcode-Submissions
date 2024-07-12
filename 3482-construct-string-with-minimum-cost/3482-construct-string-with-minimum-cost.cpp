#include <vector>
#include <queue>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

class TrieNode {
public:
    TrieNode* suffix_link;
    TrieNode* output_link;
    int pattern_ind;
    TrieNode* children[26];

    TrieNode() {
        suffix_link = nullptr;
        output_link = nullptr;
        pattern_ind = -1;
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
    }
};

class AhoCorasick {
    TrieNode* root;

public:
    AhoCorasick() {
        root = new TrieNode();
    }

    void buildTrie(const vector<string>& patterns, const vector<int>& costs) {
        for (int i = 0; i < patterns.size(); i++) {
            TrieNode* cur = root;
            for (char c : patterns[i]) {
                if (!cur->children[c - 'a']) {
                    cur->children[c - 'a'] = new TrieNode();
                }
                cur = cur->children[c - 'a'];
            }
            if (cur->pattern_ind == -1) {
                cur->pattern_ind = i;
            } else if (costs[i] < costs[cur->pattern_ind]) {
                cur->pattern_ind = i;
            }
        }
    }

    void buildSuffixAndOutputLinks() {
        root->suffix_link = root;
        queue<TrieNode*> q;
        for (int i = 0; i < 26; i++) {
            if (root->children[i]) {
                q.push(root->children[i]);
                root->children[i]->suffix_link = root;
            }
        }

        while (!q.empty()) {
            TrieNode* curstate = q.front();
            q.pop();
            for (int i = 0; i < 26; i++) {
                if (curstate->children[i]) {
                    TrieNode* curchild = curstate->children[i];
                    TrieNode* temp = curstate->suffix_link;
                    while (temp != root && !temp->children[i]) {
                        temp = temp->suffix_link;
                    }
                    if (temp->children[i]) {
                        curchild->suffix_link = temp->children[i];
                    } else {
                        curchild->suffix_link = root;
                    }
                    q.push(curchild);
                }
            }

            if (curstate->suffix_link->pattern_ind >= 0) {
                curstate->output_link = curstate->suffix_link;
            } else {
                curstate->output_link = curstate->suffix_link->output_link;
            }
        }
    }

    int mincost(const vector<int>& costs, const string& target, const vector<string>& words) {
        int n = target.length();
        vector<int> dp(n, 1e9);
        TrieNode* cur = root;
        for (int i = 0; i < n; i++) {
            while (cur != root && !cur->children[target[i] - 'a']) {
                cur = cur->suffix_link;
            }
            if (cur->children[target[i] - 'a']) {
                cur = cur->children[target[i] - 'a'];
                if (cur->pattern_ind >= 0) {
                    int stind = i - words[cur->pattern_ind].length();
                    if (stind == -1) {
                        dp[i] = min(dp[i], costs[cur->pattern_ind]);
                    } else if (dp[stind] != 1e9) {
                        dp[i] = min(dp[i], dp[stind] + costs[cur->pattern_ind]);
                    }
                }

                TrieNode* another_output = cur->output_link;
                while (another_output) {
                    int stind = i - words[another_output->pattern_ind].length();
                    if (stind == -1) {
                        dp[i] = min(dp[i], costs[another_output->pattern_ind]);
                    } else if (dp[stind] != 1e9) {
                        dp[i] = min(dp[i], dp[stind] + costs[another_output->pattern_ind]);
                    }
                    another_output = another_output->output_link;
                }
            } else {
                return -1;
            }
        }
        return dp[n - 1] == 1e9 ? -1 : dp[n - 1];
    }

    TrieNode* getRoot() {
        return root;
    }
};

class Solution {
public:
    int minimumCost(string target, vector<string>& words, vector<int>& costs) {
        AhoCorasick aho;
        aho.buildTrie(words, costs);
        aho.buildSuffixAndOutputLinks();
        return aho.mincost(costs, target, words);
    }
};
