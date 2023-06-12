// Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

// An input string is valid if:

// Open brackets must be closed by the same type of brackets.
// Open brackets must be closed in the correct order.
// Every close bracket has a corresponding open bracket of the same type.

bool isValid(char * s){
    int lenS = strlen(s);
    char* stack = (char*)malloc(sizeof(char) * lenS);
    int top = 0;
    bool valid = true;
    for (int i = 0; i < lenS; i++) {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
            stack[top] = s[i];
            top++;
        } else {
            if (s[i] == ')') {
                if (top > 0 && stack[top - 1] == '(') {
                    top--;
                } else {
                    valid = false;
                    break;
                }
            } 
            if (s[i] == '}') {
                if (top > 0 && stack[top - 1] == '{') {
                    top--;
                } else {
                    valid = false;
                    break;
                }
            } 
            if (s[i] == ']') {
                if (top > 0 && stack[top - 1] == '[') {
                    top--;
                } else {
                    valid = false;
                    break;
                }
            } 
        }
    }
    free(stack);
    return top == 0 && valid;
}