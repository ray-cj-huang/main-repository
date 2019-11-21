#include <iostream>
#include <string>
#include <cassert>
using namespace std;

int appendToAll(string a[], int n, string value);
int lookup(const string a[], int n, string target);
int positionOfMax(const string a[], int n);
int rotateLeft(string a[], int n, int pos);
int countRuns(const string a[], int n);
int flip(string a[], int n);
int differ(const string a1[], int n1, const string a2[], int n2);
int subsequence(const string a1[], int n1, const string a2[], int n2);
int lookupAny(const string a1[], int n1, const string a2[], int n2);
int separate(string a[], int n, string separator);

//additional point for rotateLeft, flip, and separate if no additional array
//no algorithm from Standard C++ library or changing global variables

int main()
{	
	//test appendToAll
/*	const int n = 5;
	string people[n] = { "donald", "lindsey", "fiona", "rudy", "mick" };
	int j = appendToAll(people, n, "!!!");  // returns 5
	// now people[0] is "donald!!!", people[1] is "lindsey!!!", ...,
	// and people[4] is "mick!!!"
	for (int k = 0; k < n; k++)
	{
		cerr << people[k] << endl;
	}
	cerr << j << endl;
*/
	
	//test lookup
/*
	string officeholders[5] = { "donald", "lindsey", "mike", "adam", "nancy" };
	int j = lookup(officeholders, 5, "adam");  // returns 3
	cerr << j;
*/

	//test positionOfMax
/*
	string persons[6] = { "donald", "lindsey", "marie", "rudy", "fiona", "adam" };
	int k = positionOfMax(persons, 6);	// returns 3, since  rudy  is latest
										// in alphabetic order
	cerr << k;
*/

	//test rotateLeft
/*	const int n = 5;
	string politician[n] = { "mike", "donald", "lindsey", "nancy", "adam" };
	int m = rotateLeft(politician, n, 1);  // returns 1
		// politician now contains:  "mike", "lindsey", "nancy", "adam", "donald"
	for (int k = 0; k < n; k++)
	{
		cerr << politician[k] << endl;
	}
	cerr << m << endl;
*/

	//countRuns
/*	string d[9] = {
	"fiona", "fiona", "fiona", "fiona", "fiona", "fiona", "fiona", "fiona", "fiona"
	};
	int p = countRuns(d, 9);  //  returns 5
		   //  The five sequences of consecutive identical items are
		   //    "rudy"
		   //    "adam"
		   //    "mike", "mike"
		   //    "fiona", "fiona", "fiona"
		   //    "mike", "mike"
	cerr << p;
*/

	//test flip
/*	const int n = 5;
	string folks[7] = { "adam", "", "fiona", "mike", "rudy", "nancy", "donald" };
	int q = flip(folks, n); // returns 5
							// folks now contains:  "rudy"  "mike"  "fiona"  ""  "adam"  "nancy"  "donald"
	for (int k = 0; k < 7; k++)
	{
		cerr << folks[k] << endl;
	}
	cerr << q << endl;
*/

	//test differ
/*	string folks[7] = { "adam", "", "fiona", "mike", "rudy", "nancy", "donald" };
	string group[6] = { "adam", "", "fiona", "donald", "mike", "rudy" };
	int r = differ(folks, 7, group, 6);  //  returns 3
	int s = differ(folks, 2, group, 3);  //  returns 2

	cerr << r << endl;
	cerr << s << endl;
*/
	
	//test subsequence
/*	string names[10] = {"gordon", "marie", "nancy", "mick", "adam", "lindsey" };
	string names1[10] = { "marie", "nancy", "mick" };
	int t = subsequence(names, 6, names1, 3);  // returns 1
	string names2[10] = { "gordon", "mick" };
	int u = subsequence(names, 5, names2, 2);  // returns -1
	
	cerr << t << endl;
	cerr << u << endl;
*/

	//test lookupAny
/*	string names[10] = { "gordon", "marie", "nancy", "mick", "adam", "lindsey" };
	string set1[10] = { "donald", "adam", "mick", "marie" };
	int v = lookupAny(names, 6, set1, 4);  // returns 1 (a1 has "marie" there)
	string set2[10] = { "rudy", "fiona" };
	int w = lookupAny(names, 6, set2, 2);  // returns -1 (a1 has none)
	cerr << v << endl;
	cerr << w << endl;
*/

	//test separate
/*	string persons[6] = {"donald", "lindsey", "marie", "rudy", "fiona", "adam" };
	int x = separate(persons, 6, "gordon");  //  returns 3
	// persons must now be
	//      "donald"  "fiona"  "adam"  "lindsey"  "rudy"  "marie"
	// or   "fiona"  "adam"  "donald"  "marie"  "lindsey"  "rudy"
	// or one of several other orderings.
	// All elements < "gordon" (i.e., "fiona", "adam", and "donald")
	//   come before all others
	// All elements > "gordon" (i.e., "rudy", "lindsey", and "marie")
	//   come after all others
	string persons2[4] = {"marie", "nancy", "lindsey", "mike" };
	int y = separate(persons2, 4, "mike");  //  returns 2
	// persons2 must now be either
	//      "marie"  "lindsey"  "mike"  "nancy"
	// or   "lindsey"  "marie"  "mike"  "nancy"
	// All elements < "mike" (i.e., "lindsey" and "marie") come
		// before all others.
	// All elements > "mike" (i.e., "nancy") come after all others.

	for (int i = 0; i < 6; i++)
	{
		cout << persons[i] << endl;
	}
	cerr << x << endl;
	cerr << "---" << endl;
	for (int i = 0; i < 4; i++)
	{
		cout << persons2[i] << endl;
	}
	cerr << y << endl;
*/
	
	//test cases from spec
/*	string h[7] = { "mick", "marie", "fiona", "rudy", "", "gordon", "lindsey" };
	assert(lookup(h, 7, "gordon") == 5);
	assert(lookup(h, 7, "fiona") == 2);
	assert(lookup(h, 2, "fiona") == -1);
	assert(positionOfMax(h, 7) == 3);

	string g[4] = { "mick", "marie", "lindsey", "nancy" };
	assert(differ(h, 4, g, 4) == 2);
	assert(appendToAll(g, 4, "?") == 4 && g[0] == "mick?" && g[3] == "nancy?");
	assert(rotateLeft(g, 4, 1) == 1 && g[1] == "lindsey?" && g[3] == "marie?");

	string e[4] = { "fiona", "rudy", "", "gordon" };
	assert(subsequence(h, 7, e, 4) == 2);

	string d[5] = { "marie", "marie", "marie", "rudy", "rudy" };
	assert(countRuns(d, 5) == 2);

	string f[3] = { "lindsey", "fiona", "mike" };
	assert(lookupAny(h, 7, f, 3) == 2);
	assert(flip(f, 3) == 3 && f[0] == "mike" && f[2] == "lindsey");

	assert(separate(h, 7, "lindsey") == 3);

	cerr << "All tests succeeded" << endl;
*/
}

int appendToAll(string a[], int n, string value)
{ 
	if (n < 0) //test n to be not negative
		return -1;

	for (int i = 0; i < n; i++)
	{
		a[i] += value; //concatenate value to each string of the array
	}
	
	return n;
}

int lookup(const string a[], int n, string target)
{
	if (n < 0) //test n to be not negative
		return -1;

	for (int i = 0; i < n; i++)
	{
		if (a[i] == target) //returning the position when the string is the same as target
			return i;
	}
	
	return -1;
}

int positionOfMax(const string a[], int n)
{
	if (n < 0) //test n to be not negative
		return -1;

	int pos = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] > a[pos]) //replace max with the new max
			pos = i;
	}
	return pos; //if all string is the same or if n = 0 or if the first is thel largerst, return 0
}

int rotateLeft(string a[], int n, int pos)
{
	if (n < 0 || pos < 0 || pos >= n) //test n to be not negative and pos to be less than n
		return -1;

	string temp = a[pos]; //store the value that will be moved
	for (int i = pos; i < n - 1; i++)
	{
		a[i] = a[i + 1]; //move everything from the right of the a[pos] to the left
	}
	a[n - 1] = temp; //replace the end with the original a[pos]
	return pos;
}

int countRuns(const string a[], int n)
{
	if (n < 0) //test n to be not negative
		return -1;

	int count = 1; //if everything is the same, the count is 1
	for (int i = 0; i < n; i++)
	{
		for (int k = i; k < n; k++)
		{
			if (a[i] != a[k]) //when next string in the array is different, count adds one, i becomes the position of the different string -> continue testing
			{
				i = k-1;
				count++;
				break;
			}
		}
	}
	return count;
}

int flip(string a[], int n)
{
	if (n < 0) //test n to be not negative
		return -1;

	for (int i = 0; i < n / 2; i++) //if n is odd, n/2 gives the floor of the value -> works because the center of the array doesn't need to be swap
	{
		string temp = a[i];
		a[i] = a[n-1 - i];
		a[n-1 - i] = temp;
	}
	return n;
}

int differ(const string a1[], int n1, const string a2[], int n2)
{
	if (n1 < 0 || n2 < 0) //test n1 and n2 to be not negative
		return -1;

	//find the smaller of n1 and n2 (or if equal, then either one)
	int c;
	if (n1 < n2)
		c = n1;
	else
		c = n2;

	for (int i = 0; i < c; i++) //test until the end of the smaller sized array
	{
		if (a1[i] != a2[i])
			return i; //return the position of the one differ
	}
	return c;
}

int subsequence(const string a1[], int n1, const string a2[], int n2)
{
	if (n2 < 0 || n1 < n2) //since n2 (the size of the testing array) has to be smaller than n1 (size of the tested array), n1 just have to be tested to not be negative (return -1 otherwise)
		return -1;

	for (int i = 0; i < n1; i++)
	{
		for (int k = 0; k < n2; k++)
		{
			if (a1[i] != a2[k]) //test next position of a1 if it differs
				break;
			else
			{
				if (k == (n2 - 1)) //when all string of a2 is matched with a1
					return (i - k); //return the position of the first position of the sequence in a1
				i++;
				continue; //test next string
			}
		}
	}

	return -1; //no subsequence
}

int lookupAny(const string a1[], int n1, const string a2[], int n2)
{
	if (n1 < 0 || n2 < 0) //test n1 and n2 to be not negative
		return -1;

	for (int i = 0; i < n1; i++)
	{
		for (int k = 0; k < n2; k++) //double for-loop -> test all if any is the same -> return the position of the first one that's the same
		{
			if (a1[i] == a2[k])
				return i;
		}
	}
	return -1;
}

int separate(string a[], int n, string separator)
{
	if (n < 0) //test n to be not negative
		return -1;
	
	int c = 0; //set count variable to be 0
	
	for (int i = 0; i < n; i++) //find if there is a string that is exactly like separator -> move it to the end first (so it will be centered)
	{
		if (a[i] == separator) 
			int temp = rotateLeft(a, n, i);
	}
	
	for (int i = 0; i < n; i++)
	{
		
		if (a[i] > separator) //move the one that's greater than separator to the end
		{
			int temp = rotateLeft(a, n, i);
			i--; //have to retest the same position as the rest of array is shifted to the left once
			c++; //add count variable
		}
		if (c == n) //the max amount of actions (testing) is the amount of interesting items of the array
			break; //since i is altered to take account the shift, exit array when all items are tested
	}
	for (int i = 0; i < n; i++)
	{
		if (a[i] >= separator)
		{
			return i; //return the first string that's greater than separator
		}
	}
	return -1; //in case of no string larger than seaparator
}