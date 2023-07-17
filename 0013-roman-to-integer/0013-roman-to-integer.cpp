class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int>m;
        m['I']=1;
        m['V']=5;
        m['X']=10;
        m['L']=50;
        m['C']=100;
        m['D']=500;
        m['M']=1000;
        int ans=0;
        int prev=0;

        for(auto it:s)
        {
            int curr=m[it];
            ans+=curr;
            if(curr>prev)
            {
                ans-=2*prev;
            }
            prev=curr;

        }
        
        return ans;
    }
};