# Industrial Programming "Anzeige und Analyse von Sensordaten"

## Aufgabenstellung
Die detaillierte [Aufgabenstellung](TASK.md) beschreibt die notwendigen Schritte zur Realisierung.

## Recherche
Die Zusammenfassung und Übersicht der verwendeten Tools und Technologien kann im File [research.md](research.md) eingesehen werden.

## Implementierung

### Materialien

* SBC, Raspberry Pi 4 Model B, [Datenblatt](https://www.raspberrypi.org/documentation/hardware/raspberrypi/bcm2711/rpi_DATA_2711_1p0_preliminary.pdf)
* MCU, NodeMCU ESP8266, [Datenblatt](https://www.espressif.com/sites/default/files/documentation/0a-esp8266ex_datasheet_en.pdf)
* Analoger Temperatursensor, tmp36, [Datenblatt](https://www.analog.com/media/en/technical-documentation/data-sheets/TMP35_36_37.pdf)

### Plan

#### Übertragung via Bus

<!-- TODO: noch über die Implementierung via UART, SPI, I2C, CAN usw.. schreiben -->

#### Übertragung via WiFi

Da der ESP8266 eine WiFi Funktion hat ist es möglich auf dem raspi einen Webservice rennen zu lassen (z.b. mit [``node.js``](https://nodejs.org/docs/latest-v10.x/api/) und [``express``](https://expressjs.com/de/) oder ``django``).
Auf dem Webservice würde man dann z.b. auf POST bzw. PUT Requests hören und diese dann in die influxDB Datenbank INSERTen (das würde aus node.js mit [``influxdb-nodejs``](https://www.npmjs.com/package/influxdb-nodejs) oder [``influx``](https://www.npmjs.com/package/influx)).
 

## Quellen
