#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

int main(int argc, char *argv[]) {
    

    if (argc != 3) {
        printf("Bitte geben die korrekte Inputdatei, sowie die korrekte Outputdatei an, um das Programm auszuführen %s \n", argv[0]);
        printf("Programm wird geschlossen.\n");
        return 1;
    }

    FILE *ifptr, *ofptr;

    char input_filename[256];
    char output_filename[256];

    sprintf(input_filename, "%s.in", argv[1]); 
    sprintf(output_filename, "%s.out", argv[2]);

    ifptr = fopen(input_filename, "r");
    if (ifptr == NULL) {
        fprintf(stderr, "Fehler: Inputdatei %s kann nicht geöffnet werden.\n", input_filename);
        return 1;
    }

    int divisor;
    int current_num;
    

    if (fscanf(ifptr, "%i", &divisor) != 1) {
        fprintf(stderr, "Fehler: Inputdatei %s ist leer oder ungültig.\n", input_filename);
        fclose(ifptr);
        return 1;
    }


    ofptr = fopen(output_filename, "w");
    if (ofptr == NULL) {
        fprintf(stderr, "Fehler: Outputdatei %s kann nicht erstellt werden.\n", output_filename);
        fclose(ifptr);
        return 1;
    }
    
   
    while (fscanf(ifptr, "%i", &current_num) > 0) {
        
        if (current_num == 0) {
            continue;
        }
        
        if (current_num % divisor == 0) {
            fprintf(ofptr, "%i\n", current_num);
        }
    }

    fclose(ifptr);
    fclose(ofptr);

    printf("Die Datei %s wurde erstellt.\n", output_filename);
    return 0;
}




