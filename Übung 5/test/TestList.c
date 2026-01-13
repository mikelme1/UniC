#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "unity.h"


void setUp(void)
{
}

void tearDown(void)
{
}

void test_main(){
   node * head = NULL;
   for (int i = 1; i < 40; i =i+3) {
      list_insert(&head,i);
   }
   list_delete(&head,4);
   list_delete(&head,10);
   list_delete(&head,16);

   list_insert(&head, -100);

   for (int i = 1; i < 45; i =i+7) {
      list_insert(&head,i);
   }
   list_insert(&head,-1);
   list_insert(&head,1);
   list_insert(&head,30);
   list_delete(&head, 28);
   TEST_ASSERT_EQUAL_INT(20,list_count(head));
   node * head2 = extract_odd_list(&head);
   remove_duplicates(head);
   TEST_ASSERT_EQUAL_INT(6,list_count(head));
   TEST_ASSERT_EQUAL_INT(13,list_count(head2));

   for (int i = 0; i<20; i=i+3){
      list_insert(&head, i);
   }
   node * head1 = list_merge(head, head2);
   remove_duplicates(head1);

   TEST_ASSERT_EQUAL_INT(23,list_count(head1));
   TEST_ASSERT_EQUAL_INT(13,list_count(head));
   TEST_ASSERT_EQUAL_INT(0, list_check(head));
}

void test_insert(){
   node * head = NULL;
   for (int i = 1; i < 20; i =i+3) {
      list_insert(&head,i);
   }
   list_insert(&head,-1);
   list_insert(&head,1);
   list_insert(&head,30);
   TEST_ASSERT_EQUAL_INT(10,list_count(head));
   TEST_ASSERT_EQUAL_INT(0, list_check(head));
}

void test_delete(){
   node * head = NULL;
   for (int i = 1; i < 20; i =i+3) {
      list_insert(&head,i);
   }
   for (int i = 1; i < 20; i =i+5) {
      list_insert(&head,i);
   }
   list_delete(&head,1);
   list_delete(&head,1);
   list_insert(&head,10);
   list_delete(&head,19);
   TEST_ASSERT_EQUAL_INT(9,list_count(head));
   TEST_ASSERT_EQUAL_INT(0, list_check(head));
}

void test_remove_duplicates(){
   node * head = NULL;
   list_insert(&head,1);
   list_insert(&head,1);
   list_insert(&head,1);
   list_insert(&head,2);
   list_insert(&head,2);
   TEST_ASSERT_EQUAL_INT(5,list_count(head));
   remove_duplicates(head);
   TEST_ASSERT_EQUAL_INT(2,list_count(head));
   TEST_ASSERT_EQUAL_INT(0, list_check(head));
}


void test_extract_odd_list(){
   node * head = NULL;
   for (int i = 1; i < 20; i =i+1) {
      list_insert(&head,i);
   }
   node * head_odd = extract_odd_list(&head);
   TEST_ASSERT_EQUAL_INT(9,list_count(head));
   TEST_ASSERT_EQUAL_INT(10,list_count(head_odd));
   TEST_ASSERT_EQUAL_INT(0, list_check(head));
   TEST_ASSERT_EQUAL_INT(0, list_check(head_odd));
}

void test_list_merge(){
   node * head1 = NULL;
   node * head2 = NULL;
   for (int i = 1; i < 20; i =i+2) {
      list_insert(&head1,i);
   }
   for (int i = 0; i < 19; i =i+2) {
      list_insert(&head2,i);
   }
   node* head = list_merge(head1, head2);
   TEST_ASSERT_EQUAL_INT(20,list_count(head));
   for (int i = 0; i < 19; i =i+1) {
      list_delete(&head,i);
   }
   TEST_ASSERT_EQUAL_INT(1,list_count(head));
   TEST_ASSERT_EQUAL_INT(10,list_count(head1));
   TEST_ASSERT_EQUAL_INT(10,list_count(head2));
   TEST_ASSERT_EQUAL_INT(0, list_check(head));
}

