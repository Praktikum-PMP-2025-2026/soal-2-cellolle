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

 temp2 = List2.head;
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
            temp2 = temp1->next;
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
