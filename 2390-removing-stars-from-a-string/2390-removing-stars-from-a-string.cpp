class Solution {
public:
    string removeStars(string s) {
        stack<char> st;
        for(auto ch : s){
            if(ch != '*'){
                st.push(ch);
            }
            else{
                st.pop();
            }
        }

        string ans = "";
        while(!st.empty()){
            char ch = st.top();
            st.pop();
            ans.push_back(ch);
        }

        reverse(ans.begin(),ans.end());

        return ans;
    }
};