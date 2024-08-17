class Solution {
public:
    string countAndSay(int n) {
        function<string(string, int)> RLE = [&](string s, int n) -> string {
            if (n == 1) {
                return s;
            }
            int i = 0;
            string ans = "";
            int j = 0;
            while (i < s.length()) {
                while (j < s.length() && s[i] == s[j])
                    j++;
                int count = j - i;
                ans += to_string(count);
                ans += s[i];
                i = j;
            }
            return RLE(ans, n - 1);
        };
        return RLE("1", n);
    }
};