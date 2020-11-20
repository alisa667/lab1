#define CATCH_CONFIG_MAIN

#include <iostream>
#include "LinkedList.h"
#include "catch.hpp"

TEST_CASE("push") {
	//checking push_back()
	LinkedList list1;
	for (int i = 0; i < 5; i++) {
		list1.push_back(i);
	}
	int count = 0;
	for (LinkedList::iterator it = list1.begin(); it != list1.end(); it++) {
		REQUIRE(*it == count);
		count++;
	}
	REQUIRE(list1.size() == 5);
	//checking push_front()
	LinkedList list2;
	for (int i = 0; i < 5; i++) {
		list2.push_front(i);
	}
	for (LinkedList::iterator it = list2.begin(); it != list2.end(); it++) {
		REQUIRE(*it == count);
		count--;
	}
	REQUIRE(list2.size() == 5);
}

TEST_CASE("pop") {
	//checking pop back
	LinkedList list1;
	for (int i = 0; i < 5; i++) {
		list1.push_back(i);
	}
	list1.pop_back();
	REQUIRE(*list1.end() == 3);
	//checking pop front
	list1.pop_front();
	REQUIRE(*list1.begin() == 1);
}

TEST_CASE("=, +=") {
	//checking operator =
	LinkedList list1;
	list1.push_back(1);
	list1.push_back(2);
	LinkedList list2;
	list2 = list1;
	LinkedList::iterator it1 = list1.begin();
	for (LinkedList::iterator it2 = list2.begin(); it2 != list2.end(); it2++) {
		REQUIRE(*it2 == *it1);
	}
	//checking LinkedList(const LinkedList& other)
	LinkedList list3(list1);
	REQUIRE(list3 == list1);
	//checking operator +=
	int comp[4] = { 1, 2, 1, 2 };
	list3 += list2;
	int count = 0;
	for (LinkedList::iterator it3 = list3.begin(); it3 != list3.end(); it3++) {
		REQUIRE(*it3 == comp[count]);
		count++;
	}
	REQUIRE(list3.size() == 4);
}

TEST_CASE("insert") {
	//checking insert
	LinkedList list;
	list.push_back(13);
	list.push_back(17);
	LinkedList::iterator it = list.begin();
	it = list.insert(it, 3);
	REQUIRE(*(--it) == 3);
	REQUIRE(list.size() == 3);
}

TEST_CASE("remove, erase") {
	//checking erase
	LinkedList list;
	for (int i = 0; i < 7; i++) {
		list.push_back(i);
	}
	// 0 - 1 - 2 - 3 - 4 - 5 - 6
	LinkedList::iterator it = list.begin();
	++it;
	it = list.erase(it);
	REQUIRE(*it == 2);
	REQUIRE(list.size() == 6);
	// 0 - 2 - 3 - 4 - 5 - 6 
	//checking multiple erase
	LinkedList::iterator it2;
	it2 = it;
	it2++;
	it2++;
	it = list.erase(it, it2);
	REQUIRE(*it == 4);
	REQUIRE(*(--it) == 0);
	// 0 - 4 - 5 - 6
	list.push_back(5);
	int remove_number = list.remove(5);
	REQUIRE(remove_number == 2);
}
