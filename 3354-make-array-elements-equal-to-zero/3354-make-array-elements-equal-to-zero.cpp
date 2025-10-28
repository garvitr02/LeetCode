class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> lSum (n, 0);
        vector<int> rSum (n, 0);

        int ways = 0;

        for(int i=1; i<n; i++){
            lSum[i] = lSum[i-1] + nums[i-1];
            rSum[n-1-i] = rSum[n-i] + nums[n-i];
        }

        for(int i=0; i<n; i++){
            if(nums[i] != 0) continue;
            if(lSum[i] == rSum[i]){
                ways += 2;
            }
            else if(abs(lSum[i] - rSum[i]) == 1) ways += 1;
        }

        return ways;
    }
};