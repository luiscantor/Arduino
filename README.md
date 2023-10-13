## Arduino CLI

$ curl -fsSL https://raw.githubusercontent.com/arduino/arduino-cli/master/install.sh | sh

$ chmod a+x bin/arduino-cli

$ ./arduino-cli core update-index

$ ./arduino-cli core install arduino:avr

$ ./arduino-cli core search

$ ./arduino-cli board list

$ ./arduino-cli sketch new Blink



### Board List
$ ./arduino-cli board list
```
Puerto       Protocolo Tipo              Nombre de la placa FQBN            Núcleo

/dev/ttyACM0 serial    Serial Port (USB) Arduino Uno        arduino:avr:uno arduino:avr
/dev/ttyAMA0 serial    Serial Port       Unknown
```


### Compile
$ ./arduino-cli compile --fqbn arduino:avr:uno Blink/



### Upload code
$ ./arduino-cli upload -p /dev/ttyACM0 --fqbn arduino:avr:uno Blink/



### Read Serial Port Data
$ cat /dev/ttyACM0




## Reference:
https://www.arduino.cc/en/Guide/ArduinoUno
https://solectroshop.com/es/content/70-como-hacer-un-detector-de-movimiento-con-arduino-y-el-sensor-hc-sr501
https://hackerspace-ffm.de/wiki/index.php?title=Arduino_IDE_like_serial_monitor_in_the_Raspberry_Pi_shell
https://www.makerguides.com/es/how-to-blink-an-led-using-arduino-4-different-ways/
https://www.youtube.com/watch?v=jU_b8WBTUew
