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