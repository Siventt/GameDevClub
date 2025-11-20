#include "raylib.h"
#include <algorithm>

const int TAM_CELDA = 16;
const int COLUMNAS = 80;
const int FILAS = 40;

bool debug_mode = true;

struct Vector2i
{
	int x;
	int y;

	bool operator==(Vector2i const& obj)
	{
		return x == obj.x and y == obj.y;
	}
};

int main(void)
{
	InitWindow(1920, 1080, "Plataformas");
	SetWindowState(FLAG_WINDOW_RESIZABLE);
	SetWindowState(FLAG_VSYNC_HINT);
	SetTargetFPS(144);

	// Creacion del escenario
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	bool matriz_colision[COLUMNAS][FILAS] = {};

	for (int i = 5; i < COLUMNAS-5; i++)
		matriz_colision[i][FILAS - 5] = true;

	// Raton
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	Vector2 raton = GetMousePosition();
	Vector2i raton_celda = {};

	while (!WindowShouldClose())
	{
		// Eventos
		if (IsKeyPressed(KEY_F1))
			debug_mode = !debug_mode;

		if (IsMouseButtonDown(MOUSE_BUTTON_LEFT) and matriz_colision[raton_celda.x][raton_celda.y] == 0)
			matriz_colision[raton_celda.x][raton_celda.y] = 1;
		if (IsMouseButtonDown(MOUSE_BUTTON_RIGHT))
			matriz_colision[raton_celda.x][raton_celda.y] = 0;

		if (IsKeyPressed(KEY_R))
			memset(matriz_colision, 0, (size_t)COLUMNAS * FILAS * sizeof(bool));

		// Actualizado
		raton = GetMousePosition();
		raton_celda = { std::clamp((int)raton.x / TAM_CELDA, 0, COLUMNAS-1) , std::clamp((int)raton.y / TAM_CELDA, 0, FILAS-1) };

		// Dibujado
		BeginDrawing();
		ClearBackground(BLACK);
		
		// Fondo
		// Escenario
		for (int c = 0; c < COLUMNAS; c++)
		{
			for (int f = 0; f < FILAS; f++)
			{
				if (matriz_colision[c][f])
					DrawRectangle(c * TAM_CELDA, f * TAM_CELDA, TAM_CELDA, TAM_CELDA, BLUE);
			}
		}

		if (debug_mode)
		{
			// Rejilla Cuadricula
			for (int i = 0; i <= FILAS; i++)
				// lineas horizontales
				DrawLine(0, i * TAM_CELDA, COLUMNAS * TAM_CELDA, i * TAM_CELDA, DARKGRAY);
			for (int i = 0; i <= COLUMNAS; i++)
				// lineas verticales
				DrawLine(i * TAM_CELDA, 0, i * TAM_CELDA, FILAS * TAM_CELDA, DARKGRAY);

			DrawText(TextFormat("Filas: %d Columnas: %d", FILAS, COLUMNAS), TAM_CELDA * (COLUMNAS+1), 20, 26, WHITE);
			DrawText(TextFormat("Raton (%d, %d)", (int)raton.x, (int)raton.y), TAM_CELDA * (COLUMNAS+1), 75, 26, WHITE);
			DrawText(TextFormat("Celda (%d, %d)", raton_celda.x, raton_celda.y), TAM_CELDA * (COLUMNAS+1), 100, 26, RED);
		}

		EndDrawing();
	}

	CloseWindow();
}