# Club de Desarrollo de Videojuegos (GDC)

**¡Bienvenido al repo del GDC!**

En el club nos dedicamos a aprender a crear videojuegos, principalmente usamos C o C++ junto con [**Raylib**](https://www.raylib.com/), una librería para facilitar el desarrollo pero sin abstraer demasiado del código.

Este repositorio está dedicado a guardar y compartir los recursos utilizados y creados en el club.

## Cómo construir los proyectos

Utilizamos [CMake](https://cmake.org/) para manejar los proyectos, este ejemplo es en Linux desde terminal pero la herramienta es independiente de la plataforma. Tras clonar este repo con `git clone ...` y encontrarse en su directorio hay que hacer lo siguiente:

1. Entrar en el proyecto (e.g. Pong), crear una carpeta `build` y entrar en ella.

```bash
cd Pong
mkdir build
cd build
```

La carpeta `build` contiene los recursos necesarios para compilar y construir el ejecutable, puede borrarse una vez creado, es donde se descarga y configura raylib.

2. Ejecutar CMake.

```bash
cmake ..
```

CMake utiliza el fichero `CMakeLists.txt` de la raíz del proyecto para saber qué tiene que hacer y con esos parámetros crea un `Makefile`.

3. Crear el ejecutable usando el `Makefile`.

```bash
make
```

4. Ejecutar el programa en la raíz del proyecto.

```bash
cd ..
./pong
```

## Cómo crear un proyecto nuevo

La carpeta `Plantilla` contiene un proyecto vacío, seguir su [README.md](./Plantilla/README.md).


