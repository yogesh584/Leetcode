class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int index1 = 0;
        int index2 = 0;
        string ans = "";

        while (index1 < word1.length() && index2 < word2.length()){
            ans.push_back(word1[index1]);
            ans.push_back(word2[index2]);
            index1++;
            index2++;
        }

        while (index1 < word1.length()){
            ans.push_back(word1[index1]);
            index1++;
        }

        while (index2 < word2.length()){
            ans.push_back(word2[index2]);
            index2++;
        }

        return ans;
    }
};