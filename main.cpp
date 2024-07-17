//
//  main.cpp
//  cs 32 project 2
//
//  Created by Jacqueline Nguyen on 1/27/23.

#include "Set.h"
#include <iostream>


using namespace std;


void singleSetTests(Set& n) {
        assert(n.size() == 0);            // empty Set has size 0
    ItemType value = "alpha";
    assert(!n.get(0, value));        // nothing to get
    assert(!n.get(3, value));
    assert(value == "alpha");        // value is unchanged
    assert(n.empty());                // empty set
    assert(!n.erase(value));        // nothing to erase
    assert(!n.contains(value));        // does not contain anything
    
    assert(n.insert("brie"));        // insert
    assert(!n.insert("brie"));        // duplicate value
    assert(n.insert("cheddar"));    // greater value
    assert(n.insert("asiago"));        // lesser value
    assert(n.insert("danby"));
    assert(n.insert("gouda"));        // my favorite cheese :)
    assert(n.insert("feta"));
    assert(n.insert("havarti"));
    assert(n.insert("edam"));
 
    assert(!n.empty());                // not empty
    assert(n.size() == 8);            // 8 items
    assert(!n.erase("gruyere"));    // nonexistent item
    ItemType test1 = "";
    assert(!n.get(-1, test1));        // invalid index
    assert(!n.get(8, test1));        // invalid index
        assert(test1 == "");        // unchanged value
    assert(n.get(0, test1));        // valid index
        assert(test1 == "asiago");    // 1st item
    assert(n.get(7, test1));
        assert(test1 == "havarti");    // last item
    assert(n.contains(test1));        // contains last index
    assert(n.contains("asiago"));    // contains first index
    assert(n.contains("brie"));


    assert(n.erase(test1));                    // erases last item
        assert(!n.contains("havarti"));        // not there anymore
    assert(n.erase("asiago"));                // erases first item
        assert(!n.contains("asiago"));
    assert(n.erase("danby"));
        assert(!n.contains("danby"));
    assert(n.size() == 5);                     // five items
    assert(!n.get(5, test1));                // invalid index
    assert(n.get(4, test1));
        assert(test1 == "gouda");            // correct item
}




void uniteCheck() {             // tests the 'unite' function
    Set a, b, c;


    a.insert("A");
    a.insert("B");
    a.insert("D");
    a.insert("J");
    a.insert("H");
    
    b.insert("Q");
    b.insert("E");
    b.insert("O");
    b.insert("H");




    c.insert("A");
    c.insert("L");
    c.insert("M");
    c.insert("O");


    unite(a, b, c);                // all Sets populated


    assert(c.contains("A"));    // tests for values that should exist in 'c'
    assert(c.contains("B"));
    assert(c.contains("D"));
    assert(c.contains("E"));
    assert(c.contains("H"));
    assert(c.contains("J"));
     assert(!c.contains("L"));
    assert(!c.contains("M"));
    assert(c.contains("O"));
    assert(c.contains("Q"));


    Set d, e, f;                // all Sets empty
    unite (d, e, f);
    assert(d.empty());
    assert(e.empty());
    assert(f.empty());
}


void butNotCheck() {            // tests the 'butNot' function
    Set a, b, c, d, e;


    a.insert("A");
    a.insert("B");
    a.insert("D");
    a.insert("J");
    a.insert("H");
    
    b.insert("Q");
    b.insert("E");
    b.insert("O");
    b.insert("H");




    c.insert("A");
    c.insert("L");
    c.insert("M");
    c.insert("O");


       butNot (a, b, c);            // values in all Sets


    assert(c.contains("A"));    // tests for values that should exist in 'c'
    assert(c.contains("B"));
    assert(c.contains("D"));
    assert(!c.contains("E"));
    assert(!c.contains("H"));
    assert(c.contains("J"));
     assert(!c.contains("L"));
    assert(!c.contains("M"));
    assert(!c.contains("O"));
    assert(!c.contains("Q"));


    butNot (a, d, e);            // 2nd Set and Result are empty
    assert(c.contains("A"));
    assert(c.contains("B"));
    assert(c.contains("D"));
    assert(!c.contains("H"));
    assert(c.contains("J"));


    Set f, g, h;                // all empty Sets
    butNot (f, g, h);
    assert(f.empty());
    assert(g.empty());
    assert(h.empty());
}




const bool isEqual(const Set& s1, const Set& s2) { // returns true if two Sets are equal,
    if (s1.size() != s2.size())                 // false otherwise; implemented for
        return false;                        // testing purposes
    for (int i = s2.size() - 1; i >= 0; i--) {
        ItemType temp1;
        ItemType temp2;
        s1.get(i, temp1);
        s2.get(i, temp2);
        if (temp1 != temp2)
            return false;
    }
    return true;
}


int main() {
    Set n;
        Set m;                        // new empty Set


        singleSetTests(n);            // runs on Set n


        n.swap(m);
        assert(!m.empty());            // m is now not empty
        singleSetTests(n);            // same behavior after swap
        assert(isEqual(m, n));        // same value after tests
    
    Set p;
    Set q(p);                    // copy constructor test with empty Set
    
     p = p;                      // aliasing test
        assert(isEqual(p, p));




    singleSetTests(q);
    singleSetTests(p);
    assert(isEqual(p, q));        // same value after tests


    Set r(p);                    // copy constructor test with filled Set
 
    assert(isEqual(p, r));
    
    Set s1;
    Set s2;
    s1 = s2;                    // assignment op with empty Set
    assert(s1.empty());
    assert(s2.empty());
    assert(isEqual(s1, s2));
    singleSetTests(s1);
        singleSetTests(s2);
    assert(isEqual(s1, s2));


    Set s3;
    s3 = s1;                    // assignment op with filled Set
    assert(isEqual(s1, s3));
    assert(isEqual(s2, s3));
    
    Set s4, s5;
    s4 = s5 = s1;                // multiple assignments
    assert(isEqual(s1, s4));
    assert(isEqual(s1, s5));
    uniteCheck();
    butNotCheck();


        cout << "All tests passed." << endl;
}


