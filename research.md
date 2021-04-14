## Research

# Welche Probleme können bei der Verwendung von Sensoren auftreten?

Sie können mit der Zeit ungenaue Werte liefern. Außerdem sollten auch immer die Umgebungsparameter beachtet werden, also:

Wenn man einen Sensor in einem Elektrisch Rauschender Umgebung betreibt kann es zur Problemen kommen. Mögliche Behebungen wären genügend Abstand zur Störquelle und Abschirmung von Störquelle / Sensor.

Desweiteren wären Temperatur, Luftfeuchtigkeit, UV-Strahlung, Druck etc. Faktoren die Sensoren stören. Man sollte immer im Datenblatt des verwendeten Sensors nachschauen für welche Situation dieser konzipiert ist. [2]

# Wie sind externe Sensoren anzusprechen? Welche verbreitete Protokolle gibt es dabei?

Über Schnittstellen / Ports. Es gibt hier die schon aus dem Wintersemester bekannten I2C, SPI, UART, OneWire, Can, I2S, usw...

UART würde 3 Leitungen benötigen TX, RX und GND und ist Full Duplex und Asynchron da es keine Clock gibt (in dem Kontext in dem ich es benutze könnte ich auf der raspi Seite auf TX bzw. auf der ESP8266 Seite auf RX verzichten da ich nur von ESP zu raspi schicke).
SPI ist benötigt 3 Leitungen + pro Slave noch einen (also es CS Chip Select) und ist auch Full Duplex (gibt ja MOSI und MISO also kann der Master mit einem Slave gleichzeitig senden und empfangen)
Mit I2C ist es möglich mit 2^7 = 128 verschiedenen Slaves zu reden allerdings nur per Halb Duplex.

Die Reichweite ist bei allen ca. gleich lang. [1]

# Wie können Daten aggregiert werden? Welche Anforderungen müssen dabei beachtet werden?

Aufgrund der begrenzten Speichergröße würde es Sinn machen erst dann einen Datensatz zu speichern wenn er anders ist als der Vorherige. Damit würde man die redundanz verhindert so dass z.b. 15 Datensätze hintereinander 21.0 °C sind.

# Wie können zeitabhängige Messdaten leicht gespeichert und verarbeitet werden?

Mit einem zeitbasierten Datastore wie influxdb. InfluxDB ist eine NoSQL Datenbank die nicht nur SQL als Abfragesprache unterstützt (daher auch das No (Not only)).
Hier ist nochmal eine kleine Übersicht von NoSQL Datenbanken:

Art | Beispiel
-------- | --------
Graph   | [neo4j](https://neo4j.com/)  
Dokumentorientierte   |   [mongoDB](https://www.mongodb.com/de)
Key-Value   |   [memcached](https://memcached.org/), [redis](https://redis.io/), [etcd](https://etcd.io/)
Spaltenorientierte   | [ApacheHBase](https://hbase.apache.org/), [ApacheCassandra](https://cassandra.apache.org/)
Wide Table   |
Time-Series   | [influxDB](https://www.influxdata.com/time-series-database/)
Multi-Value   | [OpenQM](https://www.openqm.com/openqm/)
Multi-Modell   | [ravenDB](https://ravendb.net/)

[3]

# Welche Möglichkeiten gibt es Daten zu vergleichen und diese zur Steuerung einzusetzen?

z.b. so ein Monitoring Dienst wie Grafana.

# Was muss beim Einsatz eines SBCs oder Mikrocontrollers zur fortwährenden Aufnahme von Messdaten beachtet werden?

## Speichergröße

Naja. Was die beiden verbindet ist das sie beide flüchtige und nicht flüchtige speicher haben. Beim uC wäre das SRAM und Flash bzw. wenn vorhanden EEPROM. Beim SBC RAM und halt die microSD Karte beim Raspi 4 Model B.
Nur aufjedenfall sind diese flüchtigen bzw. nicht flüchtigen speicher von der Speichergröße her begrenzt.

Beispiel:
Beim Arduino Uno (ATmega328P) hat der EEPROM eine größe von 1 KiB (1 * 2^10 = 1024 B).
Auf dem Uno hat ein double eine size von 4 B (übrigens genausoviel wie ein float auf dem Uno) [1]. Könnte man natürlich auch mit ```sizeof(double)``` herausfinden.

1024 B / 4 B = 256

Das würde bedeuten das man 256 doubles in dem EEPROM vom Arduino hineinspeichern kann.
Beim Raspi ist die microSD Karte auch nicht unbegrenzt.

## Stromversorgung

Ein Grund wieso man bei einer Messstation keinen SBC verwenden sollte ist natürlich der Stromverbrauch. Ein Raspberry Pi verbraucht ca. 4 Watt (Tastatur und Maus angeschlossen, Raspberry Pi 4 Model B, mit GUI).
Es wäre also besser einen uC zu verwenden der deutlich weniger Strom verbraucht. Sehr oft ist es auch möglich die uC in unterschiedliche Sleep Modes zu bringen wo sie noch sparsamer sind. [4]

# Quellen

[1]     "mbtechworks UART vs SPI vs I2C"; [link](https://www.mbtechworks.com/hardware/raspberry-pi-UART-SPI-I2C.html) ; 14.04.2021

[2]     "syt 3. Klasse"

[3]     "INSY bzw. SYT windpark dom"

[4]     "mborko Vortrag"

