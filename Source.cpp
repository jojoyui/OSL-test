#include <iostream>
#include <string>
#include <vector>
#include <sstream>


using namespace std;

class Checkout {
public:
	string list[99];
	double totalPrice = 0;
	int number = 0;
	
	Checkout() {
		for (int i = 0; i < 99; i++) {
			list[i] = " "; // init list
		}
	}
	void scan(string sku) {
		list[number] = sku;
		number++;
	}
	void pricingRules() {
		int atv = 0, ipd = 0, mbp = 0, vga = 0;
		for(int i = 0; list[i] != " "; i++) {
			if (list[i] == "atv") atv++;
			if (list[i] == "ipd") ipd++;
			if (list[i] == "mbp") mbp++;
			if (list[i] == "vga") vga++;
		}
		//cout << atv << ipd << mbp << vga << endl;

		// atv 
		if (atv % 3 == 0) {
			int temp = (atv / 3) * 2;
			totalPrice += temp * 109.5;
		}
		else {
			totalPrice += atv * 109.5;
		}

		// ipd
		if (ipd > 4) {
			totalPrice += ipd * 499.99;
		}
		else {
			totalPrice += ipd * 549.99;
		}

		// mbp
		vga -= mbp;
		totalPrice += mbp * 1399.99;
		totalPrice += vga * 30.0;
	}
};

int main() { 
	Checkout co;
	string list[99];

	string scan = " ";
	cout << "SKU Scanned: ";
	cin >> scan;
	stringstream ss(scan);
	vector<string> result;

	while (ss.good())
	{
		string substr;
		getline(ss, substr, ',');
		cout << substr << endl;
		co.scan(substr);
	}

	co.pricingRules();
	cout << "Total expected: " << co.totalPrice << endl;

	return 0;
}
