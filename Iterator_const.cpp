#include "LinkedList.h"

LinkedList::const_iterator::const_iterator() {
	elem_const = nullptr;
}

LinkedList::const_iterator& LinkedList::const_iterator::operator=(const LinkedList::const_iterator& other) {
	elem_const = other.elem_const;
	return *this;
}

bool LinkedList::const_iterator::operator!=(const LinkedList::const_iterator& other) const {
	return (elem_const != other.elem_const);
}

bool LinkedList::const_iterator::operator==(const LinkedList::const_iterator& other) const {
	return (elem_const == other.elem_const);
}

const value_type& LinkedList::const_iterator::operator*() const{
	return elem_const->value;
}

const value_type* LinkedList::const_iterator::operator->() const {
	return &(elem_const->value);
}

LinkedList::const_iterator& LinkedList::const_iterator::operator++() {
	elem_const = elem_const->next;
	return *this;
}

LinkedList::const_iterator& LinkedList::const_iterator::operator--() {
	elem_const = elem_const->prev;
	return *this;
}

LinkedList::const_iterator LinkedList::const_iterator::operator++(int) {
	LinkedList::const_iterator it = *this;
	++*this;
	return it;
}

LinkedList::const_iterator LinkedList::const_iterator::operator--(int) {
	LinkedList::const_iterator it = *this;
	--*this;
	return it;
}

LinkedList::const_iterator LinkedList::begin() const{
	LinkedList::const_iterator it;
	it.elem_const = tail->next;
	return it;
}

LinkedList::const_iterator LinkedList::end() const{
	LinkedList::const_iterator it;
	it.elem_const = tail;
	return it;
}

LinkedList::const_iterator LinkedList::cbegin() const {
	LinkedList::const_iterator it;
	it.elem_const = tail->next;
	return it;
}

LinkedList::const_iterator LinkedList::cend() const {
	LinkedList::const_iterator it;
	it.elem_const = tail;
	return it;
}
