#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* --- 1. Globale Arrays und Konstanten --- */
#define NUM_MOVIES 250
#define LEN_TITLE 70
#define LEN_AGE 20
#define LEN_GENRE 100

/* Globale Arrays laut Aufgabe */
char title[NUM_MOVIES][LEN_TITLE];
int year[NUM_MOVIES];
double rating[NUM_MOVIES];
int length[NUM_MOVIES];
char age[NUM_MOVIES][LEN_AGE];
char genre[NUM_MOVIES][LEN_GENRE];

/* Das Positions-Array für die Sortierung */
int position[NUM_MOVIES];

/* Globale Variable, um zu wissen, wie viele Filme wir wirklich eingelesen haben */
int movie_count = 0; 


/* --- 2. Funktion zum Einlesen --- */
void read_movies(void) {
    FILE *file = fopen("movies.in", "r");
    if (file == NULL) {
        perror("Fehler beim Öffnen von movies.in"); // Gibt genauen Systemfehler aus
        exit(1);
    }

    int i;
    for (i = 0; i < NUM_MOVIES; i++) {
        /* Initialisiere Position standardmäßig */
        position[i] = i;

        /* Versuche, eine Zeile zu lesen.
         * %69[^0-9] : Liest Titel bis zur ersten Zahl
         * %d        : Liest Jahr
         * %lf       : Liest Rating
         * %d        : Liest Länge
         * %19s      : Liest Altersfreigabe (DARF KEINE LEERZEICHEN ENTHALTEN -> Not_Rated)
         * %99[^\n]  : Liest den Rest der Zeile (Genre)
         */
        int result = fscanf(file, " %69[^0-9] %d %lf %d %19s %99[^\n]", 
                            title[i], &year[i], &rating[i], &length[i], age[i], genre[i]);

        if (result == EOF) {
            break; // Dateiende erreicht
        }

        /* FEHLERANALYSE: Wir erwarten genau 6 Elemente pro Zeile */
        if (result != 6) {
            printf("FEHLER in Zeile %d der Datei movies.in!\n", i + 1);
            printf("Es wurden nur %d von 6 Spalten erkannt.\n", result);
            printf("Bitte prüfen Sie: Steht 'Not Rated' ohne Unterstrich drin? Sind Striche '|' in der Datei?\n");
            exit(1); // Programm abbrechen, damit keine Nullen ausgegeben werden
        }
        
        movie_count++; // Zähler erhöhen
    }

    fclose(file);
}


/* --- 3. Funktion zum Schreiben --- */
void write_movies(const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Fehler: Datei %s konnte nicht geschrieben werden.\n", filename);
        exit(1);
    }

    int k;
    /* Wir gehen nur bis movie_count, nicht bis 250, falls Datei kürzer ist */
    for (k = 0; k < movie_count; k++) {
        int idx = position[k]; /* Indirekter Zugriff über Sortierung */

        /* Formatierte Ausgabe */
        fprintf(file, "%s%d %.1f %d %s %s\n", 
                title[idx], year[idx], rating[idx], length[idx], age[idx], genre[idx]);
    }

    fclose(file);
}


/* --- 5. Vergleichsfunktionen --- */

/* Gibt -1 zurück, wenn i besser ist als j (höheres Rating) */
int compare_rating(int i, int j) {
    if (rating[i] > rating[j]) return -1;
    if (rating[i] < rating[j]) return 1;
    return 0;
}

/* Gibt -1 zurück, wenn i besser ist als j (kürzere Länge) */
int compare_length(int i, int j) {
    if (length[i] < length[j]) return -1;
    if (length[i] > length[j]) return 1;
    return 0;
}


/* --- 6. Generische Sortierung (Selection Sort) --- */
void sort_movies(int (*compare)(int, int)) {
    int i, j, min_idx, temp;

    for (i = 0; i < movie_count - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < movie_count; j++) {
            /* Wir vergleichen über die Indizes im position-Array */
            if (compare(position[j], position[min_idx]) == -1) {
                min_idx = j;
            }
        }
        /* Tauschen */
        if (min_idx != i) {
            temp = position[i];
            position[i] = position[min_idx];
            position[min_idx] = temp;
        }
    }
}


/* --- 8. Tie-Breaker Sortierung --- */
/* Sortiert nach compare1, bei Gleichstand entscheidet compare2 */
void sort_movies_tie(int (*compare1)(int, int), int (*compare2)(int, int)) {
    int i, j, min_idx, temp;

    for (i = 0; i < movie_count - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < movie_count; j++) {
            
            /* Erstes Kriterium prüfen */
            int res1 = compare1(position[j], position[min_idx]);

            if (res1 == -1) {
                /* j ist klar besser */
                min_idx = j;
            } 
            else if (res1 == 0) {
                /* Gleichstand -> Zweites Kriterium prüfen */
                int res2 = compare2(position[j], position[min_idx]);
                if (res2 == -1) {
                    min_idx = j;
                }
            }
        }
        /* Tauschen */
        if (min_idx != i) {
            temp = position[i];
            position[i] = position[min_idx];
            position[min_idx] = temp;
        }
    }
    
    /* Ergebnis sofort speichern */
    write_movies("movies_ordered.out");
}


/* --- Hauptprogramm --- */
int main(void) {
    /* 1. Einlesen */
    printf("Lese movies.in ein...\n");
    read_movies();
    printf("Erfolgreich %d Filme eingelesen.\n", movie_count);

    /* 2. Unveränderte Ausgabe (Aufgabe 3 & 4) */
    write_movies("movies.out");
    printf("-> movies.out erstellt (Originalreihenfolge).\n");

    /* 3. Sortieren und Ausgeben (Aufgabe 8) */
    /* Sortiere nach Rating, bei Gleichstand nimm den kürzeren Film */
    sort_movies_tie(compare_rating, compare_length);
    printf("-> movies_ordered.out erstellt (Sortiert nach Rating, dann Länge).\n");

    return 0;
}