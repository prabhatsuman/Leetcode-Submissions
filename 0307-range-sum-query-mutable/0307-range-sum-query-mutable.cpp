class NumArray
{
    public:
        vector<int> tree;
        int n;
    NumArray(vector<int> &nums)
    {
        n = nums.size();
        tree.resize(4 *n, 0);
        buildtree(0, n - 1, 0, nums);
    }
    void buildtree(int left, int right, int node, vector<int> &nums)
    {
        if (left == right)
        {
            tree[node] = nums[left];
            return;
        }
        int mid = left + (right - left) / 2;
        buildtree(left, mid, node *2 + 1, nums);
        buildtree(mid + 1, right, node *2 + 2, nums);
        tree[node] = tree[node *2 + 1] + tree[node *2 + 2];
    }
    void updatetree(int left,int right,int node,int index,int val)
    {
        if(left==right)
        {
            tree[node]=val;
            return ;
        }
        int mid=left+(right-left)/2;
        if(index<=mid)
        {
            updatetree(left,mid,node*2+1,index,val);
        }
        else
        {
            updatetree(mid+1,right,node*2+2,index,val);
        }
        tree[node] = tree[node *2 + 1] + tree[node *2 + 2];
        
    }
    int  sum(int left,int right,int node , int l, int r)
    {
        if(left>r || right<l)return 0;
        if(left>=l && right<=r)
        {
            return tree[node];
        }
        int mid=left+(right-left)/2;
        return sum(left,mid,node*2+1,l,r)+sum(mid+1,right,node*2+2,l,r);

    }
    void update(int index, int val) {
        updatetree(0,n-1,0,index,val);
    }

    int sumRange(int left, int right) {
        return sum(0,n-1,0,left,right);
    }
};

/**
 *Your NumArray object will be instantiated and called as such:
 *NumArray* obj = new NumArray(nums);
 *obj->update(index,val);
 *int param_2 = obj->sumRange(left,right);
 */