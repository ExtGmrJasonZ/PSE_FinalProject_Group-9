# PSE_FinalProject_Group-9

Team Members:
Eric Jovian		 	          2201798004
Fauzan Athallah Arief 	  2201798326
Jason Sianandar		        2201796440
Salya Wirachman 		      2201798143

Smart Mosquito Trap
We created a Smart Mosquito Trap that implements IOT to solve people’s mosquitoes problem. This product used Arduino Uno as our pervasive device.
We use two sensors which are the humidity sensor which is used to record the surrounding area’s humidity and temperature and the sound sensor which will be used to detect 
the zap sound when the mosquito is killed so it can be inputted as the kill count. For the implementation of IOT, we use Telegram as we created a telegram bot so the user 
can interact and communicate with the product. The user can do things such as:

Requesting to know the humidity of the surroundings (in percentage)
Requesting to know the temperature of the surroundings (in degree celsius)
Requesting to turn the computer fan on
Requesting to turn the computer fan off

testing_sensor_arduino_salya.ino is the file for the Arduino
testing_sensor_salya.ino is the file for the ESP 8266 for connecting to the Telegram bot


