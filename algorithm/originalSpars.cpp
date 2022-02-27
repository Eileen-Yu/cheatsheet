#include <iostream>
#include <string>
using namespace std;
#define MAX 23   // specify the number of array elements to be available

class Node {  //insert Node class to define each member of a list
public:
	Node() {}
	Node* putOneNode(Node*, string);
	string getOneNode();
	Node* getNextPointer();
	void putNextPointer(Node*);
private:
	string str;
	Node* nextPtr;
};

Node* Node::getNextPointer() {
	return nextPtr;
}
void Node::putNextPointer(Node* x) {
	this->nextPtr = x;
}
Node* Node::putOneNode(Node* x, string s) {
	Node* temp;
	temp = new Node();
	if (temp) {
		temp->nextPtr = x;
		temp->str = s;
	}
	return temp;
}
string Node::getOneNode() {
	return str;
}									//[14]

// Insert hashlist class to manage the members in the hash array.

class HashList {
public:
	HashList();
	bool putNode(string);
	void displayList();
	Node* findNode(string);
	void  deleteNode(string);
	Node* getListPointer();
private:
	Node* ListPointer;
};


HashList::HashList()
{
	ListPointer = NULL;
}

bool HashList::putNode(string udata) {
	bool x = false;
	Node A;
	Node* temp1;
	temp1 = A.putOneNode(ListPointer, udata);
	if (temp1 != NULL)
	{
		ListPointer = temp1;
		x = true;
	}
	return x;
}
Node* HashList::getListPointer() {
	return ListPointer;
}
Node* HashList::findNode(string udata) {
	Node* temp;
	for (temp = ListPointer; temp != NULL && temp->getOneNode() != udata;
		temp = temp->getNextPointer());
	return temp;
}
void HashList::displayList() {
	Node* temp;
	for (temp = ListPointer; temp != NULL;
		temp = temp->getNextPointer())
		cout << " " << temp->getOneNode();
	cout << endl;
}
void HashList::deleteNode(string udata) {
	Node* delPtr = findNode(udata);
	if (delPtr != NULL) {						//[15]
		if (ListPointer == delPtr)
			ListPointer = delPtr->getNextPointer();
		else {
			Node* previousPtr;
			Node* temp = ListPointer;
			for (previousPtr = NULL; temp != delPtr;
				previousPtr = temp, temp = temp->
							getNextPointer());
			previousPtr->putNextPointer(delPtr->getNextPointer());
		}
		delete delPtr;
	}
	else
		cout << "Invalid data entered" << endl;
}

int main() {
	char inputLine[80] = "";       // input buffer
	int hashValue, modHash, i;
	HashList namePtr[MAX];
	cout << "Please enter each string of characters followed by <Enter>. " 
		<< endl;
	while (!cin.eof()) { // while loop to accept user data and to develop
				// hashed entry
		cin.getline(inputLine, 80);  // get user input string -- up to 
						// 80 characters
		// Enter element into data structure
		if (!cin.eof()) {   
			hashValue = 0;
			for (i = 0; i < strlen(inputLine); i++) { 
				hashValue += (int)inputLine[i];  
			}
			modHash = hashValue % MAX;  
			namePtr[modHash].putNode(inputLine);
			cout << " hashes to position " << modHash << endl;
        }
	}

	for (i = 0; i < MAX; i++) {   
		if (namePtr[i].getListPointer()) {
			cout << "For position " << i 
				<< " attached list follows: ";
			namePtr[i].displayList();
		}
	}
	return 0;
}
