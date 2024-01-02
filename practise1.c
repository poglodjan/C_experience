#include <stdio.h>
#include <math.h>

// array of pointers to double 

double calcL2norm(double *array, int size)
{
    double norm = 0;
    for(int i = 0; i<size; i++)
    {
        norm += array[i] * array[i];
    }
    return sqrt(norm);
}

// swaps two numbers 
void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
// swaps three numbers 
void swap3(int *a, int *b, int *c)
{
    int temp, temp2;
    temp = *a;
    temp2 = *b;
    *a = *c;
    *b = temp;
    *c = temp2;
}

// analyses whether integer number has repeated digits
int analyze_digits(int n)
{
    int ifis = 0;
    int finding[10] = {0};
    for(int i=n; i>0; i = i/10)
    {
        int r = i%10;
        if (finding[r] != 1)
            finding[r] = 1;
            ifis = 1;
    }
    return ifis;
}

// find the mostly repeated digit
int statistics_digits(int n)
{
    int finding[10] = {0,0,0,0,0,0,0,0,0,0};
    for(int i=n; i>0; i=i/10)
    {
        int r = i%10;
        if (finding[r] != 1)
            finding[r] += 1;
    }
    int max = finding[0];
    int index = 0;
    for(int i = 1; i<10; i++)
    {
        if(finding[i]>max)
        {
            max = finding[i];
            index = i;
        }
    }
    return index;
}

// prints names of persons starting with letter ‘A’ and older than 20 years for data given below

int print_name_age(int n)
{
    int ages[] = {43,23,21,89,2};
    char *names[] = {"Alan", "Frank", "Ann", "John", "Andrew"};
    for(int i=0; i<n; i++)
    {
        int age = ages[i];
        char *name = names[i];
        if(age>20 && name[0] == 'A')
        {
            printf("%s age: %d", name, age);
        }
    }
}

// deletes an element from the specified location from array. 

void delete_element(int *A, int size, int index)
{
    for(int i=index; i<size; i++)
    {
        A[i] = A[i+1];
    }
    A[size-1] = 0;
}

// calculate and return the weighted mean of values from array A with weights from array W
double weights(double *A, double *W, int n)
{
    double sum1, sum2 = 0;
    for(int i = 0;i<n;i++)
    {
        sum1 += A[i]*W[i];
        sum2 += W[i];
    }
    return sum1/sum2;
}

// Function should write to the array B elements of the array A arranged in the reverse order
void reverse_array(const double A[], double B[], int n) {
    for (int i = 0; i < n; i++) {
        B[i] = A[n - 1 - i];
    }
}

// find and write to the console the least element and the largest element of the array
void least_largest(int *A, int n) {
    int *least = &A[0];
    int *largest = &A[0];

    for (int i = 1; i < n; i++) {
        if (A[i] < *least) {
            least = &A[i];
        }
        if (A[i] > *largest) {
            largest = &A[i];
        }
    }

    printf("Least: %d, Largest: %d\n", *least, *largest);
}

void save3x5()
{
    double data[3][5];

    // Input loop to get three sets of five double numbers
    for (int set = 0; set < 3; set++) {
        printf("Enter five double numbers for set %d: ", set + 1);
        for (int i = 0; i < 5; i++) {
            scanf("%lf", &data[set][i]);
        }
    }
}


int main(void)
{
    // Task 1s swaping
    int a = 1, b = 2, c = 3;
    swap3(&a,&b,&c);
    printf("%d %d %d\n", a,b,c);

    int A[3] = {4,3,1};
    double W[3] = {3,4,1};
    least_largest(A, 3);

    // Task 3
    double B[3] = {2,3,1};
    double C[3] = {1,1,1};
    double *Z[3] = {A,B,C};
    for(int i=0; i<3; i++)
    {
        double norm = calcL2norm(Z[i],3);
        printf("Array %c: L2 norm = %lf\n", 'A' + i, norm);
    }
    
    // sort
    for(int i = 0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            if(calcL2norm(Z[i], 3) > calcL2norm(Z[j],3))
            {
                double *temp = Z[i];
                Z[i] = Z[j];
                Z[j] = temp;
            }
        }
    }
    printf("\nSorted array Z in ascending order of L2 norm:\n");
    for (int i = 0; i < 3; i++) {
        printf("Array: L2 norm = %lf\n", calcL2norm(Z[i], 3));
    }

}