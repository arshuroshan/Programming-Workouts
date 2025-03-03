class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();
        
        for (int i = 0; i < n - 1; ++i) {
            if (nums[i] == nums[i + 1]) {
                nums[i] *= 2;
                nums[i + 1] = 0;
            }
        }
        
        int writePointer = 0;
        for (int readPointer = 0; readPointer < n; ++readPointer) {
            if (nums[readPointer] != 0) {
                nums[writePointer++] = nums[readPointer];
            }
        }
        
        while (writePointer < n) {
            nums[writePointer++] = 0;
        }
        
        return nums;
    }
};