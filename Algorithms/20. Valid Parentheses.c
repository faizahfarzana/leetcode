/*
*   empty string valid
*   s = ""
*   len = 0
*   ---------------------------------
*   odd number of parentheses not valid
*   s = "({}"
*   len % 2 == 1
*   ---------------------------------
*   increase index and insert for opening bracket, decrease for closing bracket
*   s = "(){}"
*   s[0] = '('
*       stack[i] = '('
*       i++
*   s[1] = ')'
*       i--
*   ---------------------------------
*   closing bracket found at the beginning or without matching opening bracket not valid
*   s = "]" or s = "())"  
*   in both cases, i = 0
*   ---------------------------------
*   closing bracket found without matching opening bracket not valid
*   s = "([)]"
*   here i != 0
*   ---------------------------------
*   all opening brackets not valid
*   s = "({"
*   i != 0
*   ---------------------------------
*   all opening brackets optimization: stack index value will not reach half of string length for valid cases
*   s = "{{[[(("    not valid
*   len = 6; len / 2 = 3
*   at s[3], i == 3
*   ---------------------------------
*   valid case
*   s = "({[]})" valid
*   i will be 0 as all will be popped
*/    
//


bool isValid(char * s){
    int len = strlen(s);

    if (len == 0)       return true;
    if (len % 2 == 1)   return false;
    
    int index = 0;
    int half = len / 2;
    char stack[len];
    
    for (int i = 0; i < len; i++) {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
            if (index == half)
                return false;
            
            stack[index++] = s[i];
        }
        
        else {
            if (index == 0)
                return false;
            
            if (s[i] == ')' && stack[index - 1] == '(' || s[i] == '}' && stack[index - 1] == '{' || s[i] == ']' && stack[index - 1] == '[')
                index--;
            
            else 
                return false;
        } 
    }
    
    return (index == 0);
}