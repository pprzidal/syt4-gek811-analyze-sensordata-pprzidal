## Research

# Welche Probleme können bei der Verwendung von Sensoren auftreten?

# Wie sind externe Sensoren anzusprechen? Welche verbreitete Protokolle gibt es dabei?

# Wie können Daten aggregiert werden? Welche Anforderungen müssen dabei beachtet werden?

# Wie können zeitabhängige Messdaten leicht gespeichert und verarbeitet werden?

Mit einem zeitbasierten Datastore wie influxdb.

# Welche Möglichkeiten gibt es Daten zu vergleichen und diese zur Steuerung einzusetzen?

z.b. so ein Monitoring Dienste wie Grafana.

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
Es wäre also besser einen uC zu verwenden der deutlich weniger Strom verbraucht. Sehr oft ist es auch möglich die uC in unterschiedliche Sleep Modes zu bringen wo sie noch sparsamer sind.

