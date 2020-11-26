#include "LinkedList.h"
#include <stdexcept>

LinkedList::LinkedList() {
    tail = new Node;
    tail->prev = tail;
    tail->next = tail;
    num_of_elem = 0;
}

LinkedList::LinkedList(const LinkedList& other) {
    tail = new Node;
    tail->prev = tail;
    tail->next = tail;
    num_of_elem = 0;
    for (const_iterator it = other.begin(); it != other.end(); ++it) {
        push_back(*it);
    }
    
}

LinkedList::LinkedList(LinkedList&& other) { 
    tail = other.tail;
    num_of_elem = other.num_of_elem;
    other.tail = nullptr;
    other.num_of_elem = 0;
}

LinkedList& LinkedList::operator=(const LinkedList& other){
    if (tail == other.tail) {
        return *this;
    }
    clear();
    for (LinkedList::const_iterator it = other.begin(); it != other.end(); ++it) {
        push_back(*it);
    }
    return *this;
}

LinkedList& LinkedList::operator=(LinkedList&& other) {
    if (*this == other) {
        return *this;
    }
    clear();
    tail = other.tail;
    num_of_elem = other.num_of_elem;
    other.tail = nullptr;
    other.num_of_elem = 0;
    return *this;
}

void LinkedList::pop_front() {
    if (empty()) {
        throw std::logic_error("The list is empty!");
    }
    iterator it = begin();
    erase(it);
}


void LinkedList::pop_back() {
    if (empty()) {
        throw std::logic_error("The list is empty!");
    }
    iterator it = --end();
    erase(it);
}

void LinkedList::push_back(const value_type& value) {
    iterator it = end();
    insert(it, value);
}

void LinkedList::push_front(const value_type& value) {
    iterator it = begin();
    insert(it, value);
}

LinkedList::~LinkedList() {
    clear();
    delete tail;
}



int LinkedList::size() const {
    return num_of_elem;
}

bool LinkedList::empty() const {
    return (num_of_elem == 0);
}



void LinkedList::clear() {
    while (!empty()) 
        pop_front();
    
}

bool operator==(const LinkedList& left, const LinkedList& right) {
    if (left.num_of_elem != right.num_of_elem)
        return false;
    auto temp1 = left.tail->next;
    auto temp2 = right.tail->next;
    if (temp1->value != temp2->value)
        return false;
    while (temp1 != left.tail) {
        if (temp1->value != temp2->value)
            return false;
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    return true;
    
}

bool operator!=(const LinkedList& left, const LinkedList& right) {
    return !(right == left);
}

value_type& LinkedList::front(){
    if (empty()) {
        throw std::logic_error("The list is empty!");
    }
    return *begin();
}

const value_type& LinkedList::front() const {
    if (empty()) {
        throw std::logic_error("The list is empty!");
    }
    return *cbegin();
}

value_type& LinkedList::back() {
    if (empty()) {
        throw std::logic_error("The list is empty!");
    }
    return *--end();
}

const value_type& LinkedList::back() const {
    if (empty()) {
        throw std::logic_error("The list is empty!");
    }
    return *--cend();
}
int LinkedList::remove(const value_type& value) {
    int i = 0;
    iterator it = begin();
    while (it != end()) {
        if (*it == value) {
            it = erase(it);
            i++;
        }
        else {
            it++;
        }
    }
    return i;
}

LinkedList& LinkedList::operator+=(const LinkedList& other) {
    for (const_iterator it = other.begin(); it != other.end(); ++it) {
        push_back(*it);
    }
    return *this;
}

LinkedList operator+(const LinkedList& left, const LinkedList& right) {
    LinkedList* sum = new LinkedList(left);
    *sum += right;
    return *sum;
}
