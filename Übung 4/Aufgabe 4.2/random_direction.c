/* Header zum vierten Aufgabenblatt: Konstruktion eines Labyrinths
 * Einfuehrung in die Programmierung I
 * TU Darmstadt, Wintersemester 25/26
 * Rueckgabe einer zufaelligen Position mit einer 1 aus einem Array der Laenge 4
 */
#include <stdio.h>
#include <stdlib.h>

int random_direction(int a[4]){
   int ones = 0;
   int pos[4] = {0, 0, 0, 0};
   for ( int j = 0; j < 4; ++j) {
      if ( a[j] == 1 ) {
         pos[ones] = j;
         ones++;
      }
   }

   if(ones == 0)
	   return -1;
   else
   	return pos[rand() % ones];
}
