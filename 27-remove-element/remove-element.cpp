class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        vector<int> :: iterator t;
        t = nums.begin();
        for(int i=0;i<nums.size();i++){
            if(nums[i] == val){
                nums.erase(t);
                t--;
                i--;
            }
            t++;
        }
        return nums.size();
    }
};