#include "LinkedList.h"
#include <stdexcept>

LinkedList::LinkedList() {
    head = nullptr;
    num_of_elem = 0;
}

LinkedList::LinkedList(const LinkedList& other) {
    head = new Node;
    Node* temp = other.head;
    push_back(temp->value);
    while (temp != other.head->prev) {
        temp = temp->next;
        push_back(temp->value);
    }
    num_of_elem = other.num_of_elem;
}

LinkedList::LinkedList(LinkedList&& other) {
    head = new Node;
    *this = other;
    num_of_elem = other.num_of_elem;
    other.clear();
    
 
}

LinkedList& LinkedList::operator=(const LinkedList& other){
    clear();
    head = new Node;
    Node* temp = other.head;
    push_back(temp->value);
    while (temp != other.head->prev) {
        temp = temp->next;
        push_back(temp->value);
    }
    num_of_elem = other.num_of_elem;
    return *this;
}

LinkedList& LinkedList::operator=(LinkedList&& other) {
    clear();
    *this = other;
    num_of_elem = other.num_of_elem;
    other.clear();
    return *this;
}

void LinkedList::pop_front() {
    if (empty()) {
        throw std::logic_error("The list is empty!");
    }
    Node* temp = head;
    head->prev->next = head->next;
    head->next->prev = head->prev;//
    head = head->next;
    delete temp;
    num_of_elem--;
}


void LinkedList::pop_back() {
    if (empty()) {
        throw std::logic_error("The list is empty!");
    }
    Node* temp = head->prev;
    head->prev = head->prev->prev;
    head->prev->next = head;
    delete temp;
    num_of_elem--;
}

void LinkedList::push_back(const value_type& value) {
    Node* temp = new Node;
    temp->value = value;
    if (!this->empty()) {
        head->prev->next = temp;
        temp->prev = head->prev;
        head->prev = temp;
        temp->next = head;
    }
    else {
        head = temp;
        head->prev = head;
        head->next = head;
    }
    num_of_elem++;
}

void LinkedList::push_front(const value_type& value) {
    Node* temp = new Node;
    temp->value = value;
    if (!this->empty()) {
        head->prev->next = temp;
        temp->prev = head->prev;
        head->prev = temp;
        temp->next = head;
        head = temp;
    }
    else {
        head = temp;
        head->prev = head;
        head->next = head;
    }
    num_of_elem ++;
}

LinkedList::~LinkedList() {
    clear();
}



int LinkedList::size() const {
    return num_of_elem;
}

bool LinkedList::empty() const {
    return (num_of_elem == 0);
}



void LinkedList::clear() {
    while (!empty()) 
        pop_back();
    
}

bool operator==(const LinkedList& left, const LinkedList& right) {
    if (left.num_of_elem != right.num_of_elem)
        return false;
    auto temp1 = left.head->next;
    auto temp2 = right.head->next;
    if (temp1->value != temp2->value)
        return false;
    while (temp1 != left.head) {
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
    return *end();
}

const value_type& LinkedList::back() const {
    if (empty()) {
        throw std::logic_error("The list is empty!");
    }
    return *cend();
}
int LinkedList::remove(const value_type& value) {
    int i = 0;
    for (iterator it = begin(); it != end(); ++it) {
        if (*it == value) {
            it = erase(it);
            i++;
        }
    }
    if (*end() == value)
        i++;
    return i;
}

LinkedList& LinkedList::operator+=(const LinkedList& other) {
    for (const_iterator it = other.begin(); it != other.end(); ++it) {
        push_back(*it);
    }
   push_back(*other.end());
    return *this;
}

LinkedList operator+(const LinkedList& left, const LinkedList& right) {
    LinkedList* newList = new LinkedList;
    *newList += right;
    return *newList;
}