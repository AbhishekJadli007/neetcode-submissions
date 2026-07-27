class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<int,int>mpp;
        int n = s.length();
        int left = 0 ;
        int right = 0 ;
        int longest = 0 ;

        while(right<n){
            mpp[s[right]]++;

            while(mpp[s[right]]>1){
                mpp[s[left]]--;
                if(mpp.count(s[left])==0){
                    mpp.erase(s[left]);
                }
                left++;
            }

            longest = max(longest, right-left+1);
            right++;
        }

        return longest;
    }
};
