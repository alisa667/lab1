#pragma once
#include <cstddef>

typedef int value_type;

class LinkedList {
    friend class iterator;
    typedef struct Node {
        value_type value;
        Node* prev;
        Node* next;
    }Node;
    Node* head;
    int num_of_elem;
public:
    //������������ � ����������� ������ � ������.
    //�������, �������� - ��� ������, ����������� ������ ���������� �������� 
    //��������� ������������������. �� C++ ��������� ������ ��������� � �������
    //��������������� �������� ����������/���������� (����� �� ���������
    //��� ���������� ������� ������������������) � �������� ������������� �
    //���������� ������� (��������� �������� ���������, �� ������� ���������
    //��������).
    class iterator {
        friend class LinkedList;
        Node* elem;
    public:
        //�����������
        iterator();  
        iterator& operator=(const iterator& other);
        bool operator!=(const iterator& other) const;
        bool operator==(const iterator& other) const;
        //���������� ������ �� ������� ������� ���������.
        value_type& operator*();
        //���������� ��������� �� ������� ������� ���������.
        value_type* operator->();

        iterator& operator++();
        iterator operator++(int);
        iterator& operator--();
        iterator operator--(int);
    };
    
    class const_iterator {
        friend class LinkedList;
        Node* elem_const;
    public:
        const_iterator();
        const_iterator& operator=(const const_iterator& other);
        bool operator!=(const const_iterator& other) const;
        bool operator==(const const_iterator& other) const;
        //���������� ������ �� ������� ������� ���������.
        const value_type& operator*() const;
        //���������� ��������� �� ������� ������� ���������.
        const value_type* operator->() const;

        const_iterator& operator++();
        const_iterator operator++(int);
        const_iterator& operator--();
        const_iterator operator--(int);
    };
    /* ������������ */
    LinkedList();
    LinkedList(const LinkedList& other);
    LinkedList(LinkedList&& other);

    /* ���������� */
    ~LinkedList();

    /* �������� ������������ */
    LinkedList& operator=(const LinkedList& other);
    LinkedList& operator=(LinkedList&& other);

    /* ������ � ���������� */
    //���������� ��������, ����������� �� ������ ������� ������.
    iterator begin();
    const_iterator begin() const;
    const_iterator cbegin() const;
    //���������� ��������, ����������� �� ������� ������, ��������� �� ���������
    //�.�. ������������� � ������.
    iterator end();
    const_iterator end() const;
    const_iterator cend() const;

    /* ����������� */
    //���������� ������ ������.
    int size() const;
    //���������� ������, ���� ������ ����.
    bool empty() const;

    /* ������ � ��������� */
    //���������� ������ �� ������ ������� ������.
    value_type& front();
    const value_type& front() const;
    //���������� ������ �� ��������� ������� ������.
    value_type& back();
    const value_type& back() const;

    /* ������������ */
    //������� �������, �� ������� ��������� �������� pos.
    iterator erase(iterator position);
    //������� �������� � ��������� [begin, end).
    iterator erase(iterator begin, iterator end);
    //������� ��� ��������� value � ������.
    int remove(const value_type& value);
    //������� ������.
    void clear();

    //������� ��������� ������� ������.
    void pop_back();
    //������� ������ ������� ������.
    void pop_front();
    //��������� �������� value � ����� ������.
    void push_back(const value_type& value);
    //��������� �������� value � ������ ������.
    void push_front(const value_type& value);
    //��������� �������� value ����� ���������, �� ������� ��������� before
    iterator insert(iterator before, const value_type& value);

    /* ��������� ���������� */
    //������������ other � ������.
    LinkedList& operator+=(const LinkedList& other);

    /* ��������� ������� */
    friend bool operator!=(const LinkedList& left, const LinkedList& right);
    friend bool operator==(const LinkedList& left, const LinkedList& right);

};

/* ��������� ������� */
//���������� 2 �����
bool operator!=(const LinkedList& left, const LinkedList& right);
bool operator==(const LinkedList& left, const LinkedList& right);

//���������� ���� ������������ 2 �����.
LinkedList operator+(const LinkedList& left, const LinkedList& right);









