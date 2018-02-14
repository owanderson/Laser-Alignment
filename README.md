

![](https://github.com/owanderson/Laser-Alignment/blob/master/Logo.png)


Welcome to the Laser-Alignment project!

Laser alignment can be a time consuming process, and manual access to optics is not always possible due to the safety requirements of using high power lasers. Automated systems exist, but they are expensive. Our project aims to automate the laser alignment process using a raspberry pi, keeping the hardware expenditure to a fraction of the cost of conventional solutions.

## Components
- 4x continuous rotation servo motors
- 2x fixed rotation servo motors
- 2x photodiodes
- 1x laser pointer

![](https://github.com/owanderson/Laser-Alignment/blob/master/DIAGRAM.png)

In our baseline model, we provide the hardware and software to align a laser to a set point, aligning to the first photo diode by configuring mirror mount 1, flipping out this photo diode by a fixed rotation servo motor, and configuring mirror mount 2 to align to the second photo diode. Once aligned, the second photo diode is removed from the beam path leaving the system in a fully aligned state.

Our software will facilitate manual mirror control, as well as providing several optimisation techniques to choose from, depending on the level of alignment required for your needs.
