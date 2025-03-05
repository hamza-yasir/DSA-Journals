#pragma once

#include<iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;

class DataProcessor {
private:
	int* data;
	int size;

public:
	DataProcessor(int n);
	~DataProcessor();
	void display(int i = 0);
	int findMax(int i = 0, int maxVal = INT_MIN);
	int findMin(int i = 0, int minVal = INT_MAX);
	int sum(int i = 0);
	template <typename T>
	T product(int i = 0);
	double mean();
	double variance(int i = 0, double meanVal = -1);
	double standardDeviation();
	int modeRecursive(int currentIndex, int &maxCount, int &modeVal, int i = 0, int count = 0);
	int mode();
	void swap(int &a, int &b);
	void sortArray(int i = 0, int j = 0);
	double median();
	int search(int key, int i = 0);
};

