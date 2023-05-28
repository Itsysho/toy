// Given a string s, return the string after replacing every uppercase letter with the same lowercase letter.

char * toLowerCase(char * s){
    int sSize = strlen(s);
    for (int i = 0; i < sSize; i++) {
        if (s[i] >= 'A' && s[i] <= 'Z') 
            s[i] = s[i] - 'A' + 'a';
    }
    return s;
}