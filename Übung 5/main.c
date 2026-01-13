#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"

int main(void) {
   node * head = NULL;
   for (int i = 1; i < 40; i =i+3) {
      list_insert(&head,i);
   }
   for (int i = 2; i < 20; i =i+2) {
      list_delete(&head,i);
   }
   list_delete(&head,-1);
   list_delete(&head,297);
   list_insert(&head, -100);

   for (int i = 1; i < 45; i =i+7) {
      list_insert(&head,i);
   }
   list_insert(&head,-1);
   list_insert(&head,1);
   list_insert(&head,30);
   list_delete(&head, 28);
   list_print(head);
   node * head2 = extract_odd_list(&head);
   remove_duplicates(head);
   list_print(head);
   list_print(head2);

   for (int i = 0; i<20; i=i+3){
      list_insert(&head, i);
   }
   node * head1 = list_merge(head, head2);
   remove_duplicates(head1);
   list_print(head1);
   list_check(head1);

   free_list(head1);
}
