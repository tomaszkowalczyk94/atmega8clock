# ATmega8 Digital LED Clock ⏰

| ![image-6.png](image-6.png) |

A custom-built, DIY digital clock powered by an **ATmega8** microcontroller and a 4-digit 7-segment green LED display. This project involves a custom perfboard circuit, transistor-based display multiplexing, and a fully custom 3D-printed enclosure designed in FreeCAD.

## 🌟 Features
* **Microcontroller:** Atmel ATmega8 
* **Display:** 0.56" 4-Digit 7-Segment LED display with colons/dots (LED4-AF-05643FG-B PBF).
* **Multiplexing:** Utilizes BC547 NPN transistors for switching the common anodes.
* **Custom Enclosure:** 3D printed case and lid, originally modeled in FreeCAD.
* **Programming:** Flashed via a USBAsp programmer using Arduino IDE.

---

## 🛠️ Hardware & Components

* **1x ATmega8** Microcontroller
* **1x LED4-AF-05643FG-B PBF** (4-Digit 7-Segment Display, 0.56", Green, Common Anode)
* **5x BC547 NPN Transistors** (Used to drive the common anodes)
* **Resistors** (For base current limiting on the transistors and segment current limiting)
* **USBAsp Programmer** (For flashing the ATmega8)
* Universal perfboard/stripboard

---

## 🔌 Circuit & Pinout

The display requires multiplexing. The **Common Anodes** are driven by the ATmega8 via BC547 NPN transistors (which conduct when a high signal is applied to the base). The **Cathodes** are connected directly to the ATmega8 digital pins. 

### Anode Connections (via BC547 Transistors)
| Display Pin | ATmega8 Pin (Arduino IDE) | Function |
| :--- | :--- | :--- |
| **14** | Digital Pin 13 | DIGIT 1 |
| **11** | Digital Pin 10 | DIGIT 2 |
| **10** | Digital Pin 9 | DIGIT 3 |
| **7** | Digital Pin 6 | Colon / Dots (UC, LC) |
| **6** | Digital Pin 5 | DIGIT 4 |

### Cathode Connections (Direct to ATmega8)
| Display Pin | ATmega8 Pin (Arduino IDE) | Segment |
| :--- | :--- | :--- |
| **13** | Digital Pin 12 | Segment A |
| **9** | Digital Pin 8 | Segment B |
| **4** | Digital Pin 3 | Segment C |
| **2** | Digital Pin 1 | Segment D |
| **1** | Digital Pin 0 | Segment E |
| **12** | Digital Pin 11 | Segment F |
| **5** | Digital Pin 4 | Segment G |
| **3** | Digital Pin 2 | Dot (DP / OP) |
| **8** | Digital Pin 7 | Colon (UC, LC) |

---

## 📦 3D Printed Enclosure

The repository includes custom 3D models for the clock's housing.
* **`case.FCStd`**: The original FreeCAD project file. Use this if you want to modify the dimensions or design.
* **`case-PartBody.stl`**: The main body of the enclosure, ready for slicing and 3D printing.
* **`case-wieczkoThickness001.stl`**: The back lid/cover for the enclosure.

*Tip: Print with standard PLA/PETG. No special supports are required if oriented face-down.*

---

## 💻 Software & Programming

The code for this project was written in the Arduino IDE and leverages basic multiplexing logic to illuminate the 7-segment display. 

**Flashing the ATmega8:**
1. You will need a **USBAsp** programmer.
2. Install the necessary drivers using [Zadig](https://zadig.akeo.ie/).
3. Connect the USBAsp to the ATmega8 via the ISP headers.
4. In Arduino IDE, select the ATmega8 board, set the programmer to "USBAsp", and click **"Upload Using Programmer"**.

*Helpful resources for programming raw AVR chips:*
* [Majsterkowo: Programming microcontrollers with USBAsp (Polish)](https://majsterkowo.pl/programowanie-mikrokontrolerow-za-pomoca-programatora-usbasp/)
* [YouTube Tutorial](https://www.youtube.com/watch?v=X01Nhq8TeY0&t=58s)

---

## 📸 Gallery

| Circuit Design | 
| :---: 
| ![image-4.png](image-4.png) |

| Prototype | 
| :---: 
| ![image-3.png](image-3.png) |


| Final electronic board | 
| :---: 
| ![image-7.png](image-7.png) |

