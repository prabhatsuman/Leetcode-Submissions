class DSU
{
    public:
    vector<int> parent;
    vector<int> size;
    DSU(int n)
    {
        parent.resize(n);
        size.resize(n,1);
        for(int i=0;i<n;i++)
        {
            parent[i]=i;
        }
    }
    int findPar(int u)
    {
        if(u==parent[u])
        {
            return u;
        }
        return parent[u]=findPar(parent[u]);
    }
   
    void unionBySize(int u,int v)
    {
        int parU=findPar(u);
        int parV=findPar(v);
        if(parU==parV)
        {
            return ;
        }
        if(size[parU]<size[parV])
        {
            parent[parU]=parV;
            size[parV]+=size[parU];
        }
        else
        {
            parent[parV]=parU;
            size[parU]+=size[parV];
        }
    }
};
class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        map<int,vector<pair<int,int>>> time;
        time[0].push_back({0,firstPerson});
        for(auto it:meetings)
        {
            time[it[2]].push_back({it[0],it[1]});
        }
        DSU ds(n);

        for(auto [t,meetings]:time)
        {
            for(auto [x,y]:meetings)
            {
                ds.unionBySize(x,y);
            }
            for(auto [x,y]:meetings)
            {
                int parZ=ds.findPar(0);
                int parX=ds.findPar(x);
                if(parX!=parZ)
                {
                    ds.parent[x]=x;
                    ds.parent[y]=y;
                    ds.size[x]=1;
                    ds.size[y]=1;
                }
            }
        }
        vector<int> ans;
        for(int i=0;i<n;i++)
        {
            if(ds.findPar(i)==ds.findPar(0))
            {
                ans.push_back(i);
            }
        }
        return ans;


       

    

    }
};