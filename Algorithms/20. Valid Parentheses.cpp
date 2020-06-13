// i can take stack
// inputs are opening and closing brackets
// opening brackets: push
// closing brackets: check if the last pushed item is its pair. if true then pop if not then return false as its invalid
// return true if stack empty after iteration, false if not
// return false if stack empty when closing bracket is found
// empty string return true


// Solution 1: using stack

class Solution {
public:
    bool isValid(string s) {
        stack<char> brackets;
        
        if (!s.length()) return true;
        
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[')
                brackets.push(s[i]);   
            
            else if (brackets.empty())	return false;
            else if (s[i] == ')' && brackets.top() == '(')	brackets.pop();
            else if (s[i] == ']' && brackets.top() == '[')	brackets.pop();
            else if (s[i] == '}' && brackets.top() == '{')	brackets.pop();
            else return false; 
        }
    
        return (brackets.empty());
    }
};


// Solution 2: using map and stack

class Solution {
public:
    bool isValid(string s) {
        if (!s.length()) return true;
        
        stack<char> brackets;
        map<char, char> pairs;
        
        pairs[')'] = '(';
        pairs['}'] = '{';
        pairs[']'] = '[';
        
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[')
                brackets.push(s[i]);   
            
            else if (brackets.empty() || pairs[s[i]] != brackets.top()) 
                return false;
            
            else brackets.pop();
        }
    
        return (brackets.empty());
    }
};