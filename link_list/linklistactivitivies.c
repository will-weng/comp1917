#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "linkList.h"


// create an empty list


list newList (void) {
   list newList = malloc(sizeof(struct _list));
   return newList;
}

// delete the first node
void deleteHead (list l) {
   if(l->head != NULL) {
      link currNode = l->head;
      l->head = currNode->next;
      free(currNode);
   }
}

// delete the end node
void deleteLast (list l) {
   if(l->head->next == NULL) {
      free(l->head);
      l->head = NULL;
   } else if (l->head != NULL) {
      link currNode = l->head;
      link nextNode = currNode->next;
      while(nextNode->next != NULL) {
         nextNode = nextNode->next;
         currNode = currNode->next;
      }
      free(nextNode);
      currNode->next = NULL;   
   }
}

// join two lists

// move all the elements from the second list to the end of
// the first list (in order).  this leaves the second list
// empty and all the elements in the first list. 
void concatenate (list to, list from) {

   if(to->head != NULL && from->head != NULL) {
      link endTo = to->head;
      while(endTo->next != NULL) {
         endTo = endTo->next;
      }
      link currNode = from->head;
      while(currNode->next != NULL) {
         endTo->next = currNode;
         currNode = currNode->next;
         endTo = endTo->next;
      }
      from->head = NULL;
   } else if(to->head == NULL) {
      to->head = from->head;
      from->head = NULL;
   }
}

void printList( list l){
   link it = l->head;
   while(it){
      printf("%d->",it->value);
      it = it->next;
   }
   printf("X\n");
}

// count the number of nodes containing 42
int count42s (list l) {
   printList(l);
   int counter = 0;
   if(l->head != NULL) {
      link currNode = l->head;
      while(currNode != NULL) {
         if(currNode->value == 42) {
            counter++;
         }
         currNode = currNode->next;
      }
   }
   printf("counter is %d\n", counter);
   return counter;
}
