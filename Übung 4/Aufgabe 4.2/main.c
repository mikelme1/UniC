#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#include "print_maze.h"
#include "random_direction.h"

/* Hilfsfunktion, um Speicher freizugeben */
void free_maze(char **maze, int rows) {
    for (int i = 0; i < rows; i++) {
        free(maze[i]);
    }
    free(maze);
}

/* Chooses a direction at random using the function random_direction()
 * and checks if it is a valid cell for visiting
 * If so, it recursively calls the same function with the new coordinates
 */
void dfs_maze(char **mat, int m, int n, int x, int y){
    // 1. Markieren Sie die aktuelle Zelle als besucht ('0')
    // Die logische Koordinate (x, y) entspricht im Array [2*y + 1][2*x + 1]
    mat[2 * y + 1][2 * x + 1] = '0';

    // Schleife, um alle Nachbarn abzuarbeiten (Backtracking erfolgt automatisch durch Rekursion und Schleife)
    while (1) {
        int neighbors[4] = {0, 0, 0, 0}; // 0: North, 1: South, 2: East, 3: West

        // Überprüfe Norden (y-1)
        if (y > 0 && mat[2 * (y - 1) + 1][2 * x + 1] == '1') {
            neighbors[0] = 1;
        }
        // Überprüfe Süden (y+1)
        if (y < n - 1 && mat[2 * (y + 1) + 1][2 * x + 1] == '1') {
            neighbors[1] = 1;
        }
        // Überprüfe Osten (x+1)
        if (x < m - 1 && mat[2 * y + 1][2 * (x + 1) + 1] == '1') {
            neighbors[2] = 1;
        }
        // Überprüfe Westen (x-1)
        if (x > 0 && mat[2 * y + 1][2 * (x - 1) + 1] == '1') {
            neighbors[3] = 1;
        }

        // 2. Wählen Sie zufällig einen unbesuchten Nachbarn.
        int dir = random_direction(neighbors);

        // 5. Falls alle Nachbarn bereits besucht sind (dir == -1), kehren Sie zurück
        if (dir == -1) {
            break;
        }

        // 3. Entfernen Sie die Wand zwischen beiden Zellen & 4. Rekursiver Aufruf
        if (dir == 0) { // North
            mat[2 * y][2 * x + 1] = '0'; // Wand entfernen (oben)
            dfs_maze(mat, m, n, x, y - 1);
        } else if (dir == 1) { // South
            mat[2 * y + 2][2 * x + 1] = '0'; // Wand entfernen (unten)
            dfs_maze(mat, m, n, x, y + 1);
        } else if (dir == 2) { // East
            mat[2 * y + 1][2 * x + 2] = '0'; // Wand entfernen (rechts)
            dfs_maze(mat, m, n, x + 1, y);
        } else if (dir == 3) { // West
            mat[2 * y + 1][2 * x] = '0'; // Wand entfernen (links)
            dfs_maze(mat, m, n, x - 1, y);
        }
    }
}


int main ()
{
    int i, rows, cols, start_x, start_y, m, n, x, y;
    char **maze;

    srand(time(0));

    printf("Insert the dimensions of the maze. The starting location is (0,0) \n");
    scanf("%d %d", &m, &n);

    while((m <= 0) || (n <= 0) || (x >= m) || (y >= n) || (x < 0) || (y < 0)) 
    {
        printf("Wrong input. Insert positive integers for the size of the maze and start location values between (0,0) and (m-1, n-1) \n");
        scanf("%d %d %d %d", &m, &n, &x, &y);
    }

    rows = 2 * m + 1;
    cols = 2 * n + 1;
    

    // Für die DFS nutzen wir direkt x und y als logische Koordinaten.

    // 1. Dynamisches Array anlegen und Speicher allokieren
    maze = (char**)malloc(rows * sizeof(char*));
    if (maze == NULL) return 1;

    for (i = 0; i < rows; i++) {
        maze[i] = (char*)malloc(cols * sizeof(char));
        if (maze[i] == NULL) return 1; 
    }

    // Initialisierung: Alles voller Wände ('1')
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            maze[r][c] = '1';
        }
    }

    // 2. Tiefensuche aufrufen
    // Dimensionen m, n und die Startposition x, y
    dfs_maze(maze, m, n, x, y);

    // 3. Zwei Positionen auf dem Rand definieren (Eingang/Ausgang)
    // Eingang oben links (beim logischen Feld 0,0 -> Array Feld 0,1)
    maze[0][1] = '0'; 
    // Ausgang unten rechts (beim logischen Feld m-1, n-1 -> Array Feld rows-1, cols-2)
    maze[rows - 1][cols - 2] = '0';

    // 4. Labyrinth ausgeben
    print_maze(maze, rows, cols);

    // Speicher aufräumen
    free_maze(maze, rows);

    return 0;
}