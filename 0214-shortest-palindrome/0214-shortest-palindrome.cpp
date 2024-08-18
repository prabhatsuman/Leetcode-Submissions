class Solution {
public:
    const int p=31;
    const int m=1e9+7;
    string shortestPalindrome(string s) {
        //lets find longest palindrome for first index
        //using rolling hashes
        int preHash=0,suffHash=0;
        long long pow=1;
        int index=-1;
        for(int i=0;i<s.length();i++)
        {
            preHash=((long long)preHash*p+(s[i]-'a'+1))%m;
            suffHash=(suffHash+(long long)(s[i]-'a'+1)*pow)%m;
            pow=(long long)(pow*p*1LL)%m;
            if(preHash==suffHash)
            {
                index=i;
            }
        }
        string temp=s.substr(index+1,s.length());
        reverse(temp.begin(),temp.end());
        return temp+s;
    }
};