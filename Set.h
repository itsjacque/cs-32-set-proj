//
//  Set.hpp
//  cs 32 project 2
//
//  Created by Jacqueline Nguyen on 1/27/23.
//

#ifndef Set_h
#define Set_h

#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

class Set;

void unite(const Set& s1, const Set& s2, Set& result);

void butNot(const Set& s1, const Set& s2, Set& result);

using ItemType = std::string; //TheTypeOfElementGoesHere;


class Set
{
  public:
    Set();
    ~Set();
    Set (const Set &src);
    Set &operator=(const Set&src);
    bool empty() const;
    int size() const;
    bool insert(const ItemType& value);
    bool erase(const ItemType& value);
    bool contains(const ItemType& value) const;
    bool get(int pos, ItemType& value) const;
    void swap(Set& other);
 private:
    int nOfItems;
    struct Node {
        ItemType value;
        Node *next;
        Node *prev;
    };
    Node *head;
    
};


#endif /* Set_h */
