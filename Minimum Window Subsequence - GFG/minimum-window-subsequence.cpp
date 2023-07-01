//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string minWindow(string str1, string str2) {
        // Write your Code here
        int i=0,j=0;
        int ind=-1;
        int res=1e9;
        string ans="";
        
        
        
        int n=str1.size(),m=str2.size();
        for(;i<n;i++)
        {
            
            if(str1[i]==str2[j])
            {
                // cout<<i<<" "<<j<<endl;
                if(j==0)ind=i;
                if(j==m-1 && i-ind+1<res)
                {
                    string temp="";
                    res=i-ind+1;
                    for(int k=ind;k<=i;k++)
                    {
                        temp+=str1[k];
                    }
                    ans=temp;
                    i=ind;
      
                 
                }
                   j=(j+1)%m;
            }
            
        }
      
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        string str1, str2;
        cin >> str1 >> str2;

        Solution obj;
        cout << obj.minWindow(str1, str2) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}

// } Driver Code Ends