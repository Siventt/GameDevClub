# Plantilla CMake para raylib

Esta plantilla de un proyecto básico para raylib usando CMake, se ha probado con Visutal Studio Code y desde terminal.

La rama master del código fuente de raylib se descarga usando CMake FetchContent desde Github y se compila 
desde la fuente ya que es más sencillo que incluir binarios preconstruidos de cada plataforma y configuración.

CMake se encargará de construir tanto Raylib como el proyecto, pudiendo configurar las opciones de Raylib 
según se necesiten.

## Para usar C++

Cambiar para usar C++ es sencillo, solo hay que modificar ciertas líneas del `CMakeLists.txt`:

Configuración para C
```
project(my_raylib_game C)

set(CMAKE_C_STANDARD 99)

file(GLOB_RECURSE PROJECT_SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_LIST_DIR}/sources/*.c")
```

Configuración para C++
```
project(my_raylib_game CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB_RECURSE PROJECT_SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_LIST_DIR}/sources/*.cpp")
```

Después de esto relanza CMake y se construirá usando C++.


## En Ubuntu

sudo apt install libwayland-dev libxkbcommon-dev xorg-dev

https://www.glfw.org/docs/latest/compile_guide.html#compile_deps_wayland

## Utilidades

Para lanzar desde terminal con una línea. Una vez hecho CMake, siempre que no haga falta recompilar raylib
o se añadan ficheros nuevos al proyecto.

> `cd build/; make; cd ..; ./cool_game.elf`

## Agradecimientos

* Autor original de esta plantilla: SasLuca
  Repositorio GitHub: https://github.com/SasLuca/raylib-cmake-template







