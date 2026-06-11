pi@retropie:~ $ cat /etc/os-release 
PRETTY_NAME="Raspbian GNU/Linux 10 (buster)"
NAME="Raspbian GNU/Linux"
VERSION_ID="10"
VERSION="10 (buster)"
VERSION_CODENAME=buster
ID=raspbian
ID_LIKE=debian
HOME_URL="http://www.raspbian.org/"
SUPPORT_URL="http://www.raspbian.org/RaspbianForums"
BUG_REPORT_URL="http://www.raspbian.org/RaspbianBugs"




Lo primero de todo es saber cómo manejarse por el sistema.



Para manejarse por ES

## Controles Teclado:
[Documentación de Retropie](https://retropie.org.uk/docs/)

### Teclado

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

#### J1

Hacer una tabla
[SOUTH]  : Amarillo | KEY LEFT SHIFT
[EAST]   : Rojo | KEYSPACE
[WEST]   : Verde | KEY M
[NORTH]  : Azul | KEY LEFT ALT

[START]  : Blanco | KEY V
[SELECT] : Rojo Superior | KEY C

[D-PAD-UP]    : Palanca Arriba | KEY UP
[D-PAD-DOWN]  : Palanca Abajo | KEY DOWN
[D-PAD-LEFT]  : Palanca Izquierda | KEY LEFT
[D-PAD-RIGHT] : Palanca Derecha | KEY RIGHT

[LEFT SHOULDER] : Negro Superior | KEY Z
[RIGHT SHOULDER] : Negro Inferior | KEY X

### GENERAL

[HOTKEY] : Morado | KEY 6


[DOWN]   : 
[LEFT]   : 
[RIGHT]  : 
[UP]     :




[F1]     : 

## Añadir ROMs y BIOS

Conectarse por red, desde el mismo explorador o por ssh.

Desde un equipo en la misma red local:
> `ssh root@batocera.local`

La contraseña de root es `linux`



Saber qué BIOS se necesita:
MAIN MENU >> GAME SETTINGS >> MISSING BIOS CHECK
Buscar las bios con esos códigos MD5

## Terminal

Puedes cambiar a una terminal con [Ctrl]+[Alt]+[F3].
Con [Ctrl]+[Alt]+[F1] vuelves a la interfaz gráfica.




## Actualizaciones

RASPBERRY-SETUP: sirve para actualizar paquetes del OS.
`RETROPIE SETUP` >> `Update`.

Tiene una apartado en la [documentación](https://retropie.org.uk/docs/Updating-RetroPie/).

(A 14/05/2026, al buscar falla en algunos paquetes, quizá ya no se mantienen.)
