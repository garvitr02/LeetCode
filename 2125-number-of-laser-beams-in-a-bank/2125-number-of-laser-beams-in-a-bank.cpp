class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int n = bank.size();
        int m = bank[0].size();
        int prev = 0;
        int curr = 0;
        int ans = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(bank[i][j] == '1'){
                    curr += 1;
                }
            }
            if (curr != 0){
                ans += prev*curr;
                prev = curr;
                curr = 0;
            }
        }
        return ans;
    }
};