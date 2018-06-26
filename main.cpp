#include "Sequence.h"
#include <iostream>

int main()
{
        Sequence a("dna.txt");
	cout << "The length of DNA: "  << a.length() << endl;
	cout << "A: " << a.numberOf('A') << endl;
	cout << "T: " << a.numberOf('T') << endl;
	cout << "C: " << a.numberOf('C') << endl;
	cout << "G: " << a.numberOf('G') << endl;
	cout << "The longest consecutive: " << a.longestConsecutive() << endl;
	cout << "The longest repeated: " << a.longestRepeated() << endl;
	return 0;
}

