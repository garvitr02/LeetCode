class Solution {

private:

    int lowerBound(vector<int> &nums, int target){

        int n = nums.size();

        int low = 0;
        int high = n-1;

        int index = -1;

        while(low <= high){

            int mid = (low + high)/2;

            if(nums[mid] >= target){
                index = mid;
                high = mid-1;
            }
            else{
                low = mid + 1;
            }
        }

        return index;
    }

    int upperBound(vector<int> &nums, int target){

        int n = nums.size();

        int low = 0;
        int high = n-1;

        int index = n;

        while(low <= high){

            int mid = (low + high)/2;

            if(nums[mid] > target){
                index = mid;
                high = mid -1;
            }
            else{
                low = mid + 1;
            }
        }

        return index;
    }


public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        int lb;
        int ub;

        lb = lowerBound(nums, target);
        ub = upperBound(nums,target);

        if( lb == -1 || nums[lb] != target){
            return {-1,-1};
        }
        else{
            return {lb, ub-1};
        }

    }
};