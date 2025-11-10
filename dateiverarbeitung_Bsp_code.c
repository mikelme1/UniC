#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("This Program must be called with exactly two arguments specifying the name of the input and output file. Terminating.\n");
        return 1;
    }
    // Deklariere Pointer für Input - und Outputdatei .
    FILE *ifptr, *ofptr;

    /* Öffne Inputdatei (übergeben in der Kommandozeile im selben Verzeichnis wie
     * das ausführende Programm). "r" steht hier für " read ". */
    ifptr = fopen(argv[1], "r");
    // Informiere den Nutzer , falls das Öffnen der Datei fehlgeschlagen ist
    if (ifptr == NULL) {
        fprintf(stderr, "Can’t open input file!\n");
        return 1;
    }

    // Summiere über alle Zahlen in der Datei zu findenden Zahlen
    int num = 0;
    int sum = 0;
    /* Lese aus jeder Zeile der geöffneten Datei einen Integer und speichere ihn
     * in der Variable num. fscanf (..) gibt einen Wert größer 0 zurück , solange
     * das Dateiende nicht erreicht ist . */
    while (fscanf(ifptr, "%i", &num) > 0) {
        sum += num;
    }

    /* Öffne Outputdatei übergeben in Kommandozeile im selben Verzeichnis wie das
     ausführende Programm . "w" steht hier für " write ". */
    ofptr = fopen(argv[2], "w");

    // Informiere den Nutzer , falls Öffnen der Datei fehlgeschlagen ist
    if (ofptr == NULL) {
        fprintf(stderr, "Can’t open output file!\n");
        return 1;
    }

    // Schreibe Summe in die Outputdatei
    fprintf(ofptr, "%i", sum);

    // Schließe die beiden Dateien
    fclose(ifptr);
    fclose(ofptr);

    return 0;
}