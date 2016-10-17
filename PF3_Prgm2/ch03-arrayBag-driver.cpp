//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

#include <iostream>
#include <string>
#include "ArrayBag.h"

void displayBag(ArrayBag<std::string>& bag)
{
	std::cout << "The bag contains " << bag.getCurrentSize()
		<< " items:" << std::endl;
	std::vector<std::string> bagItems = bag.toVector();
   
	int numberOfEntries = (int) bagItems.size();
	for (int i = 0; i < numberOfEntries; i++)
	{
		std::cout << bagItems[i] << " ";
	}  // end for
	std::cout << std::endl << std::endl;
}	// end displayBag

void bagTester(ArrayBag<std::string>& bag)
{
	std::cout << "isEmpty: returns " << bag.isEmpty() 
        << "; should be 1 (true)" << std::endl;
	displayBag(bag);

	std::string items[] = {"one", "two", "three", "four", "five", "one"};
	std::cout << "Add 6 items to the bag: " << std::endl;
	for (int i = 0; i < 6; i++)
	{
		bag.add(items[i]);
	}  // end for
   
	displayBag(bag);
   
	std::cout << "isEmpty: returns " << bag.isEmpty() 
        << "; should be 0 (false)" << std::endl;
	
	std::cout << "getCurrentSize: returns " << bag.getCurrentSize() 
        << "; should be 6" << std::endl;
   
	std::cout << "Try to add another entry: add(\"extra\") returns " 
        << bag.add("extra") << std::endl;      
   
	std::cout << "contains(\"three\"): returns " << bag.contains("three")
        << "; should be 1 (true)" << std::endl;
	std::cout << "contains(\"ten\"): returns " << bag.contains("ten")
        << "; should be 0 (false)" << std::endl;
	std::cout << "getFrequencyOf(\"one\"): returns "
        << bag.getFrequencyOf("one") << " should be 2" << std::endl;
	std::cout << "remove(\"one\"): returns " << bag.remove("one")
        << "; should be 1 (true)" << std::endl;
	std::cout << "getFrequencyOf(\"one\"): returns "
        << bag.getFrequencyOf("one") << " should be 1" << std::endl;
	std::cout << "remove(\"one\"): returns " << bag.remove("one")
		<< "; should be 1 (true)" << std::endl;
	std::cout << "remove(\"one\"): returns " << bag.remove("one")
        << "; should be 0 (false)" << std::endl;
	std::cout << std::endl;
   
	displayBag(bag);
   
	std::cout << "After clearing the bag, ";
	bag.clear();
   
	std::cout << "isEmpty: returns " << bag.isEmpty()
		<< "; should be 1 (true)" << std::endl;
}  // end bagTester

void bagTester2(ArrayBag<std::string>& bag)
{
	std::cout << "isEmpty: returns " << bag.isEmpty()
		<< "; should be 1 (true)" << std::endl;
	displayBag(bag);

	std::string items[] = { "one", "two", "three", "three", "four", "six", "one" };
	std::cout << "Add 7 items to the bag: " << std::endl;
	for (int i = 0; i < 7; i++)
	{
		bag.add(items[i]);
	}  // end for

	displayBag(bag);

	std::cout << "isEmpty: returns " << bag.isEmpty()
		<< "; should be 0 (false)" << std::endl;

	std::cout << "getCurrentSize: returns " << bag.getCurrentSize()
		<< "; should be 7" << std::endl;

	std::cout << "Try to add another entry: add(\"extra\") returns "
		<< bag.add("extra") << std::endl;

	std::cout << "contains(\"three\"): returns " << bag.contains("three")
		<< "; should be 1 (true)" << std::endl;
	std::cout << "contains(\"ten\"): returns " << bag.contains("ten")
		<< "; should be 0 (false)" << std::endl;
	std::cout << "getFrequencyOf(\"one\"): returns "
		<< bag.getFrequencyOf("one") << " should be 2" << std::endl;
	std::cout << "remove(\"one\"): returns " << bag.remove("one")
		<< "; should be 1 (true)" << std::endl;
	std::cout << "getFrequencyOf(\"one\"): returns "
		<< bag.getFrequencyOf("one") << " should be 2" << std::endl;
	std::cout << "remove(\"one\"): returns " << bag.remove("one")
		<< "; should be 1 (true)" << std::endl;
	std::cout << "remove(\"one\"): returns " << bag.remove("one")
		<< "; should be 1 (true)" << std::endl;
	std::cout << std::endl;

	displayBag(bag);

	std::cout << "After clearing the bag, ";
	bag.clear();

	std::cout << "isEmpty: returns " << bag.isEmpty()
		<< "; should be 1 (true)" << std::endl;
}  // end bagTester2

void bagUnionTest(ArrayBag<std::string> bag1, ArrayBag<std::string> bag2) {
	std::cout << "Populating bags with items..." << std::endl;
	std::string items1[] = { "one", "five", "one" };
	for (int i = 0; i < 3; i++)
	{
		bag1.add(items1[i]);
	}
	std::cout << "Getting current size of first bag: " << bag1.getCurrentSize() << std::endl;
	displayBag(bag1);

	std::string items2[] = { "three", "six", "one" };
	for (int i = 0; i < 3; i++)
	{
		bag2.add(items2[i]);
	}
	std::cout << "Getting current size of second bag: " << bag2.getCurrentSize() << std::endl;
	displayBag(bag2);

	std::cout << "Testing bagUnion... " << std::endl;
	bag1 = bag1.bagUnion(bag2);

	std::cout << "Testing result bag..." << std::endl;
	displayBag(bag1);
}

int main()
{
	ArrayBag<std::string> bag;
	std::cout << "Testing the first Array-Based Bag:" << std::endl;
	std::cout << "The initial first bag is empty." << std::endl;
	bagTester(bag);
	ArrayBag<std::string> bag2;
	std::cout << std::endl << "Testing the second Array-Based Bag:" << std::endl;
	std::cout << "The initial second bag is empty." << std::endl;
	bagTester2(bag2);
	std::cout << std::endl << "Testing the Bag Union function..." << std::endl << std::endl;
	bagUnionTest(bag, bag2);
	std::cout << "All done!" << std::endl;

	system("pause");
	return 0;
}	// end main

/*
 Testing the Array-Based Bag:
 The initial bag is empty.
 isEmpty: returns 1; should be 1 (true)
 The bag contains 0 items:
 
 
 Add 6 items to the bag:
 The bag contains 6 items:
 one two three four five one
 
 isEmpty: returns 0; should be 0 (false)
 getCurrentSize: returns 6; should be 6
 Try to add another entry: add("extra") returns 0
 contains("three"): returns 1; should be 1 (true)
 contains("ten"): returns 0; should be 0 (false)
 getFrequencyOf("one"): returns 2 should be 2
 remove("one"): returns 1; should be 1 (true)
 getFrequencyOf("one"): returns 1 should be 1
 remove("one"): returns 1; should be 1 (true)
 remove("one"): returns 0; should be 0 (false)
 
 The bag contains 4 items:
 five two three four
 
 After clearing the bag, isEmpty: returns 1; should be 1 (true)
 All done!
 */