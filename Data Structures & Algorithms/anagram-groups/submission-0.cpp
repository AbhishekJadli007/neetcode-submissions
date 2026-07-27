class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>mpp;

        for(auto str :strs){
            string sorted = str;
            sort(sorted.begin(),sorted.end());
            mpp[sorted].push_back(str);
        }

        vector<vector<string>>ans;

        for(auto itr : mpp){
            ans.push_back(itr.second);
        }
        return ans;
    }
};
