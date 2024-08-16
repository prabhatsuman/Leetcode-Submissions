class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        for(char it:num)
        {
            while(!st.empty() && k>0 && st.top()-'0'>it-'0')
            {
                st.pop();
                k--;
            }
            st.push(it);
        }
        
        string res="";
        while(k-->0)st.pop();
        while(!st.empty()){
            res+=st.top();
            st.pop();
        }
        // cout<<res<<endl;
        while(res.size() && res.back()=='0')res.pop_back();
        if(res.size()==0)return "0";
        
        reverse(res.begin(),res.end());
        return res;
    }
};