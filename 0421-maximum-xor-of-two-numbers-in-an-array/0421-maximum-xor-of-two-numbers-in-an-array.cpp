struct Node {
    map<int, Node*> mp;
};
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Node* root = new Node();
        for (auto it : nums) {
            Node* temp = root;
            for (int i = 31; i >= 0; i--) {
                int bit = (it >> i) & 1;
                if (temp->mp.find(bit) == temp->mp.end()) {
                    temp->mp[bit] = new Node();
                }
                temp = temp->mp[bit];
            }
        }

        int ans = 0;
        for (auto it : nums) {
            int x = 0;
            Node* temp = root;
            for (int i = 31; i >= 0; i--) {
                int bit = (it >> i) & 1;
                if (temp->mp.find(1 - bit) != temp->mp.end()) {
                    x |= (1 << i);
                    temp = temp->mp[1 - bit];
                } else {
                    temp = temp->mp[bit];
                }
            }
            ans = max(ans, x);
        }
        return ans;
    }
};
