class Solution
{
    public:
        int minTaps(int n, vector<int> &ranges)
        {
            vector<int> max_start(n+1, 0);
            for (int i = 0; i < n + 1; i++)
            {
                int start = max(0, i - ranges[i]);
                int end = min(n, i + ranges[i]);
                max_start[start] = max(max_start[start], end);
            }
            
            int max_end=0;
            int curr_end=0;
            int taps=0;
            for(int i=0;i<n+1;i++)
            {
                if(i>max_end)
                {
                    return -1;
                }
                if(i>curr_end)
                {
                    taps++;
                    curr_end=max_end;
                }
                max_end=max(max_end,max_start[i]);

            }
            return taps;
        }
};