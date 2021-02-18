# CPU_Stats
Fetches the temperature, utilization, and power of your CPU and displays it on a mini screen.

You will need:

1x Arduino (any model that can be plugged in via USB)

1x SSD1306 0.96 inch I2C OLED



Download CoreTemp https://www.alcpu.com/CoreTemp/

Go to the Tools tab and check "Logging On". This will store your data in a .csv file. You can configure the program to be minimized and start up on boot.

To hook up your display follow the instructions here https://randomnerdtutorials.com/guide-for-oled-display-with-arduino/

Create a file to contain your path and com port declarations. I called mine reference.py. 

Upload the .ino file to your arduino and then run the python script.





