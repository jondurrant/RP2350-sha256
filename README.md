# RP2350-sha256
Testing out the SHA256 on RP2350 and Pico 2

Comparing the performance between WolfSSL implimentation of SHA256 and the hardware SHA256 on the Pico.


## Data File
I am using a very large image in the img folder and have converted this to a headerfile with bin2c

## RP2350SHA256
Produce the SHA256 of the data file using the RP2350 hardware. Measure the time in ms.

## WolfSSLSHA256
Produce the SHA256 of the data file using the WolfSSL Crypt library and measure the time in ms.

My normal WolfSSH port is designed for FreeRTOS, so just hacking it here to run baremetal for this experiment