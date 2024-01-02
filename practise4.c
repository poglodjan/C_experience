//Alokacje
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void zad1()
{
    int size;
    scanf("%d", &size);
    double *p = malloc(size*sizeof(double));
    free(p);
}

int *zad2(int num, int start, int step)
{
    int *ptr = (int*)calloc(num,sizeof(int));
    if(ptr==NULL) return NULL;
    ptr[0] = start;
    for(int i=1; i<num; i++) 
    {
        ptr[i] = step + ptr[i-1];
    }
    return ptr;
}

void *zad3(int n)
{
    int d=0;
    int temp_n = n;
    while (temp_n > 0)
    {
        d++;
        temp_n /= 10;
    }

    int *p =(int*)malloc((d+1)*sizeof(int)+1);
    if (p == NULL)
        return NULL;

    p[d]=-1;
    for (int k = d - 1; k >= 0; k--)
    {
        p[k] = n % 10;
        n /= 10;
    }
    return p;
}

char *zad4(const char *inputString)
{
    size_t inputLength = strlen(inputString);
    char *resultString = (char *)malloc((inputLength + 1) * sizeof(char));

    if (resultString == NULL)
        return NULL;

    size_t resultIndex = 0;
    for (size_t i = 0; i < inputLength; i++)
    {
        if (inputString[i] != ' ')
        {
            resultString[resultIndex] = inputString[i];
            resultIndex++;
        }
    }
    resultString[resultIndex] = '\0';
    return resultString;
}

char *concatenateStrings(const char *str1, const char *str2)
{
    size_t len1 = strlen(str1);
    size_t len2 = strlen(str2);
    char *resultString = (char *)malloc((len1 + len2 + 1) * sizeof(char));

    if (resultString == NULL)
        return NULL;

    strcpy(resultString, str1);
    strcat(resultString, str2);
    return resultString;
}

////////////////////// complex numbers //////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct
{
    double Re, Im;
} CMPLX;

typedef struct
{
    int numElements;
    CMPLX *elements;
} CMPLX_SET;

void create_random_set(CMPLX_SET *pcs, int num)
{
    srand(time(NULL));
    pcs->elements = (CMPLX *)malloc(num * sizeof(CMPLX));

    if (pcs->elements == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    pcs->numElements = num;
    
    for (int i = 0; i < num; i++)
    {
        pcs->elements[i].Re = (double)rand() / RAND_MAX; 
        pcs->elements[i].Im = (double)rand() / RAND_MAX; 
    }
}

void delete_random_set(CMPLX_SET *pcs)
{
    free(pcs->elements);
    pcs->numElements = 0;
}

void print_random_set(CMPLX_SET cs)
{
    printf("Complex Set:\n");
    for (int i = 0; i < cs.numElements; i++)
    {
        printf("Element %d: %.2f + %.2fi\n", i + 1, cs.elements[i].Re, cs.elements[i].Im);
    }
}

void change_set_size(CMPLX_SET *pcs, int num)
{
    pcs->elements = (CMPLX *)realloc(pcs->elements, num * sizeof(CMPLX));

    if (pcs->elements == NULL)
    {
        printf("Memory reallocation failed.\n");
        exit(EXIT_FAILURE);
    }
    pcs->numElements = num;
}

int main()
{   
    zad1();

    // Part 2
    int num = 5;
    int start = 10;
    int step = 3;
    int *result = zad2(num, start, step);

    if (result != NULL)
    {
        for (int i = 0; i < num; i++)
        {
            printf("%d ", result[i]);
        }

        free(result); 
    }


    // part 3
    int n = 12345;
    int *result_3 = zad3(n);

    if (result_3 != NULL)
    {
        for (int i = 0; i < 5; i++)
        {
            printf("%d ", result_3[i]);
        }

        free(result_3); 
    }
    
    // part 4
    const char *input = "Hello World! This is a test.";
    char *result_4 = zad4(input);
    if (result_4 != NULL)
    {
        printf("Original: %s\n", input);
        printf("Modified: %s\n", result_4);

        free(result);
    }

    // part 5
    const char *str1 = "Hello, ";
    const char *str2 = "world!";

    char *result_5 = concatenateStrings(str1, str2);

    if (result_5 != NULL)
    {
        printf("Original 1: %s\n", str1);
        printf("Original 2: %s\n", str2);
        printf("Concatenated: %s\n", result_5);

        free(result_5); 
    }

    // part 6
    CMPLX_SET complexSet;
    int initialSize = 5;

    create_random_set(&complexSet, initialSize);
    print_random_set(complexSet);
    int newSize = 8;
    change_set_size(&complexSet, newSize);
    print_random_set(complexSet);
    delete_random_set(&complexSet);

    return 0;
}