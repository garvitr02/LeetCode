class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        
        int n = nums.size();
        
        if(n==1) return 0;
        
        int j = 0;
        
        int cnt = 0;
        
        for(int i=1; i<n; i++){
            if(nums[i] == nums[j]){
                nums[i] += 1;
                cnt++;
            }
            
            else if (nums[i] < nums[j]){
                cnt += nums[j] - nums[i] + 1;
                nums[i] = nums[j]+1;
            }
            j++;
        }
        
        return cnt;
        
        
    }
};