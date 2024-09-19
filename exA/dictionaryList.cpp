// lookuptable.cpp

// ENSF 480 - Lab 2 - Exercise A
 
// Completed by:

#include <assert.h>
#include <iostream>
#include <stdlib.h>
#include "dictionaryList.h"
#include "mystring_B.h"

using namespace std;

Node::Node(const Key& keyA, const Datum& datumA, Node *nextA)
  : keyM(keyA), datumM(datumA), nextM(nextA)
{
}

DictionaryList::DictionaryList()
  : sizeM(0), headM(0), cursorM(0)
{
}

DictionaryList::DictionaryList(const DictionaryList& source)
{
  copy(source);
}

DictionaryList& DictionaryList::operator =(const DictionaryList& rhs)
{
  if (this != &rhs) {
    destroy();
    copy(rhs);
  }
  return *this;
}

DictionaryList::~DictionaryList()
{
  destroy();
}

int DictionaryList::size() const
{
  return sizeM;
}

int DictionaryList::cursor_ok() const
{
  return cursorM != 0;
}

const Key& DictionaryList::cursor_key() const
{
  assert(cursor_ok());
  return cursorM->keyM;
}

const Datum& DictionaryList::cursor_datum() const
{
  assert(cursor_ok());
  return cursorM->datumM;
}

void DictionaryList::insert(const int& keyA, const Mystring& datumA)
{
  // Add new node at head?                                                                                  
  if (headM == 0 || keyA < headM->keyM) {
    headM = new Node(keyA, datumA, headM);
    sizeM++;
  }
	
  // Overwrite datum at head?                                                                               
  else if (keyA == headM->keyM)
    headM->datumM = datumA;
	
  // Have to search ...                                                                                     
  else {
      
    //POINT ONE
		
    // if key is found in list, just overwrite data;                                                        
    for (Node *p = headM; p !=0; p = p->nextM)
		{
			if(keyA == p->keyM)
			{
				p->datumM = datumA;
				return;
			}
		}
		
    //OK, find place to insert new node ...                                                                 
    Node *p = headM ->nextM;
    Node *prev = headM;
		
    while(p !=0 && keyA >p->keyM)
		{
			prev = p;
			p = p->nextM;
		}
		
    prev->nextM = new Node(keyA, datumA, p);
    sizeM++;
  }
  cursorM = NULL;
	
}

void DictionaryList::remove(const int& keyA)
{
    if (headM == 0 || keyA < headM -> keyM)
        return;
    
    Node *doomed_node = 0;
    
    if (keyA == headM-> keyM) {
        doomed_node = headM;
        headM = headM->nextM;
        
        // POINT TWO
    }
    else {
        Node *before = headM;
        Node *maybe_doomed = headM->nextM;
        while(maybe_doomed != 0 && keyA > maybe_doomed-> keyM) {
            before = maybe_doomed;
            maybe_doomed = maybe_doomed->nextM;
        }
        
        if (maybe_doomed != 0 && maybe_doomed->keyM == keyA) {
            doomed_node = maybe_doomed;
            before->nextM = maybe_doomed->nextM;
        }
        
        
    } 
    if(doomed_node == cursorM)
        cursorM = 0;
    
    delete doomed_node;           // Does nothing if doomed_node == 0.
    sizeM--;
}

void DictionaryList::go_to_first()
{
    cursorM = headM;
}

void DictionaryList::step_fwd()
{
    assert(cursor_ok());
    cursorM = cursorM->nextM;
}

void DictionaryList::make_empty()
{
    destroy();
    sizeM = 0;
    cursorM = 0;
}


// The following function are supposed to be completed by the stuents, as part
// of the exercise B part II. the given fucntion are in fact place-holders for
// find, destroy and copy, in order to allow successful linking when you're
// testing insert and remove. Replace them with the definitions that work.

void DictionaryList::find(const Key& keyA)
{
  //key == int 
  //datum == string
  // cout << "\nDon't know how to find " << keyA << " (or any other key).\n";
  // cout << "... so exit is being called.\n";
  
  Node* temp = this ->  headM;
  int found = 0;
  while (temp != 0){
    if (temp ->keyM == keyA){
      cursorM = temp;
      found = 1;
      break;
    } 
      temp = temp ->nextM;
  }
  if (!found){
    cursorM = 0;
  }
}


void DictionaryList::destroy()
{
  // cout << "\nWARNING: DictionaryList::destroy() is abandoning nodes\n"
  //      << "when it should be deleting them!\n";
  go_to_first();
  while(cursorM != 0){
    Node* temp = cursorM;
    cursorM = cursorM->nextM;
    remove(temp->keyM);
  }

}


void DictionaryList::copy(const DictionaryList& source)
{
  headM = 0;
  this->sizeM = source.sizeM;
  for (Node* temp = source.headM; temp != 0; temp = temp->nextM){
    this -> insert(temp -> keyM, temp -> datumM);
  }
  if (source.cursorM != 0 ){
    find(source.cursorM -> keyM);
  } else {
    this -> cursorM = 0;
  }
  
}

Mystring DictionaryList::operator [] (const int index) const
{
  if (index == 0){
    return this->cursor_datum();
  } else {
    Node* temp = this->headM;
    while (temp->nextM != nullptr){
      if (index == 0){
        return temp->datumM;
      } else {
        temp = temp ->nextM;
      }
    }
  return "0";
}
}

ostream& operator << (ostream& out, const DictionaryList& in) {
  Node* temp = in.headM;
  for (int i = 0; i < in.sizeM; i++)
  {
    int outInt = in.cursor_key();
    Mystring outStr = in.cursor_datum();
    cout << in.cursor_key() << "  " <<in.cursor_datum();
    
  }
  
}
