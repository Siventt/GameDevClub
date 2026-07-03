#pragma once
#include "raylib.h"
#include "raymath.h"
#include "util.hpp"

extern const float GRAVEDAD;

struct Jugador
{
	Jugador(Vector2 pos, int tam_celda);
	~Jugador();

	void act_celda();
	void mov_hor(bool izquerda, bool derecha, float delta);
	void mov_ver(bool abajo, bool arriba, float delta);
	void revisar_pos(bool casilla);
	void dibujar();
	void dibujar_colision();

	void act_anim();
	void dibujar_estado();

	Rectangle cuerpo;
	Vector2i celda;
	Vector2i dir;
	Vector2 vel;
	float vel_mov;
	float fuerza_salto;
	bool puede_saltar;

	Texture2D sprite;
	Rectangle frame;
	int frame_actual;
	int frame_cont;
};