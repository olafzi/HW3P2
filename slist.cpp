// CS311 Yoshii Complete all functions with their comments

// ====================================================
//HW#: HW3P1 slist  inheriting from llist
//Your name: Olaf Zielinski
//Complier:  g++
//File type: slist.cpp implementation file
//=====================================================

using namespace std;
#include<iostream>
#include"slist.h" 

// ** Make sure llist constructor and destructors have couts in them

slist::slist()
{ cout << "slist constructor: " << endl;
  Front = Rear = NULL;
  Count = 0;}

int slist::search(el_t key){
  Node *p = Front;        //temp node
  int elcount = 1;        //node counter
  while (p != NULL) {     //while p isn't null, keep going
    if (p->Elem == key)
      return elcount; //counter
    p = p->Next;        //otherwise, continue
    elcount++;          //and increment the counter.
  }
  return 0;        
}

void slist::replace(el_t element, int pos){

  if (pos <  1 || pos > Count) //check if valid number
    throw OutOfRange();             //if not, throw out of range.
  Node *p = Front;                    //otherwise, make a temporary node at front
  for (int i = 1; i < pos; i++)   //while not the designated node, increment
    p = p->Next;                    //move the p pointer along the list.
  p->Elem = element;                  //when =Node, replace the element with the new elem.

}

bool slist::operator==(const slist& OtherOne){
  if(Count != OtherOne.Count)
    return false;
  for(Node *n = Front, *on = OtherOne.Front; n != NULL && on != NULL; n = n->Next, on = on->Next)
    if(n->Elem != on->Elem)
      return false;
  return true;
}
