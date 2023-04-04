class Solution {
public:
    int partitionString(string s) {
        unordered_map<char,bool> um;

        int ans = 0;
        for(int i = 0;i < s.length();i++){
            if(um[s[i]]){
                ans++;
                um.clear();
                um[s[i]] = true;
            }
            else{
                um[s[i]] = true;
            }
        }

        return ans+1;
    }
};