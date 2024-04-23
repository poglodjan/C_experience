
// h
class tabD{
    int n;
    char *a; //pointer of an array
    void init(int n);
    void fill(char ch=0; const char* tab=nullptr);
public:
    tabD() : n(0), a(nullptr) {}
    explicit tabD(int n, char ch=0);
    tabD(int n, const char* tab);
    tabD(char ch);

    tabD(const tabD& t);
    tabD& operator=(const tabD& t);
    ~tabD();
    
    //methods
    int size() const { return n; }
    char& operator[](int i) { return a[i]; } 
    const char& operator[](int i) const { return a[i]; } 
    friend bool operator==(const tabD& t1, const tabD& t2);
    friend bool operator!=(const tabD& t1, const tabD& t2);
    friend tabD operator+(const tabD& t1, const tabD& t2);
    tabD& operator+=(const tabD& t);
    friend std::ostream& operator<<(std::ostream& out, const tabD& t);
    friend std::istream& operator>>(std::istream& in, tabD& t);
}

// main
char tab[] = {'1', '2', '3', '4', '5', '6', '7'};
const char* s = "54321";
int main()
{
    tabD V1, V2(5), V3(6, 'x'), V4(7, tab), V5(3,s), V6('2');
}

// cpp
// constructors
tabD::tabD(int n, int char ch) n(n)
{
    init(n);
    fill(ch);
}

tabD::tabD(int n, const char* tab): n(n)
{
    init(n);
    fill(0,tab);
}

tabD::tabD(char ch) : n(1)
{
    init(1);
    fill(ch);
}

tabD::init(int n) // alocating memory
{
    if (n<=0) { this->n=0; a=nullptr; return; }
    this->n=n;
    a=new(nothrow) char[n];
    if(!a) { this->n=0; return; }
}

tabD::fill(char ch, const char* tab)
{
    for(int i=0; i<n; i++)
    {
        a[i] = tab ? tab[i] : ch;
    }
}

// assignment
tabD::tabD(const tabD& t)
{
    init(t.n);
    wypelnij(0, t.a);
}

tabD& tabD::operator=(const tabD& t)
{
    if(this!=&t)
    {
        if(n!=t.n)
        { delete[] a; init(t.n); }
        wypelnij(0, t.a);
    }
    return *this;
}

tabD::~tabD() { delete [] a; }

bool operator==(const tabD& t1, const tabD& t2) 
{
    if (t1.n != t2.n)
        return false;
    for (int i = 0; i < t1.n; i++)
        if (t1[i] != t2[i])
            return false;
    return true;
}

bool operator!=(const tabD& t1, const tabD& t2) 
{
    return !(t1 == t2);
}

tabD operator+(const tabD& t1, const tabD& t2) 
{
    if (t1==tabD()) return t2; // no elements in t1
    if (t2==tabD()) return t1;
    tabD t3(t1.n+t2.n);
    if (t3==tabD()) return t3; 
    for ( int i = 0; i < t1.n; ++i) t3[i] = t1[i];
    for ( int i = 0; i < t2.n; ++i) t3[t1.n + i] = t2[i];
    return t3;
}
tabD& tabD::operator+=(const tabD& t) 
{
    return *this = *this + t;
}

ostream& operator<<( ostream& out, const tabD& t )
{
    out<<"[";
    for ( int i=0; i<t.n; ++i ) out<<t[i]; // wersja: operator[] const
    return out<<"]";
}
istream& operator>>( istream& in, tabD& t )
{
    int n;
    do {
    cout << "Podaj n="; in>>n;
    } while (n<=0);

    if (n != t.n) 
    {
        delete[] t.a;
        t.init(n);
    }
    for (int i = 0; i < t.n; ++i) { cout<<"a["<<i<<"]="; in>>t[i]; }
    return in;
}
