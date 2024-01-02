// struktury
#include <string.h>
#include <stdio.h>

typedef struct Rational Rational;

struct A{
    unsigned int i;
    double *p;
};

struct Rational{
    int num;
    int den;
};

struct Length {
    int meters;
    int centimeters;
};

//4. Function to calculate the difference between two time periods
struct TIME {
    int hours;
    int minutes;
    int seconds;
};
void timeDifference(struct TIME t1, struct TIME t2, struct TIME *difference) {
    int time1InSeconds = t1.hours * 3600 + t1.minutes * 60 + t1.seconds;
    int time2InSeconds = t2.hours * 3600 + t2.minutes * 60 + t2.seconds;

    int diffInSeconds = time1InSeconds > time2InSeconds ? time1InSeconds - time2InSeconds : time2InSeconds - time1InSeconds;

    difference->hours = diffInSeconds / 3600;
    difference->minutes = (diffInSeconds % 3600) / 60;
    difference->seconds = diffInSeconds % 60;
}

Rational fun1(int a, int b)
{
    Rational c;
    c.num = a;
    c.den = b;
    return c;
}
void print_struct(Rational a)
{
    printf("[%d %d]", a.num, a.den);
}

void write(Rational *a)
{
    scanf("%d", &(a->num));
    scanf("%d", &(a->den));
}
Rational sum_struct(Rational a, Rational b)
{   
    Rational sum;
    sum.den = a.den * b.den;
    sum.num = (a.num*b.den) + (b.num*a.den);
    return sum;
}

int compare(Rational a, Rational b)
{
    a.num = a.num * b.den;
    b.num = b.num * a.den;
    if (a.num==b.num)
        return 0;
    if (a.num>b.num)
        return 1;
    if (a.num<b.num)
        return -1;
}

typedef struct Student Student;
struct Student{
    char f_name[10];
    char l_name[10];
    int sem;
};

int compare_students(Student s1, Student s2)
{
    if(strcmp(s1.f_name, s2.f_name)!=0)
        return 0;
    if(strcmp(s1.l_name, s2.l_name)!=0)
        return 0;
    if(s1.sem>s2.sem)
        return 1;
    if(s1.sem<s2.sem)
        return -1;
    return 0;
}

int compareLengths(struct Length l1, struct Length l2) {
    if (l1.meters == l2.meters && l1.centimeters == l2.centimeters) {
        return 0; 
    } else if ((l1.meters > l2.meters) || (l1.meters == l2.meters && l1.centimeters > l2.centimeters)) {
        return 1;
    } else {
        return -1; 
    }
}

struct Length addLengths(struct Length l1, struct Length l2) {
    struct Length result;
    result.meters = l1.meters + l2.meters;
    result.centimeters = l1.centimeters + l2.centimeters;

    // Adjust if centimeters exceed 100
    if (result.centimeters >= 100) {
        result.meters += result.centimeters / 100;
        result.centimeters %= 100;
    }

    return result;
}

// Function to subtract two lengths
struct Length subtractLengths(struct Length l1, struct Length l2) {
    struct Length result;
    result.meters = l1.meters - l2.meters;
    result.centimeters = l1.centimeters - l2.centimeters;

    // Adjust if centimeters go below 0
    if (result.centimeters < 0) {
        result.meters -= 1;
        result.centimeters += 100;
    }

    return result;
}

int main()
{
    // Example lengths
    struct Length length1 = {3, 75};
    struct Length length2 = {3, 75};
    Rational a;
    write(&a);
    print_struct(a);

    // Compare lengths
    int comparison = compareLengths(length1, length2);
    if (comparison == 0) {
        printf("The lengths are equal.\n");
    } else if (comparison == 1) {
        printf("Length 1 is greater than Length 2.\n");
    } else {
        printf("Length 1 is less than Length 2.\n");
    }

    struct Length sum = addLengths(length1, length2);
    printf("Sum: %d meters %d centimeters\n", sum.meters, sum.centimeters);

    struct TIME time1 = {10, 45, 30}; 
    struct TIME time2 = {8, 30, 15}; 
    struct TIME timeDiff;

    timeDifference(time1, time2, &timeDiff);

    printf("Time Difference: %d hours, %d minutes, %d seconds\n", timeDiff.hours, timeDiff.minutes, timeDiff.seconds);
}

