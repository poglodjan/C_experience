static constexpr int MAX_DECIMAL_VALUE = 143;
static constexpr int SIZE = 10;
static constexpr int MAX_N = 11;

class Fibonacci
{
	bool numberF[SIZE];
	int generate_n(int n) const;

	void fix();
public:
	explicit Fibonacci();
	explicit Fibonacci(int dec);
	friend std::ostream& operator<<(std::ostream& out, const Fibonacci& lf);

	Fibonacci(const char* fib);
	int operator()() const;

};

