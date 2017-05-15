#include <string>
#include "VigenereContainer.h"

using namespace std;

void stringToUpper(string& editedString) {

	for(int i = 0; i < editedString.length(); i++) {
		editedString[i] = toupper(editedString[i]);
	}
}

VigenereContainer::VigenereContainer() {
	currentString = "";
}

VigenereContainer::VigenereContainer(string newString) {
	currentString = newString;
}

void VigenereContainer::encipher(string key) {

	string ciphertext;

	stringToUpper(key);
	stringToUpper(currentString);

	for(int i = 0, keyindex = 0; i < currentString.length(); i++) {
		if(isalpha(currentString[i])) {
			ciphertext += ((currentString[i]-'A') + (key[keyindex % key.length()]-'A')) % 26 + 'A';
			keyindex++;
		}
		else {
			ciphertext += currentString[i];
		}
	}

	currentString = ciphertext;

}

void VigenereContainer::decipher(string key) {

	string plaintext;

	stringToUpper(key);
	stringToUpper(this->currentString);

	for(int i = 0, keyindex = 0; i < currentString.length(); i++) {
		if(isalpha(currentString[i])) {
			plaintext += (26 + (currentString[i]-'A') - (key[keyindex % key.length()]-'A')) % 26 + 'A';
			keyindex++;
		}
		else {
			plaintext += currentString[i];
		}
	}

	currentString = plaintext;

}
