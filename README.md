# Industrial Programming "Anzeige und Analyse von Sensordaten"

## Aufgabenstellung
Die detaillierte [Aufgabenstellung](TASK.md) beschreibt die notwendigen Schritte zur Realisierung.

## Recherche
Die Zusammenfassung und Übersicht der verwendeten Tools und Technologien kann im File [research.md](research.md) eingesehen werden.

## Implementierung

<!-- TODO: ganz schlecht die bilder ins repo zu geben -->

### Materialien

* SBC, Raspberry Pi 4 Model B, [Datenblatt](https://www.raspberrypi.org/documentation/hardware/raspberrypi/bcm2711/rpi_DATA_2711_1p0_preliminary.pdf)
* MCU, NodeMCU ESP8266, [Datenblatt](https://www.espressif.com/sites/default/files/documentation/0a-esp8266ex_datasheet_en.pdf)
* Analoger Temperatursensor, tmp36, [Datenblatt](https://www.analog.com/media/en/technical-documentation/data-sheets/TMP35_36_37.pdf)
* female to male jumper wires (eben weil der Raspi male pins auf diesem GPIO Header hat und wir von dort auf ein Steckbrett gehen wollen)

### Plan

#### Übertragung via Bus

Da es recht einfach ist und für dieses Beispiel vielleicht auch gar nicht so schlecht ist könnte UART gewählt werden. Hierzu braucht man nur 3 Leitungen RX, TX und GND.
Außerdem muss man auf dem Raspi die UART Schnittstellen aktivieren. Das geht via ``sudo raspi-config``.

``sudo raspi-config`` -> ``Interface Options`` -> ``Serial Port`` -> ``No`` -> ``Yes``

Dann wird rebooted und mittels ``ls -la /dev/`` die ``serial0 bzw. serial1`` geben.

Mit ``cat /boot/overlays/README``:

Hier sieht man welche Funktionen auf welchen Pins laufen:

![bla](img/bild1.png)

Und dann sollte man noch schauen wo diese Ports auf dem GPIO Header sind. Glücklicherweise gibt es hierfür auch ein Programm welches ``pinout`` heißt.

![blub](img/bild2.png)

Das finale Wireing sieht dann so aus:

![bild6](img/bild6.jpg)

Man sieht das die 3 Pins die wir benötigen also gleich nebeneinander liegen. Auf dem ESP8266 hab ich einfach D7 (RX), D8(TX) und GND verwendet. Dazu noch die SoftwareSerial Library die in der Arduino IDE per Default schon dabei ist.

Auf dem raspi kann man mittels python auf die Seriellen Schnittstellen zugreifen. siehe [inserter.py](src/raspi/inserter.py)

Hier muss eig. nur mehr eine Library zum connecten zu influxdb.

```
mkdir syt8_gek811
cd syt8_gek811
python3 -m venv syt8_gek811
source syt8-gek811/bin/activate
pip install influxdb
pip install pyserial
deactivate
```

<!-- TODO: noch über die Implementierung via UART, SPI, I2C, CAN usw.. schreiben -->

#### Übertragung via WiFi

Da der ESP8266 eine WiFi Funktion hat ist es möglich auf dem raspi einen Webservice rennen zu lassen (z.b. mit [``node.js``](https://nodejs.org/docs/latest-v10.x/api/) und [``express``](https://expressjs.com/de/) oder ``django`` mit python).
Auf dem Webservice würde man dann z.b. auf POST bzw. PUT Requests hören und diese dann in die influxDB Datenbank INSERTen (das würde aus node.js mit [``influxdb-nodejs``](https://www.npmjs.com/package/influxdb-nodejs) oder [``influx``](https://www.npmjs.com/package/influx) gehen).

### docker influxdb & grafana

Docker Container für InfluxDB:

```shell script
sudo docker run --name influxdb -d -p 8086:8086 influxdb:2.0.4  # pull the image, and make a new docker container with this image
sudo docker start influxdb                                      # to start it if not already started via run
sudo docker ps -a                                               # to see if its running 
```

```shell script
sudo docker run -d -p 3000:3000 --name grafana grafana/grafana
sudo docker start grafana                                       # to start it if not already started via run
sudo docker ps -a                                               # to see if its running
```

Danach muss überprüft werden diese zwei Container im selben Docker Netzwerk sind:

``sudo docker network inspect bridge``

Hier sieht man das 2 Container im selben Netzwerk sind. Der influxdb hat die IP 172.17.0.2 und der grafana die 172.17.0.3.

Wenn man also von einem Browser in dem Netwerk aus nun die IP von dem Raspi auf Port 3000 anfragt bekommt man die Antwort von Grafana.
Die default credentials sind uname: admin, pw: admin. Ich hab Sie auf uname: admin, pw: grafana4syt8gek geändert.

Dann muss man eine neue Data Source dazugeben. Das waren meine Einstellungen:

![bild3](img/bild3.png)

![bild4](img/bild4.png)

Und wenn man dann noch eine Query macht sieht man z.b. so einen Graph:

![bild5](img/bild5.png)

## Quellen

[1]     "raspberry pi 4 model b datasheet";[link](https://www.raspberrypi.org/documentation/hardware/raspberrypi/bcm2711/rpi_DATA_2711_1p0_preliminary.pdf) ;12.04.2021

[2]     "Espressif ESP8266 datasheet";[link](https://www.espressif.com/sites/default/files/documentation/0a-esp8266ex_datasheet_en.pdf) ;12.04.2021

[3]     "tmp36 datasheet";[link](https://www.analog.com/media/en/technical-documentation/data-sheets/TMP35_36_37.pdf) ; 12.04.2021

[4]     "node.js v10.24 doc";[link](https://nodejs.org/docs/latest-v10.x/api/) ;12.04.2021

[5]     "nodejs express";[link](https://expressjs.com/de/) ;12.04.2021

[6]     "npm influxdb-nodejs";[link](https://www.npmjs.com/package/influxdb-nodejs) ;12.04.2021

[7]     "npm influx";[link](https://www.npmjs.com/package/influx) ;12.04.2021
