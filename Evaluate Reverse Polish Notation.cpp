class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int one, two;

        for (auto x : tokens) {
            if (x != "*" && x != "/" && x != "+" && x != "-") {
                int vl = stoi(x);
                st.push(vl);
            } else {
                two = st.top(); st.pop();
                one = st.top(); st.pop();
                switch (x[0]) {
                    case '*':
                        st.push(one * two);
                        break;
                    case '/':
                        st.push(one / two);
                        break;
                    case '+':
                        st.push(one + two);
                        break;
                    case '-':
                        st.push(one - two);
                        break;
                }
            }
        }

        return st.top();
    }
};
