class Solution {
public:
    int trap(vector<int>& height) {
        long long ans = 0;
        stack<int> st;
        int n = height.size();
        for(int i = 0; i < n; i++){
            while(!st.empty() && height[st.top()] <= height[i]){
                int current = st.top();
                st.pop();
                if(st.empty()) {
                    break;
                }
                int diff = i - st.top() - 1;
                ans += (long long)(min(height[st.top()],height[i]) - height[current]) * diff;
            }
            st.push(i);
        }
        return ans;
    }
};