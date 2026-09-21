#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 17
#define ALFABETO 26
#define NUMERI 10
#define SPECIALI 28

void verificaPassword(char password[], char maiuscola[], char minuscola[], char speciali[], char numeri[]);
int checkMaiuscola(char mai[], char p[]);
int checkMinuscola(char min[], char p[]);
int checkSpeciali(char sp[], char p[]);
int checkNumeri(char num[], char p[]);

int main(){
    srand(time(NULL));
    int scelta =0;
    char password[N] = {'c'};
    char maiuscola[ALFABETO] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    char minuscola[ALFABETO] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    char speciali[SPECIALI] = {'!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '-', '_', '=', '+', '[', ']', '{', '}', '|', ';', ':', ',', '.', '<', '>', '?', '/', '\\'};
    char numeri[NUMERI] = {'0','1','2','3','4','5','6','7','8','9'};



    do{

        printf("\n\nScegli:\n 1. generare password causalmente\n 2. Inserisci password per verificare la sicurezza\nInserisci:");
        scanf("%d", &scelta);
        if(scelta != 1 && scelta != 2)
            printf("hai sbagliato\n");
            // se l'utente non invia 
            while (getchar() != '\n');
            scelta = 0;

    } while(scelta != 1 && scelta != 2);
    switch(scelta) {
        case 2:
            verificaPassword(password, minuscola, maiuscola, speciali, numeri);


            break;

        case 1:

            int l = (rand()%7) + 10;

            for (int i = 0; i<l; i++) {
                int j = rand()%4;
                switch (j) {
                    case 0:
                        password[i] = maiuscola[rand()%ALFABETO];
                        break;
                    case 1:
                        password[i] = minuscola[rand()%ALFABETO];
                        break;
                    case 2:
                        password[i] = speciali[rand()%SPECIALI];
                        break;
                    case 3:
                        password[i] = numeri[rand()%NUMERI];
                        break;
                }
            }










    }
    printf("\n\n");
    for (int i = 0; password[i] != '\0'; i++) {
        printf("%c", password[i]);
    }
    main();

    return 0;
}

void verificaPassword(char password[], char maiuscola[], char minuscola[], char speciali[], char numeri[]) {
    int v = 0;
    printf("Inserisci la password (max 16 caratteri):\t");
    scanf("%16s", password);

    for (int i = 0; password[i] != '\0'; i++)
        if (i < 10) {
            printf("Password troppo corta!");
            v = 1;
            break;
        }

    if (checkMaiuscola(maiuscola, password) == 1) printf("\nHa almeno 1 maiuscola\n");
    else {
        printf("Non ha una maiuscola\n");
        v= 1;
    }
    if (checkMinuscola(minuscola, password) == 1) printf("Ha almeno 1 minuscola\n");
    else {
        printf("Non ha una minuscola\n");
        v= 1;
    }
    if (checkSpeciali(speciali, password) == 1) printf("Ha almeno 1 carattere speciale\n");
    else {
        printf("Non ha una carattere speciale\n");
        v= 1;
    }
    if (checkNumeri(numeri, password) == 1) printf("Ha almeno 1 numero\n");
    else {
        printf("Non ha una numero\n");
        v= 1;
    }

    if (v== 1) verificaPassword(password, minuscola, maiuscola, speciali, numeri);
    else main();
}


int checkMaiuscola(char mai[], char p[]) {
    int n = 0;
    for (int i = 0; p[i] != '\0'; i++)
        for (int j = 0; j < ALFABETO; j++)
            if(p[i] == mai[j]) n++;

    if (n == 0) return (0);
    else return (1);

}

int checkMinuscola(char min[], char p[]) {
    int n = 0;
    for (int i = 0; p[i] != '\0'; i++)
        for (int j = 0; j < ALFABETO; j++)
            if(p[i] == min[j]) n++;
    if (n == 0) return (0);
    return (1);
}

int checkSpeciali(char sp[], char p[]) {
    int n = 0;
    for (int i = 0; p[i] != '\0'; i++)
        for (int j = 0; j < ALFABETO; j++)
            if(p[i] == sp[j]) n++;
    if (n == 0) return (0);
    return (1);
}

int checkNumeri(char num[], char p[]) {
    int n = 0;
    for (int i = 0; p[i] != '\0'; i++)
        for (int j = 0; j < ALFABETO; j++)
            if(p[i] == num[j]) n++;
    if (n == 0) return (0);
    return (1);
}




