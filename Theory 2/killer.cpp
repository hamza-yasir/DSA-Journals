#include"Implementation.h"

using namespace std;
int main() {
	int n = 10;
	DataProcessor dp(n);

	cout << "Generated Data: ";
	dp.display();

	cout << "\n-----------------------------------------------\n";
	cout << "Operation\t\tResult\n";
	cout << "-----------------------------------------------\n";
	cout << "Maximum\t\t\t" << dp.findMax() << endl;
	cout << "Minimum\t\t\t" << dp.findMin() << endl;
	cout << "Sum\t\t\t" << dp.sum() << endl;
	cout << "Product\t\t\t" << dp.product<long long>() << endl;
	cout << "Mean\t\t\t" << dp.mean() << endl;
	cout << "Standard Deviation\t" << dp.standardDeviation() << endl;
	cout << "Mode\t\t\t" << dp.mode() << endl;
	cout << "Median\t\t\t" << dp.median() << endl;
	cout << "-----------------------------------------------\n";

	int k;
	cout << "\nEnter the value you seek : ";
	cin >> k;
	int index = dp.search(k);
	if (index != -1)
		cout << k << " found at index " << index << endl;
	else
		cout << k << " not found" << endl;

	return 0;
}
