class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        
        int r = 0;
        int y = x;
        while(x != 0){
            
            int rem = x%10;
            x/=10;
            
            if (r < INT_MIN/10 || r > INT_MAX/10) return false;
            r = 10*r + rem;
        }
        if(y == r) return true;
        return false;
        
    }
};