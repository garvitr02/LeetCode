class Solution {
public:
    int minimumPushes(string word) {
        map<char, int> freq;

        for(auto c : word) {
            freq[c]++;
        }

        vector<int> frequencies;
        for (auto it : freq) {
            frequencies.push_back(it.second);
        }
        sort(frequencies.rbegin(), frequencies.rend());

        int cost = 0;
        int factor = 1;
        int cnt = 0;

        for (int i = 0; i < frequencies.size(); ++i) {
            if (cnt == 8) {
                cnt = 0;
                factor++;
            }
            cost += factor * frequencies[i];
            cnt++;
        }

        return cost;
    }
};