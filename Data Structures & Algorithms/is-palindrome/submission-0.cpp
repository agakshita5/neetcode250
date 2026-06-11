class Solution {
public:
    bool isPalindrome(string str) {
        string s = "";
        for(char c : str){
            if(isalnum(c)) s += c;
        }

        int i=0, j=s.size()-1;

        while(i<j){
            if(tolower(s[i])==tolower(s[j])){
                i++;
                j--;
            }else{
                return false;
            }
        }
        
        return true;
    }
};
// wasitacaroracatisaw