import paho.mqtt.client as mqtt
import os
import time
from array import *

#c1 = array('c',[0xAA, 0xAA, 0x04, 0x03, 0x01, 0x64])
#c2 = array('c',[0xAA, 0xAA, 0x04, 0x03, 0x01, 0x00])
c1 = "aaaa04030164"
c2 = "aaaa04030100"
c = 123

def on_connect(mosq, obj, rc):
    print("rc: " + str(rc))

def on_message(mosq, obj, msg):
    print(msg.topic + " " + str(msg.qos) + " " + str(msg.payload))	

def on_publish(mosq, obj, mid):
    print("mid: " + str(mid))

def on_subscribe(mosq, obj, mid, granted_qos):
    print("Subscribed: " + str(mid) + " " + str(granted_qos))

def on_log(mosq, obj, level, string):
    print(string)
def ohoh(mosq, obj, msg):
	#print("ohoh")
	print(float(msg.payload))
		
	tem.append(float(msg.payload))
	tem.pop(0)
	plotNow()
	plt.pause(.5)

#----------------------------------------
#mqttc = mosquitto.Mosquitto()
mqttc = mqtt.Client()
# Assign event callbacks
mqttc.on_message = on_message
#mqttc.on_message = ohoh
mqttc.on_connect = on_connect
mqttc.on_publish = on_publish
mqttc.on_subscribe = on_subscribe


# Connect
#mqttc.username_pw_set("esp", "123")
mqttc.connect("128.199.139.40", 1883)
#mqttc.connect("128.199.139.40", "1883") ~ python 2

# Start subscribe, with QoS level 0
#mqttc.subscribe("#", 0)

# Publish a message
mqttc.publish("viaot/esp00000001/out", "Connected")
#----------------------------------------
def event():
	print("pub-")
	mqttc.publish("viaot/esp00000001/out", "I'm online")
def reconnect():
	mqttc.connect("128.199.139.40", "1883")
# Continue the network loop, exit when an error occurs
try:
	while True:

		#a = unichr(0xAA) ~ python2
		#a = chr(0xAA)
		off1 = bytearray([0xAA, 0xAA, 0x04, 0x03, 0x00, 0x00])
		on1 = bytearray([0xAA, 0xAA, 0x04, 0x03, 0x00, 0x64])

		off2 = bytearray([0xAA, 0xAA, 0x04, 0x03, 0x01, 0x00])
		on2 = bytearray([0xAA, 0xAA, 0x04, 0x03, 0x01, 0x64])

		off3 = bytearray([0xAA, 0xAA, 0x04, 0x03, 0x02, 0x00])
		on3 = bytearray([0xAA, 0xAA, 0x04, 0x03, 0x02, 0x64])


		mqttc.publish("switch/5ccf7fa3315/in", on1)
		time.sleep(3)
		mqttc.publish("switch/5ccf7fa3315/in", on2)
		time.sleep(3)

		mqttc.publish("switch/5ccf7fa3315/in", on3)
		time.sleep(3)
		mqttc.publish("switch/5ccf7fa3315/in", off1)
		time.sleep(3)

		mqttc.publish("switch/5ccf7fa3315/in", off2)
		time.sleep(3)
		mqttc.publish("switch/5ccf7fa3315/in", off3)
		time.sleep(3)

except KeyboardInterrupt:
	mqttc.disconnect()
	pass

