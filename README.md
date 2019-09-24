## Example for STM32F4 Discovery Board

This is a basic example which shows how to use the li_can_slv stack on a F4 Discovery board. As you can see in the project folder we have used CubeMX to generate the basic sw layer.

### Hardware needed 

*   STM32F4 Discovery Board
*	A CAN Bus Break-out Board like this one http://copperhilltech.com/can-bus-breakout-board-5-vdc. Following pins are used for CAN.

	| Pin | Name   |
	|-----|:------:|
	| PD0 | CAN_RX |
	| PD1 | CAN_TX |

*  The example also uses this serial pins for some debugging output.
  
  	| Pin  | Name      |
	|------|:---------:|
	| PC6  | USART6_TX |
	| PC7  | USART6_RX |
  

### How to start with the software? ###

First of all it is necessary to install the STM32CUBEIDE https://www.st.com/en/development-tools/stm32cubeide.html 

##### Clone the Repository

Clone the repository with ``git clone recursive`` because the projects uses submodules. You must use SSH because the submodules used in this example uses SSh URL's. So as an example use. 

``git clone git@github.com:liebherrnenzing/li_can_slv_demo_stm32f4_discovery.git --recursive``


##### Install the needed Tools

STM32CUBE IDE

##### Import into Eclipse

At this point it is possible to import the project into the GNU MCU Eclipse Toolchain you have installed at the beginning. But you must modify the Build Command. So navigate to properties and change the path at C/C++ Build, Builder Settings, Build command.

