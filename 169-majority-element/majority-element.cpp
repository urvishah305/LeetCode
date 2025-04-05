class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int c;
        for(int& n : nums){
            if(count == 0){
                c = n;
            }
            count += (n == c) ? 1 : -1;
        }
        return c;
    }
};