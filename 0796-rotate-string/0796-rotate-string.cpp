class Solution {
public:
    bool rotateString(string s, string goal) {
        int n=s.length();
        for(int i=0;i<n;i++)
        {
            bool flag=false;
            int k=0;
            for(int j=i;j<i+n;j++)
            {
                if(goal[j%n]==s[k])
                {
                    k++;
                }
                if(k==n)return true;
            }
        }
        return false;
    }
};