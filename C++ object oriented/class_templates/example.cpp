#include <complex>

template <typename T>
int compare(const T a, const T b)
{
  if(a<b) return 1;
  if(a>b) return -1;
  return 0;
}

template<> // for const char* no specialization
int compare(const char* a, const char* b)
{
  return strcmp(a,b);
}

template<typename T, int N> // passing array to template
T sum(const T(&A)[N])
{
  T result{};
  for(int i=0; i<N; ++i)
    result += A[i];
  return result;
}
// or
template<typename T>
T sum(T* A, int N) // otherwise we cant take N in function
{
  T result{};
  for(int i=0; i<N; ++i)
      result += A[i];
  return result;
}




