#include "LinkedList.h"

LinkedList::iterator::iterator() {
	elem = nullptr;
}

LinkedList::iterator &LinkedList::iterator::operator=(const LinkedList::iterator &other){
	elem = other.elem;
	return *this;
}

bool LinkedList::iterator::operator!=(const LinkedList::iterator& other) const {
	return (elem != other.elem);
}

bool LinkedList::iterator::operator==(const LinkedList::iterator& other) const {
	return (elem == other.elem);
}

value_type& LinkedList::iterator::operator*() {
	return elem->value;
}

value_type* LinkedList::iterator::operator->() {
	return &(elem->value);
}

LinkedList::iterator& LinkedList::iterator::operator++() {
	elem = elem->next;
	return *this;
}

LinkedList::iterator& LinkedList::iterator::operator--() {
	elem = elem->prev;
	return *this;
}

LinkedList::iterator LinkedList::iterator::operator++(int) {
	LinkedList::iterator it = *this;
	++*this;
	return it;
	
}

LinkedList::iterator LinkedList::iterator::operator--(int) {
	LinkedList::iterator it = *this;
	--*this;
	return it;
}

LinkedList::iterator LinkedList::begin(){
	LinkedList::iterator it;
	it.elem = tail->next;
	return it;
}

LinkedList::iterator LinkedList::end() {
	LinkedList::iterator it;
	it.elem = tail;
	return it;
}

LinkedList::iterator LinkedList::erase(LinkedList::iterator position) {
	LinkedList::iterator itTemp;
	itTemp.elem = position.elem->next;
	itTemp.elem->prev = itTemp.elem->prev->prev;
	itTemp.elem->prev->next = itTemp.elem;
	num_of_elem--;
	delete position.elem;
	return itTemp;
}

LinkedList::iterator LinkedList::erase(LinkedList::iterator begin, LinkedList::iterator end) {
	while (begin != end) {
		begin = erase(begin);
	}
	return begin;
}

LinkedList::iterator LinkedList::insert(LinkedList::iterator before, const value_type& value) {
	Node* newNode = new Node;
	newNode->value = value;
	before.elem->prev->next = newNode;
	newNode->prev = before.elem->prev;
	newNode->next = before.elem;
	before.elem->prev = newNode;
	num_of_elem++;
	return before;

}
