#include "commonFunctions.h"

void clearBuffer() {
    getchar();
}

int allDigits(char *s) {
    int len = strlen(s);
    int i;

    for (i=0; i<len; i++){
        if (!isdigit(s[i]))
            return 0;
    }
    return 1;
}



