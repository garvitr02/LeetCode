class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int , int> hashMap;

        vector<int> arr;

        for(int i =0 ;i< nums.size(); i++){

            int rem = target - nums[i];
            if (hashMap.find(rem) != hashMap.end()){
                arr.push_back(hashMap[rem]);
                arr.push_back(i);
                break;

            }

            else{
                hashMap[nums[i]] = i; 
            }
        }

        return arr;
    }
};