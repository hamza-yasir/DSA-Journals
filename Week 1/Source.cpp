#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include<string>
#include <conio.h>

using namespace std;

/* Exercise 1.6

class Student {

	string firstName,lastName;
	int marks[10];

public:
	void loadData(ifstream& file, int subjectCount) {
		file >> firstName >> lastName;
		for (int i = 0; i < subjectCount; i++) {
			file >> marks[i];
		}
	}

	float calculateAverage(int subjectCount) {
		int total = 0;
		for (int i = 0; i < subjectCount; i++) {
			total += marks[i];
		}
		return static_cast<float>(total) / subjectCount;
	}

	void showData(int subjectCount) {
		cout << left << setw(12) << firstName << "Avg: " << fixed << setprecision(1) << calculateAverage(subjectCount) << endl;
	}

	float getAvg(int subjectCount) {
		return calculateAverage(subjectCount);
	}
};

int main() {
	string fileTitle;
	Student stud[10];
	int studentCount, subjectCount;

	cout << "Enter the file name: ";
	cin >> fileTitle;
	cout << endl;

	ifstream file(fileTitle);
	if (!file) {
		cout << "Error: Unable to open file!" << endl;
		return 1;
	}

	file >> studentCount >> subjectCount;

	for (int i = 0; i < studentCount; i++) {
		stud[i].loadData(file, subjectCount);
	}

	cout << left << setw(12) << " Name" << setw(12) << "Average Score" << endl;
	cout << "-------------------------------------------------" << endl;
	for (int i = 0; i < studentCount; i++) {
		stud[i].showData(subjectCount);
	}

	float maxAvg = stud[0].getAvg(subjectCount);
	float minAvg = stud[0].getAvg(subjectCount);
	float totalClassAvg = 0;

	for (int i = 0; i < studentCount; i++) {
		float currentAvg = stud[i].getAvg(subjectCount);
		if (currentAvg > maxAvg) {
			maxAvg = currentAvg;
		}
		if (currentAvg < minAvg) {
			minAvg = currentAvg;
		}
		totalClassAvg += currentAvg;
	}

	float classAvg = totalClassAvg / studentCount;
	cout << "\nOverall Class Average: " << fixed << setprecision(2) << classAvg << endl;
	cout << "Highest Average Score: " << maxAvg << endl;
	cout << "Lowest Average Score: " << minAvg << endl;

	cout << "\nStudents scoring below the class average:\n\n";
	cout << left << setw(12) << "Name" << setw(12) << "Average Score" << endl;
	cout << "-------------------------------------------------" << endl;
	for (int i = 0; i < studentCount; i++) {
		if (stud[i].getAvg(subjectCount) < classAvg) {
			stud[i].showData(subjectCount);
		}
	}

	return 0;
}







// Exercise 1.5
class House {
public:
	char owner[21];
	char address[21];
	int bedrooms;
	float price;

	void readData() {
		
		cout << "Enter Owner: ";
		cin.getline(owner, 20);
		cout << "Enter Address: ";
		cin.getline(address, 20);
		cout << "Number of Bedrooms?: ";
		cin >> bedrooms;
		cout << "Price: ";
		cin >> price;
	}

	void displayData() {
		cout << left << setw(15) << owner << setw(25) << address << setw(15) << bedrooms << setw(15) << price << "\n";
	}
};

int main() {
	House available[100];
	int count = 0;
	char choice;

	do {

		cout << "\nEntering data for house " << count + 1 << "\n";
		if (count > 0) cin.ignore();
		available[count].readData();
		count++;
		cout << "\nEnter another house? (Y/N): ";
		cin >> choice;
	} while ((choice == 'Y' || choice == 'y') && count < 100);

	system("cls");
	cout << "\n" << left << setw(15) << "Owner" << setw(25) << "Address" << setw(15) << "Bedrooms" << setw(15) << "Price ($)" << "\n";
	cout << "----------------------------------------------------------------------\n";

	for (int i = 0; i < count; i++) {
		available[i].displayData();
	}

	_getch();
	return 0;
}



/* example 1.7
int main() {
	char name[10];
	float mt1, mt2, final, avg;

	ifstream fin;
	ofstream fout;

	fin.open("input.dat");
	fout.open("output.dat");

	while (!fin.eof()) {
		fin >> name >> mt1 >> mt2 >> final;
		avg = 0.25*mt1 + 0.25*mt2 + 0.5*final;
		fout << name << '\t' << avg << endl;

	}
	fin.close();
	fout.close();
}

Example 1.6 Exercise 1.4
int main(void)		//explicity passing void, doesnt make a difference even if not there
{
	ofstream outfile;
	outfile.open("fout.txt");
	if (!outfile) {
		cerr << "Error: Could not create fout.txt!" << endl;
		return 1;
	}
	/*if file in another folder we give pathway, e.g (" ./name of folder/file name ")
	with . representing root folder

ifstream infile;
infile.open("fin.txt");
if (!infile) {
	cerr << "Error: fin.txt not found!" << endl;
	return 1;
}

char ch;
int count = 0, wordCount = 0, sentenceCount = 0;
while (infile.get(ch)) {		// loop runs untill all characters from file read

	outfile << ch;		// copying everything from infile to outfile, no need to do it for word and sentence count
	count++;

	if (ch == ' ' || ch == '.') {
		wordCount++;
	}

	if (ch == '.' || ch == '\n') {
		sentenceCount++;
	}

}
outfile << "\n\n character count = " << count << endl;
outfile << "\n\n word count = " << wordCount << endl;
outfile << "\n\n sentence count = " << sentenceCount << endl;

infile.close();
outfile.close();

cout << "\n character count = " << count << endl;
cout << "\n word count = " << wordCount << endl;
cout << "\n sentence count = " << sentenceCount << endl;

return 0;
}

#include<iostream>
using namespace std;

template <class T, int N>
class MySequence
{
	T memblock[N];
public:
	void setmember(int x, T value);
	T getmember(int x);
	T GetMax();
	T GetMin();
};
/*
@brief : sets value to a particular index
@prams :X defines the index at which we have to save the value
Value is the value that needs to be set to the index

template <class T, int N>
void MySequence <T, N> ::setmember(int x, T value)
{
	memblock[x] = value;
}
template <class T, int N> T MySequence<T, N>::getmember(int x)
{
	return memblock[x];
}
template <class T, int N> T MySequence<T, N>::GetMax()
{
	T max = memblock[0];
	for (int i = 0; i < N; i++)
	{
		if (max < memblock[i])
		{
			max = memblock[i];
		}
	} return max;
}
template <class T, int N> T MySequence<T, N>::GetMin()
{
	T min = memblock[0];
	for (int i = 0; i < N; i++)
	{
		if (min > memblock[i])
		{
			min = memblock[i];
		}
	} return min;
}

int main()
{
	MySequence <int, 5> myints;
	MySequence <double, 5> mydoubles;
	myints.setmember(0, 100);
	myints.setmember(1, 222);
	myints.setmember(2, 333);
	mydoubles.setmember(3, 13.52);
	cout << myints.getmember(0) << endl;
	cout << mydoubles.getmember(3) << endl;
	cout << myints.GetMax() << endl;
	cout << myints.GetMin();
	return 0;
}

/*Example 1.1
int max1(int X, int Y) {
return (X>Y) ? X : Y;
}
void max2(int X, int Y, int &Larger) {
Larger = ( X > Y ) ? X : Y; }
void max3 {int X, int Y, int *Larger)
{ *Larger = (X > Y) ? X : Y; }




Exercise 1.1
#include <math.h>
class Complex {
private:
	float re, im;
public:
	Complex(float r, float i) { re = r; im = i; }
	Complex(float r)
	{ re = r; im = 0.0;}
	~Complex() {};
	double Magnitude() {
		return sqrt(re * re + Imag() * Imag());
	}
	float Real()
	{
		return re;
	}
	float Imag()
	{
		return im;
	}
	Complex operator+(Complex b)
	{
		return Complex(re + b.re, im + b.im);
	}
	Complex operator=(Complex b)
	{
		re = b.re;im = b.im; return *this;
	}
	Complex operator*(const Complex& other) {
		return Complex(re * other.re , im * other.im);
	}
	};
int main() {
	Complex a(1.0, 1.0);
	Complex* b = new Complex(5.0,3.0);
	Complex c(0, 0);
	cout << "a real = " << a.Real() << ", a imaginary = " << a.Imag() << endl;
	cout << "b real = " << b->Real() << ", b imaginary = " << b->Imag() << endl;
	c = a + (*b);
	cout << "c real = " << c.Real() << ", c imaginary = " << c.Imag() << endl;
	Complex d(0, 0);
	d = a * (*b);
	cout << "d real = " << d.Real() << ", d imaginary = " << d.Imag() << endl;
	delete b;

	return 0;
}
Example 1.4
template<class T>
class mypair
{
T a,b;
public:
mypair (T first, T second)
{ a = first ; b = second }
T getmax ();
};
template <class T>
T mypair<T>::getmax ()
{
T retval;
retval = a>b? a : b;
return retval;
}
int main ()
{
mypair <int> myobject (100, 75);
cout<< myobject.getmax();
return 0;
}
Example 1.3

T GetMax(T a, T b)
{
	T result;
	result = (a > b) ? a : b;
	return (result);
}
int main() {
	int i = 5, j = 6, k;
	long L = 10, m = 5, n;
	k = GetMax<int>(i, j);
	n = GetMax<long>(L, m);
	cout << k << endl;
	cout << n << endl;

	Example 1.4 and Exercise 1.2
	template <class T>
class mypair
{
	T a, b;
public:
	mypair(T first, T second)
	{
		a = first;
		b = second;
	}
	T GetMin();
	T GetMax();
	};
	template <class T>
	T mypair <T> :: GetMax() {
		T returnVal;
		returnVal = a > b ? a : b;
		return returnVal;
	}
	template <class T>
	T mypair <T> ::GetMin() {
		T returnVal;
		returnVal = a < b ? a : b;
		return returnVal;
	}
int main()
{
	mypair <int> myobject(100, 75);
	cout << myobject.GetMax() << endl;
	cout << myobject.GetMin();
	return 0;
}
*/
*/