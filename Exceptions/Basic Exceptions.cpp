#include <iostream>

using namespace std;

double ShouldGoWrong (double x, double y) {
	if (y == 0.0) {
		throw -1;
	}

	if (x == -1.0) {
		throw "Divided into -1, just testing it works";
	}

	if (x + y == 10.0) {
		throw string ("testing string but this is a char for some reason...");
	}

	return x / y;
}

int main () {
	double result = 0.0;
	try {
		result = ShouldGoWrong (5.0, 5.0);
	} catch (int e) {
		if (e == -1) {
			cout << "Error Occurred: " << e << "...\nDivided by zero." << endl;
		}
	} catch (char const * e) {
		cout << "Error Occurred: " << e << endl;
	} catch (string &e) {
		cout << "Need help now... " << e.c_str() << endl;
	}

	cout << "result: " << result << endl;

	return 0;
}