class Solution {
public:
    string minWindow(string s, string t) {
        int n=s.length();
        unordered_map<char,int> mp;
        for(auto it:t)
        {
            mp[it]++;
        }
        int size=t.size(),start=0,end=0,begin=0,len=1e9;
        while(end<n)
        {
            if(mp[s[end++]]-->0)
            {
                size--;
            }
            while(!size)
            {
                if((end-start)<len)
                {
                    begin=start;
                    len=end-start;
                }
                if(mp[s[start++]]++==0)
                {
                    size++;
                }
            }
        }
        return len==1e9?"":s.substr(begin,len);
        
    }
};