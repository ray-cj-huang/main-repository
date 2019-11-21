#include <iostream>
#include <string>
using namespace std;

int main() {

	cout << "Defendant: ";
	string defName;
	getline(cin, defName);

	cout << "Amount paid (in thousands): ";
	double amtPaid;
	cin >> amtPaid;

	cin.ignore(10000, '\n'); //remove the additional line from cin >>

	cout << "Fake athlete? (y/n): ";
	string fake;
	getline(cin, fake);

	//create variables used in calculation below
	double fine = 20;
	double notFined = amtPaid;
	double percFined;
	
	//determine the percentage fined for the next $210 thousand paid
	//have to be outside the calculation to make sure percFined is initialized every time
	if (fake == "y")
		percFined = 0.22;
	else //cannot use else if because percFined will not be initiailzed when input err
		percFined = 0.10;

	//calculate the fine
	if (amtPaid <= 40)
		fine += amtPaid * .66;
	else {
		fine += 40.0 * .66;
		notFined -= 40;
		if (notFined <= 210) {
			fine += notFined * percFined;
		}
		else {
			fine += 210 * percFined;
			notFined -= 210;
			fine += notFined * 0.14;
		}
	}

	//set output double to one decimal place
	cout.setf(ios::fixed);
	cout.precision(1);

	cout << "---" << endl;

	//print out result
	if (defName == "")
		cout << "You must enter a defendant name." << endl;
	else if (amtPaid < 0)
		cout << "The amount paid must not be negative." << endl;
	else if (fake == "y" || fake == "n")
		cout << "The suggested fine for " << defName << " is $" << fine << " thousand." << endl;
	else
		cout << "You must enter y or n." << endl;

}