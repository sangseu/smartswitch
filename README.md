# smartswitch
v1:
- smartconfig, save to eeprom
- reset by connect GPIO16~RESET pin
- on/off relay with mr.Quat's message frame

v2:
- smartconfig, save to eeprom
- auto reset after config
- connect mqtt broker with ID. ID get from MAC address
- frequen pub ID, relay status to a topic
- get status relay
- auto reconnect wifi, reconnect mqtt, reset if connection fail
- on/off relay with mr.Quat's message frame

v3:
- on/off
