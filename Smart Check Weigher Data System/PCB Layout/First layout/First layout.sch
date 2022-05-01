EESchema Schematic File Version 4
EELAYER 30 0
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
L RF_Module:ESP-12E U1
U 1 1 622EC8CF
P 5200 3650
F 0 "U1" H 5200 4631 50  0000 C CNN
F 1 "ESP-12E" H 5200 4540 50  0000 C CNN
F 2 "RF_Module:ESP-12E" H 5200 4539 50  0001 C CNN
F 3 "http://wiki.ai-thinker.com/_media/esp8266/esp8266_series_modules_user_manual_v1.1.pdf" H 4850 3750 50  0001 C CNN
	1    5200 3650
	1    0    0    -1  
$EndComp
$Comp
L Connector:Jack-DC J1
U 1 1 622F19B1
P 1500 3600
F 0 "J1" H 1557 3925 50  0000 C CNN
F 1 "Jack-DC" H 1557 3834 50  0000 C CNN
F 2 "Connector_BarrelJack:BarrelJack_Horizontal" H 1550 3560 50  0001 C CNN
F 3 "~" H 1550 3560 50  0001 C CNN
	1    1500 3600
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x04 J2
U 1 1 622F36B3
P 6550 3450
F 0 "J2" H 6630 3442 50  0000 L CNN
F 1 "Conn_01x04" H 6630 3351 50  0000 L CNN
F 2 "Connector_PinHeader_1.00mm:PinHeader_1x04_P1.00mm_Vertical" H 6550 3450 50  0001 C CNN
F 3 "~" H 6550 3450 50  0001 C CNN
	1    6550 3450
	1    0    0    -1  
$EndComp
$Comp
L Regulator_Linear:L7805 U2
U 1 1 622F3DF9
P 3000 3400
F 0 "U2" H 3000 3642 50  0000 C CNN
F 1 "L7805" H 3000 3551 50  0000 C CNN
F 2 "Connector_PinHeader_1.00mm:PinHeader_1x03_P1.00mm_Vertical" H 3025 3250 50  0001 L CIN
F 3 "http://www.st.com/content/ccc/resource/technical/document/datasheet/41/4f/b3/b0/12/d4/47/88/CD00000444.pdf/files/CD00000444.pdf/jcr:content/translations/en.CD00000444.pdf" H 3000 3350 50  0001 C CNN
	1    3000 3400
	1    0    0    -1  
$EndComp
$Comp
L Device:CP C1
U 1 1 622F4889
P 2450 3600
F 0 "C1" H 2568 3646 50  0000 L CNN
F 1 "CP" H 2568 3555 50  0000 L CNN
F 2 "Capacitor_THT:CP_Radial_D4.0mm_P1.50mm" H 2568 3509 50  0001 L CNN
F 3 "~" H 2450 3600 50  0001 C CNN
	1    2450 3600
	1    0    0    -1  
$EndComp
$Comp
L Device:CP C2
U 1 1 622F50CD
P 3600 3600
F 0 "C2" H 3718 3646 50  0000 L CNN
F 1 "CP" H 3718 3555 50  0000 L CNN
F 2 "Capacitor_THT:CP_Radial_D4.0mm_P1.50mm" H 3718 3509 50  0001 L CNN
F 3 "~" H 3600 3600 50  0001 C CNN
	1    3600 3600
	1    0    0    -1  
$EndComp
Wire Wire Line
	2450 3450 2450 3400
Wire Wire Line
	2450 3400 2700 3400
Wire Wire Line
	3300 3400 3600 3400
Wire Wire Line
	3600 3400 3600 3450
Wire Wire Line
	2450 3750 3000 3750
Wire Wire Line
	3000 3750 3000 3700
Wire Wire Line
	3600 3750 3000 3750
Connection ~ 3000 3750
$Comp
L power:GND #PWR0101
U 1 1 622F5AFB
P 3000 3750
F 0 "#PWR0101" H 3000 3500 50  0001 C CNN
F 1 "GND" H 3005 3577 50  0000 C CNN
F 2 "" H 3000 3750 50  0001 C CNN
F 3 "" H 3000 3750 50  0001 C CNN
	1    3000 3750
	1    0    0    -1  
$EndComp
Wire Wire Line
	1800 3500 1800 3400
Wire Wire Line
	1800 3400 2450 3400
Connection ~ 2450 3400
Wire Wire Line
	1800 3700 1800 3750
Wire Wire Line
	1800 3750 2450 3750
Connection ~ 2450 3750
Wire Wire Line
	3600 3400 3600 2750
Wire Wire Line
	3600 2750 5200 2750
Wire Wire Line
	5200 2750 5200 2850
Connection ~ 3600 3400
Wire Wire Line
	3600 3750 3600 4550
Wire Wire Line
	3600 4550 5200 4550
Wire Wire Line
	5200 4350 5200 4550
Connection ~ 3600 3750
Wire Wire Line
	6350 3350 6350 2750
Wire Wire Line
	6350 2750 5200 2750
Connection ~ 5200 2750
Wire Wire Line
	6350 3650 6350 4550
Wire Wire Line
	6350 4550 5200 4550
Connection ~ 5200 4550
Wire Wire Line
	5800 3450 6350 3450
Wire Wire Line
	5800 3550 6350 3550
$EndSCHEMATC
