double Area(double InputRadius, double Pi=3.1415);
int operate (int a, int b);
double operate (double a, double b);
inline double power(double a){return(a*a);}

struct rectangle
{
double x;
double y;
double area()
{
return (x * y);
}
};