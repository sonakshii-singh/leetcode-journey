class Solution {
public:
    void reverseString(vector<char>& s) {
        stack<char> st;
        for(auto it:s){
          st.push(it);
        }
        for(int i=0; i<s.size(); i++){
            s[i]=st.top();
            st.pop();
        }
    }
};