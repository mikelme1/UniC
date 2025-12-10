/* Header zum vierten Aufgabenblatt: Konstruktion eines Labyrinths
 * Einfuehrung in die Programmierung I
 * TU Darmstadt, Wintersemester 25/26
 * Ausgabe des Labyrinths
 */


#include <stdio.h>
#include "print_maze.h"
#include "config.h"

void print_maze(char **maze, int height, int width) {
   for(int y = 0; y < height; y++) {
      for(int x = 0; x < width; x++) {
         switch(maze[y][x]-'0') {
         case WALL:   selectBackgroundColor(BG_WALL_COLOR); selectTextColor(FG_WALL_COLOR); printf(WALL_SYMBOL); resetColor(); break;
         //case START:  selectBackgroundColor(BG_START_COLOR); selectTextColor(FG_START_COLOR); printf(START_SYMBOL); resetColor(); break;
         case SOL:    selectBackgroundColor(BG_SOL_COLOR); selectTextColor(FG_SOL_COLOR); printf(SOL_SYMBOL);  break;
         default:     selectBackgroundColor(BG_PATH_COLOR); selectTextColor(FG_PATH_COLOR); printf(PATH_SYMBOL);  break;
      }
      }
      printf("\n");
      resetColor();
   }
}
