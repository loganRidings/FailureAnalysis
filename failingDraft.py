# This is the first draft of our device automation code
# The goal is to send commands over the serial pins of the raspberry pi, and recieve data back.

##########################################################################
#       Still need to DO: get the dataframe and csv reading going.       #
##########################################################################

# Imports:
import serial # pyserial package that will do the heavy lifting of machine/serial commands
import time # A way to time the updates of the different components
import pandas as pd # package for DataFrame object to help with CSV writing

# Setting up our serial object: Port for Pi is ttyS0. Baudrate agreed with arduino code, the rest is default parameters
# Not necessary to worry about unless we want to do higher complexity serial communication later.
# timeout of 1 seconds
ser = serial.Serial(
        port = '/dev/ttyS0',
        baudrate = 9600,
        parity=serial.PARITY_NONE,
        stopbits=serial.STOPBITS_ONE,
        bytesize=serial.EIGHTBITS,
        timeout=1
        )

# Command flags for Arduinos. Stop is the same across all devices so it has a -1
## STILL NEED TO FILL DEVICE 4
FLAGS = {0: bytes(b'driver\n'), 1: bytes(b'current\n'), 2:byets(b'photoOne\n'), 3: bytes(b'photoTwo\n'), -1: bytes(b'stop/n')}
N = 4 # number of arduinos
WAITTIME = 30 # Wait time between checks in seconds
readColumns = ['C0', 'C1', 'C2', 'C3', 'C4','C5', 'PR0', 'PR1', 'PR2', 'PR3', 'PR4', 'PR5', 'TIME', 'MEASURE_NUM']
READOUT = pd.df(columns=readColumns)

# Stick everything inside the main function
def main():

    # set time to initialize the code to 0 so it starts right away
    old_time = 0

    # Keep the script running until something breaks
    while True:

        # Only initialize if it's been 30 seconds or more
        if time.time() >= (old_time+WAITTIME):

            # cycle through each arduino
            for i in range(N):

                # command write and flush
                ser.write(FLAGS[i])
                ser.flush()

                # read
                while ser.in_waiting > 0:
                    line = ser.readline().decode('utf-8').rstrip()
                    print(line)

                # stop
                ser.write(FLAGS[-1])
                ser.flush()

            # reset old_time to the new time so the loop waits 30 seconds+
            old_time = time.time()

    print("Error: The while loop was broken")
    return False


if __name__ == '__main__':
    main()
