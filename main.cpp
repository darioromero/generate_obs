/*

 Code to produce random double precision numbers from a gaussian distribution
 The produced nrows of ncols will be written to a file on disk.
 This code is an attempt to write a library that will compare two different
 sets of arrays where the arrays represent some wells. We will then calculate
 the distance between then and extract the 5 closest one rows on each one row.
 Example: 
	- Array 'A' has 4 million rows with 5-columns dimensionality.
	- Array 'B' has 2 million rows with same number of columns as 'A'.

	For every row in array 'A' we want to find the 5 closest (similar) rows
	in array 'B' and do the same for every single row in 'A'.
	array 'A' will always be considered the 'principal' array.
	array 'B' will always be considered the 'secondary' array in a way that 
	          we can replace rows in array 'B' with another secondary instance.

	In essence, we want to find the 5-similar rows in array 'B' corresponding 
	            or closely similar to array 'A'.

*/

#include <iostream>
#include <fstream>
#include <ctime>
#include <random>

using namespace std;


int main() {

	int loops = 2;
	int nrows = 1; 
	int ncols = 6;

	// variable storing the random generated number
	// from the gaussian distribution
	double num;

	// open file to write row-columns
	ofstream ofs;
	ofs.open("C:/temp/matrix_xxx.csv", ios::out);

	std::random_device rd;

	double mu = 0.0, sigma = 1.0;

	// loop to write nloops-times random numbers
	time_t now = time(0);

	for (int i = 0; i < loops; i++) {
		std::mt19937 eng(rd());
		std::normal_distribution<double> normal(mu, sigma);
		for (int j = 0; j < ncols; j++) {
			num = (double)normal(eng);
			ofs << abs(num);
			if (j < (ncols - 1)) {
				 ofs << ",";
			}
		}
		ofs << endl;
	}
	ofs.close();
	time_t after = time(0);
	cout << "Elapsed: " << (after - now) << endl;

	return 0;
}