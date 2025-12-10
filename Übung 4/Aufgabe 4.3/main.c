#include <stdio.h>

int main() {
    /* * 1. Interpretiere die Nachricht als Hexadezimalzahl.
     * Wir nutzen 'unsigned long long', da 0x16AAAAAABC (10 Stellen) 
     * größer ist als ein normaler 'int' (meist 8 Stellen) fassen kann.
     */
    unsigned long long input = 0x16AAAAAABC;

    /* * 2. Entferne sowohl die letzten 8 als auch die ersten 8 Bits.
     */
    
    // a) Letzte 8 Bits entfernen:
    // Durch einen Rechts-Shift (>>) um 8 Stellen fallen die hintersten 8 Bits (das "BC") weg.
    // Aus 0x16AAAAAABC wird 0x16AAAAAA.
    unsigned int temp = (input >> 8);

    // b) Erste 8 Bits entfernen:
    // Die Zahl ist jetzt 0x16AAAAAA. Die "ersten 8 Bits" sind das "16" ganz vorne.
    // Um diese zu löschen, nutzen wir eine UND-Maske (&).
    // Wir wollen nur die hinteren 6 Stellen (AAAAAA) behalten. 
    // Jedes F im Hexadezimal steht für 4 Bits (1111). 6 Stellen * 4 = 24 Bits.
    // Maske: 0xFFFFFF (behält die unteren 24 Bits, setzt den Rest auf 0).
    temp = temp & 0x00FFFFFF; 
    // temp ist jetzt: 0xAAAAAA

    /* * 3. Ändere alle Bits, welche in der Zahl 0x3F0011 eine '1' sind.
     * "Ändern" (oder Invertieren) von bestimmten Bits macht man mit XOR (^).
     */
    temp = temp ^ 0x3F0011;

    /* * 4. Von links beginnend betrachte jedes zweite Bit und vertausche '1' und '0'.
     * Wir haben 24 Bits (da unser Ergebnis maximal 0xFFFFFF groß ist).
     * "Von links beginnend jedes zweite" bedeutet:
     * Bit 1 (links): lassen
     * Bit 2: tauschen
     * Bit 3: lassen
     * Bit 4: tauschen
     * ...
     * Das Muster "lassen, tauschen, lassen, tauschen..." entspricht binär 010101...
     * Hexadezimal ist binär 0101 eine '5'.
     * Die Maske für 24 Bits ist also: 0x555555
     */
    unsigned int result = temp ^ 0x555555;

    // Ausgabe als Hexadezimalzahl (%X)
    printf("Das Heissgetraenk ist: %X\n", result);

    return 0;
}
