#include <stdlib.h>
#include <stdio.h>
#include <assert.h>


#include "List.h"

static void print_list(list l);

void test_insert_at_n(void);
void test_odd_and_even(void);
void test_remove_duplicates(void);

int main(int argc, char* argv[])
{

    printf("Testing lists...\n------------------------------------------------\n");

    printf("UNCOMMENT THESE TESTS WHEN YOU WANT TO RUN THEM!!!!!\n");
    //test_insert_at_n();
    //test_odd_and_even();

    printf("------------------------------------------------\n>>> All tests PASSED!\n");
    return EXIT_SUCCESS;
}


void test_insert_at_n(void)
{
    printf("Testing insert_at_n()...");
    //printf("Testing insertion into an empty list...\n");

    // create list(s) and node(s) for test(s).
    list l1 = malloc(sizeof(struct _list));
    assert(l1 != NULL);
    l1->first = NULL;
    l1->size = -1;

    insert_at_n(l1, 0, 1);
    assert(l1->first->value == 1);
    insert_at_n(l1, 1, 3);
    assert(l1->first->next->value == 3);
    insert_at_n(l1, 10, 42);
    assert(l1->first->next->next->value == 42);
    insert_at_n(l1, 0, -1);
    assert(l1->first->value == -1);
    insert_at_n(l1, 1, -2);
    assert(l1->first->next->value == -2);
    insert_at_n(l1, 3, -10);
    assert(l1->first->next->next->next->value == -10);


    // cleaning up - keep australia beautiful~~~
    link del_cur = l1->first;
    l1->first = NULL;
    link del_prev;
    while(del_cur != NULL){
        del_prev = del_cur;
        del_cur = del_cur->next;
        del_prev->next = NULL;
        free(del_prev);
    }

    free(l1);

    printf("PASSED.\n");

}

void test_odd_and_even(void)
{

    printf("Testing odd_and_even()...");

    list l1 = malloc(sizeof(struct _list));
    assert(l1 != NULL);
    l1->first = NULL;
    l1->size = -1;

    list l1_odd = malloc(sizeof(struct _list));
    assert(l1_odd != NULL);
    l1_odd->first = NULL;
    l1_odd->size = -1;

    list l1_even = malloc(sizeof(struct _list));
    assert(l1_even != NULL);
    l1_even->first = NULL;
    l1_even->size = -1;

    odd_and_even(l1, l1_odd, l1_even);

    assert(l1->first == NULL);
    assert(l1_odd->first == NULL);
    assert(l1_even->first == NULL);




    list l2 = malloc(sizeof(struct _list));
    assert(l2 != NULL);
    l2->first = NULL;
    l2->size = -1;

    link new_node_7 = malloc(sizeof(struct _node));
    assert(new_node_7 != NULL);
    new_node_7->value = 8;
    new_node_7->next = NULL;


    link new_node_8 = malloc(sizeof(struct _node));
    assert(new_node_8 != NULL);
    new_node_8->value = 7;
    new_node_8->next = new_node_7;


    link new_node_6 = malloc(sizeof(struct _node));
    assert(new_node_6 != NULL);
    new_node_6->value = 6;
    new_node_6->next = new_node_8;

    link new_node_3 = malloc(sizeof(struct _node));
    assert(new_node_3 != NULL);
    new_node_3->value = 5;
    new_node_3->next = new_node_6;


    link new_node_5 = malloc(sizeof(struct _node));
    assert(new_node_5 != NULL);
    new_node_5->value = 4;
    new_node_5->next = new_node_3;

    link new_node_2 = malloc(sizeof(struct _node));
    assert(new_node_2 != NULL);
    new_node_2->value = 3;
    new_node_2->next = new_node_5;


    link new_node_4 = malloc(sizeof(struct _node));
    assert(new_node_4 != NULL);
    new_node_4->value = 2;
    new_node_4->next = new_node_2;

    link new_node_1 = malloc(sizeof(struct _node));
    assert(new_node_1 != NULL);
    new_node_1->value = 1;
    new_node_1->next = new_node_4;

    l2->first = new_node_1;



    list l2_odd = malloc(sizeof(struct _list));
    assert(l2_odd != NULL);
    l2_odd->first = NULL;
    l2_odd->size = -1;

    list l2_even = malloc(sizeof(struct _list));
    assert(l2_even != NULL);
    l2_even->first = NULL;
    l2_even->size = -1;

    odd_and_even(l2, l2_odd, l2_even);  
    assert(l2->first == NULL);

    
    //printf("Checking nodes....\n");
    assert(l2_odd->first->value == 1);
    assert(l2_odd->first->next->value == 3);
    assert(l2_odd->first->next->next->value == 5);

    assert(l2_even->first->value == 2);
    assert(l2_even->first->next->value == 4);
    assert(l2_even->first->next->next->value == 6);
    assert(l2_even->first->next->next->next->value == 8);
  
    list l3 = malloc(sizeof(struct _list));
    assert(l3 != NULL);
    l3->first = NULL;
    l3->size = -1;

    list l3_odd = malloc(sizeof(struct _list));
    assert(l3_odd != NULL);
    l3_odd->first = NULL;
    l3_odd->size = -1;

    list l3_even = malloc(sizeof(struct _list));
    assert(l3_even != NULL);
    l3_even->first = NULL;
    l3_even->size = -1;


    link new_node_a7 = malloc(sizeof(struct _node));
    assert(new_node_a7 != NULL);
    new_node_a7->value = 15;
    new_node_a7->next = NULL;


    link new_node_a8 = malloc(sizeof(struct _node));
    assert(new_node_a8 != NULL);
    new_node_a8->value = 7;
    new_node_a8->next = new_node_a7;


    link new_node_a6 = malloc(sizeof(struct _node));
    assert(new_node_a6 != NULL);
    new_node_a6->value = 13;
    new_node_a6->next = new_node_a8;

    link new_node_a3 = malloc(sizeof(struct _node));
    assert(new_node_a3 != NULL);
    new_node_a3->value = 5;
    new_node_a3->next = new_node_a6;


    link new_node_a5 = malloc(sizeof(struct _node));
    assert(new_node_a5 != NULL);
    new_node_a5->value = 11;
    new_node_a5->next = new_node_a3;

    link new_node_a2 = malloc(sizeof(struct _node));
    assert(new_node_a2 != NULL);
    new_node_a2->value = 3;
    new_node_a2->next = new_node_a5;


    link new_node_a4 = malloc(sizeof(struct _node));
    assert(new_node_a4 != NULL);
    new_node_a4->value = 9;
    new_node_a4->next = new_node_a2;

    link new_node_a1 = malloc(sizeof(struct _node));
    assert(new_node_a1 != NULL);
    new_node_a1->value = 1;
    new_node_a1->next = new_node_a4;

    l3->first = new_node_a1;

    odd_and_even(l3, l3_odd, l3_even);

    assert(l3_odd->first->value == 1);
    assert(l3_odd->first->next->value == 9);
    assert(l3_odd->first->next->next->value == 3);
    assert(l3_odd->first->next->next->next->value == 11);
    assert(l3_odd->first->next->next->next->next->value == 5);
    assert(l3_odd->first->next->next->next->next->next->value == 13);
    assert(l3_odd->first->next->next->next->next->next->next->value == 7);
    assert(l3_odd->first->next->next->next->next->next->next->next->value == 15);

    // cleaning up - keep australia beautiful~~~
    link del_cur = l1->first;
    l1->first = NULL;
    link del_prev;
    while(del_cur != NULL){
        del_prev = del_cur;
        del_cur = del_cur->next;
        del_prev->next = NULL;
        free(del_prev);
    }

    del_cur = l1_odd->first;
    l1_odd->first = NULL;
    while(del_cur != NULL){
        del_prev = del_cur;
        del_cur = del_cur->next;
        del_prev->next = NULL;
        free(del_prev);
    }

    del_cur = l1_even->first;
    l1_even->first = NULL;
    while(del_cur != NULL){
        del_prev = del_cur;
        del_cur = del_cur->next;
        del_prev->next = NULL;
        free(del_prev);
    }




    del_cur = l2->first;
    l2->first = NULL;
    while(del_cur != NULL){
        del_prev = del_cur;
        del_cur = del_cur->next;
        del_prev->next = NULL;
        free(del_prev);
    }

    del_cur = l2_odd->first;
    l2_odd->first = NULL;
    while(del_cur != NULL){
        del_prev = del_cur;
        del_cur = del_cur->next;
        del_prev->next = NULL;
        free(del_prev);
    }

    del_cur = l2_even->first;
    l2_even->first = NULL;
    while(del_cur != NULL){
        del_prev = del_cur;
        del_cur = del_cur->next;
        del_prev->next = NULL;
        free(del_prev);
    }





    del_cur = l3->first;
    l3->first = NULL;
    while(del_cur != NULL){
        del_prev = del_cur;
        del_cur = del_cur->next;
        del_prev->next = NULL;
        free(del_prev);
    }

    del_cur = l3_odd->first;
    l3_odd->first = NULL;
    while(del_cur != NULL){
        del_prev = del_cur;
        del_cur = del_cur->next;
        del_prev->next = NULL;
        free(del_prev);
    }

    del_cur = l3_even->first;
    l3_even->first = NULL;
    
    while(del_cur != NULL){
        del_prev = del_cur;
        del_cur = del_cur->next;
        del_prev->next = NULL;
        free(del_prev);
    }

    free(l1);
    free(l2);
    free(l3);

    printf("PASSED.\n");
}

void test_remove_duplicates(void)
{
    printf("Testing remove_duplicates()...");
    
    printf("PASSED\n");
}


static void print_list(list l)
{
    assert(l != NULL);

    link curr = l->first;

    while(curr != NULL){
        printf("[%d]->", curr->value);
        curr = curr->next;
    }
    printf("[X]\n");
}
