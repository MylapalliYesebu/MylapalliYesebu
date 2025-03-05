// Write a C program to identify different types of tokens in a given program.

/* Output
    'int' IS A KEYWORD 
    'a' IS A VALID IDENTIFIER 
    '=' IS AN OPERATOR 
    'b' IS A VALID IDENTIFIER 
    '+' IS AN OPERATOR 
    '1c' IS NOT A VALID IDENTIFIER */

// Code
#include <stdbool.h> 
#include <stdio.h> 
#include <string.h> 
#include <stdlib.h> 

// Returns 'true' if the character is a DELIMITER. 
bool isDelimiter(char ch) { 
    return (ch == ' ' || ch == '+' || ch == '-' || ch == '*' || 
            ch == '/' || ch == ',' || ch == ';' || ch == '>' || 
            ch == '<' || ch == '=' || ch == '(' || ch == ')' || 
            ch == '[' || ch == ']' || ch == '{' || ch == '}');
}

// Returns 'true' if the character is an OPERATOR. 
bool isOperator(char ch) { 
    return (ch == '+' || ch == '-' || ch == '*' || 
            ch == '/' || ch == '>' || ch == '<' || ch == '=');
}

// Returns 'true' if the string is a VALID IDENTIFIER. 
bool validIdentifier(char* str) { 
    if (!((str[0] >= 'a' && str[0] <= 'z') || 
          (str[0] >= 'A' && str[0] <= 'Z') || 
          (str[0] == '_')))
        return false;
  
    for (int i = 1; str[i] != '\0'; i++) {
        if (!((str[i] >= 'a' && str[i] <= 'z') || 
              (str[i] >= 'A' && str[i] <= 'Z') || 
              (str[i] >= '0' && str[i] <= '9') || 
              (str[i] == '_')))
            return false;
    }
  
    return true;
}

// Returns 'true' if the string is a KEYWORD. 
bool isKeyword(char* str) { 
    const char* keywords[] = {
        "if", "else", "while", "do", "break", "continue", "int", "double", 
        "float", "return", "char", "case", "sizeof", "long", "short", 
        "typedef", "switch", "unsigned", "void", "static", "struct", "goto"
    };
    
    int numKeywords = sizeof(keywords) / sizeof(keywords[0]);
    for (int i = 0; i < numKeywords; i++) {
        if (!strcmp(str, keywords[i]))
            return true;
    }
    return false;
}

// Returns 'true' if the string is an INTEGER. 
bool isInteger(char* str) { 
    int len = strlen(str);
    if (len == 0) return false;

    for (int i = 0; i < len; i++) { 
        if ((str[i] < '0' || str[i] > '9') || (str[i] == '-' && i > 0)) 
            return false; 
    } 
    return true; 
}

// Returns 'true' if the string is a REAL NUMBER. 
bool isRealNumber(char* str) { 
    int len = strlen(str);
    bool hasDecimal = false;
    
    if (len == 0) return false;
    
    for (int i = 0; i < len; i++) { 
        if ((str[i] < '0' || str[i] > '9') && str[i] != '.' || 
            (str[i] == '-' && i > 0)) 
            return false;
        if (str[i] == '.') hasDecimal = true; 
    } 
    return hasDecimal; 
}

// Extracts the SUBSTRING. 
char* subString(char* str, int left, int right) { 
    char* subStr = (char*)malloc(sizeof(char) * (right - left + 2)); 
    for (int i = left; i <= right; i++) 
        subStr[i - left] = str[i]; 
    subStr[right - left + 1] = '\0'; 
    return subStr; 
}

// Parses the input STRING and identifies tokens. 
void parse(char* str) { 
    int left = 0, right = 0, len = strlen(str); 

    while (right <= len && left <= right) { 
        if (!isDelimiter(str[right])) 
            right++; 

        if (isDelimiter(str[right]) && left == right) { 
            if (isOperator(str[right])) 
                printf("'%c' IS AN OPERATOR\n", str[right]); 
            right++; 
            left = right; 
        } 
        else if ((isDelimiter(str[right]) && left != right) || (right == len && left != right)) { 
            char* subStr = subString(str, left, right - 1); 

            if (isKeyword(subStr)) 
                printf("'%s' IS A KEYWORD\n", subStr);
            else if (isInteger(subStr)) 
                printf("'%s' IS AN INTEGER\n", subStr); 
            else if (isRealNumber(subStr)) 
                printf("'%s' IS A REAL NUMBER\n", subStr); 
            else if (validIdentifier(subStr)) 
                printf("'%s' IS A VALID IDENTIFIER\n", subStr); 
            else 
                printf("'%s' IS NOT A VALID IDENTIFIER\n", subStr); 

            left = right; 
            free(subStr);
        } 
    } 
}

// DRIVER FUNCTION 
int main() { 
    char str[100] = "int a = b + 1c; "; 
    parse(str); // Calling the parse function 
    return 0; 
}
