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

