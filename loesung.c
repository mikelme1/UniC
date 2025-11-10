#include <stdio.h>
#include <stdlib.h>
#include <time.h>


double get_random_uniform() {
    return (double)rand() / RAND_MAX;
}


int main(void) {
    
    
    srand(time(NULL)); 

    int N; 
    int scan_result;
    
    printf("Bitte Anzahl der Experimente (N) eingeben.\nHinweis: Bitte nur natürliche Zahlen eingeben\n(Bei Kommazahlen wird nur der Wert vor dem Komma gewertet): ");
    scanf("%d", &N); 
    printf("Eingegebene Anzahl der Experimente: %d\n", N);
    long long t = 0; 
    
  if (N < 0|| N == 0  )
  {
    printf("Die Eingabe ist ungültig. Bitte nur positive natürliche Zahlen eingeben.\n");
    return 1;   
  }


    for (int i = 0; i < N; i++) {
        
       
        
        double summe = 0.0;
        int n = 0; 

       
        while (summe <= 1.0) {
            
           
            summe = summe + get_random_uniform();
            
           
            n = n + 1; 
        }

    
        t = t + n;
        
      
    }
    
    double e_approximation = (double)t / N;
    
    printf("\nApproximation für e nach %d Experimenten:\n", N);
    printf("e ≈ %f\n", e_approximation); 
    
    return 0;
}
