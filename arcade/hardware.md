# Hardware

- **Raspberry Pi 4 Modelo B:** con 4GB RAM y 64GB almacenamiento. Es donde se ejecutan todos los juegos, base de todo.

- **Monitor ASUS:** parece que funciona con VGA por lo que se necesita un conversor de HDMI a VGA (y otro de microHDMI a HDMI, por la entrada de la Raspberry) para mostrar el vídeo.

- **Altavoces Logitech:** integrados en la carcasa de la arcade. El audio se regula con el dial. La salida de audio en la configuración de la raspberry debe ser "Headphones". Por alguna razón, si el audio no está al 100%, no se escucha.

- **Teclado:** está dentro de la máquina y es útil para administrarla fácilmente.

- **Mando arcade:** los botones y joystick se conecta a la placa I-PAC2 Ultimarc mediante cables. En el nivel más cercano al hardware, los controles están asignados a ciertas teclas del teclado y son reconfigurables mediante un [software específico](https://www.ultimarc.com/control-interfaces/i-pacs/i-pac2/).
Los controles en EmulationStation y Retroarch atienden a las teclas ya configuradas pero son independientes entre sí. Al menos en EmulationStation la A es el botón verde; la B, el azul; la Y, la amarillo; y la X, el rojo.

## Audio

- Para que el audio en la arcade se escuche incluso bajando el volumen desde emulation station a menos del 100% hay que poner AudioCard=Default, AudioDevice=Headphones y Mixer=ALSA.
- Subir la ganancia desde el menu de retroarch (Settings > Audio > Volume Gain) es otra manera de subir el audio sin tocar emulationStation o el dial. 
se pueden normalizar el audio de todos los juegos para que suenen al mismo nivel. Desde la config de retroarch
