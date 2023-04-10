class Solution {
public:
    bool isValid(string s) {
        stack <char> st;

        // step 1 : Iterating String
        for (int i = 0;i < s.length();i++){
            char bracket = s[i];
            if(bracket == '(' || bracket == '[' || bracket == '{'){
                st.push(bracket);
            }
            else{
                if(st.empty()){
                    return false;
                }
                
                char TopBracket = st.top();
                if((TopBracket == '(' && bracket == ')') || (TopBracket == '[' && bracket == ']') || (TopBracket == '{' && bracket == '}')){
                    st.pop();
                }
                else{
                    return false;
                }
            }
        }

        if(st.empty()){
            return true;
        }
        else{
            return false;
        }
    }
};