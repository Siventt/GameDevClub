# Hardware

- **Raspberry Pi 4 Modelo B:** con 4GB RAM y procesador Broadcom BCM2711. Es donde se ejecutan todos los juegos, base de todo.

- **Monitor:** parece que funciona con VGA por lo que se necesita un conversor de HDMI a VGA (y otro de microHDMI a HDMI, por la entrada de la Raspberry) para mostrar el vídeo.

- **Altavoces:** integrados en la carcasa de la arcade. El audio límite se regula con el dial. La salida de audio en la configuración de la raspberry debe ser "Headphones".

- **Teclado:** está dentro de la máquina y es útil para administrarla fácilmente.

- **Arcade-pad:** los botones y joystick se conecta a la placa I-PAC2 Ultimarc mediante cables. En el nivel más cercano al hardware, los controles están asignados a ciertas teclas del teclado y son reconfigurables mediante un [software específico](https://www.ultimarc.com/control-interfaces/i-pacs/i-pac2/).
Los controles en EmulationStation y Retroarch atienden a las teclas ya configuradas pero son independientes entre sí. Al menos en EmulationStation la A es el botón verde; la B, el azul; la Y, la amarillo; y la X, el rojo.

## Audio

- Para que el audio se escuche incluso al bajarlo del 100%, en los ajustes de EmulationStation hay que poner AudioCard=Default, AudioDevice=Headphones y Mixer=ALSA.

- Subir la ganancia desde el menu de Retroarch (`Settings` > `Audio` > `Volume Gain`) es otra manera de subir el audio sin tocar el de EmulationStation o el dial. 

- Se supone que se puede normalizar el audio de todos los juegos para que suenen al mismo nivel. Desde la config de Retroarch.
