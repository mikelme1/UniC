#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

// Hilfsfunktion: Neuen Knoten erstellen
node* new_node(int data) {
   node* e = (node*)malloc(sizeof(node));
   if (e == NULL) return NULL; 
   e->data = data;
   e->next = NULL; // Wichtig: Pointer auf NULL setzen
   return e;
}

void free_node(node* node) {
   free(node);
}

// 2. Einfügen 
void list_insert(node** head, int data) {
    node* neu = new_node(data); 
    if (neu == NULL) return;

    // Fall 1: Liste leer oder neues Element muss an den Anfang
    if (*head == NULL || (*head)->data >= data) {
       
        
       
        *head = neu; 
    } 
    // Fall 2: Einfügen in der Mitte/Ende
    else {
        node* curr = *head;
        while (curr->next != NULL && curr->next->data < data) {
            curr = curr->next;
        }
        neu->next = curr->next;
        curr->next = neu;
    }
}

// 3. Löschen
void list_delete(node** head, int data) {
    if (head == NULL || *head == NULL) return;

    // Kopf löschen
    if ((*head)->data == data) {
        node* weg = *head;
        *head = (*head)->next;
        free_node(weg);
        return;
    }

    // Suchen und löschen
    node* curr = *head;
   
    while (curr->next != NULL && curr->next->data != data) {
        
        if (curr->next->data > data) return; 
        curr = curr->next;
    }

    
    if (curr->next != NULL) {
        node* weg = curr->next;
        curr->next = weg->next;
        free_node(weg);
    }
}

// 5. Zusammenführen
node* list_merge(node* head1, node* head2) {
    node* new_head = NULL;
    
    // Einfach alles in eine neue Liste kopieren
    node* tmp = head1;
    while (tmp != NULL) {
        list_insert(&new_head, tmp->data);
        tmp = tmp->next;
    }

    tmp = head2;
    while (tmp != NULL) {
        list_insert(&new_head, tmp->data);
        tmp = tmp->next;
    }

    return new_head;
}

// 4. Duplikate weg
void remove_duplicates(node* head) {
    if (head == NULL) return;

    node* curr = head;
    while (curr->next != NULL) {
        if (curr->data == curr->next->data) {
            node* doppelt = curr->next;
            curr->next = doppelt->next;
            free_node(doppelt);
        } else {
            curr = curr->next;
        }
    }
}

// 6. Ungerade Zahlen rausziehen
node* extract_odd_list(node** head) {
    if (head == NULL || *head == NULL) return NULL;

    node* odd_head = NULL;
    node* odd_tail = NULL;

    node* curr = *head;
    node* prev = NULL;

    while (curr != NULL) {
        if (curr->data % 2 != 0) { // ungerade
            node* move = curr;
            
            // Aus alter Liste rausnehmen
            if (prev == NULL) {
                *head = curr->next;
                curr = *head;
            } else {
                prev->next = curr->next;
                curr = curr->next;
            }

            // In neue Liste rein
            // move->next = NULL;
           
            
            if (odd_head == NULL) {
                odd_head = move;
                odd_tail = move;
            } else {
                odd_tail->next = move;
                odd_tail = move;
            }

        } else {
            prev = curr;
            curr = curr->next;
        }
    }

    return odd_head;
}

void list_print(node* head) {
   node* cur = head;
   while (cur != NULL) {
      printf("%i\n", cur->data);
      cur = cur->next;
   }
   printf("\n");
}

int list_count(node* head) {
   int count = 0;
   node* cur = head;
   while (cur != NULL) {
      count++;
      cur = cur->next;
   }
   return count;
}

int list_check(node *head)
{
    if (head == NULL || head->next == NULL)
        return 0;

    node* cur = head;
    while (cur->next != NULL) {
        if (cur->data > cur->next->data)
        {
         printf("Check fails: %i > %i\n", cur->data, cur->next->data);
         return 1;
        }
        cur = cur->next;
    }
    return 0;
}

void free_list(node* head){
   
   if (head == NULL) return;
   
   while(head != NULL){
      node* temp = head;
      head = head->next;
      free_node(temp);
   }
}