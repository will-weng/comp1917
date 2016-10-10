    // a concrete linked list
    // list is a pointer to a struct - containing the head ptr
     
    typedef struct _node *link;    // a link points ot a node
     
    typedef struct _node {
        int value;
    	link next;
    } node;
     
    // a list is represented by a pointer to a struct which contains 
    // a pointer to the first node of the list called the "head"
    typedef struct _list {
        link head;
    } *list; 
    
    
    

// create an empty list

list newList (void);

// delete the first node
void deleteHead (list l);

// delete the end node
void deleteLast (list l);

// join two lists

// move all the elements from the second list to the end of
// the first list (in order).  this leaves the second list
// empty and all the elements in the first list. 
void concatenate (list to, list from);

// count the number of nodes containing 42
int count42s (list l);

void testList (void);
