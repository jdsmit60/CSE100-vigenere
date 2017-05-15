#ifndef VIGENERECONTAINTER_H
#define VIGENERECONTAINTER_H

#include <string>

using namespace std;

class VigenereContainer {

	private:

	string currentString;

	public:

	VigenereContainer();
	VigenereContainer(string);
	void encipher(string key);
	void decipher(string key);
	void setCurrentString(string newString) {
		currentString = newString;
	}
	string getCurrentString() {
		return currentString;
	}

};

#endif
