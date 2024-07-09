#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        __int128 ans = -10;
        __int128 minProd = 1, maxProd = 1;
        for (auto it : nums) {
            __int128 temp = minProd;
            minProd = min({static_cast<__int128>(it), it * minProd, it * maxProd});
            maxProd = max({static_cast<__int128>(it), it * maxProd, it * temp});
            ans = max(ans, maxProd);
        }
        return static_cast<int>(ans);
    }
};
