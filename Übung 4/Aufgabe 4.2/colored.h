/*
 * Datei: colored.h
 *
 * Alle Parameter von
 * https://en.wikipedia.org/wiki/ANSI_escape_code
 */

#ifndef _colored
#define _colored

/* Farb-Definitionen als Präprozessor-Makros
 * siehe SGR Parameter
 */
#define C_RESET   0
#define C_BLACK   0
#define C_RED     1
#define C_GREEN   2
#define C_YELLOW  3
#define C_BLUE    4
#define C_MAGENTA 5
#define C_CYAN    6
#define C_WHITE   7
#define C_DEFAULT 9

/* Min/Max Werte für einfaches Iterieren */
#define C_MIN     0
#define C_MAX     7

/* Offset Werte für Farbwahl */
#define C_OFFSET_TEXT 30
#define C_OFFSET_BG   40

/* Funktion zur Farbwahl des Textes
 * color: 0 oder 30-37, siehe Farbnamen
 */
void selectTextColor(int color);

/* Funktion zur Farbwahl des Hintergrundes
 * color: 30-37, siehe Farbnamen
 */
void selectBackgroundColor(int color);

/* Funktion zur gleichzeitigen Farbwahl von Text und Hintergrund
 * text: Textfarbe, siehe Farbnamen
 * bg  : Hintergrundfarbe, siehe Farbnamen
 */
void selectColors(int text, int bg);

/* Funktion um Standard wiederherzustellen
 */
void resetColor();


#endif
