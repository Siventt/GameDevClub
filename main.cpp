#include <raylib.h>
#include <random>

int puntos_j1 = 0;
int puntos_j2 = 0;

bool pausa = true;
int ronda_gan = 0;	// 0 - Ninguno
					// 1 - Jugador 1
					// 2 - Jugador 2

Sound sonido_gol;

struct Bola
{
	Vector2 pos = {};
	int radio = 0;
	Vector2 vel = {};
	Color color = WHITE;

	void actualizar()
	{
		pos.x += vel.x;
		pos.y += vel.y;

		if (vel.x > 12)
		{
			color = ORANGE;
			if (vel.x > 18)
				color = RED;
		}

		comprobar_colisiones();
	}

	void comprobar_colisiones()
	{
		if (pos.x + radio >= GetScreenWidth())
		{
			puntos_j1++;
			ronda_gan = 1;
			reiniciar();
		}
			
		if (pos.x - radio <= 0)
		{
			puntos_j2++;
			ronda_gan = 2;
			reiniciar();
		}

		if (pos.y + radio >= GetScreenHeight() or pos.y - radio <= 0)
			vel.y *= -1;
	}

	void reiniciar()
	{
		PlaySound(sonido_gol);
		pos = { 640, 400 };
		vel = Vector2{ 6, 6 };
		color = WHITE;
		pausa = true;
	}

	void dibujar()
	{
		DrawCircle(pos.x, pos.y, radio, color);
	}
};

struct Pala
{
	Rectangle rec = {};
	int vel = 0;

	void actualizar()
	{
		if (IsKeyDown(KEY_W))
			rec.y -= vel;
		if (IsKeyDown(KEY_S))
			rec.y += vel;

		comprobar_colision();
	}

	void actualizar2()
	{
		if (IsKeyDown(KEY_UP))
			rec.y -= vel;
		if (IsKeyDown(KEY_DOWN))
			rec.y += vel;

		comprobar_colision();
	}

	void comprobar_colision()
	{
		if (rec.y <= 5)
			rec.y = 5;
		else if (rec.y >= GetScreenHeight() - rec.height - 5)
			rec.y = GetScreenHeight() - rec.height - 5;
	}

	void dibujar()
	{
		DrawRectangle(rec.x, rec.y, rec.width, rec.height, WHITE);
	}
};

int main()
{
	InitWindow(1280, 800, "Pong");
	InitAudioDevice();
	SetTargetFPS(60);

	Sound sonido_golpeS[2];
	sonido_golpeS[0] = LoadSound("Sonidos/pongblipa4.wav");
	sonido_golpeS[1] = LoadSound("Sonidos/pongblipa5.wav");
    sonido_gol = LoadSound("Sonidos/objective-complete.wav");

	Bola bola;
	bola.pos = Vector2{ 640, 400 };
	bola.radio = 10;
	bola.vel = Vector2{ 6, 6 };

	Pala pala;
	pala.rec = Rectangle{ 10, (float)GetScreenHeight() / 2 - 50, 25, 100 };
	pala.vel = 10;

	Pala pala2;
	pala2.rec = Rectangle{ (float)GetScreenWidth() - 35, (float)GetScreenHeight() / 2 - 50, 25, 100 };
	pala2.vel = 10;


	while (!WindowShouldClose())
	{
		if (IsKeyPressed(KEY_ENTER))
		{
			pausa = !pausa;
			ronda_gan = 0;
		}

		if (!pausa)
		{
			bola.actualizar();
			pala.actualizar();
			pala2.actualizar2();

			if (CheckCollisionCircleRec(bola.pos, bola.radio, pala.rec))
			{
				if (bola.vel.x < 24) // Limite de velocidad!
					bola.vel.x *= -1.1f;
				else
					bola.vel.x *= -1;
				bola.pos.x = pala.rec.x + pala.rec.width + bola.radio; // Adicional. BUG FIX
				// no me gusta, da inclinación a la pelota, buscar mejor math
				// bola.vel.y = (bola.pos.y - pala.rec.y) / (pala.rec.height / 2) * -bola.vel.x;

				PlaySound(sonido_golpeS[rand() % 2]);
			}
			if (CheckCollisionCircleRec(bola.pos, bola.radio, pala2.rec))
			{
				if (bola.vel.x < 10)
					bola.vel.x *= -1.15f;
				else
					bola.vel.x *= -1;

				PlaySound(sonido_golpeS[rand() % 2]);
			}
		}
		BeginDrawing();
		ClearBackground(BLACK);

		DrawCircle(GetScreenWidth() / 2, GetScreenHeight() / 2, 15, GRAY);
		DrawLine(GetScreenWidth() / 2, 0, GetScreenWidth() / 2, GetScreenHeight(), WHITE);

		bola.dibujar();
		pala.dibujar();
		pala2.dibujar();
	
		DrawText(TextFormat("%i", puntos_j1), GetScreenWidth() * 1 / 3 - 60, 10, 60, WHITE);
		DrawText(TextFormat("%i", puntos_j2), GetScreenWidth() * 2 / 3, 10, 60, WHITE);

		if (pausa)
		{
			DrawText("Press 'Enter' to play!", GetScreenWidth() * 1 / 3 + 10, 200, 32, YELLOW);
			if (ronda_gan == 1)
				DrawText("P1 WINS!", pala.rec.x, pala.rec.y - 30, 32, YELLOW);
			else if (ronda_gan == 2)
				DrawText("P2 WINS!", pala2.rec.x - 110, pala2.rec.y - 30, 32, YELLOW);
		}

		EndDrawing();
	}

	UnloadSound(sonido_gol);
	UnloadSound(sonido_golpeS[0]);
	UnloadSound(sonido_golpeS[1]);

	CloseAudioDevice();
	CloseWindow();
}
