#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define NUM_SHIPS 3  // Nombre de navires par joueur


#define GRID_SIZE 6  // Taille de la grille augmentée à 10x10

// Initialisation des grilles
void initializeGrid(char grid[GRID_SIZE][GRID_SIZE]) {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            grid[i][j] = '~'; // '~' symbolise l'eau
        }
    }
}

// Affichage de la grille
void printGrid(char grid[GRID_SIZE][GRID_SIZE], int showShips) {
    printf("  ");
    for (int i = 0; i < GRID_SIZE; i++) {
        printf("%d ", i);
    }
    printf("\n");

    for (int i = 0; i < GRID_SIZE; i++) {
        printf("%d ", i);
        for (int j = 0; j < GRID_SIZE; j++) {
            if (showShips || grid[i][j] != 'S') {
                printf("%c ", grid[i][j]);
            } else {
                printf("~ "); // Cacher les navires de l'ordinateur
            }
        }
        printf("\n");
    }
}

// Placement du navire
void placeShip(char grid[GRID_SIZE][GRID_SIZE]) {
    int x = rand() % GRID_SIZE;
    int y = rand() % GRID_SIZE;
    grid[x][y] = 'S'; // 'S' représente un navire
}

// Vérification si le navire est touché
int checkHit(char grid[GRID_SIZE][GRID_SIZE], int x, int y) {
    if (grid[x][y] == 'S') {
        grid[x][y] = 'X'; // 'X' symbolise un coup réussi
        return 1;
    } else {
        grid[x][y] = 'O'; // 'O' symbolise un coup raté
        return 0;
    }
}

// Attaque de l'ordinateur
void computerAttack(char grid[GRID_SIZE][GRID_SIZE]) {
    int x = rand() % GRID_SIZE;
    int y = rand() % GRID_SIZE;
    printf("L'ordinateur attaque la position (%d, %d)...\n", x, y);
    if (checkHit(grid, x, y)) {
        printf("L'ordinateur a touché votre navire !\n");
    } else {
        printf("L'ordinateur a raté.\n");
    }
}

// Vérification de la victoire
int checkVictory(char grid[GRID_SIZE][GRID_SIZE]) {
    int shipsRemaining = 0;
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if (grid[i][j] == 'S') {
                shipsRemaining++;
            }
        }
    }
    return shipsRemaining == 0; // Victoire si aucun navire restant
}



// Fonction principale avec niveaux de difficulté
int main() {
    srand(time(NULL));
    char playerGrid[GRID_SIZE][GRID_SIZE];
    char computerGrid[GRID_SIZE][GRID_SIZE];

    initializeGrid(playerGrid);
    initializeGrid(computerGrid);

  
    // Placement des navires
for (int i = 0; i < NUM_SHIPS; i++) {
    placeShip(computerGrid);
    placeShip(playerGrid);
}


    printf("Bienvenue dans le jeu de bataille navale !\n");

    int difficulty;
    printf("Choisissez un niveau de difficulté (1 = Facile, 2 = Moyen, 3 = Difficile) : ");
    scanf("%d", &difficulty);

    int maxTurns = (difficulty == 1) ? 10 : (difficulty == 2) ? 7 : 5;
    int turns = 0;

    while (1) {
        printf("\nGrille de jeu :\n");
        printGrid(playerGrid, 0);

        // Tour du joueur
        int x, y;
        printf("\nEntrez vos coordonnées d'attaque (x y) : ");
        scanf("%d %d", &x, &y);

        if (x < 0 || x >= GRID_SIZE || y < 0 || y >= GRID_SIZE) {
            printf("Coordonnées invalides. Essayez encore.\n");
            continue;
        }

        if (checkHit(computerGrid, x, y)) {
            printf("Touché !\n");
        } else {
            printf("Dans l'eau...\n");
        }

        if (checkVictory(computerGrid)) {
            printf("Félicitations ! Vous avez gagné !\n");
            break;
        }

        // Tour de l'ordinateur
        computerAttack(playerGrid);

        if (checkVictory(playerGrid)) {
            printf("Dommage, l'ordinateur a gagné !\n");
            break;
        }

        turns++;
        if (turns >= maxTurns) {
            printf("Nombre de tours max atteint. Match nul !\n");
            break;
        }
    }

    return 0;
}
