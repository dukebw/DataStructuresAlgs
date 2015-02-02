/* ========================================================================
   File: linked_list.cpp
   Date: Feb. 1/2015
   Revision: 1
   Creator: Brendan Duke
   Notice: (C) Copyright 2015 by BRD Inc. All Rights Reserved.
   ======================================================================== */

#include <stdlib.h>

// NOTE(brendan): singly-linked list
typedef struct Node *Link;

struct Node {
  int item;
  Link next;
};

// NOTE(brendan): append item to l; side-effects; recursive
Link rAppend(Link l, int item) {
  if(l) {
    l->next = rAppend(l->next, item);
  }
  else {
    Link result = (Link)malloc(sizeof *result);
    result->next = 0;
    result->item = item;
    return result;
  }
}

// NOTE(brendan): append l1 reversed to l2; side-effects; recursive
Link rRevAppend(Link l1, Link l2) {
}

// NOTE(brendan): reverse with side-effects; recursive
Link rReverse(Link l) {
  return rRevAppend(l, 0);
}

int main(int argc, char **argv) {
}
