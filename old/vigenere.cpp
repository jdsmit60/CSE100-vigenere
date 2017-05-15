#include <string>
#include <iostream>

using namespace std;

bool isStringAlpha(string testString);
void stringToUpper(string& editedString);

int main(int argc,char *argv[]) {

	string keyword = argv[1];
	string plaintext;
	string ciphertext;

	// input validation

	if(argc != 2 || !(isStringAlpha(keyword))) {
		cout << endl << "Usage:" << endl << endl
		     << "vigenere [keyword]" << endl
		     << "    Encrypt some plaintext using [keyword]." << endl
		     << "    [keyword] must contain only letters. [keyword] cannot contain whitespace characters." << endl
		     << "    Plaintext is entered after program execution begins." << endl
		     << "vigenere {-h --help}" << endl
		     << "    Prints this help." << endl << endl;
		     return 1;
	}

	cout << "Enter plaintext here. Your plaintext is allowed to contain any valid character,\nbut only alphabetical characters will be enciphered." << endl
	     << "plaintext: ";
	getline(cin,plaintext);
	stringToUpper(plaintext);
	stringToUpper(keyword);

	for(int i = 0, keyindex = 0; i < plaintext.length(); i++) {
		if(isalpha(plaintext[i])) {
			ciphertext += ((plaintext[i]-'A') + (keyword[keyindex % keyword.length()]-'A')) % 26 + 'A';
			keyindex++;
		}
		else {
			ciphertext += plaintext[i];
		}
	}

	cout << "ciphertext: " << ciphertext << endl;

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

void stringToUpper(string& editedString) {

	for(int i = 0; i < editedString.length(); i++) {
		editedString[i] = toupper(editedString[i]);
	}
}
