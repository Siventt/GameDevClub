#include "raylib.h"
#include <algorithm>
#include "util.hpp"
#include "jugador.hpp"
#include <string.h>

const int TAM_CELDA = 16;
const int COLUMNAS = 80;
const int FILAS = 40;

const float GRAVEDAD = 16 * TAM_CELDA;

bool debug_mode = true;

static void ActualizarCamara(Camera2D* camera, Jugador* jug);

int main(void)
{
	InitWindow(750, 450, "Plataformas");
	SetWindowState(FLAG_WINDOW_RESIZABLE);
	SetWindowState(FLAG_VSYNC_HINT);
	SetTargetFPS(60);

	// Creacion del escenario
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	bool matriz_colision[COLUMNAS][FILAS] = {};

	for (int i = 5; i < COLUMNAS-5; i++)
		matriz_colision[i][FILAS - 5] = true;

	// Raton
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	Vector2 raton = GetMousePosition();
	Vector2i raton_celda = {};

	// Jugador
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	Jugador jug = { {6 * TAM_CELDA, 6 * TAM_CELDA}, TAM_CELDA };

	float delta = 0;

	// Camara
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

	Camera2D camara = { 0 };
	camara.target = { jug.cuerpo.x, jug.cuerpo.y };
	camara.offset = { GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f };
	camara.rotation = 0;
	camara.zoom = 2.5f;

	while (!WindowShouldClose())
	{
		delta = GetFrameTime();

		// Eventos
		//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		if (IsKeyPressed(KEY_F1))
			debug_mode = !debug_mode;

		if (IsMouseButtonDown(MOUSE_BUTTON_LEFT) and matriz_colision[raton_celda.x][raton_celda.y] == 0)
			matriz_colision[raton_celda.x][raton_celda.y] = 1;
		if (IsMouseButtonDown(MOUSE_BUTTON_RIGHT))
			matriz_colision[raton_celda.x][raton_celda.y] = 0;

		if (IsKeyPressed(KEY_R))
			memset(matriz_colision, 0, (size_t)COLUMNAS * FILAS * sizeof(bool));

		if (IsKeyPressed(KEY_Q))
		{
			jug.cuerpo.x = raton.x - jug.cuerpo.width/2;
			jug.cuerpo.y = raton.y - jug.cuerpo.height/2;
		}

		jug.mov_hor(matriz_colision[jug.celda.x - 1][jug.celda.y],
			matriz_colision[jug.celda.x + 1][jug.celda.y], delta);
		jug.mov_ver(matriz_colision[jug.celda.x][jug.celda.y + 1],
			matriz_colision[jug.celda.x][jug.celda.y - 1], delta);
		

		// Actualizado
		//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		jug.act_celda();
		jug.revisar_pos(matriz_colision[jug.celda.x][jug.celda.y]);

		ActualizarCamara(&camara, &jug);


		raton = GetScreenToWorld2D(GetMousePosition(), camara);
		raton_celda = { std::clamp((int)raton.x / TAM_CELDA, 0, COLUMNAS-1), 
					    std::clamp((int)raton.y / TAM_CELDA, 0, FILAS-1   ) };

		// Dibujado
		//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		BeginDrawing();
		ClearBackground(BLACK);
		
		BeginMode2D(camara);
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

		jug.dibujar();

		if (debug_mode)
		{
			// Rejilla Cuadricula
			for (int i = 0; i <= FILAS; i++)
				// lineas horizontales
				DrawLine(0, i * TAM_CELDA, COLUMNAS * TAM_CELDA, i * TAM_CELDA, DARKGRAY);
			for (int i = 0; i <= COLUMNAS; i++)
				// lineas verticales
				DrawLine(i * TAM_CELDA, 0, i * TAM_CELDA, FILAS * TAM_CELDA, DARKGRAY);

			jug.dibujar_colision();

			DrawText(TextFormat("Filas: %d Columnas: %d", FILAS, COLUMNAS), TAM_CELDA * (COLUMNAS+1), 20, 26, WHITE);
			DrawText(TextFormat("Raton (%d, %d)", (int)raton.x, (int)raton.y), TAM_CELDA * (COLUMNAS+1), 75, 26, WHITE);
			DrawText(TextFormat("Celda (%d, %d)", raton_celda.x, raton_celda.y), TAM_CELDA * (COLUMNAS+1), 100, 26, RED);
			DrawText(TextFormat("Jugador (%d,%d)", (int)jug.cuerpo.x, (int)jug.cuerpo.y), TAM_CELDA * (COLUMNAS + 1), 150, 26, WHITE);
			DrawText(TextFormat("Celda (%d,%d)", jug.celda.x, jug.celda.y), TAM_CELDA * (COLUMNAS + 1), 175, 26, RED);
		}

		EndMode2D();

		EndDrawing();
	}

	CloseWindow();
}

static void ActualizarCamara(Camera2D* camera, Jugador* jug)
{
	static Vector2 bbox = { 0.2f, 0.2f };

	Vector2 bboxWorldMin = GetScreenToWorld2D({ (1 - bbox.x) * 0.5f * GetScreenWidth(), (1 - bbox.y) * 0.5f * GetScreenHeight()}, *camera);
	Vector2 bboxWorldMax = GetScreenToWorld2D({ (1 + bbox.x) * 0.5f * GetScreenWidth(), (1 + bbox.y) * 0.5f * GetScreenHeight() }, *camera);
	camera->offset = { (1 - bbox.x) * 0.5f * GetScreenWidth(), (1 - bbox.y) * 0.5f * GetScreenHeight() };

	if (jug->cuerpo.x < bboxWorldMin.x) camera->target.x = jug->cuerpo.x;
	if (jug->cuerpo.y < bboxWorldMin.y) camera->target.y = jug->cuerpo.y;
	if (jug->cuerpo.x > bboxWorldMax.x) camera->target.x = bboxWorldMin.x + (jug->cuerpo.x - bboxWorldMax.x);
	if (jug->cuerpo.y > bboxWorldMax.y) camera->target.y = bboxWorldMin.y + (jug->cuerpo.y - bboxWorldMax.y);
}