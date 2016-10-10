/*
 *  reverseList.c
 *  2013s1 Practice Prac Exam #1
 *  UNSW comp1917
 *
 *  Created by INSERT YOUR NAME HERE
 *  Share freely CC-BY-3.0
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "reverseList.h"

//reverse a link list given
list reverse (list inputList) {

   if(inputList == NULL) {
      return inputList;
   }

   list currNode = inputList->rest;
   list tempNode = currNode;
   list reverseList = inputList;
   reverseList->rest = NULL;

   while(currNode != NULL) {
      tempNode = tempNode->rest;
      currNode->rest = reverseList;
      reverseList = currNode;
      currNode = tempNode;
   }

   return reverseList;
}
