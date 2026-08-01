class Solution {
public:
    int characterReplacement(string s, int k) {
        
        int maxfreq = 0 ;
        int n = s.length();
        int left = 0 ;
        int right = 0 ;
        int maxlen = 0 ;
        vector<int>freq(26,0);

        while(right<n){
            freq[s[right]-'A']++;
            maxfreq = max(maxfreq,freq[s[right]-'A']);

            while(right-left+1 - maxfreq > k){
                freq[s[left]-'A']--;
                for(auto itr : freq){
                    maxfreq = max(maxfreq,itr);
                }
                left++;
            }
            if(right-left+1 - maxfreq <= k){
                maxlen = max(maxlen,right-left+1);
            }
            right++;
        }

        return maxlen;
    }
};
