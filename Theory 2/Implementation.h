#pragma once

#include"Class.h"

// Constructor
DataProcessor::DataProcessor(int n) {
	size = n;
	data = new int[size];
	srand(time(0));
	for (int i = 0; i < size; i++) {
		data[i] = rand() % 30 + 1;
	}
}

// Destructor
DataProcessor::~DataProcessor() {
	delete[] data;
}

// Display function
void DataProcessor::display(int i) {
	if (i == size) {
		cout << endl;
		return;
	}
	cout << data[i] << " ";
	display(i + 1);
}

// Find maximum
int DataProcessor::findMax(int i, int maxVal) {
	if (i == size) return maxVal;
	return findMax(i + 1, (maxVal > data[i]) ? maxVal : data[i]);
}

// Find minimum
int DataProcessor::findMin(int i, int minVal) {
	if (i == size) return minVal;
	return findMin(i + 1, (minVal < data[i]) ? minVal : data[i]);
}

// Sum function
int DataProcessor::sum(int i) {
	if (i == size) return 0;
	return data[i] + sum(i + 1);
}

// Product function (template)
template <typename T>
T DataProcessor::product(int i) {
	if (i == size) return 1;
	return static_cast<T>(data[i]) * product<T>(i + 1);
}

// Mean function
double DataProcessor::mean() {
	return (double)sum() / size;
}

// Variance function
double DataProcessor::variance(int i, double meanVal) {
	if (meanVal == -1) meanVal = mean();
	if (i == size) return 0;
	double diff = data[i] - meanVal;
	return (diff * diff + variance(i + 1, meanVal));
}

// Standard deviation function
double DataProcessor::standardDeviation() {
	return sqrt(variance() / size);
}

// Mode recursive function
int DataProcessor::modeRecursive(int currentIndex, int &maxCount, int &modeVal, int i, int count) {
	if (i == size) {
		if (count > maxCount) {
			maxCount = count;
			modeVal = data[currentIndex];
		}
		if (currentIndex == size - 1) return modeVal;
		return modeRecursive(currentIndex + 1, maxCount, modeVal);
	}
	return modeRecursive(currentIndex, maxCount, modeVal, i + 1, count + (data[i] == data[currentIndex]));
}

int DataProcessor::mode() {
	int maxCount = 0, modeVal = data[0];
	return modeRecursive(0, maxCount, modeVal);
}

// Swap function
void DataProcessor::swap(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}

// Sort function 
void DataProcessor::sortArray(int i, int j) {
	if (i == size - 1) return;
	if (j < size - i - 1) {
		if (data[j] > data[j + 1]) swap(data[j], data[j + 1]);
		sortArray(i, j + 1);
	}
	else {
		sortArray(i + 1, 0);
	}
}

// Median function
double DataProcessor::median() {
	sortArray();
	if (size % 2 == 0)
		return (data[size / 2 - 1] + data[size / 2]) / 2.0;
	else
		return data[size / 2];
}

// Search function
int DataProcessor::search(int key, int i) {
	if (i == size) return -1;
	if (data[i] == key) return i;
	return search(key, i + 1);
}