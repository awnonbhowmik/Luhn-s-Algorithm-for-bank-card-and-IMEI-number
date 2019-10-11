#include <iostream>
#include <numeric>			//for accumulate()
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	uint64_t n;
	vector<int>a;

	cout << "Enter the number:";
	cin >> n;

	while (n > 0) {
		a.push_back(n % 10);
		n /= 10;
	}

	if (a.size() == 15 || a.size() == 16)
		cout << "\nCould be a IMEI or IMEISV number or credit card number\n";
	else if (a.size() == 16 || a.size() == 17)
		cout << "\nCould be a credit card number\n";
	else {
		cout << "Invalid CC or IMEI/IMEI-SV number";
		return 0;
	}

	for (auto x : a)
		cout << x << " ";

	//The vector contains the original number in reverse, so reversing it will correct the order
	reverse(a.begin(), a.end());

	cout << "\nThe original number split version looks like...\n";
	for (auto x : a)
		cout << x << " ";

	cout << "\n\n";
	switch (a[0])
	{
	case 3:
		cout << "\nPossibly a Travel/Entertainment card";
		break;

	case 4:
		cout << "\nPossibly a Visa card";
		break;

	case 5:
		cout << "\nPossibly a Master card";
		break;

	case 6:
		cout << "\nPossibly a Discover card";
		break;

	default:
		break;
	}

	cout << "\n\n";
	//Work from second rightmost number in the vector towards the left, doubling every other second number
	for (int i = a.size() - 2; i >= 0; i -= 2)
		a[i] *= 2;

	cout << "\nAfter Doubling, original number split looks like...\n";
	for (auto x : a)
		cout << x << " ";

	cout << "\nTurning the two digit numbers into single digit by adding the digits...\n";
	for (unsigned int i = 0; i < a.size(); i++) {
		if (a[i] > 9)
			a[i] -= 9;
	}

	for (auto x : a)
		cout << x << " ";

	cout << "\n\nChecksum: " << (accumulate(a.begin(), a.end(), 0) % 10 == 0 ? "Valid" : "Invalid");

	return 0;
}
