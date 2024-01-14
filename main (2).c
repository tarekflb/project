#include <stdio.h>
#include "raylib.h"
#define MAX_ELEMENTS 20
// Fonction de tri par sélection avec représentation visuelle
void selectionSortVisual(int arr[], int n, int ascending) {
    const int screenWidth = 900;
    const int screenHeight = 500;
    const int barWidth = 50;
    const int spacing = 10;
    const int startX = 150;
    const int textOffsetY = 40;
// Initialisation de la fenêtre graphique avec Raylib
    InitWindow(screenWidth, screenHeight, "Selection Sort Visualization using Raylib");
    SetTargetFPS(1);// Fixe le nombre d'images par seconde

    int i, j, index;
 // Boucle principale du tri par sélection
    for (i = 0; i < n - 1; i++) {
        index = i;
		// Recherche de l'élément minimum/maximum dans la portion non triée du tableau

        for (j = i + 1; j < n; j++) {
            if ((ascending && arr[j] < arr[index]) || (!ascending && arr[j] > arr[index])) {
                index = j;
            }
        }
// Echange des éléments
        int temp = arr[index];
        arr[index] = arr[i];
        arr[i] = temp;
// Affichage graphique à chaque étape du tri
        BeginDrawing();
        ClearBackground(RAYWHITE);
// Affiche le texte indiquant si le tri est croissant ou décroissant

        DrawText(ascending ? "Sorting Ascending" : "Sorting Descending", 50, 10 + textOffsetY, 20, BLACK);
// Dessine les barres représentant les éléments du tableau
        for (int k = 0; k < n; k++) {
            Color color = DARKGRAY;
// Met en évidence les éléments en cours de comparaison ou d'échange
            if (k == i || k == index) color = RED;

            DrawRectangle(startX + k * (barWidth + spacing), 300 - arr[k] * 5, barWidth, arr[k] * 5, color);
            DrawText(TextFormat("%d", arr[k]), startX + k * (barWidth + spacing) + 10, 310 + textOffsetY, 20, BLACK);
        }

        EndDrawing();
		// Pause pour la visualisation (peut être ajustée pour contrôler la vitesse)

        for (int delay = 0; delay < 20000000; delay++) {}
    }
// Boucle pour maintenir la fenêtre ouverte après le tri
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(DARKGRAY);
// Affiche le texte indiquant si le tri est croissant ou décroissant
        DrawText(ascending ? "Sorting Ascending" : "Sorting Descending", 50, 10 + textOffsetY, 20, BLACK);
// Dessine les barres représentant les éléments du tableau après le tri
        for (int k = 0; k < n; k++) {
            DrawRectangle(startX + k * (barWidth + spacing), 300 - arr[k] * 5, barWidth, arr[k] * 5, GREEN);
            DrawText(TextFormat("%d", arr[k]), startX + k * (barWidth + spacing) + 10, 310 + textOffsetY, 20, BLACK);
        }

        EndDrawing();
    }
// Ferme la fenêtre graphique à la fin
    CloseWindow();
} 
        int main() {
    int taille;
    int i;

    // Demande à l'utilisateur de saisir le nombre d'éléments dans le tableau
    printf("Enter the number of elements: ");
    scanf("%d", &taille);

    // Vérifie que la taille est valide
    if (taille <= 0 || taille >= MAX_ELEMENTS) {
        printf("Invalid size.");
        return 1; // Termine le programme avec un code d'erreur
    }

    // Déclare un tableau pour stocker les éléments saisis par l'utilisateur
    int arr[MAX_ELEMENTS];

    // Demande à l'utilisateur de saisir chaque élément du tableau
    for (i = 0; i < taille; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    // Initialise la fenêtre graphique avec Raylib
    InitWindow(900, 500, "Selection Sort Visualization using Raylib");
    SetTargetFPS(60); // Fixe le nombre d'images par seconde à 60

    // Définit les rectangles pour les boutons Ascendant et Descendant
    Rectangle buttonAsc = { 250, 100, 250, 50 };
    Rectangle buttonDesc = { 150, 190, 250, 50 };

    // Boucle principale du programme
    while (!WindowShouldClose()) {
        // Vérifie si la souris est sur le bouton Ascendant et si le bouton gauche est enfoncé
        if (CheckCollisionPointRec(GetMousePosition(), buttonAsc) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            printf("Ascending Sort/\n");
            selectionSortVisual(arr, taille, 1); // Appelle la fonction de tri avec l'option Ascendant
        }

        // Vérifie si la souris est sur le bouton Descendant et si le bouton gauche est enfoncé
        if (CheckCollisionPointRec(GetMousePosition(), buttonDesc) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            printf("Descending Sort \n");
            selectionSortVisual(arr, taille, 0); // Appelle la fonction de tri avec l'option Descendant
        }
    }

    // Dessine les éléments graphiques dans la fenêtre Raylib
    BeginDrawing();
    ClearBackground(RAYWHITE);

    // Dessine la phrase "Choisissez le type de tri :"
    DrawText("Choose the Sorting Type  :", 50, 50, 20, BLACK);

    // Dessine les boutons avec des couleurs différentes
    DrawRectangleRec(buttonAsc, BLUE);
    DrawRectangleRec(buttonDesc, DARKGRAY);

    // Dessine le texte sur les boutons
    DrawText(" Ascending Sort", buttonAsc.x + 20, buttonAsc.y + 15, 20, BLACK);
    DrawText("Descending Sort ", buttonDesc.x + 20, buttonDesc.y + 15, 20, BLACK);

    EndDrawing();

    // Ferme la fenêtre graphique à la fin du programme
    CloseWindow();

    return 0; // Termine le programme avec succès
}
