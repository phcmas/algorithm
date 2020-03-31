#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void basicMatching(char *parent, char *pattern) {
    int parentSize = strlen(parent);
    int patternSize = strlen(pattern);

    for (int i=0; i <= parentSize - patternSize; i++) {
        int found = 1;
        for (int j=0; j < patternSize; j++) {
            if (parent[i+j] != pattern[j]) {
                found = 0; break;
            }
        }
        if (found) {
            printf("%d\n", i+1);
        }
    }
}

int *makeTable(char *pattern) {
    int patternSize = strlen(pattern);
    int *table = (int *)malloc(sizeof(int)*patternSize);
    char *copy = pattern;
    int i=0, j=1, index = -1;
    table[0]=-1;

    while (j < patternSize) {
        if (copy[i] != pattern[j]) {
            table[j] = -1;
            i=0; j++;
        } else {
            index++; table[j] = index;
            i++;j++;
        }
    }
    return table;
}

void KMPAlgorithm(char *parent, char *pattern) {
    int parentSize = strlen(parent);
    int patternSize = strlen(pattern);
    int *table = makeTable(pattern);
    int i=0, j=-1;
    int count =0;
    
    while (i < parentSize) {
        if (parent[i] != pattern[j+1]) {
            if (j == -1) {i++; continue;}
            j = table[j];
        } else {
            i++;j++;
        }

        if (j == patternSize-1) {
            j =-1; count++;
        }
    }
    printf("%d\n",count);
}


int main(void) {
    basicMatching("ABCDEFG","EF");
    KMPAlgorithm("AEFDEFGEFEF","EFD");

    printf("Done");
    return 0;
}

