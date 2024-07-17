//
//  Set.cpp
//  cs 32 project 2
//
//  Created by Jacqueline Nguyen on 1/27/23.
//

#include "Set.h"
#include <iostream>
using namespace std;


bool Set::empty() const {
    return (nOfItems == 0);
}

int Set::size() const {
    return nOfItems;
}

bool Set::insert(const ItemType& value) {
    Node *currNode = head->next;
    while (currNode != head) {
        // if the values are the same return false
        if (currNode->value >= value) {
            if (currNode->value == value) {
                return false;
            }
            Node* p;
            p= new Node;
            p->value= value;
            p->next= currNode;
            p->prev= currNode->prev;
            currNode->prev= p;
            currNode->prev->prev->next=p;
            nOfItems++;
            return true;
        }
        currNode= currNode->next;
    }
    // if there are no values greater than value or set is empty
        Node *p;
        p = new Node;
        p->value = value;
        p->next = head;
        p->prev = currNode->prev;

        currNode->prev=p;
        p->prev->next= p;
        nOfItems++;
        return true;
}

bool Set::erase(const ItemType& value) {
    Node *currNode = head->next;
    while (currNode != head) {
        if(currNode->value == value){
            currNode->next->prev = currNode->prev;
            currNode->prev->next = currNode->next;
            nOfItems--;
            delete currNode;
            return true;
        }
        currNode = currNode->next;
    }
    return false;
}

bool Set::contains(const ItemType& value) const {
    Node *currNode = head->next;
    while (currNode != head) {
        if(currNode->value == value) {
            return true;
        }
        currNode= currNode->next;
    }
    return false;
}

bool Set::get(int pos, ItemType& value) const {
    
    if (pos < 0 || pos >= nOfItems) {
        return false;
    }
    
    Node* currNode = head->next;
    for (int i = 0; i < pos; i++) {
        currNode = currNode->next;
    }
    value = currNode->value;
    return true;
}

void Set::swap(Set& other) {
    int temp = nOfItems;
    nOfItems = other.nOfItems;
    other.nOfItems = temp;
    
    Node* tempptr = head;
    head = other.head;
    other.head = tempptr;
}


Set::Set() {
    head = new Node;
    head->next= head;
    head->prev= head;
    nOfItems = 0;
}

Set::~Set() {
    
    Node *p = head->next;
    while (p != head) {
        Node *n = p->next;
        delete p;
        p = n;
    }
    delete head;
}

Set::Set (const Set &src) {
    
    nOfItems= src.nOfItems;
    // dummy node
    Node* p = src.head->next;
    head = new Node;
    if (p->next == p) {
        head->next = head;
        head->prev = head;
    } else {
        head->next = new Node;
        Node *currNode = head->next;
        currNode->prev = head;
        // real first node
        while (p->next != src.head) {
            currNode->value = p->value;
            Node *nextNode =  new Node;
            currNode->next = nextNode;
            currNode->next->prev = currNode;
            currNode = currNode->next;
            p = p->next;
        }
        currNode->value = p->value;
        currNode->next = head;
        head->prev = currNode;
    }
}

Set& Set::operator=(const Set&src){
    if (this != &src) {
        Set temp(src);
        swap(temp);
    }
    return *this;
}

void unite(const Set& s1, const Set& s2, Set& result) {
    ItemType x;
    Set newSet;
    result = newSet;
    for (int i = 0 ; i < s1.size(); i++) {
        s1.get(i, x);
        result.insert(x);
    }
    for (int i = 0 ; i < s2.size(); i++) {
        s2.get(i, x);
        result.insert(x);
    }
}

void butNot(const Set& s1, const Set& s2, Set& result) {
    Set newSet;
    result = newSet;
    ItemType x;

    for (int i = 0 ; i < s1.size(); i++) {
        if (s1.get(i,x)){
            if (!s2.contains(x)) {
                result.insert(x);
            }
        }
    }
    
}
