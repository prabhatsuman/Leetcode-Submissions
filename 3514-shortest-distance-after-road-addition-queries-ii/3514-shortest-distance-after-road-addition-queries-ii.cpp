class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        set<int> st;
        for(int i=0;i<n;i++)
        {
            st.insert(i);
        }
        vector<int> ans;
        for(auto it:queries)
        {
            int x=it[0],y=it[1];
            auto i=st.lower_bound(x+1);
            auto j=st.upper_bound(y-1);
            st.erase(i,j);
            ans.push_back(st.size()-1);
        }
        return ans;

    }
};