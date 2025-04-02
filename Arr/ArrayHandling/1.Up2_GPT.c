#include <stdio.h>
#include <string.h>

#define MAX_CHAR 256

// Hàm tìm độ dài lớn nhất của chuỗi con không lặp lại
int maxUniqueSubstringLength(const char *str) {
    int lastIndex[MAX_CHAR]; // Mảng lưu vị trí cuối cùng của mỗi ký tự
    for (int i = 0; i < MAX_CHAR; i++) {
        lastIndex[i] = -1; // Khởi tạo tất cả vị trí là -1
    }
    
    int maxLength = 0, start = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (lastIndex[(unsigned char)str[i]] >= start) {
            start = lastIndex[(unsigned char)str[i]] + 1;
        }
        lastIndex[(unsigned char)str[i]] = i;
        
        maxLength = (i - start + 1 > maxLength) ? i - start + 1 : maxLength;
    }
    return maxLength;
}

int main() {
    char str[100];
    printf("Nhập chuỗi: ");
    scanf("%99s", str);
    
    printf("Độ dài lớn nhất của chuỗi con không lặp lại: %d\n", maxUniqueSubstringLength(str));
    
    return 0;
}
