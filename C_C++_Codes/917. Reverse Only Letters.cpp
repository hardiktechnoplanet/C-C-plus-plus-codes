class Solution {
public:
    string reverseOnlyLetters(string s) {
        int len = s.size();
        int l = 0;
        int r = s.size() - 1;
        
        while(l < r){
            while(l < r && !isalpha(s[l])){
                l++;
            }
            while(r > l   && !isalpha(s[r])){
                r--;
            }
            
            swap(s[l],s[r]);
            l++;
            r--;
           
        }
        return s;
        
    }
};
