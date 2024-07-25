class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        sort(costs.begin(),costs.end(),[](auto a,auto b)
        {
            return a[0]-b[0]<a[1]-b[1];
        });
        for(auto it:costs)
        {
            cout<<it[0]<<" "<<it[1]<<endl;
        }
        int a=0,b=0;
        int cost=0;
        for(auto it:costs)
        {
            if(a<costs.size()/2)
            {
                a++;
                cost+=it[0];
            }
            else
            {
                b++;
                cost+=it[1];
            }
        }
        return cost;
    }
};