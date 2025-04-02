#include <stdio.h>
#include <string.h>

#define MAX_CHAR 256

#include <stdio.h>
#include <string.h>

int lengthOfLongestSubstring(char *s) {
    int n = strlen(s);
    int charIndex[MAX_CHAR]; // ASCII characters
    for (int i = 0; i < MAX_CHAR; i++) {
        charIndex[i] = -1; // Initialize all characters as not seen
    }
    
    int maxLength = 0;
    int left = 0; // Left boundary of the sliding window
    
    for (int right = 0; right < n; right++) {
        if (charIndex[s[right]] >= left) {
            left = charIndex[s[right]] + 1; // Move left (to the postion of last duplicate seen )to avoid duplicate
        }
        
        charIndex[s[right]] = right; // Update last seen index into HashMap

        if ( (right - left + 1 ) > maxLength)
        {
            maxLength = right - left + 1;
        }
    }
    
    return maxLength;
}

int main() {
    char str[100];
    printf("Input String: ");
    scanf("%99s", str);
    
    printf("max length of string not repeated in array is: %d\n", lengthOfLongestSubstring(str));
    
    return 0;
}
