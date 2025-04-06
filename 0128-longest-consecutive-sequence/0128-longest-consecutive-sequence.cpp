class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        
        unordered_set<int> st;
        int n = nums.size();
        
        if(n==0) return 0;
        for(int i=0; i<n; i++){
            st.insert(nums[i]);
        }

        int cnt = 0;
        int len = 1;

        for(auto it : st){
            cnt = 1;
            if(st.find(it-1) == st.end()){
                int x = it;
                while(st.find(x+1) != st.end()){
                    cnt++;
                    x++;
                }

                len = max(len,cnt);
            }
        }

        return len; 
    }
};