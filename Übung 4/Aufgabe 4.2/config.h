/* Header zum vierten Aufgabenblatt: Konstruktion eines Labyrinths
 * Konfiguration
 */


#ifndef CONFIG_H
#define CONFIG_H

#include "colored.h"

#define WALL 1
#define BG_WALL_COLOR C_BLACK  
#define FG_WALL_COLOR C_WHITE 
#define WALL_SYMBOL "  "

#define START 2
#define BG_START_COLOR C_YELLOW
#define FG_START_COLOR C_BLACK
#define START_SYMBOL "St"

#define PATH 0
#define BG_PATH_COLOR C_WHITE
#define FG_PATH_COLOR C_WHITE 
#define PATH_SYMBOL "  "

#define SOL 3
#define BG_SOL_COLOR C_RED
#define FG_SOL_COLOR C_BLACK
#define SOL_SYMBOL "||"

#endif
