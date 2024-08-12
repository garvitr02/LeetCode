class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        int n=nums.size();
        int xor1 = nums[0];
        for(int i=1; i<n; i++){
            
            xor1 = xor1^nums[i];
        }
        
        int xor2 = 0;
        
        for(int i=1; i<n+1; i++){
            xor2 = xor2 ^ i;
        }
        
        return xor1 ^ xor2;
    }
};