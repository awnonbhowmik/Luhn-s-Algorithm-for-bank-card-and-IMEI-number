#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>

using namespace std;

int main() {
	int n;
	vector<int>a;

	cout << "This program demonstrates Luhn's algorithm to check\n whether a card number or IMEI number is valid\n\n";
	cout << "Enter card number:";
	cin >> n;

	//split the number into individual digits
	while (n > 0) {
		a.push_back(n % 10);
		n /= 10;
	}

	/*its in the reverse order, so reverse the vector and get the originnal order*/
	reverse(a.begin(), a.end());

	/*start from the second rightmost digit, and double every second number moving towards the right, with starting number included*/
	for (int i = a.size() - 1; i >= 0; i -= 2)
		a[i] *= 2;

	cout << "\nDoubled...\n";
	for (auto x : a)
		cout << x << " ";

	for (int i = 0; i < a.size(); i++) {
		int sum = 0;
		while (a[i] > 0) {
			sum += a[i] % 10;
			a[i] /= 10;
		}
		a[i] = sum;
	}

	cout << "\nSum double digit numbers...\n";
	for (auto x : a)
		cout << x << " ";

	/*See if the sum of the new digits is divisible by 10. This is why
	this method is also known as the (mod 10) method*/
	cout << "\n" << (accumulate(a.begin(), a.end(), 0) % 10 ? "Valid" : "Invalid");
	return 0;
}