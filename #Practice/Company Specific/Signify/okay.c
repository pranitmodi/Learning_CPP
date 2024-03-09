#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long unlockingKey(long key) {
    char str[20]; // To hold the key as a string
    sprintf(str, "%ld", abs(key));

    int n = strlen(str);
    // Sorting the digits in ascending order
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (str[i] > str[j]) {
                char temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }
        }
    }

    // Ensuring the first digit is not zero
    if (str[0] == '0') {
        for (int i = 1; i < n; i++) {
            if (str[i] != '0') {
                char temp = str[0];
                str[0] = str[i];
                str[i] = temp;
                break;
            }
        }
    }

    return atol(str);
}

int main() {
    long key;
    scanf("%ld", &key);
    printf("%ld\n", unlockingKey(key));
}