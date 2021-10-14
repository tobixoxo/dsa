
class Solution {
public:
    bool isValid(string s) {
        stack <char> s1 ;
        string exp = s;
        int i = 0;
        while(i < s.size())
        {
            char c = s[i];
            if (c == '(' || c == '{' || c == '[')
            {
                s1.push(c);
            }
            else if (c == '}')
            {
                if (s1.empty()) return false;
                else if (s1.top() != '{')
                {
                    return false;
                }
                else s1.pop();
               
            }
            else if (c == ')')
            {
                if (s1.empty()) return false;
                else if (s1.top() != '(')
                {
                    return false;
                }
                else s1.pop();
            }
            else if (c == ']')
            {
                if (s1.empty()) return false;
                else if (s1.top() != '[')
                {
                    return false;
                }
                else s1.pop();
            }
            i++;
            
        }
        if (s1.empty()) return true;
        else return false;
        
    }
};
