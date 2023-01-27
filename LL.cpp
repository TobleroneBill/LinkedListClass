#include <iostream>
#include "LL.h"
#include <random>
#include <time.h>
#include <math.h>

// For String
#include <regex>
#include <string>


//____________INT LIST______________//

//constructor
LinkedList::LinkedList(){
	Size = 0;
	HeadNode = new intListNode;
	base = 10;
}

intListNode* LinkedList::GetHeadPointer() {
	return HeadNode;
}

int LinkedList::GetSize() {
	return LinkedList::Size;
}

int LinkedList::GetBase() {
	return base;
}

void LinkedList::IncrementSize() {
	LinkedList::Size++;
}

// Add something to end of the list
void LinkedList::Append(int ListItem) {
	// If empty, set value to given item
	if (LinkedList::GetSize() == 0) {
		HeadNode->Value = ListItem;
		LinkedList::IncrementSize();
		return;
	}

	intListNode* NewNode = new intListNode;
	NewNode->Value = ListItem;

	intListNode* nextPtr = HeadNode;
	intListNode* old = HeadNode;

	// to add an item, you need to get the last item and give it an new adress of a new ListNode
	while (nextPtr) {
		// set old to current, then current to next
		old = nextPtr;
		nextPtr = nextPtr->next;
	}

	// set the last node to hold the adress of the newly added node
	old->next = NewNode;
	LinkedList::IncrementSize();
}

//set the value of a list item at a given index
void LinkedList::SetValue(int Index,int NewVal) {
	intListNode* ptr = LinkedList::GetHeadPointer();
	for (int i = 0; i != Index; i++) {
		ptr = ptr->next;
	}
	ptr->Value = NewVal;
}

// if reversing in place, we shouldnt need a return value
void LinkedList::ReverseList() {

	intListNode* mainPtr = GetHeadPointer();
	intListNode* currentPtr = mainPtr;
	intListNode* reversePtr = mainPtr;
	bool start = true;
	
	while (mainPtr) {
		if (start) {
			start = false;
			// Make the head node point to null (now last element), Then advance the pointer for rest of loops
			mainPtr = mainPtr->next;
			currentPtr->next = nullptr;
			continue;
		}

		// Idea is basically this: The main pointer goes through normally, with the reverse pointer lagging
		// behind, so it can keep track of the last adress
		// At each stage, it sets the current nodes pointer, to point towards the lagging one, Then all pointers
		// Advance. This continues until the end, where the last pointer is now the start of the list, and is
		// assigned head pointer for the list (u go gurl)

		
		currentPtr = mainPtr;				// get current position
		mainPtr = mainPtr->next;			// main ptr advances
		currentPtr->next = reversePtr;		// make the current node point to the last node
		reversePtr = currentPtr;			// reset positions for next loop
		currentPtr = mainPtr;
	}	
	//set to last before null, because the other 2 pointers will be set to null by this point
	HeadNode = reversePtr;
}

// check list for specific value. Returns T/F for use in logic statements
bool LinkedList::CheckList(int value) {
	intListNode* ptr = GetHeadPointer();
	int index = 0;
	while (ptr) {
		if (ptr->Value == value) {
			std::cout << value << " is at index " << index << std::endl;
			return true;
		}
		index++;
		ptr = ptr->next;
	}
	return false;
}


// Cool and fun :)
bool LinkedList::BinarySearch(int target) {
	// Get start and end pointers
	// Get a target int to seatch for
	// Pointer for the Middle
	// 
	// LOOP:
	// Loop to middle by for with floor(size/2)
	// Record index, and then check if value is too high or low
	// Make a new loop with a new middle, being += or -= half of middle size
	// Then keep doing this until you find the value, or if the size of the loop == 1
	// if value found, retrun true
	// else retrurn false EZ

	intListNode* start = GetHeadPointer();
	intListNode* end = start;
	intListNode* main = start;

	// this will get swapped with main if too low, as will start
	while (end) {
		end = end->next;
	}

	bool checking = true;
	int index = floor(GetSize() / 2);
	int checks = 0;
	while (checking) {
		// set main to start so it can always loop up (if a value is behind a check, this needs to be able
		// to move backwards)
		checks++;		// diagnostics
		main = start;
		for (int i = 0; i < index; i++) {
			main = main->next;
		}
		std::cout << main->Value << " Was found at index " << index << std::endl;
		// If value is less than the target
		if (main->Value < target) {
			start = main;				// The pointer will always end at halfway
			std::cout << "Target too low\n";

		}	
		if (main->Value > target) {
			std::cout << "Target too high\n";
			// too large
			end = main;
		}

		// if target found
		if (main->Value == target) { 
			std::cout << "Target found in: " << checks << std::endl;
			return true; }

		// loop size = 1 if we have looped through everything and found no match
		if (index == 1) {
			std::cout << "Target not found in: " << checks << std::endl;
			return false;
		}
		index = floor(index / 2);		// half for loop size
	}
}

int LinkedList::ListSum() {
	int sum = 0;
	intListNode* ptr = GetHeadPointer();
	while (ptr) {
		sum += ptr->Value;
		ptr = ptr->next;
	}
	return sum;
}

void LinkedList::PrintList() {
	intListNode* ptr = LinkedList::GetHeadPointer();
	int index = 0;
	while (ptr) {
		std::cout << "Value at: " << index << " is " << ptr->Value << std::endl;
		index++;
		ptr = ptr->next;
	}
}

// Return all odd, or even items (depending on what user wants)
LinkedList* LinkedList::OddList(bool even)
{
	LinkedList* OddList = new LinkedList;

	intListNode* ptr = GetHeadPointer();

	// FlipFlop decides weather to return odd/even
	bool flipFlop = false;
	if (even) { flipFlop = true; }

	while (ptr) {
		if (flipFlop) {
			OddList->Append(ptr->Value);
			flipFlop = false;
		}
		else {
			flipFlop = true;
		}
		ptr = ptr->next;
	}

	return OddList;
}

// Apply a function to all list items (engineered for squaring)
void LinkedList::ApplyFunc(int (*func)(int,int)) {
	intListNode* ptr = GetHeadPointer();
	while (ptr) {
		// have to be pretty explicit about what the function is. Cool to see this is possible tho
		ptr->Value = func(ptr->Value, 2);
		ptr = ptr->next;
	}
}

// Can only do 10-2, because otherwise we need to add letters, which cant be done in an int.
// Could make a string list representation, but think that would need to have its own conversion method.
void LinkedList::UpdateBase(int newbase) {
	if (newbase > 10 || newbase < 2) { std::cout << "invalid Range (2-10)\n"; return; }
	int oldbase = base;
	intListNode* ptr = GetHeadPointer();
	// if new base is less than the oldbase, Divide
	if (newbase < oldbase) {
		while (ptr) {
			LinkedList* finalVal = new LinkedList;
			int temp = ptr->Value;
			// need to turn each digit into a part of a list, and then reverse it so it can include 0 values)
			//take each digit in its sequence and multiply by digit * base^digit position
			while (temp!=0) {
				int next = temp / newbase; // get quotient
				int nextMod = temp % newbase; // get remainder 
				finalVal->Append(nextMod);
				temp = next;
			}
			// complicated list based way of reversing a number lol
			finalVal->ReverseList();	// reverse number
			ptr->Value = finalVal->ToInt();	// turn number as list back into int
			ptr = ptr->next;
			delete finalVal;
		}
	}
	// multiply
	// Get number of digits, and for each one, total += currentDigi*(original base^current digit)
	else {
		while (ptr) {
			LinkedList* numberList = LinkedList::NumToList(ptr->Value);
			intListNode* numberNode = numberList->GetHeadPointer();
			int digit = numberList->GetSize()-1;	//think this needs -1, because the way stuff is indexed
			int total = 0;
			while (numberNode)
			{
				int newVal = numberNode->Value * (std::pow(oldbase, digit));
				digit--;
				total += newVal;
				numberNode = numberNode->next;
			}

			ptr->Value = total;
			delete numberList;
			ptr = ptr->next;
		}
	}
	base = newbase;
}

// Right:
// Move head pointer by size, then set the previous values to be on the end of the list
// Left:
// We are moving the end to the start. end positions Listsize-input size. Then we move ptr up to that position
// and set its next to null and move each one after to the start (so we will need to keep track of that).
void LinkedList::Rotate(int size, bool right) {
	if (GetSize() <= 1) {
		std::cout << "List too small to rotate\n";
		return;
	}
	intListNode* ptr = GetHeadPointer();
	intListNode* endptr = ptr;


	if (right) {
		while (endptr->next) {
			endptr = endptr->next;	// get last node
		}

		// move pointer right
		for (int i = 0; i < size; i++) {
			endptr->next = ptr;			// Set end to here
			endptr = ptr;				// add to end of the list

			ptr = ptr->next;		// Advance position
		}
		endptr->next = nullptr;
		HeadNode = ptr; // set start to rotated position
	}
	else {
		
		intListNode* end;
		// move nodes from start , to the end - input, //idk about this: but the one before, so we can set it to the end
		for (int i = 0; i < (GetSize() - size)-1; i++) {
			endptr = endptr->next;
		}
		// the node before the start is the new end
		end = endptr;
		endptr = endptr->next;
		end->next = nullptr;
		HeadNode = endptr;	// this is the new end

		while (endptr->next)
		{
			endptr = endptr->next;
		}

		endptr->next = ptr;

	}
}

// Adds 1 list to another (l1 + l2 e.g 1a,1b,1c + 2a,2b,2c = 1a,1b,1c,2a,2b,2c).
void LinkedList::Combine(LinkedList* l2) {
	intListNode* l1ptr = GetHeadPointer();
	intListNode* l2ptr = l2->GetHeadPointer();
	//Get last pointer, and append all other values
	while (l1ptr){
		if (l1ptr->next == NULL) { break; }
		l1ptr = l1ptr->next;
	}
	while (l2ptr)
	{
		Append(l2ptr->Value);
		l2ptr = l2ptr->next;
	}
}

void LinkedList::Combine_A(LinkedList* l2) {
	// Get 2 lists, and insert the second one inbetween each element of the 1st
	intListNode* l1Ptr = GetHeadPointer();
	intListNode* l2Ptr = l2->GetHeadPointer();
	intListNode* temp = l1Ptr;

	//Have to loop through current List
	while (l1Ptr) {
		IncrementSize();
		temp = l1Ptr->next;

		intListNode* newNode = new intListNode;
		newNode->Value = l2Ptr->Value;
		newNode->next = l1Ptr->next;

		l2Ptr = l2Ptr->next;
		l1Ptr->next = newNode;
		l1Ptr = temp;
	}
	
	//loop through second list and add on if there are more values
	while (l2Ptr)
	{
		Append(l2Ptr->Value);
		l2Ptr = l2Ptr->next;
	}
	

	
}

// For below
void LinkedList::Insert(intListNode * l1ptr, intListNode * l2ptr) {
	//l1 is bigger than l2 ALWAYS
	
	intListNode* headAdress = l1ptr;
	intListNode* LastAdress = nullptr;
	// insert before l1 values
	while (l2ptr) {
		// Steps - get save the next adress for refrencing. Since l1 is always bigger, what does this mean...
		
		// what needs to happen:]
		// insert the l2 value before l1, but as a new node (since its a copy)
		// then advance l2, until it hits a value that is equal to, or greater than L1
		// once that happens, switch to the duo loop (inserting ahead of (l1 index 0)


		// l1 is at index 0 when this happens
		if (l2ptr->Value > l1ptr->Value) { break; }
		intListNode* insertNode = new intListNode;

		// 
		insertNode->Value = l2ptr->Value;
		// if null, set the head to this point, and save this memory position for else section
		if (not LastAdress) { LastAdress = insertNode; HeadNode = insertNode; }
		else {
			// set the next adress of the last node to the inserted node. Save inserted node as last adresss.
			LastAdress->next = insertNode; 
			LastAdress = insertNode;
		}
		l2ptr = l2ptr->next;
	}
	// Once we have broken out the loop, set next adress to l1head
	LastAdress->next = headAdress;

	// now loop thru 1st list, and check where to insert items
	while (l1ptr->next) {
		intListNode* temp = l1ptr->next;
		if (not l2ptr) { break; }

		if (l1ptr->next->Value > l2ptr->Value) {
			intListNode* insertNode = new intListNode;
			insertNode->Value = l2ptr->Value;
			insertNode->next = temp;

			l2ptr = l2ptr->next;
			l1ptr->next = insertNode;
			continue;
		}
		l1ptr = temp;
	}
}

// THIS used to make me feel like jesus, but now i feel like a janitor :( 
void LinkedList::Combine_S(LinkedList* l2) {

	intListNode* l1 = GetHeadPointer();
	intListNode* l2ptr = l2->GetHeadPointer();

	// checks which list is bigger, and uses that one as the base
	// Insert(l1, l2ptr);
	

	if(l1->Value > l2ptr->Value){	Insert(l1, l2ptr);}
	else {	Insert(l2ptr,l1);}

	// Recaluclate size
	int size = 0;
	l1 = GetHeadPointer();

	while (l1) {
		size++;
		l1 = l1->next;
	}
	Size = size;
}

void LinkedList::SelectSort() {
	intListNode* startIndex = GetHeadPointer();
	intListNode* ptr = startIndex;
	int loopNum = 0;
	while (startIndex) {
		intListNode* lowestPtr = ptr;
		int lowestVal = ptr->Value;
		// advance the startpointer
		while (ptr) {
			// if ptr value is lower than current lowest found value, set it and save the pointer (to swap).
			if (ptr->Value <= lowestVal) { lowestVal = ptr->Value; lowestPtr = ptr; }
			ptr = ptr->next;
		}
		loopNum++;
		// swap the 2 values
		lowestPtr->Value = startIndex->Value;
		startIndex->Value = lowestVal;

		startIndex = startIndex->next;
		ptr = startIndex;
	}
	std::cout << "Sorted: " << std::endl;
	PrintList();
}


// Returns fibbonachi sequence List up to specified sequence size
LinkedList* LinkedList::Fib(int size) {
	//Fib sequence Numbers
	LinkedList* returnList = new LinkedList;
	int num1 = 1;
	int num2 = 1;
	returnList->Append(num1);
	returnList->Append(num2);

	for (int i = 0; i <= size; i++) {
		int newNum = num1 + num2;
		// turn num2 into last num1
		num2 = num1;
		// turn num1 into current fib number
		num1 = newNum;
		// if it goes out of int range (becomes negative if too large + Range is around 45 elements)
		if (newNum < 0) { break; }
		returnList->Append(newNum);
	}

	return returnList;
}

// Returns a random list of specified size. SizeMult = element int range (default is 0-100)
LinkedList* LinkedList::RandomList(int size,float sizeMult=1) {
	LinkedList* returnList = new LinkedList;
	srand(std::time(nullptr));
	// will automatically be cast to an int, so no worries about rounding 
	int randSize = (100*sizeMult);
	if (randSize == 0) { randSize = 10; }
	
	for (int i = 0; i < size; i++) {
		returnList->Append(rand() % randSize);
	}

	return returnList;
}

// Returns a random list of specified size,  default element int range is 0-100
LinkedList* LinkedList::RandomList(int size) {
	LinkedList* returnList = new LinkedList;
	srand(std::time(nullptr));
	// will automatically be cast to an int, so no worries about rounding 
	for (int i = 0; i < size; i++) {
		returnList->Append(rand() % 100);
	}
	return returnList;
}

// Makes a list based on given int. Each element of the list is each digit of the number.
LinkedList* LinkedList::NumToList(int Num) {
	LinkedList* returnList = new LinkedList;
	int DigitCount = GetDigits(Num) - 1;	//-1 so that we get correct multiplier (only thing this is used for)
	
	for (int i = DigitCount; i >= 0; i--) {
		int Multiplier = std::pow(10, i);
		int finalVal = Num/Multiplier;
		finalVal %= 10;
		returnList->Append(finalVal);
	}
	return returnList;
}


// Converts list into a single int
int LinkedList::ToInt() {
	int Digits = 0;
	intListNode* ptr = LinkedList::GetHeadPointer();
	int finalInt = 0;
	while (ptr) {
		Digits += GetDigits(ptr->Value);
		ptr = ptr->next;
	}
	ptr = LinkedList::GetHeadPointer();
	while (ptr) {
		Digits -= (GetDigits(ptr->Value));
		finalInt += ptr->Value * pow(10, Digits);
		ptr = ptr->next;
	}
	return finalInt;
}


// In an ideal world, this would all work as a single method, but with some kind of operator variable.
// The only way i can think of doing that would be with a big switch/if statement block, and that still
// Requires too much copy paste  :/


int LinkedList::AddAsListI(int num1, int num2) {
	LinkedList* num1L = LinkedList::NumToList(num1);
	LinkedList* num2L = LinkedList::NumToList(num2);

	LinkedList* FinalInt = new LinkedList();

	intListNode* l1Ptr = num1L->GetHeadPointer();
	intListNode* l2Ptr = num2L->GetHeadPointer();

	//If one size is larger, it means the number is bigger.
	if (num1L->GetSize() != num2L->GetSize()){
		if (num1L->GetSize() > num2L->GetSize()) {
			// advance correct amount of nodes, until num2 start
			for (int i = num1L->GetSize() - num2L->GetSize(); i > 0; i--) {
				FinalInt->Append(l1Ptr->Value);
				l1Ptr = l1Ptr->next;
			}
		}
		else {
			// advance correct amount of nodes, until num1 start
			for (int i = num2L->GetSize() - num1L->GetSize(); i > 0; i--) {
				FinalInt->Append(l2Ptr->Value);
				l2Ptr = l2Ptr->next;
			}
		}
	}

	while (l2Ptr)
	{
		FinalInt->Append(l1Ptr->Value + l2Ptr->Value);
		l2Ptr = l2Ptr->next;
		l1Ptr = l1Ptr->next;
	}
	
	return FinalInt->ToInt();

}
LinkedList* LinkedList::AddAsList(int num1, int num2) {
	LinkedList* num1L = LinkedList::NumToList(num1);
	LinkedList* num2L = LinkedList::NumToList(num2);

	LinkedList* FinalInt = new LinkedList();

	intListNode* l1Ptr = num1L->GetHeadPointer();
	intListNode* l2Ptr = num2L->GetHeadPointer();

	//If one size is larger, it means the number is bigger.
	if (num1L->GetSize() != num2L->GetSize()) {
		if (num1L->GetSize() > num2L->GetSize()) {
			// advance correct amount of nodes, until num2 start
			for (int i = num1L->GetSize() - num2L->GetSize(); i > 0; i--) {
				FinalInt->Append(l1Ptr->Value);
				l1Ptr = l1Ptr->next;
			}
		}
		else {
			// advance correct amount of nodes, until num1 start
			for (int i = num2L->GetSize() - num1L->GetSize(); i > 0; i--) {
				FinalInt->Append(l2Ptr->Value);
				l2Ptr = l2Ptr->next;
			}
		}
	}

	while (l2Ptr)
	{
		FinalInt->Append(l1Ptr->Value + l2Ptr->Value);
		l2Ptr = l2Ptr->next;
		l1Ptr = l1Ptr->next;
	}

	return FinalInt;

}


int LinkedList::SubtractAsListI(int num1, int num2) {
	LinkedList* num1L = LinkedList::NumToList(num1);
	LinkedList* num2L = LinkedList::NumToList(num2);

	LinkedList* FinalInt = new LinkedList();

	intListNode* l1Ptr = num1L->GetHeadPointer();
	intListNode* l2Ptr = num2L->GetHeadPointer();

	//If one size is larger, it means the number is bigger.
	if (num1L->GetSize() != num2L->GetSize()) {
		if (num1L->GetSize() > num2L->GetSize()) {
			// advance correct amount of nodes, until num2 start
			for (int i = num1L->GetSize() - num2L->GetSize(); i > 0; i--) {
				FinalInt->Append(l1Ptr->Value);
				l1Ptr = l1Ptr->next;
			}
		}
		else {
			// advance correct amount of nodes, until num1 start
			for (int i = num2L->GetSize() - num1L->GetSize(); i > 0; i--) {
				FinalInt->Append(l2Ptr->Value);
				l2Ptr = l2Ptr->next;
			}
		}
	}

	while (l2Ptr)
	{
		FinalInt->Append(l1Ptr->Value - l2Ptr->Value);
		l2Ptr = l2Ptr->next;
		l1Ptr = l1Ptr->next;
	}

	return FinalInt->ToInt();

}
LinkedList* LinkedList::SubtractAsList(int num1, int num2) {
	LinkedList* num1L = LinkedList::NumToList(num1);
	LinkedList* num2L = LinkedList::NumToList(num2);

	LinkedList* FinalInt = new LinkedList();

	intListNode* l1Ptr = num1L->GetHeadPointer();
	intListNode* l2Ptr = num2L->GetHeadPointer();

	//If one size is larger, it means the number is bigger.
	if (num1L->GetSize() != num2L->GetSize()) {
		if (num1L->GetSize() > num2L->GetSize()) {
			// advance correct amount of nodes, until num2 start
			for (int i = num1L->GetSize() - num2L->GetSize(); i > 0; i--) {
				FinalInt->Append(l1Ptr->Value);
				l1Ptr = l1Ptr->next;
			}
		}
		else {
			// advance correct amount of nodes, until num1 start
			for (int i = num2L->GetSize() - num1L->GetSize(); i > 0; i--) {
				FinalInt->Append(l2Ptr->Value);
				l2Ptr = l2Ptr->next;
			}
		}
	}

	while (l2Ptr)
	{
		FinalInt->Append(l1Ptr->Value - l2Ptr->Value);
		l2Ptr = l2Ptr->next;
		l1Ptr = l1Ptr->next;
	}

	return FinalInt;

}


int LinkedList::MultiplyAsListI(int num1, int num2) {
	LinkedList* num1L = LinkedList::NumToList(num1);
	LinkedList* num2L = LinkedList::NumToList(num2);

	LinkedList* FinalInt = new LinkedList();

	intListNode* l1Ptr = num1L->GetHeadPointer();
	intListNode* l2Ptr = num2L->GetHeadPointer();

	//If one size is larger, it means the number is bigger.
	if (num1L->GetSize() != num2L->GetSize()) {
		if (num1L->GetSize() > num2L->GetSize()) {
			// advance correct amount of nodes, until num2 start
			for (int i = num1L->GetSize() - num2L->GetSize(); i > 0; i--) {
				FinalInt->Append(l1Ptr->Value);
				l1Ptr = l1Ptr->next;
			}
		}
		else {
			// advance correct amount of nodes, until num1 start
			for (int i = num2L->GetSize() - num1L->GetSize(); i > 0; i--) {
				FinalInt->Append(l2Ptr->Value);
				l2Ptr = l2Ptr->next;
			}
		}
	}

	while (l2Ptr)
	{
		FinalInt->Append(l1Ptr->Value * l2Ptr->Value);
		l2Ptr = l2Ptr->next;
		l1Ptr = l1Ptr->next;
	}

	return FinalInt->ToInt();

}
LinkedList* LinkedList::MultiplyAsList(int num1, int num2) {
	LinkedList* num1L = LinkedList::NumToList(num1);
	LinkedList* num2L = LinkedList::NumToList(num2);

	LinkedList* FinalInt = new LinkedList();

	intListNode* l1Ptr = num1L->GetHeadPointer();
	intListNode* l2Ptr = num2L->GetHeadPointer();

	//If one size is larger, it means the number is bigger.
	if (num1L->GetSize() != num2L->GetSize()) {
		if (num1L->GetSize() > num2L->GetSize()) {
			// advance correct amount of nodes, until num2 start
			for (int i = num1L->GetSize() - num2L->GetSize(); i > 0; i--) {
				FinalInt->Append(l1Ptr->Value);
				l1Ptr = l1Ptr->next;
			}
		}
		else {
			// advance correct amount of nodes, until num1 start
			for (int i = num2L->GetSize() - num1L->GetSize(); i > 0; i--) {
				FinalInt->Append(l2Ptr->Value);
				l2Ptr = l2Ptr->next;
			}
		}
	}

	while (l2Ptr)
	{
		FinalInt->Append(l1Ptr->Value * l2Ptr->Value);
		l2Ptr = l2Ptr->next;
		l1Ptr = l1Ptr->next;
	}

	return FinalInt;

}

// Converts list into a single long (Doesnt Work with iostream, or this is bugged (same with float))
long LinkedList::ToLong() {
	int Digits = 0;
	intListNode* ptr = LinkedList::GetHeadPointer();
	long finalInt = 0;
	std::cout<<std::flush;
	while (ptr) {
		std::cout << ptr->Value;
		Digits += GetDigits(ptr->Value);
		ptr = ptr->next;
	}
	ptr = LinkedList::GetHeadPointer();
	while (ptr) {
		Digits -= (GetDigits(ptr->Value));
		finalInt += ptr->Value * pow(10, Digits);
		ptr = ptr->next;
	}

	return finalInt;
}


//Destructor
LinkedList::~LinkedList() {
	intListNode* ptr = GetHeadPointer();
	intListNode* nextptr = ptr;
	
	while (nextptr) {
		ptr = nextptr;
		nextptr = nextptr->next;
		delete ptr;
	}

}



//____________STRINGLIST______________//
// Default Constructor
StringList::StringList() {

}

// InputConstructor
StringList::StringList(std::string input) {
	StringList::Append(input);
}

// Getters
int StringList::GetSize() {
	return Size;
}
strListNode* StringList::GetHead() {
	return Head;
}

void StringList::PrintList() {
	strListNode* ptr = StringList::GetHead();
	std::cout << "[";
	while (ptr) {
		if (ptr->next == nullptr) {
			std::cout << "\"" << ptr->Value << "\"";
		}
		else
		{
			std::cout << "\"" << ptr->Value << "\", ";

		}
		ptr = ptr->next;
	}
	std::cout << "]\n";

}



// Adds an input to the linked list, with each element split by whitespace. Uses Regex, and is more needlessly
// complicated than python regex
void StringList::Append(std::string input) {
	
	std::string newString = input;
	std::regex WordRe(R"(([\w\S]+))");
	std::smatch matches;

	// cbegin is start of word, cend is end. pass in regex to match against each word
	std::sregex_iterator pos (newString.cbegin(), newString.cend(), WordRe);
	// end = nothing, so if it stops matching, then it will == nothing, and exit the loop
	std::sregex_iterator end;

	// Loop to end of nodes
	strListNode* ptr = StringList::GetHead();
	while (ptr->next) {
		ptr = ptr->next;
	}

	
	while(pos != end) {
		if (GetSize() == 0) {
			Size++;
			GetHead()->Value = pos->str();
		}
		else {
			Size++;
			strListNode* newNode = new strListNode;
			newNode->Value = pos->str();
			ptr->next = newNode;
			ptr = ptr->next;
		}
		pos++;
	}

}

void StringList::PrintFrame(std::string input) {
	StringList* returnList = new StringList;
	returnList->Append(input);

	strListNode* ptr = returnList->GetHead();
	int charsize = 0;
	while (ptr) {
		if (ptr->Value.size() > charsize) { charsize = ptr->Value.size(); }
		ptr = ptr->next;
	}
	// now we have biggest size, we can Make the frame size 2 chars bigger
	for (int i = 0; i < charsize+4; i++) {
		std::cout << "*";
	}
	std::cout<<std::endl;

	ptr = returnList->GetHead();
	int wordsize = 0;
	while (ptr) {
		wordsize = ptr->Value.size();
		std::cout << "* " << ptr->Value;
		for (int i = 0; i < charsize - (wordsize); i++) {
			std::cout << " ";
		}
		std::cout << " *\n";
		ptr = ptr->next;
	}
	
	for (int i = 0; i < charsize + 4; i++) {
		std::cout << "*";
	}
	std::cout << std::endl;
}

std::string StringList::ToString() {
	std::string returnString = "";
	strListNode* ptr = StringList::GetHead();

	while (ptr) {
		returnString += (" " + ptr->Value);
		ptr = ptr->next;
	}

	returnString += "\n";

	return returnString;
}

// Extra Functions
int GetDigits(int input) {
	if (input / 10 == 0) { return 1; }
	else { return 1 + GetDigits(input/10); }
}

void PrintHi() {
	std::cout << "HI\n";
}