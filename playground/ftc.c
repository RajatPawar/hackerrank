#include <stdio.h>

main() {
    // C = (5/9)(F-32)
    // Print table from F 0 to F 300 
    
    // Header
    printf("Fahrenheit\t\tCelcius\n");

    for(int lower = 300; lower >= 0; lower -= 20) {
    printf("%d\t\t%6.1f\n", lower, ((5.0 * (lower - 32.0))/9.0));
    }

}
