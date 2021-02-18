import csv
import serial
import time
import glob
import os
import reference

list_of_files = glob.glob(reference.path)
latest_file = max(list_of_files, key=os.path.getctime) #fetches latest .csv file

arduino = serial.Serial(reference.com,115200,timeout=1)

while True:
    f1 = open(latest_file, "r")
    last_line = f1.readlines()[-1]
    f1.close()

    last_line = last_line.split(",")

    averagetemp = int((int(last_line[1])+int(last_line[2])+int(last_line[3])+int(last_line[4])+int(last_line[5])+int(last_line[6]))/6)
    averageusage = int((int(last_line[11])+int(last_line[16])+int(last_line[21])+int(last_line[26])+int(last_line[31])+int(last_line[36]))/6)


    cputemp = str(averagetemp)
    cpupower = str(last_line[38])
    averageusage = str(averageusage)

    output = cputemp + cpupower + averageusage #concatinates the strings as one single data packet to be sent over serial

    time.sleep(1)

    arduino.write(output.encode())
    
    time.sleep(0.5)



