import serial
import os
import datetime
import time

serial_port = '/dev/Lakeshore';
baud_rate = 9600; #In arduino, Serial.begin(baud_rate)
    
#log_file_path = 'Z:\\Dewar_Temperatures\\'
log_file_path = '/home/lab-42/skynet/Logs/PulseTube_Chilled_Water/'

#output_file = open(write_to_file_path, "w+");
try:
    ser = serial.Serial(serial_port, baud_rate, 
                        bytesize=serial.SEVENBITS, 
                        parity=serial.PARITY_ODD, 
                        stopbits=serial.STOPBITS_ONE, 
                        timeout=1)
except:
    try:
        ser.close()
    except:
        print ("Serial port already closed" )
    ser = serial.Serial(serial_port, baud_rate, 
                        bytesize=serial.SEVENBITS, 
                        parity=serial.PARITY_ODD, 
                        stopbits=serial.STOPBITS_ONE, 
                        timeout=1)

# while True:
# run only once    
if True:    
    
    #ser.write('*IDN?\r\n')
    ser.write(bytes('KRDG?\r\n','utf-8'))
    time.sleep(1)
    
    line = ser.readline().decode('utf-8')
    
    #line = line.decode("utf-8") #ser.readline returns a binary, convert to string
    
    #print(line);

    my_today = datetime.datetime.today()
    today = str(my_today.strftime('%Y-%m-%d'))
    log_filename = today + '_dewar.log'

    if os.path.isfile(log_file_path + log_filename):
        log_file = open(log_file_path + log_filename, 'a')
    else:    
        log_file = open(log_file_path + log_filename, 'w')
            
    
    curr_time = str(my_today.strftime('%Y/%m/%d-%H:%M:%S'))
    #hlp = curr_time + ","
    
    data = line.split(',')
    data_str = ""
    for k in range(len(data)):
        #print k
        data_str += curr_time + "," + str(k) + "," + data[k] + "\n"
    
    #hlp += str(line)
    hlp = data_str[:-1]
    #hlp = hlp[:-1] # delete last comma
    
    print (hlp)            
    
    log_file.write(hlp)# + "\n")
 
    log_file.close()
    
    #time.sleep(30)
    
ser.close()

    
    
