# Start 
This is an IoT project in which I use a microcontroller **NodeMCU**.It will also include such components as a seven-segment indicator, shift register 74HC595.The data exchange via the web page is performed through the **mqtt server** located on Linux. The web page will be formed through the **python**.

# First step 
I used Debian for the project.You need to install a **Mosquitto MQTT broker** on Debian.
The following steps:
```
sudo apt-get update
sudo apt-get install mosquitto
sudo apt-get install mosquitto mosquitto-clients
```
What to check whether everything works it is necessary to open through the program one more session and to execute from one session the command of the publication and from other subscriber.
```
mosquitto_pub  -t hello/world -m "Hello"
mosquitto_sub  -t hello/world
```
# Second step
I do  for this project not use the function **shiftOut**.The server for the microcontroller NodeMCU is written in C ++ using the **PubSubClient** library.

Circuit diagrams:
https://www.tinkercad.com/things/56lrFg5FXwh-copy-of-laba11/editel?sharecode=Ac7eZ2wCjRrfBJw_7wlBIeuYghkJ-SPpQ8-TkekAa7g



#Third step
We create a  server with the help of a **python** and a framework **Flask**.In this project it will be the basic widgets created in the  **html** and **css**.
Also with the help of a **python** we connect to the server **mqtt** using a library such as **paho.mqtt.client**

# End
In the future, this project will be redesigned and there will be another **Arduino UNO** that will be connected via the data transfer protocol **I2C** and a keyboard 4*4 will be connected to the Arduino and not use libary **Keypad.h**.