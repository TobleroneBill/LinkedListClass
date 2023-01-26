#include <iostream>
#include "LL.h"
#include <random>
#include <time.h>

//TODO - alternate Merge 

void PrintLine() {
	std::cout << "-----------------------------\n";
}

int Power(int number, int power) {
	int sum = number;
	for (int i = 1; i != power; i++) {
		sum *= number;
	}
	return sum;
}

void PrintPoop() { std::cout << "Poop" << std::endl; }

int main() {

	{
	/*
	// Creating lists
	LinkedList* newList = new LinkedList;
	LinkedList* list2 = new LinkedList;
	srand(std::time(nullptr));
	int ListSize = 20;

	for (int i = 0; i < ListSize; i++) {
		newList->Append(rand()%100);
	}
	

	newList->PrintList();
	
	// Reversing
	{
	PrintLine();
	std::cout << std::endl;
	newList->ReverseList();
	newList->PrintList();
	PrintLine();
	std::cout << std::endl;
	newList->ReverseList();
	newList->PrintList();
	}
	LinkedList* Oddlist = newList->OddList(false);
	LinkedList* EvenList = newList->OddList(true);

	// Odd and even index lists
	{
	std::cout<< "Sum: " << newList->ListSum() << std::endl;
	std::cout << "List Size: " << newList->GetSize() << std::endl;
	PrintLine();

	std::cout << "Odd List: " << std::endl;
	Oddlist->PrintList();
	PrintLine();

	std::cout << std::endl;
	std::cout << "Even List: " << std::endl;
	EvenList->PrintList();
	PrintLine();

	std::cout << std::endl;
	std::cout << "Copied List: " << std::endl;
	list2 = newList;
	list2->PrintList();
	PrintLine();

	}

	// This is really cool like HOLY SHIZA
	std::cout << std::endl;
	std::cout << "Testing: " << std::endl;
	newList->OddList(true)->PrintList();
	PrintLine();

	// Regular Combine
	{
	std::cout << std::endl;
	std::cout << "Combined List (odd+even): " << std::endl;
	Oddlist->Combine(EvenList);
	Oddlist->PrintList();
	PrintLine();

	}
	
	// AltListCombine
	{
	std::cout << "Lists before alt Combine: " << std::endl;

	LinkedList* l1 = new LinkedList;
	LinkedList* l2 = new LinkedList;

	l1->Append(1);
	l1->Append(2);
	l1->Append(3);

	l2->Append(7);
	l2->Append(8);
	l2->Append(9);

	l1->PrintList();
	l2->PrintList();


	std::cout << "Alternated Concatonated List: " << std::endl;
	l1->Combine_A(l2);
	l1->PrintList();
	PrintLine();

	//EvenList->AlternateConcatonate(Oddlist);
	}
	
	// Function passing to all items

	// Takes an adress to a function, and uses this to apply it on everything within the list. In this case,
	// Sets all item to item^2
	//newList->ApplyFunc(&Power);
	//newList->PrintList();


	
	// Selection sort =3
	{
	LinkedList* list3 = new LinkedList;
	for (int i = 0; i < 100; i++) {
		list3->Append(rand() % 100);
	}
	list3->SelectSort();
	
	EvenList->SelectSort();
	Oddlist->SelectSort();
	std::cout << std::endl;
	}
	//Sorted Combine (concatonates, and sorts at the SAME TIME (really hard to make lol)
	{
	LinkedList* poop = new LinkedList;
	LinkedList* pee = new LinkedList;

	poop->Append(100);
	poop->Append(2323);
	poop->Append(7);
	poop->Append(49);
	poop->Append(21);

	pee->Append(123);
	pee->Append(4444);
	pee->Append(60);
	pee->Append(1234);
	pee->Append(11);

	poop->SelectSort();
	pee->SelectSort();

	std::cout << "_____________________________________\n";

	poop->Combine_S(pee);
	poop->PrintList();
	}

	PrintLine();
	LinkedList* FibList = LinkedList::Fib(100);
	FibList->PrintList();

	PrintLine();
	LinkedList* RandList = LinkedList::RandomList(10);
	RandList->PrintList();

	PrintLine();

	LinkedList* RandList2 = LinkedList::RandomList(100,0);
	RandList2->SelectSort();
	RandList->SelectSort();

	PrintLine();
	RandList->Combine_S(RandList2);
	RandList->PrintList();
	PrintLine();
	LinkedList* digitList = LinkedList::NumToList(102342);
	digitList->PrintList();
	*/
	}
	
	StringList* strlist = new StringList("Hey guys hows it going, my name is johnathan banks");
	strlist->Append("yummy yummy in my tummy =3");
	strlist->PrintList();
	PrintLine();

	StringList::PrintFrame("123 ABC POO POO PEE PEE LOL aweiuhfalweglawihgaleriha");
	PrintLine();

	// lol
	StringList::PrintFrame(strlist->ToString());
	PrintLine();

	StringList::PrintFrame("ekruhaeluhgailrghaelrihaeriuhaeriguhaeirhgealirhealiraeliruaelirgilaerhgila Isaergaergaegatrgaer SAGLRGAERIGAJaihIGHRAHIGlkguHSLIFEUHwl4tiWH 9w4ht9WH4T hWO4THluwhfliUWHEFLwih4i8tW w4itWH4TI");

	LinkedList* funi = LinkedList::RandomList(4,0.5);
	funi->SelectSort();
	//funi->PrintList();
	//std::cout << funi->ToLong()<<std::endl;

	std::cout << LinkedList::AddAsListI(2, 3) << std::endl;;
	std::cout<< LinkedList::SubtractAsListI(2, 3) << std::endl;;
	std::cout << LinkedList::MultiplyAsListI(2, 3) << std::endl;;

	std::cout << LinkedList::AddAsListI(123,4444) << std::endl;;
	std::cout << LinkedList::SubtractAsListI(123, 2) << std::endl;;
	std::cout << LinkedList::MultiplyAsListI(666, 420) << std::endl;;

	LinkedList* addList = LinkedList::AddAsList(100, 230);
	LinkedList* subList = LinkedList::SubtractAsList(100, 230);
	LinkedList* MultiList = LinkedList::MultiplyAsList(100, 230);

	addList->PrintList();
	PrintLine();
	subList->PrintList();
	PrintLine();
	MultiList->PrintList();
	PrintLine();

	std::cout << addList->ToInt() << std::endl;;
	std::cout << subList->ToInt() << std::endl;;
	std::cout << MultiList->ToInt() << std::endl;;

	addList->SelectSort();
	subList->SelectSort();
	MultiList->SelectSort();

	PrintLine();
	addList->Combine_S(subList);
	addList->PrintList();
	std::cout<< "Size: " << addList->GetSize();
	PrintLine();

	//LinkedList* baseList = new LinkedList();
	LinkedList* baseList = LinkedList::RandomList(10);

	baseList->Append(55);
	PrintLine();
	baseList->PrintList();
	PrintLine();
	baseList->UpdateBase(2);
	baseList->PrintList();
	PrintLine();
	baseList->UpdateBase(10);
	baseList->PrintList();

	// to base 10 and back

	system("pause");
	return 0;
}