/*
File name: dictionaryList.cpp
Assignment: Lab 2 Excerise A
Completed by: John Tumacder 
Submission date: Sept 23, 2024
*/


// lookuptable.cpp

// ENSF 480 - Lab 2 - Exercise A
 
// Completed by: John Tumacder

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
  // this-> make_empty();
  this -> headM = 0;
  this -> sizeM = 0;
  this -> cursorM = 0;
  this->headM = source.headM;
  // this->sizeM = source.sizeM;

  for (Node* temp = source.headM; temp != nullptr; temp = temp->nextM){
    // cout << temp->keyM <<endl; 
    this -> insert(temp -> keyM, temp -> datumM);
    sizeM++;
  }
  // Node* temp = source.headM;
  // for (int i = 0; i < sizeM; i++)
  // {
  //   insert(temp->keyM, temp->datumM);
  //   temp = temp->nextM;
  // }
  
  if (source.cursorM != 0 ){
    find(source.cursorM -> keyM);
  } else {
    this -> cursorM = 0;
  }
  
}

Mystring DictionaryList::operator [] (const int index) const
{
  int loc = index;
  if (index == 0){
    return this->headM->datumM;
  }  
  Node* temp = this->headM;
  while (temp->nextM != nullptr){
    if (loc == 0){
      break;
    } else {
      temp = temp->nextM;
      loc = loc - 1;
    }
  }
  return temp->datumM;;
}

ostream& operator << (ostream& out, const DictionaryList& diList) {
  Node* temp = diList.headM;
  for (int i = 0; i < diList.sizeM-1; i++)
  {
    if (temp->nextM == nullptr){
      break;
    }
    // cout << temp->keyM << endl;
    cout << temp->keyM << "  " <<temp->datumM.c_str() << endl;
    temp = temp-> nextM;
  }
  return out << temp->keyM << "  " <<temp->datumM.c_str() << endl;
}
