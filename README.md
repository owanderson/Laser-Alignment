
[Watch our video here!](https://youtu.be/S9H6QgvDfmc)

![](https://github.com/owanderson/Laser-Alignment/blob/master/Logo.png)


Welcome to the Laser-Alignment project!

Laser alignment can be a time consuming process, and manual access to optics is not always possible due to the safety requirements of using high power lasers. Automated systems exist, but they are expensive. Our project aims to automate the laser alignment process using a Raspberry Pi, keeping the hardware expenditure to a fraction of the cost of conventional solutions.

## Components
- 4x continuous rotation servo motors
- 2x fixed rotation servo motors
- 2x photodiodes
- 1x laser pointer

![](https://github.com/owanderson/Laser-Alignment/blob/master/Diagram.png)

While rastering, we alternate between sending pulses to the continuous rotation motors to move the laser beam with checking the signal returned from the photodiode. This means that in practise all of the signals shall not be sent simultaneously, allowing CPU load to be minimised. The following diagram shows all the signal types sent and recieved.

![](https://github.com/owanderson/Laser-Alignment/blob/master/Slide1.PNG)

A flowchart of the rastering process is seen below.

![](https://github.com/owanderson/Laser-Alignment/blob/master/Flowchart.png)

In our baseline model, we provide the hardware and software to align a laser to a set point, aligning to the first photo diode by configuring mirror mount 1, flipping out this photo diode by a fixed rotation servo motor, and configuring mirror mount 2 to align to the second photo diode. Once aligned, the second photo diode is removed from the beam path leaving the system in a fully aligned state.

Our software will facilitate manual mirror control, as well as providing several optimisation techniques to choose from, depending on the level of alignment required for your needs.

The group consists of Owen Anderson, Rowan Pocock and Nicholas Smith. Owen is responsible for GUI implementation, Rowan is responsible for all hardware and Nicholas is responsible for motor control synchronisation.
The mirror mount to be automated in this project is a standard kinematic mirror mount for 1” optics, shown below. This can be ordered from Thorlabs: [https://www.thorlabs.com/newgrouppage9.cfm?objectgroup_id=1492] and is a typical optical mount used for standard laser system setups. 

![](https://github.com/owanderson/Laser-Alignment/blob/master/Mount.png)

All hardware to connect motors to optical components has been designed on TinkerCad and 3D printed on a Flashforge Finder 3D printer. The fundamental hardware component is the motorised mirror mount, shown in the image below. This connects the mount dials to the motors, then links the two motors together and braces them by bolting them onto the spare mirror mount screw hole. 

![](https://github.com/owanderson/Laser-Alignment/blob/master/MMM.PNG)

A screenshot of the CAD drawing of two sets of these motor holders is also shown. 

The laser used in this project is a typical laser diode pen from Ebay (632 nm). A linear actuator has been designed to move a lens into and out of the beam path to de-focus the laser, which is shown in the image below.

![](https://github.com/owanderson/Laser-Alignment/blob/master/Linear_actuator.PNG)

The linear actuator is connected directly to the laser pen. The motor is connected to a cog which drives the linear actuator back and forth and the lens is encapsulated at the end of the linear actuator arm.
In this system, the photodiode needs to be flipped in and out, as there are two photodiodes that must intermittently intersect the beam path, so as not to obstruct the other photodiode. The photodiode flip-arm is shown below. 

![](https://github.com/owanderson/Laser-Alignment/blob/master/PD.PNG)

This has a 180 rotation servo motor, so two positions can be determined as ‘in beam path’ and ‘out of beam path’. The photodiode will be connected via the 3 wires shown in the image to the circuit.
The circuit is shown below. This connects all 8 motors to a common power supply that can be plugged into a wall-socket, then routes all signals from each motor to a wire that can be connected to the RPi pins. For the photodiode signal, an ADC has been used, ‘PCF8591P’, which can be seen in the bottom left of the image. This discretises the voltage (0-5V) from the photodiode into binary signal from 0-255 and sends this to the RPi. 

![](https://github.com/owanderson/Laser-Alignment/blob/master/Circuit.png)

Below shows an image of the entire set-up at present. Later improvements will be getting a PCB made rather than the soldered prototype board, as well as cleaning up some of the 3D printed designs. 

![](https://github.com/owanderson/Laser-Alignment/blob/master/Project.png)

This set-up is currently for a visible light laser diode, but could be adapted to any laser by changing the mirrors and the photodiode with inclusion of an ND filter to avoid photodiode saturation. 
