class Solution {
public:
    int findMin(vector<int>& nums) {

        int n = nums.size();

        int low = 0;
        int high = n-1;
        int ansIndex = 0;

        while(low <= high){

            int mid = (low+high)/2;

            if(nums[low] <= nums[mid]){
                if(nums[low] < nums[ansIndex]) ansIndex = low;
                low = mid + 1;
            }
            else{
                if(nums[mid] < nums[ansIndex]) ansIndex = mid;
                high = mid -1;
            }
        }

        return nums[ansIndex];
        
    }
};