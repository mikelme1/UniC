#ifndef LIST
#define LIST

typedef struct node{
	int data;
	struct node * next;
}node;

node *new_node(int data);
void free_node(node* node);
void list_insert(node** head, int data);
void list_delete (node** head, int data);
void remove_duplicates(node* head);
node *list_merge(node* head1, node* head2);
node *extract_odd_list(node** head);
void list_print(node* head);
int list_count(node* head);
int list_check(node* head);
void free_list(node* head);

#endif /* LIST */
