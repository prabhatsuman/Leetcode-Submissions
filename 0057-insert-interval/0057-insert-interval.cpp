class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        int n=intervals.size();
        sort(intervals.begin(),intervals.end());
        // cout<<n<<endl;
      
        vector<vector<int>> ans;
        for(int i=0;i<n;)
        {
            vector<int> temp;
            temp.push_back(intervals[i][0]);
            int end=intervals[i][1];
            i++;
            while(i<n && end>=intervals[i][0])
            {
                end=max(end,intervals[i][1]);
                i++;
            }
       
            
           
                temp.push_back(end);
       
            
         
        
            ans.push_back(temp);
           

        }
        return ans;
    }
};