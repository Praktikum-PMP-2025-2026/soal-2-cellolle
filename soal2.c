/** EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2024/2025
 *   Modul               : : 04 –  Dynamic Structures
 *   Hari dan Tanggal    : Senin, 4 April 2026
 *   Nama (NIM)          : Marcello Menata Pandiangan (13224069)
 *   Nama File           : prak2_13224069.c
 *   Deskripsi           : 
 * 
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    int data;
    struct Node* next;
};

struct List {
    struct Node* head;
};

// Fungsi memeriksa status kekosongan list
int Kosong(struct List* l) {
    return l->head == NULL;
}


void sort(struct List* l) {
    if (Kosong(l)) return;
    struct Node *i, *j;
    int temp;
    for (i = l->head; i->next != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}

void removeDuplicates(struct List* l) {
    struct Node *ptr1, *ptr2, *dup;
    ptr1 = l->head;
    while (ptr1 != NULL && ptr1->next != NULL) {
        ptr2 = ptr1;
        while (ptr2->next != NULL) {
            if (ptr1->data == ptr2->next->data) {
                dup = ptr2->next;
                ptr2->next = ptr2->next->next;
                free(dup);
            } else {
                ptr2 = ptr2->next;
            }
        }
        ptr1 = ptr1->next;
    }
}

void display(struct List* l) {
    printf("MERGED ");
    struct Node* temp = l->head;
    if (Kosong(l)) {
        printf("EMPTY");
        return;
    }
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

}

void inputlsit(struct List* l, int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
    if (l->head == NULL) {
        l->head = newNode;
        return;
    }
    struct Node* temp = l->head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

int main() {
    struct List List1;
    struct List List2;
    struct List ListMerged;
    List1.head = NULL;
    List2.head = NULL;
    ListMerged.head = NULL;
    int inputN;
    int inputM;
    int N;
    int M;
    int inputtotal;
    int inputterbanyak;
    int nilai1;
    int nilai2;
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &inputN);
        inputlsit(&List1 , inputN);
    }
    scanf("%d", &M);
    for (int i = 0; i < M; i++)
    {
        scanf("%d", &inputM);
        inputlsit(&List2 , inputM);
    }
    inputtotal = M+N;
    display (&List1);
    display (&List2);

    struct Node* temp1 = List1.head;
    printf("%d -> ", temp1->data);
    struct Node* temp2 = List2.head;
    printf("%d -> ", temp2->data);
    for (int i = 0; i < inputtotal; i++)
    {
        while (temp1 != NULL) {
        inputlsit (&ListMerged, temp1->data);
        temp1 = temp1->next;
        }

        while (temp2 != NULL){
        inputlsit (&ListMerged, temp2->data);
        temp2 = temp2->next;   
        }

    }
    display (&ListMerged);
    
    return 0;
}
