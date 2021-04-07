# Embedded Devices "Anzeige und Analyse von Sensordaten" - Taskdescription

## Einführung
Single-Board-Computer und/oder Mikrocontroller werden zur Aufnahme und Verarbeitung von Sensordaten eingesetzt.

## Ziele
Das Ziel ist es eine geeignete Schnittstelle zur Aufnahme von Sensordaten auszuwählen. Die Daten sollen aggregiert und zur weitern Verarbeitung bearbeitet bzw. angezeigt werden. Es soll möglich sein, die aufgenommenen Daten zur Steuerung und Regelung einzusetzen.

## Kompetenzzuordnung
**GK SYT8 Industrielle Informationstechnik | Embedded Systems | Datenaquirierung**  
* "Sensordaten aufnehmen, aufarbeiten und über gängige industrielle Kommunikationssysteme zur Verfügung stellen"

**EK SYT8 Industrielle Informationstechnik | Embedded Systems | Datenaquirierung**  
* "Datenanalysen automatisieren und Ergebnisse zur Steuerung aufbereiten"

## Voraussetzungen
* Verwendung von Mikrokontrollern und Single-Board-Computern (SBC)
* Kenntnis einer hardwarenahen Programmiersprache
* Grundverständnis von digitalen Systemen
* Grundkenntnisse über die sichere Verwendung von Elektronikbauteilen
* Programmierung und Konfiguration eines Single-Board-Computers
* Aufnahme von Sensordaten
* Auswahl und Gegenüberstellung von Kommunikationsschnittstellen

## Detailierte Aufgabenbeschreibung
Die Themenschwerpunkte sollen soweit erläutert und mit Quellen versehen werden, sodass ein leichter Einstieg und eine mühelose Verwendung der einzelnen Tools und der Hardware gegeben ist.

Es soll mindestens ein Sensor aus dem Sensorkit gewählt werden, dessen Daten kontinuierlich mittels eines Single-Board-Computers (SBC) oder Mikrocontrollers (STM32F3/F4) verarbeitet werden. Dabei ist zu beachten, dass gewisse zeitliche Kriterien zu erfüllen sind. Die Verarbeitung der Daten ist erst im erweiterten Teil zu implementieren. Vorerst sollen nur die Sensordaten mit unterschiedlichen Methoden ausgelesen und gespeichert werden.

Um Daten leicht analysieren zu können und diese zur Steuerung einsetzen zu können, empfiehlt es sich entsprechende Schnittstellen einzusetzen. Als vorgeschlagene Umgebung ist ein zeitbasierter Datastore (InfluxDB) und ein Monitoring-Framework (Grafana) zu konfigurieren und mit den aufgenommenen Sensordaten zu füllen. Es ist jedoch erwünscht auch andere Anbieter zu vergleichen und diese einzusetzen.


## Fragestellungen
* Welche Probleme können bei der Verwendung von Sensoren auftreten?
* Wie sind externe Sensoren anzusprechen? Welche verbreitete Protokolle gibt es dabei?
* Wie können Daten aggregiert werden? Welche Anforderungen müssen dabei beachtet werden?
* Wie können zeitabhängige Messdaten leicht gespeichert und verarbeitet werden?
* Welche Möglichkeiten gibt es Daten zu vergleichen und diese zur Steuerung einzusetzen?
* Was muss beim Einsatz eines SBCs oder Mikrocontrollers zur fortwährenden Aufnahme von Messdaten beachtet werden?

## Abgabe
Die Fragestellungen sollen im File **research.md** abgehandelt werden. Die entsprechenden Konfigurationsdateien und Deployment-Anweisungen sind im **README.md** festzuhalten. Etwaiger Programmcode zur Sensordaten-Verarbeitung ist ebenfalls zu dokumentieren. Implementierungen müssen entsprechend beschrieben und leicht deployable sein!

### Classroom Git-Repository
[Hier](https://github.com/500) finden Sie das Abgabe-Repository zum Entwickeln und Commiten Ihrer Lösung. Sollte der Server durch einen unerwarteten Umstand daran gehindert worden sein, die an ihn gesendete Anfrage zu erfüllen, muss der Link zu Beginn des Labors persönlich beantragt werden!

## Bewertung
Gruppengrösse: 1-2 Person(en)
### Grundanforderungen **überwiegend erfüllt**
- [ ] Ausarbeitung der Fragestellungen
- [ ] Konfiguration und Inbetriebnahme eines SBCs
- [ ] Auslesen von extern angeschlossenen Sensordaten
### Grundanforderungen **zur Gänze erfüllt**
- [ ] Verarbeitung und entsprechende Aggregierung von Sensordaten
- [ ] Weitergabe der Sensordaten an entsprechende externe Schnittstellen
### Erweiterte Anforderungen **überwiegend erfüllt**
- [ ] Installation eines time-series Datastores
- [ ] Verwendung einer webbasierten, grafischen Anzeige der Sensordaten
### Erweiterte Anforderungen **zur Gänze erfüllt**
- [ ] automatisierte Funktionsüberprüfung
- [ ] Warnmeldung bei Überschreiten von vordefinierten Schwellenwerten

### Quellen
* "Serial Communications Methods via GPIO"; MBTechWorks; last visited: 2019-04-08; [online](https://www.mbtechworks.com/hardware/raspberry-pi-UART-SPI-I2C.html)
* "35 in 1 Arduino Sensorenkit Modulkit" AZ Delivery [online](https://www.az-delivery.de/products/35-in-1-arduino-zubehor-kit?_pos=4&_sid=fc18e5112&_ss=r)
* "InfluxDB - open source time series platform" [online](https://github.com/influxdata/influxdb)
* "Grafana Labs - The open platform for beautiful analytics and monitoring" [online](https://grafana.com/)

---
**Version** *20210324v2*
