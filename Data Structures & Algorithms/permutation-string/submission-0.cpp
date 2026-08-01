class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        int windowSize = s1.length();
        int n = s2.length();

        if(windowSize > n) return false;

        vector<int> freq1(26,0);
        vector<int> freq2(26,0);

        for(char ch : s1)
            freq1[ch-'a']++;

        int left = 0;

        for(int right = 0; right < n; right++){

            freq2[s2[right]-'a']++;

            if(right-left+1 > windowSize){
                freq2[s2[left]-'a']--;
                left++;
            }

            if(right-left+1 == windowSize){
                if(freq1 == freq2)
                    return true;
            }
        }

        return false;
    }
};