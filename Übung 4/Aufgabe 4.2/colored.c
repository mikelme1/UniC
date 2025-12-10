/*
 * Datei: colored.c
 * Autor: Veranstaltungsteam EinfProg I, WiSe 25/26
 *
 * Implementation von Funktionen zur Farbwahl im Terminal nach
 * ANSI-Escape-Codes.
 *
 */

#include "colored.h"
#include <stdio.h>

/* Interne Funktion, die den übergebenen Code als CSI SGR Code ausgibt
 */
static void selectColor(int color) {
  // Print ESC CSI SGR Code:
  // \033 - ESC (Octal, ASCII)
  // [    - CSI (Control Sequence Introducer)
  // %i   - int Parameter for SGR
  // m    - SGR (Select Graphic Rendition)
  printf("\033[%im",color);
}

void selectTextColor(int color) {
  // Return if parameter not valid:
  if ((color > C_MAX || color < C_MIN) && color != C_DEFAULT)
    return;

  selectColor(color + C_OFFSET_TEXT);
}

void selectBackgroundColor(int color) {
  if ((color > C_MAX || color < C_MIN) && color != C_DEFAULT)
    return;

  selectColor(color + C_OFFSET_BG);
}

void selectColors(int text, int bg) {
  if ( (text > C_MAX || text < C_MIN) ||
       (bg   > C_MAX || bg   < C_MIN)   )
    return;

  selectTextColor(text);
  selectBackgroundColor(bg);
}

void resetColor() {
  selectColor(C_RESET);
}
