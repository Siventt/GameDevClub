#pragma once
#include "raylib.h"
#include "raymath.h"
#include "util.hpp"

extern const float GRAVEDAD;

struct Jugador
{
	Jugador(Vector2 pos, int tam_celda);

	void act_celda();
	void mov_hor(bool izquerda, bool derecha, float delta);
	void mov_ver(bool abajo, bool arriba, float delta);
	void revisar_pos(bool casilla);
	void dibujar();
	void dibujar_colision();

	Rectangle cuerpo;
	Vector2i celda;
	Vector2i dir;
	Vector2 vel;
	float vel_mov;
	float fuerza_salto;
	bool puede_saltar;
};