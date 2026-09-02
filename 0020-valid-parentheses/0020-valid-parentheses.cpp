class Solution {
public:
    bool isValid(string s) {
        stack<char>st;

        for(int i = 0; i < s.size(); i++){
            if(s[i] == '(' || s[i] == '{' || s[i] == '['){ // check if it is opening bracket 
                st.push(s[i]); // push it into stack 
            }else{
                if(st.empty()){ // if a closing bracket comes and stack is empty it means no pair return false 
                    return false;
                } // but if this condition satisfies check for the pairs 
                if(st.top() == '(' && s[i] == ')' || st.top() == '{' && s[i] == '}' || st.top() == '[' && s[i] == ']'){
                    st.pop();
                }else{ // and if this also not then return false 
                    return false;
                }
            }
        }

        return st.empty(); // if the stack becomes empty atlast means each opening brakcet got its closing bracket and its valid else its false i.e, not valid 

    }
};