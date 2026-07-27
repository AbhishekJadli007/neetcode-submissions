class Solution {
public:
    bool isPalindrome(string s) {
        string str="";
        for(int i=0 ; i<s.length() ; i++){
            if(isalnum(s[i])){
                str+=tolower(s[i]);
            }
        }
        string ans = str;
        reverse(ans.begin(),ans.end());

        return (ans==str);
    }
};
