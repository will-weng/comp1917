// List.h

#define TRUE 1
#define FALSE 0

// node struct and link typedef
// these are the nodes in our list 
typedef struct _node *link; 

typedef struct _node { 
    int value; 
    link next; 
} node;


typedef struct _list *list;

struct _list { 
    link first;
    int size;
} ;


//#########################################################################
//				YOUR TASK(S)
//#########################################################################

/*
	NOTE - you should not be simply copying values around, 
	these exercises should be completed using pointer manipulation
*/


// take a list and insert a new node, containing the value v, at position n
// note: the list is zero indexed. (first node is node 0, second node is node 1 and so on...)
// n will be >= 0, but n may not be < list length. in that case, the new node will be placed at the end of the list
void insert_at_n(list l, int n, int v);

// take a list, move all odd elements to the odd list, all even elements to the even list
// the original list, l, should be empty (its 'first' member should be equal to NULL) 
void odd_and_even(list l, list odd, list even);

// take a list and remove any duplicate entries from it
// if a duplicate is found, the first node containing that value should be removed. 
void remove_duplicates(list l);




