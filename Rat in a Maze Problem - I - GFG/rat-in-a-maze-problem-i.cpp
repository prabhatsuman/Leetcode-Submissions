//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    bool ratInMaze(vector<vector<int>> &m, int n, vector<string> &res, string path, int i, int j)
    {
        
        if(i>=n || j>=n || i<0 || j<0 || m[i][j]==0)
            return false;
        if(i==n-1 && j==n-1)
        {
            res.push_back(path);
            return true;
        }
        
        m[i][j]=0;
        bool right=ratInMaze(m,n,res,path+'R',i,j+1);
        bool down=ratInMaze(m,n,res,path+'D',i+1,j);
        bool left=ratInMaze(m,n,res,path+'L',i,j-1);
        bool up=ratInMaze(m,n,res,path+'U',i-1,j);
       
        m[i][j]=1;
        return right || down || left || up;
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string> res;
        string path="";
        if(m[0][0]==0)
            return res;
        
        ratInMaze(m,n,res,path,0,0);

        
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends