class StockSpanner {
public:
    stack<pair<int,int>> st; // pair of price and index
    int ind = 0;
    
    StockSpanner() {
        
    }
    
    int next(int price) {
        ind++;
        // Pop all elements that have a price less than or equal to the current price
        while(!st.empty() && st.top().first <= price) {
            st.pop();
        }
        // If the stack is empty, it means the current price is the highest so far
        int span = st.empty() ? ind : ind - st.top().second;
        // Push the current price and its index onto the stack
        st.push({price, ind});
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
