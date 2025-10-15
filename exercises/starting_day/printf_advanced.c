#include <stdio.h>

int main() {
    // We will store text inside these arrays (character lists)
    // Don't worry if you don't understand arrays yet — just imagine these as "boxes to keep words"
    char first[50], last[50], domain[100];

    printf("Enter your email (format: firstname.lastname@domain): ");
    // This scanf may look scary, but it's actually doing a smart trick:
    // %[^.]  → Read everything until '.' and store it into first
    // %*c    → Read and IGNORE the dot ( * means 'skip' )
    // %[^@]  → Read everything until '@' and store it into last
    // %*c    → Skip the '@'
    // %[^\n] → Read the rest of the line until Enter is pressed, store into domain
    scanf("%[^.]%*c%[^@]%*c%[^\n]", first, last, domain);

    printf("\nFirst Name: %s\nLast Name: %s\nDomain: %s\n", first, last, domain);
    return 0;
}
