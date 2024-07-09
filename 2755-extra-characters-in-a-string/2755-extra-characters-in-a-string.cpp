struct Trie {
    map<char, Trie*> mp;
    bool isEndOfWord;
    Trie() { isEndOfWord = false; }
};
class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        Trie* root = new Trie();
        for (string st : dictionary) {
            Trie* temp = root;
            for (int i = 0; i < st.length(); i++) {
                if (temp->mp.find(st[i]) == temp->mp.end()) {
                    temp->mp[st[i]] = new Trie();
                }
                temp = temp->mp[st[i]];
            }
            temp->isEndOfWord=true;
        }
        int n=s.length();
        int dp[n+1];
        memset(dp,-1,sizeof(dp));
        function<int(int)> helper=[&](int ind)
        {
            if(ind==n)
            {
                return 0;
            }
            if(dp[ind]!=-1)return dp[ind];
            int ans=helper(ind+1)+1;
            
            Trie* temp=root;
            for(int i=ind;i<n;i++)
            {
                if(!temp->mp.count(s[i]))
                {
                    break;
                }
                temp=temp->mp[s[i]];
                if(temp->isEndOfWord)
                {
                    ans=min(ans,helper(i+1));
                }
            }
            return dp[ind]=ans;
        };
        return helper(0);

    }

};