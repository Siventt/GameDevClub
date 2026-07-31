# Redes

Para conectar la rpi a una red WIFI hay varios métodos.
* Recomendado: `RASPI-CONFIG` >> `1 System Options` >> `S1 Wireless LAN`.
  * Introducir SSID y clave.
* La entrada de `WIFI` en el menú de RetroPie no funciona bien y parece muy viejo.

**NOTA:** Se recomienda conectarse a un punto de acceso móvil para mayor seguridad, desaconsejando la conexión a redes públicas como la de Eduroam. 

## Conexión Remota

La forma más cómoda de acceder es usando SSH desde otro ordenador en la misma LAN.

Debería estar activado por defecto pero si no: [Activar SSH](https://retropie.org.uk/docs/SSH/)

Una vez conectado a internet se puede conocer su IP desde terminal con

> `ip addr`

O con la entrada `SHOW MY IP` en el menú `RetroPie` de EmulationStation.

Una vez conocida conectar usando SSH desde terminal

> `ssh pi@[IP]`

La clave por defecto es `raspberry` pero ha sido cambiada por seguridad.

## Transferencia de ficheros

Para pasar archivos entre un ordenador y la rpi se aconseja usar uno de estos dos comandos:

> `scp [opciones] [origen] [destino]`

> `rsync [opciones] [origen] [destino]`

`[origen]` o `[destino]` pueden sustituirse por un directorio de tu máquina o de otra conectada en remoto: `usuario@ip:ruta`

Rsync es un comando más potente que permite traspasos más flexibles. Se recomienda las opciones: `-avP`