#include <vector>
#include <string>
#include <map>
#include <functional>
using namespace std;

struct Trie {
    map<char, Trie*> mp;
    bool isEndOfWord;
    Trie() { isEndOfWord = false; }
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie* root = new Trie();
        for (const string& s : words) {
            Trie* temp = root;
            for (char c : s) {
                if (temp->mp.find(c) == temp->mp.end()) {
                    temp->mp[c] = new Trie();
                }
                temp = temp->mp[c];
            }
            temp->isEndOfWord = true;
        }

        int n = board.size();
        int m = board[0].size();
        vector<string> res;
        vector<int> dx = {-1, 0, 1, 0};
        vector<int> dy = {0, -1, 0, 1};
        vector<vector<bool>> visited(n, vector<bool>(m, false));

        function<void(int, int, Trie*, string&)> dfs = [&](int x, int y, Trie* temp, string& curr) {
            if (temp->isEndOfWord) {
                res.push_back(curr);
                temp->isEndOfWord = false; 
            }
            visited[x][y] = true;
            for (int i = 0; i < 4; i++) {
                int newx = x + dx[i];
                int newy = y + dy[i];
                if (newx >= 0 && newy >= 0 && newx < n && newy < m &&
                    !visited[newx][newy] && temp->mp.count(board[newx][newy])) {
                    curr.push_back(board[newx][newy]);
                    dfs(newx, newy, temp->mp[board[newx][newy]], curr);
                    curr.pop_back();
                }
            }
            visited[x][y] = false;
        };

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (root->mp.count(board[i][j])) {
                    string curr;
                    curr.push_back(board[i][j]);
                    dfs(i, j, root->mp[board[i][j]], curr);
                }
            }
        }
        
        

        return res;
    }
};
