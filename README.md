# Club de Desarrollo de Videojuegos (GDC)

**¡Bienvenido al repo del GDC!**

En el club nos dedicamos a aprender a desarrollar videojuegos, principalmente usando C++ y una sencilla librería que nos facilita la programación llamada [**Raylib**](https://www.raylib.com/).

Este repositorio está dedicado a guardar y compartir los recursos utilizados y creados en el club.

## Comienzo Rápido

Utilizamos esta [**plantilla**](https://github.com/raylib-extras/raylib-quickstart/tree/main) para empezar rápidamente a desarrollar en C/C++ y Raylib. Funciona en Linux, Windows y Mac, instrucciones rápidas para **Linux**:
1. Clonamos el repositorio en nuestro equipo.
```bash
git clone https://github.com/raylib-extras/raylib-quickstart.git
```
2. Renombramos el proyecto y entramos al directorio.
```bash
mv raylib-quickstart <NOMBRE>
cd <NOMBRE>
```
3. Eliminamos elementos que no usaremos.
```bash
rm -r include/ resources/ build-MinGW-W64.bat build-VisualStudio2022.bat
```
4. Cambiamos el fichero fuente para usar C++. (Si se quiere usar C, saltar paso)
```bash
mv src/main.c src/main.cpp
```
5. Copiamos este código plantilla dentro de `main.cpp`.
```c++
#include "raylib.h"

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);

            DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}
```
6. Vamos a `build/` donde se encuentran los ficheros para construir el proyecto.
```bash
cd build/
```
7. Actualizamos el proyecto. Descargará Raylib si no lo encuentra.
```bash
./premake5 gmake
```
8. Volvemos al directorio raíz del proyecto y ejecutamos `make`, siempre tenemos que realizar esta acción para recompilar el proyecto cuando hagamos cambios.
```bash
cd ..
make
```
9.  El ejecutable de nuestro juego se genera en `\bin`, lo abrimos de esta forma:
```bash
./bin/Debug/<NOMBRE>
```
10. ¡Disfruta!




