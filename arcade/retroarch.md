# Retroarch

Retroarch es una plataforma de emulacion que centraliza una gran variedad de emuladores. Cada emulador es un *core*, se identifican por llevar el prefijo 'lr-' que significa [libRetro](https://docs.libretro.com/start/understanding/).  

## Guía de configuración

- Para guardar/cargar los cambios de configuración de Retroarch: `Main Menu` > `Configuration File`. Aun así, se puede activar el guardado automático en `Settings` > `Configuration`.

- En `Settings` > `User Interface` puedes desactivar los mensajes que salen al iniciar un juego.

#### Modo Kiosk

- También en `Settings` > `User Interface` puedes activar el Modo Kiosk que principalmente esconde la sección `Settings`. Para desactivar el modo kiosk `Main Menu` > `Disable Kiosk Mode`. Para ello hay que introducir una contraseña previamente estableciada desde el menú donde se activó.

- Para desactivar el Modo Kiosk accedemos a Retroarch, `Main Menu` > `Disable Kiosk Mode`. Al introducir la contraseña, los Ajustes no aparecerán de inmediato: se debe salir y volver a entrar del apartado `Main Menu` (entrado a otra sección) y luego ir a `Main Menu` > `Configuration File` > `Save Main Configuration`. Tras esto reiniciamos Retroarch y recuperaremos el acceso completo.

#### Núcleo de MAME

- Para el core `lr-mame2003-plus` se recomienda obtener las roms de un romset MAME 0.78-Plus para garantizar la compatibilidad con el núcleo.

- El emulador MAME tiene su propio menú interno accesible con la tecla `TAB`. Las configuaraciones de este menú causan conflictos con los mapeos de botones de retroarch, teniendo que modificar la configuración de este menú propio. Las configuraciones de MAME se guardan en `RetroPie` > `roms` > `arcade` > `mame2003-plus` > `cfg`. El archivo `default.cfg` contiene el input general, al borrarlo se restauran los valores por defecto.

- Guía rápida para configurar controles: se recomienda cambiar los botones de posición desde Retroarch (`Quick Menu` > `Controls`), es decir, el `Botón 1` se mapea al botón donde está asignado el `Botón 2`, lo mismo con los `Botones 3 y 4` entre sí.