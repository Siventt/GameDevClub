# Redes

Para conectar la rpi a una red WIFI hay varios métodos.
* Recomendado: `RASPI-CONFIG` >> `1 System Options` >> `S1 Wireless LAN`.
  * Introducir SSID y clave.
* La entrada de `WIFI` en el menú de RetroPie no funciona bien y parece muy viejo.

## Conexión Remota

La forma más cómoda de acceder es usando SSH desde otro ordenador en la misma LAN.

[Activar SSH](https://retropie.org.uk/docs/SSH/)

Una vez conectado a internet aparecerá su IP.

> `ssh pi@[IP]`

La clave por defecto es `raspberry` pero ha sido cambiada por seguridad.