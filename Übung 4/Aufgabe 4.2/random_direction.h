/* Header zum vierten Aufgabenblatt: Konstruktion eines Labyrinths
 * Einfuehrung in die Programmierung I
 * TU Darmstadt, Wintersemester 25/26
 * Rueckgabe einer zufaelligen Position mit einer 1 aus einem Array der Laenge 4
 */

#ifndef RANDOM_DIRECTION_H
#define RANDOM_DIRECTION_H

#include <stdlib.h>

/* Input:  An array of integers of size 4 with entries 0 or 1
 *	   Each index of the array denotes one of the 4 directions
 *         Entry 1 denotes valid direction, entry 0 denotes invalid direction
 * Output: Returns at random one index of the input array whose entry is 1
 *	   If the array contains only 0's it returns -1
 */

int random_direction(int *);

#endif
