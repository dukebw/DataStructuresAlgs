/* ========================================================================
   File: linked_list.cpp
   Date: Feb. 1/2015
   Revision: 1
   Creator: Brendan Duke
   Notice: (C) Copyright 2015 by BRD Inc. All Rights Reserved.
   ======================================================================== */

#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 256

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
    return l;
  }
  else {
    Link result = (Link)malloc(sizeof(*result));
    result->next = NULL;
    result->item = item;
    return result;
  }
}

// NOTE(brendan): append l1 to l2; side-effects; recursive
Link rAppend(Link l1, Link l2) {
  if(l2) {
    l2->next = rAppend(l1, l2->next);
    return l2;
  }
  else {
    return l1;
  }
}

// NOTE(brendan): append l1 reversed to l2; side-effects; recursive
// i.e. returns [reversed l1, l2]
Link rRevAppend(Link l1, Link l2) {
  if(l1) {
    Link temp = l1->next;
    l1->next = l2;
    l2 = l1;
    return rRevAppend(temp, l2);
  }
  else {
    return l2;
  }
}

// NOTE(brendan): reverse with side-effects; recursive
Link rReverse(Link l) {
  return rRevAppend(l, NULL);
}

// NOTE(brendan): reverse with side-effects; iterative
Link iReverse(Link l) {
  if(l) {
    Link p = l;
    Link q = l->next;
    while(q) {
      Link temp = q->next;
      q->next = p;
      p = q;
      q = temp;
    }
    l->next = NULL;
    return p;
  }
  else {
    return NULL;
  }
}

// NOTE(brendan): return formatted string representing list
char *toString(Link l) {
  char *result = (char *)malloc(sizeof(char) * MAXLINE);
  result[0] = '[';
  int i = 1;
  if(l) {
    while(l->next) {
      // NOTE(brendan): calculate new place in array
      i += sprintf(result + i, "%d, ", l->item);
      l = l->next;
    }
    i += sprintf(result + i, "%d]", l->item);
  }
  else {
    sprintf(result + i, "]");
  }
  return result;
}

// NOTE(brendan): testing client
int main(int argc, char **argv) {
  Link l1 = NULL; 
  Link l2 = NULL;
  for(int i = 0; i < 10; ++i) {
    l1 = rAppend(l1, i);
  }
  for(int i = 10; i < 20; ++i) {
    l2 = rAppend(l2, i);
  }
  l1 = rRevAppend(l1, l2);
  printf("%s\n", toString(l1));

  l1 = rReverse(l1);
  printf("%s\n", toString(l1));
  printf("%s\n", toString(rReverse(NULL)));
  printf("%s\n", toString(rRevAppend(NULL, NULL)));
  printf("%s\n", toString(iReverse(l1)));
  printf("%s\n", toString(iReverse(NULL)));
}
