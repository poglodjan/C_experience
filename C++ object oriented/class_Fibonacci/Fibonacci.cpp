
int Fibonacci::generate_n(int n) const
{
	int a = 0, b = 1, c, i;
	if (n == 0)
		return a;
	for (i = 2; i <= n; i++)
	{
		c = a + b;
		a = b;
		b = c;
	}
	return b;
}

Fibonacci::Fibonacci()
{
	for (int i = 0; i < SIZE; i++)
		numberF[i] = false;
}

Fibonacci::Fibonacci(int dec)
{
	for (int i = 0; i < SIZE; i++)
		numberF[i] = false;
	if (dec > MAX_DECIMAL_VALUE)
		return;
	for (int i = 0; i < SIZE; i++)
	{
		if (generate_n(MAX_N - i) <= dec)
		{
			numberF[i] = true;
			dec -= generate_n(MAX_N - i);
		}
	}
}

std::ostream& operator<<(std::ostream& out, const Fibonacci& lf)
{
	bool flag = true;
	for (int i = 0; i < SIZE; i++)
	{
		if (lf.numberF[i])
			flag = false;
		if (!flag)
			out << lf.numberF[i];
	}
	if (flag)
		out << '0';
	out << 'F';
	return out;
}


Fibonacci::Fibonacci(const char* fib)
{
	for (int i = 0; i < SIZE; i++)
		numberF[i] = false;
	int len = strlen(fib);
	if (!len || len > 10)
		return;
	for (int i = SIZE - len, j = 0; i < SIZE; i++, j++)
		if (fib[j] == '1')
			numberF[i] = true;
	fix();
}

void Fibonacci::fix()
{
	for (int i = 1; i < SIZE - 1; i++)
		if (numberF[i] && numberF[i + 1])
		{
			numberF[i - 1] = true;
			numberF[i] = numberF[i + 1] = false;
		}
}


int Fibonacci::operator()() const
{
	int dec = 0;
	for (int i = 0; i < SIZE; i++)
		if (numberF[i])
			dec += generate_n(MAX_N - i);
	return dec;
}


