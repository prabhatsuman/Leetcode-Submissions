class Solution {
public:
    const int mod=1e9+7;
    int sumSubarrayMins(vector<int>& arr) {
        stack<int> st;
        int n=arr.size();
        int res=0;
        for(int right=0;right<=n;right++)
        {
            while(!st.empty() && (right==n || arr[st.top()]>=arr[right]))
            {
                int mid=st.top();
                st.pop();
                int left= st.empty()?-1:st.top();
                res=(res+(long long )(right-mid)*(mid-left)*arr[mid])%mod;
            }
            st.push(right);
        }
        return res;
        
    }
};