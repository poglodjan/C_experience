#include <stdio.h>
#include <math.h>
#include <string.h>

// 1
// counts letters in string
int mystrlen(const char *str)
{
    int i=0;
    while(str[i]!='\0')
    {
        i++;
    }   
    return i;
}

// 2
// copy one string to another
void mystrcopy(char *dest, const char *str)
{
    int i=0;
    while(str[i]!='\0')
    {
        dest[i] = str[i];
        i++;
    }
    dest[i] = '\0';
}
void mystrcopy2(char *dest, const char *src)
{
    while(*src!='\0')
    {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';
}

// 3
// comparison
int mystrcnm(const char *str1, const char *str2)
{
    int i=0;
    while(str1[i]!='\0' && str2[i]!='\0')
    {
        if(str1[i]!=str2[i])
            return -1;        
        i++;
    }
    if(str1[i]!=str2[i])
        return -1;
    return 0;
}

// 4
// concatenating
void mystrcat(const char *src, char *dest)
{
    int i=0;
    while(dest[i] != '\0')
    {
        i++;
    }
    int j=0;
    while(src[j] != '\0')
    {
        dest[j+i] = src[j];
        j++;
    }
    dest[j+i] = '\0';
}
void mystrcat_upgrade(const char *src,char *dest)
{
    int dest_len = mystrlen(dest);
    int j=0;
    while(src[j] != '\0')
    {
        dest[j+dest_len] = src[j];
        j++;
    }
    dest[j+dest_len] = '\0';
}

// 5
//Returns index of char in string
int mystrchar(const char *src, char c)
{
    int i=0;
    while(src[i]!='\0')
    {
        if(src[i]==(char)c)
        {
            return i;
        }
        i++;
    }
    return -1;
}
// returns address
char* mystrchr_adress(const char *src, char c) {
    int i =0;
    while (src[i] != '\0') {
        if (src[i] == (char)c)
            return (char *)&src[i]; 
        else
            i++;
    }
    return NULL; 
}
char* mystrchr_adress2(const char *src, char c){
    while(*src!='\0')
    {
        if(*src==(char)c)
            return (char *)src;
        else
            src++;
    }
    return NULL;
}

// 6
// polindrome
int polindrom(const char *str)
{
    int i, str_len = mystrlen(str);
    for(i=0; i<str_len/2; i++)
    {
        if(str[i]!=str[str_len-i-1])
            return 0;
    }
    return 1;
}

// 7
// removing char at position 
void strrmidx(char *src, int k) {
    int str_len = mystrlen(src);
    for (int i = k-1; i < str_len && src[i]!='\0'; i++) {
        src[i] = src[i + 1];
    }
    src[str_len - 1] = '\0';
}

// 8
// removing char at first occurance
void strrmchr(char *src, char ch)
{
    int index = mystrchar(src, ch)+1;
    strrmidx(src, index);
}
void strrmchr2(char *src, char ch) {
    char *ptr = src;
    while (*ptr != '\0') {
        if (*ptr == ch) {
            char *runner = ptr;
            while (*runner != '\0') {
                *runner = *(runner + 1);
                runner++;
            }
            return; 
        }
        ptr++;
    }
}

// 9
// removes every character ch in string
void strrmchr_every(char *src, char ch) 
{
    int str_len = mystrlen(src);
    int copy_index = 0;

    for (int i = 0; i < str_len; i++) {
        if (src[i] != ch) {
            src[copy_index] = src[i];
            copy_index++;
        }
    }
    src[copy_index] = '\0';
}

// 10
// removes uppercase
void remove_upercase(char *src)
{
    int str_len = mystrlen(src);
    int copy_index = 0;
    for(int i=0; i<str_len; i++)
    {
        if(src[i]>='A' && src[i]<='Z')
            continue;
        else
            src[copy_index] = src[i];
        copy_index++;
    }
    src[copy_index] = '\0';
}

// 11
// removes substring by start and lenght
void srtrmsub(char *src, int start, int length)
{
    int str_len = mystrlen(src);
    int copy_index=0, tmp=0;
    for(int i=0; i<str_len; i++)
    {
        if(i == start)
        {
            for(int j=0; j<length; j++)
                tmp++;
        }
        else
        {
            src[copy_index] = src[i+tmp];
        copy_index++;
        }
    }
    src[copy_index] = '\0';
}

// 12
// removes every substring by given string
void strrmstr(char src[], const char toremove[]) {
    int src_len = mystrlen(src);
    int toremove_len = mystrlen(toremove);

    for (int i = 0; i <= src_len - toremove_len; ) {
        int match = 1;
        for (int j = 0; j < toremove_len; j++) {
            if (src[i + j] != toremove[j]) {
                match = 0;
                break;
            }
        }
        if (match) {
            for (int j = i; j < src_len - toremove_len; j++) {
                src[j] = src[j + toremove_len];
            }
            src[src_len - toremove_len] = '\0';
            src_len -= toremove_len;
        } else {
            i++;
        }
    }
}

// 13
// replace each given character to another
int strrplcch(char *src, char toreplace, char replacewith) {
    int replacements = 0;

    for (int i = 0; src[i] != '\0'; i++) {
        if (src[i] == toreplace) {
            src[i] = replacewith;
            replacements++;
        }
    }
    return replacements;
}

// 14
// replace lowercase to uppercase
void strupper(char *src) {
    for (int i = 0; src[i] != '\0'; i++) 
    {
        if (src[i] >= 'a' && src[i] <= 'z') 
        {
            src[i] = src[i] - 'a' + 'A';
        }
    }
}

// 15
// replace in string a substring indicated by start position and length with another string
void strrplcsub(char *src, int start, int length, const char *replacement) {
    int src_len = strlen(src);
    int replacement_len = strlen(replacement);

    for (int i = src_len; i >= start + length; i--) {
        src[i + replacement_len - length] = src[i];
    }

    for (int i = 0; i < replacement_len; i++) {
        src[start + i] = replacement[i];
    }
}

// 16
// replace in string a substring by another string
void strrplcstr(char *src, const char *toreplace, const char *replacewith) {
    int src_len = strlen_custom(src);
    int toreplace_len = strlen_custom(toreplace);
    int replacewith_len = strlen_custom(replacewith);

    for (int i = 0; i <= src_len - toreplace_len; ) {
        int match = 1;
        for (int j = 0; j < toreplace_len; j++) {
            if (src[i + j] != toreplace[j]) {
                match = 0;
                break;
            }
        }

        if (match) {
            for (int j = src_len; j >= i + toreplace_len; j--) {
                src[j + replacewith_len - toreplace_len] = src[j];
            }

            for (int j = 0; j < replacewith_len; j++) {
                src[i + j] = replacewith[j];
            }

            i += replacewith_len;
            src_len += replacewith_len - toreplace_len;
        } else {
            i++;
        }
    }
}

// last
// replace digits to world if it is < 12
void numberToWord(int num, char *word) {
    const char *words[] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve"};
    
    if (num >= 0 && num <= 12) {
        strcpy(word, words[num]);
    } else {
        // Handle numbers greater than 12 if needed
        strcpy(word, "");
    }
}
void replaceNumbers(char *src) {
    char result[500]; 
    int i = 0, j = 0;

    while (src[i] != '\0') {
        if (src[i] >= '0' && src[i] <= '9') {
            int num = 0;
            while (src[i] >= '0' && src[i] <= '9') {
                num = num * 10 + (src[i] - '0');
                i++;
            }
            char word[20]; 
            numberToWord(num, word);

            int k = 0;
            while (word[k] != '\0') {
                result[j++] = word[k++];
            }
        } else {
            result[j++] = src[i++];
        }
    }

    result[j] = '\0';
    strcpy(src, result);
}

int main()
{
    printf("\n________Copy_______\n\n");
    char *str = "pokemon";
    char dest[20];
    mystrcopy(dest, str);
    printf("%s", dest);

    printf("\n________Length_______\n\n");
    printf("%d", mystrlen(str));

    printf("\n________Comparison_______\n\n");
    char str1[25], str2[25];
    printf("Wprowadz str1, str2: \n");
    scanf("%s", str1);
    scanf("%s", str2);
    printf("%d", mystrcnm(str1,str2));

    printf("\n________Concatenate_______\n\n");
    mystrcat_upgrade(str2, str1);
    printf("Połączony string: %s", str1);
    
    printf("\n________Finding char adress_______\n\n");
    char findChar = 'n';
    char *result = mystrchr_adress2(str,findChar);
    if(result!=-1)
        printf("Character '%c' found at adress: %ld\n", findChar, result);
    else
        printf("No such char");

    printf("\n________Polindromes_______\n\n");
    printf("Polindrom check: %d",polindrom(str));

    printf("\n________Remove char at given position_______\n\n");
    char string[30] = "Hello world"; // can be editable!! char * cannot
    mystrcopy(dest, string);
    strrmidx(string, 4);
    printf("String before: %s string after: %s", dest, string);

    printf("\n________Remove char (first occurrence)_______\n\n");
    char string2[30] = "My birthday";
    char toremove = 'b';
    strrmchr(string2, toremove);
    printf("String after: %s", string2);

    printf("\n________Remove char (each occurrence)_______\n\n");
    char string3[30] = "Mathematics equations";
    toremove = 'a';
    strrmchr_every(string3, toremove);
    printf("String after: %s", string3);

    printf("\n________Remove Uppercase_______\n\n");
    char string4[30] = "FoR iNt in RAnGe NeurAL NETWork";
    toremove = 'a';
    remove_upercase(string4);
    printf("String after: %s", string4);

    printf("\n________Remove Substring_______\n\n");
    char string5[30] = "My family lives in Warsaw";
    srtrmsub(string5, 3, 6);
    printf("String after: %s", string5);

    return 0;
}