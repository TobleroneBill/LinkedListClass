#pragma once

// Has many Linked List Methods, for an Int based list, and a String based list
// Comments above tell you the gist of each method, but in essence, all Lists hold:
// - A chain of data type based nodes
// - The size of the chain
// - Methods for effecting the contents of the chain
// - Static methods, for creating new lists based on specfic requirements e.g. String List's print as a frame


struct intListNode {
	int Value = 0;
	intListNode* next = nullptr;
};

class LinkedList {
	int Size = 0;
	intListNode* HeadNode;
	int base = 10;

	// For use in sort combine (private so it cant be easily accessed
	void Insert(intListNode* l1ptr, intListNode* l2ptr);


public:
	// constructor
	LinkedList();

	intListNode* GetHeadPointer();
	int GetSize();
	void IncrementSize();

	// Add something to end of the list
	void Append(int ListItem);
	
	//set the value of a list item at a given index
	void SetValue(int Index,int NewVal);
	
	// if reversing in place, we shouldnt need a return value
	void ReverseList();
	
	// check list for specific value. Returns T/F for use in logic statements
	bool CheckList(int value);
	
	// Using a for loop, because that seems like easiest method to start with
	int ListSum();
	
	// returns lowest list number
	int GetLowest();

	// if even is set to false, Returns a list of odd numbers, else even
	LinkedList* OddList(bool even);
	
	// Lets user defined function be used on every element of the list. needs pointer to function adress
	void ApplyFunc(int (*func)(int, int));

	//Upadtes which base system the list is using 
	void UpdateBase(int newbase);

	// Adds 1 list to another (l1 + l2, not l2+l1. e.g 1a,1b,1c + 2a,2b,2c = 1a,1b,1c,2a,2b,2c)
	void Combine(LinkedList* l2);

	// alternates the insert of the combine(e.g. 1a,2a,1b,2b,1c,2c...etc)
	void Combine_A(LinkedList* l2);

	// Using sorted lists, combine them into a new sorted list
	void Combine_S(LinkedList* l2);

	// Select sort the list (most basic sorting)
	void SelectSort();

	//TODO: Make static
	//convert list to a single number
	int ToInt();
	long ToLong();
	long long ToLLong();

	// Actual task is easier: Wants you to return the list instead of a new int.
	// Maybe needs 2 method signatures?

	//Add 2 numbers by thier list index equivilents (e.g 12 + 21 = 33)
	static int AddAsListI(int num1, int num2);
	static LinkedList* AddAsList(int num1, int num2);
	
	// Needs some work in the final conversion (toint doesnt really cut it (maybe katarugah multi =3)
	// Multiply 2 numbers by thier list index equivilents (e.g 12 * 21 = 22)
	static LinkedList* MultiplyAsList(int num1, int num2);
	static int MultiplyAsListI(int num1, int num2);
	
	//Subtract 2 numbers by thier list index equivilents (e.g 12 - 21 = -9)
	static LinkedList* SubtractAsList(int num1, int num2);
	static int SubtractAsListI(int num1, int num2);


	// TODO: Make a list with bigger data type. 
	// Returns Fibbonachi seqeuce up to input as a list (up to like 45, because its using ints)
	static LinkedList* Fib(int size);

	// Should make a random generated list method, up to a specified user size.
	static LinkedList* RandomList(int size, float sizeMult);
	static LinkedList* RandomList(int size);

	
	// Returns a list of each digit in specified input (e.g. 1234 = 1,2,3,4)
	static LinkedList* NumToList(int Num);

	//Destructor
	~LinkedList();


	void PrintList();
};

// could use a polymorphic base list class, but for the purposes of the task, and also i hate polymorphism,
// this is just a string version of above.

struct strListNode {
	std::string Value;
	strListNode* next = nullptr;
};

class StringList {
	strListNode* Head = new strListNode;
	int Size = 0;
public:

	// constructor
	StringList(std::string input);
	StringList();

	// getters
	int GetSize();
	strListNode* GetHead();

	// Print the list
	void PrintList();

	// Add to the list
	void Append(std::string input);

	//Turn list back into a string
	std::string ToString();

	// Make frame
	static void PrintFrame(std::string input);

};

int GetDigits(int input);

void PrintHi();
