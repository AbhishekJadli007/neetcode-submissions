class Solution {
private:
bool isPalindrome(string s , int i , int j){

    while(i<j){
        if(s[i]!=s[j]) return false;
        i++;
        j--;
    }

    return true;
}

void solve( vector<vector<string>>&ans , vector<string> & ds , string s , int ind , int n){
    if(ind == n){
        ans.push_back(ds);
        return;
    }

    for(int i=ind ; i<n ; i++){
        if(isPalindrome(s,ind,i)){
            ds.push_back(s.substr(ind,i-ind+1));
            solve(ans,ds,s,i+1,n);
            ds.pop_back();
        }
    }
    return;

}
public:
    vector<vector<string>> partition(string s) {
         vector<vector<string>> ans ;
         vector<string>ds;

         solve(ans,ds,s,0,s.length());

         return ans;

    }
};
