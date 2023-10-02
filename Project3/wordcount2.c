#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>
#define max 5000
char data[max];

void read() {
    FILE* fp;

    if (fopen_s(&fp, "d.txt", "r") != 0) {
        printf("파일 읽기 실패");
        return; 
    }

    fread(data, sizeof(char), sizeof(data), fp);
    fclose(fp);
    printf("%s", data);
}

void col(char* string) {
    int col = 1, count = 0, flag = 0, cmpct = 0;

    for (int i = 0; data[i] != '\0'; i++) {
        if (count > 10) {
            col++;
            count = 0;
        }
        if (data[i] == '.') {
            col++;
            count = 0;
        }
        if (data[i] != ' ' && data[i] != '\n' && data[i] != '\t' && data[i] != '\r' && flag != 1) {
            count++;
            flag = 1;
            cmpct = 0;
            if (string[cmpct] == data[i]) {
             
                for (int j = i; data[j] != ' ' && data[j] != '\n' && data[j] != '\t' && data[j] != '\r'; j++) {
                    if (string[cmpct] != data[j]) {
                        break;
                    }
                    else cmpct++;
                    if (cmpct == strlen(string)) {
                        printf("(%d,%d),", col, count);
                        break;
                    }
                }
            }
        }
        if (data[i] == ' ' || data[i] == '\n' || data[i] == '\t' || data[i] == '\r' || flag != 1) {
            flag = 0;
        }
    }
}

int main() {
    read();
    printf("\n찾을 단어 입력: ");
    char a[max]; 
    scanf("%s", a); 
    printf("\n");
    col(a); 
    return 0;
}
