#include <string>
#include <iostream>
#include "VigenereContainer.h"

using namespace std;

bool isStringAlpha(string testString);

int main(int argc,char *argv[]) {

	// input validation

	if(argc != 3 || !(isStringAlpha(argv[2])) || !(argv[1] != "-e" || argv[1] != "--encipher" || argv[1] != "-d" || argv[1] != "--decipher")) {
		cout << endl << "Usage:" << endl << endl
		     << "vigenere {-e --encipher} [keyword]" << endl
		     << "    Encrypt some plaintext using [keyword]." << endl
		     << "    [keyword] must contain only letters. [keyword] cannot contain whitespace characters." << endl
		     << "    Plaintext is entered after program execution begins." << endl
		     << "vigenere {-d --decipher} [keyword]" << endl
		     << "    Decrypt some ciphertext using [keyword]." << endl
		     << "    [keyword] must contain only letters. [keyword] cannot contain whitespace characters." << endl
		     << "    Ciphertext is entered after program execution begins." << endl
		     << "vigenere {-h --help}" << endl
		     << "    Prints this help." << endl << endl;
		     return 1;
	}


	// convert command-line options from c-strings to c++ string objects so that comparisons work properly
	string option = argv[1];
	string keyword = argv[2];


	if(option == "-e" || option == "--encipher") {

		string plaintext;

		cout << "Enter plaintext here. Your plaintext is allowed to contain any valid character,\nbut only alphabetical characters will be enciphered." << endl
		     << "plaintext: ";
		getline(cin,plaintext);

		VigenereContainer text(plaintext);

		text.encipher(keyword);

		cout << "ciphertext: " << text.getCurrentString() << endl;

	}
	else {

		string ciphertext;

		cout << "Enter ciphertext here. Your ciphertext is allowed to contain any valid character,\nbut only alphabetical characters will be deciphered." << endl
		     << "ciphertext: ";
		getline(cin,ciphertext);

		VigenereContainer text(ciphertext);

		text.decipher(keyword);

		cout << "plaintext: " << text.getCurrentString() << endl;

	}

	return 0;

}

bool isStringAlpha(string testString) {

	for(int i = 0; i < testString.length(); i++) {
		if(!(isalpha(testString[i]))) {
			return false;
		}
	}
	return true;
}
