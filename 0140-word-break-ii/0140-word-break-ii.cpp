class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<vector<string>> ans;
        vector<string> temp;
        map<string, int> dict;
        for (auto it : wordDict) {
            dict[it]++;
        }
        int n = s.length();
        function<void(int)> helper = [&](int ind) -> void {
            if (ind == n) {
                ans.push_back(temp);
                return;
            }
            for (int k = ind; k < n; k++) {
                string str = s.substr(ind, k - ind + 1);
                if (dict.count(str)) {

                    temp.push_back(str);
                    helper(k + 1);
                    temp.pop_back();
                }
            }
        };
        helper(0);
        vector<string> res;
        for (auto it : ans) {
            string tp = "";
            for (string str : it) {
                tp += str;
                tp += " ";
            }
            tp.pop_back();
            res.push_back(tp);
        }
        return res;
    }
};