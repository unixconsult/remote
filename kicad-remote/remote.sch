EESchema Schematic File Version 2
LIBS:remote-rescue
LIBS:power
LIBS:device
LIBS:switches
LIBS:relays
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
LIBS:remote-cache
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L Arduino_Nano_Socket XA?
U 1 1 5AEF6128
P 4900 3450
F 0 "XA?" V 5000 3450 60  0000 C CNN
F 1 "Arduino_Nano_Socket" V 4800 3450 60  0000 C CNN
F 2 "" H 6700 7200 60  0001 C CNN
F 3 "" H 6700 7200 60  0001 C CNN
	1    4900 3450
	1    0    0    -1  
$EndComp
$Comp
L POT-RESCUE-remote RV?
U 1 1 5AEF645A
P 1900 3550
F 0 "RV?" V 1725 3550 50  0000 C CNN
F 1 "forward/backward" V 1800 3550 50  0000 C CNN
F 2 "" H 1900 3550 50  0001 C CNN
F 3 "" H 1900 3550 50  0001 C CNN
	1    1900 3550
	1    0    0    -1  
$EndComp
Wire Wire Line
	3600 3550 2050 3550
$Comp
L POT-RESCUE-remote RV?
U 1 1 5AEF64A4
P 2200 3800
F 0 "RV?" V 2025 3800 50  0000 C CNN
F 1 "right/left" V 2100 3800 50  0000 C CNN
F 2 "" H 2200 3800 50  0001 C CNN
F 3 "" H 2200 3800 50  0001 C CNN
	1    2200 3800
	0    -1   -1   0   
$EndComp
Wire Wire Line
	3600 3650 2200 3650
Wire Wire Line
	1900 3800 2050 3800
Wire Wire Line
	1900 3700 1900 4850
Wire Wire Line
	1900 3400 1900 1850
$Comp
L +3V3 #PWR?
U 1 1 5AEF64F3
P 1900 1850
F 0 "#PWR?" H 1900 1700 50  0001 C CNN
F 1 "+3V3" H 1900 1990 50  0000 C CNN
F 2 "" H 1900 1850 50  0001 C CNN
F 3 "" H 1900 1850 50  0001 C CNN
	1    1900 1850
	1    0    0    -1  
$EndComp
Wire Wire Line
	2350 3800 2350 3200
Wire Wire Line
	2350 3200 1900 3200
Connection ~ 1900 3200
$Comp
L LM5109BSD U?
U 1 1 5AEF66E7
P 7800 3150
F 0 "U?" H 7850 3500 50  0000 L CNN
F 1 "L9110" H 7850 3600 50  0000 L CNN
F 2 "Housings_DFN_QFN:WSON8_4x4mm_Pitch0.8mm" H 7800 3150 50  0001 C CIN
F 3 "" H 7800 3150 50  0001 C CNN
	1    7800 3150
	1    0    0    -1  
$EndComp
Wire Wire Line
	7400 3150 7500 3150
$Comp
L Motor_DC M?
U 1 1 5AEF683A
P 8600 3100
F 0 "M?" H 8700 3200 50  0000 L CNN
F 1 "Motor_DC" H 8700 2900 50  0000 L TNN
F 2 "" H 8600 3010 50  0001 C CNN
F 3 "" H 8600 3010 50  0001 C CNN
	1    8600 3100
	1    0    0    -1  
$EndComp
Wire Wire Line
	8100 3350 8450 3350
Wire Wire Line
	8450 3350 8450 3400
Wire Wire Line
	8450 3400 8600 3400
Wire Wire Line
	8100 2950 8450 2950
Wire Wire Line
	8450 2950 8450 2900
Wire Wire Line
	8450 2900 8600 2900
Wire Wire Line
	7500 2950 7500 3050
Wire Wire Line
	7400 3050 7400 3150
$Comp
L CONN_01X02 P?
U 1 1 5AF2914B
P 6600 2800
F 0 "P?" H 6600 2950 50  0000 C CNN
F 1 "ss-hc-12" V 6700 2800 50  0000 C CNN
F 2 "" H 6600 2800 50  0000 C CNN
F 3 "" H 6600 2800 50  0000 C CNN
	1    6600 2800
	1    0    0    -1  
$EndComp
Wire Wire Line
	6200 2750 6400 2750
Wire Wire Line
	6200 2850 6400 2850
Wire Wire Line
	6200 3250 6950 3250
$Comp
L IRF9540N Q?
U 1 1 5AF29B80
P 7700 2450
F 0 "Q?" H 7950 2525 50  0000 L CNN
F 1 "p-chn" H 7950 2450 50  0000 L CNN
F 2 "TO-220" H 7950 2375 50  0000 L CIN
F 3 "" H 7700 2450 50  0000 L CNN
	1    7700 2450
	1    0    0    -1  
$EndComp
Wire Wire Line
	7800 2650 7800 2750
Connection ~ 6950 3250
Wire Wire Line
	6950 3250 6950 2500
Wire Wire Line
	6200 3350 7200 3350
Wire Wire Line
	7200 3350 7200 2950
Wire Wire Line
	7200 2950 7500 2950
Wire Wire Line
	6200 3450 7300 3450
Wire Wire Line
	7300 3450 7300 3050
Wire Wire Line
	7300 3050 7400 3050
$EndSCHEMATC
