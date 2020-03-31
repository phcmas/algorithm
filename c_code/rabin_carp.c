#include <stdio.h>
#include <stdlib.h>

char *parent = "acabacdabac";
char *pattern = "abacdab";

void check (char *parent, char *pattern, int start) {
    int found = 1;
    int patternSize = strlen(pattern);

    for (int i=0; i < patternSize; ++i) {
        if (parent[start+i] != pattern[i]) {
            found = 0;
            break;
        }
    }

    if (found) {
        printf("Matching at %d\n", start+1);
    }
}

void rabinCarp(char *parent, char *pattern) {
    int parentSize = strlen(parent);
    int patternSize = strlen(pattern);
    int parentHash=0, patternHash=0, power=1;

    for (int i=0; i < parentSize-patternSize; ++i) {
        if (i == 0) {
            for (int j = 0; j < patternSize; ++j){
                parentHash = parentHash + parent[patternSize-j-1] * power;
                patternHash = patternHash + pattern[patternSize-j-1] * power;
                if (j < patternSize -1) power = power *2;
            }
        } else {
            parentHash = 2 * (parentHash- parent[i-1]*power)+ parent[patternSize-1+i];
        }
        if (parentHash == patternHash) {
            check (parent,pattern, i);
        }
    }

}

int main(void) {
    rabinCarp(parent, pattern);

    
}















