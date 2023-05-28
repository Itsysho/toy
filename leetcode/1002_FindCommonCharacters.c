// Given a string array words, return an array of all characters that show up in all strings within the words (including duplicates). You may return the answer in any order.

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** commonChars(char ** words, int wordsSize, int* returnSize){
    int comm[128] = {0};
    for (int i = 0; i < wordsSize; i++) {
        int count[128] = {0};
        for (int j = 0; words[i][j] != 0; j++) {
            count[words[i][j]]++;
        }
        if (i == 0) {
            for (int k = 0; k < 128; k++) {
                comm[k] = count[k];
            }
        } else {
            for (int k = 0; k < 128; k++) {
                if (comm[k] > count[k]) {
                    comm[k] = count[k];
                }
            }
        }
    }
    int size = 0;
    for (int i = 0; i < 128; i++) {
        if (comm[i] > 0)
            size += comm[i];
    }
    *returnSize = size;
    char** ret = (char**)malloc(size * sizeof(char*));
    int idx = 0;
    for (int i = 0; i < 128; i++) {
        while (comm[i] > 0) {
            ret[idx] = (char*)malloc(2 * sizeof(char));
            ret[idx][0] = i;
            ret[idx][1] = '\0';
            comm[i]--;
            idx++;
        }
    }
    return ret;
}