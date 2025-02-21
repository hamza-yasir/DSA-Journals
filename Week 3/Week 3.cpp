#include<iostream>
#include<conio.h>
using namespace std;

/*------------------------------------------------------------------------
							Exercise 3.3 c
--------------------------------------------------------------------------

bool IsPrime(int n, int divisor) {
	if (divisor == 1) {
		return true; 
	}
	if (n % divisor == 0) {
		return false; 
	}
	return IsPrime(n, divisor - 1); 
}


bool PrimeCaller(int n) {
	if (n <= 1) {
		return false; 
	}
	return IsPrime(n, n - 1);
}

int main() {
	int n;
	cout << "Enter a number to check if it's prime: ";
	cin >> n;

	if (PrimeCaller(n)) {
		cout << n << " is a prime number." << endl;
	}
	else {
		cout << n << " is not a prime number." << endl;
	}

	_getch();
	return 0;
}



int BinomialCoefficient(int n, int k) {

	if (k == 0 || k == n) {
		return 1;
	}
	return BinomialCoefficient(n - 1, k - 1) + BinomialCoefficient(n - 1, k);
}

int main() {
	int n, k;
	cout << "Enter first value : ";
	cin >> n ;
	cout << "Enter second value : ";
	cin >> k;

	if (k > n || n < 0 || k < 0) {
		cout << "Invalid input!!" << endl;
	}
	else {
		cout << "C(" << n << ", " << k << ") = " << BinomialCoefficient(n, k) << endl;
	}

	_getch();
	return 0;
}


/*------------------------------------------------------------------------
							Exercise 3.3 a
--------------------------------------------------------------------------
int recursive(int N) {
	if (N < 0) {
		
		return 0;
	}
	else
		cout << N << endl;
		return recursive(N - 1);
}
int main() {
	int k;
	cout << "enter value of N: ";
	cin >> k;

	cout << "N to 0" << endl;
	cout << "------" << endl;
	recursive(k);

	return 0;
}
/*------------------------------------------------------------------------
					EXAMPLE 3.4 and Exercise 3.2
--------------------------------------------------------------------------

int Ackermann(int m, int n) {
	if (m == 0) {
		return (n + 1);
	}
	else if (m > 0 && n == 0) {
		return (Ackermann(m - 1, 1));
	}
	else if (m > 0 && n > 0) {
		return (Ackermann(m - 1, Ackermann(m, n - 1)));
	}
}
int main() {
	int a, b;
	cout << "Ackerman for (3,4) is : " << Ackermann(3, 4) << endl << endl;
	cout << "\nEnter first value to use in Ackermann function: ";
	cin >> a;
	cout << "\nEnter second value to use in Ackermann function: ";
	cin >> b;
	cout << "Value obtained is : " << Ackermann(a, b);
	return 0;
}

/*------------------------------------------------------------------------
					EXAMPLE 3.3 and Exercise 3.1
--------------------------------------------------------------------------

int Power(int x, int N) {
	if (N == 0) {
		return 1;
	}
	else
		return(Power(x, N - 1)*x);
}
int main() {
	cout << "N\t2^N " << endl;
	cout << "-----------------" << endl;

	for (int N = 0; N <= 20; N++) {
		cout << N << "\t" << Power(2, N) << endl;
	}
	return 0;
}

/*------------------------------------------------------------------------
							EXAMPLE 3.2
--------------------------------------------------------------------------

void rev() {
	char ch;
	cin.get(ch);
	if (ch != '\n') {
		rev();
		cout.put(ch);
	}
}
int main() {
	rev();
	_getch();
	return 0;

}

/*------------------------------------------------------------------------
                            EXAMPLE 3.1
--------------------------------------------------------------------------


int fact(int n)
{
	if (n == 0)
	{
		return 1;
	}
	else
		return (n*fact(n - 1));

}

int main() {
	cout << fact(5);
	_getch();
	return 0;
}
*/