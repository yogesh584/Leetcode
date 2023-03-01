class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;
        else{
            unordered_map<char,int> um;
            for(int i = 0;i < s.length();i++){
                um[s[i]]++;
                um[t[i]]--;
            }        
            
            for(auto it : um){
                if(it.second != 0)  return false;
            }
            return true;
        }     
    }
};