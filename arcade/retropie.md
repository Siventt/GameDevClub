# Información Importante sobre RetroPie

## Sobre el Sistema Operativo

Retropie es el OS que usa la rpi. En nuestro caso usamos una imagen de Raspbian GNU/Linux 10 (buster) basada en un sistema debian de 32 bits.

Raspbian ya no recibe soporte, el proyecto se ha renombrado a [Raspberry Pi OS](https://www.raspberrypi.com/documentation/).

[Documentación de Retropie](https://retropie.org.uk/docs/)

## Controles Teclado
Por defecto Retropie usa la distribución de teclado en-us,
se puede cambiar desde raspi-config.

### Teclado

Para un teclado normal

  Input  | Tecla          |
:-------:|:---------------|
[UP]     | Up Arrow Key  
[DOWN]   | Down Arrow Key
[LEFT]   | Left Arrow Key
[RIGHT]  | Right Arrow Key
[START]  | Spacebar
[SELECT] | Backspace
[EAST]   | Escape
[SOUTH]  | Enter
[NORTH]  | X
[WEST]   | Z

### Mandos de Arcade

El sistema reconoce el mando de arcade como un teclado.

## Terminal

Puedes cambiar a una terminal con [Ctrl]+[Alt]+[F3] o con [F4].
Con [Ctrl]+[Alt]+[F1] vuelves a la interfaz gráfica.

## Actualizaciones

RASPBERRY-SETUP: sirve para actualizar paquetes del OS.
`RETROPIE SETUP` >> `Update`.

Tiene una apartado en la [documentación](https://retropie.org.uk/docs/Updating-RetroPie/).

Los repositorios estaban desactualizados, al cambiarlos los paquetes ya se pueden actualizar.
[Fuente Oficial](https://retropie.org.uk/forum/topic/37291/issues-with-retropie-4.x-buster-installations-of-packages-solved).

## Retropie-Extra

Es un repositorio no oficial que incluye scripts que permiten ampliar las funcionalidades del sistema: añadir más emuladores, libretro-cores, ports...

Para añadir scripts se debe clonar el repositorio de [github](https://github.com/Exarkuniv/RetroPie-Extra) y luego ejecutar `RetroPie-Extra/install-extras.sh`
