/** EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2024/2025
 *   Modul               : : 04 –  Dynamic Structures
 *   Hari dan Tanggal    : Senin, 4 May 2026
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


int Kosong(struct List* list) {
    return list->head == NULL;
}

void display(struct List* list) {
    printf("MERGED ");
    struct Node* temp = list->head;
    if (Kosong(list)) {
        printf("EMPTY");
        return;
    }
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

}

void inputlsit(struct List* list, int var) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = var;
    newNode->next = NULL;
    if (list->head == NULL) {
        list->head = newNode;
        return;
    }
    struct Node* temp = list->head;
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


    struct Node* temp1 = List1.head;
    struct Node* temp2 = List2.head;
    for (int i = 0; i < inputtotal; i++)
    {
        while (temp1 != NULL && temp2 != NULL) {
            if (temp1 -> data >= temp2 -> data)
            {
                inputlsit (&ListMerged, temp2->data);
                temp2 = temp2->next;
            }
            else if (temp2 -> data > temp1 -> data)
            {
                inputlsit (&ListMerged, temp1->data);
                temp1 = temp1->next;   
            }
    }

             
        while (temp1 != NULL)
        {
            inputlsit (&ListMerged, temp1->data);
            temp1 = temp1->next;
        }
        while (temp2 != NULL)
        {
            inputlsit (&ListMerged, temp2->data);
            temp2 = temp2->next;
        }
        
}
    display (&ListMerged);

    return 0;
}
