# WIFI CONTROL BOT


## Table of Contents

- [Project](# WIFI CONTROL BOT)
  - [Table of Contents](#table-of-contents)
  - [About The Project](#about-the-project)
  - [Demo](#demo)
  - [File Structure](#file-structure)
  - [Getting started](#Getting-Started)
  - [Future Work](#future-work)
  - [Contributors](#contributors)
  - [Acknowledgements and Resources](#acknowledgements-and-references)
  - [License](#license)
  
## About

In this project, we will set up a wifi server and control the bot using our phone 
  ### Project Workflow 
- learn to make and design a joystick webpage to help users control the bot
- testing the webpage by checking if the coordinates are correctly updated on the terminal.
- understand the line following the code of wall e .
- structuring an algorithm for controlling motor speeds according to the readings from the joystick webpage.
- testing whether the bot is stopping properly according to the joystick
- giving additional power to specific motors in specific cases for proper turning


## DEMO




https://github.com/tvilight4/Wifi_control_bot/assets/122543856/67c1a887-8ec4-418c-a7a2-a1c6221f6cce




## File Structure
```
├── CMakeLists.txt
├── build
├── frontend
│   └── joystick.html
├── main
│   ├── CMakeLists.txt
│   ├── Kconfig
│   ├── component.mk
│   ├── include
│   ├── line_following.c
│   ├── tuning_http_server.c
│   └── wifi_handler.c
├── partition_table.csv
├── sdkconfig
├── sdkconfig.defaults
└── sdkconfig.old

11 directories, 38 files
``` 
## Getting Started

### Prerequisites
To download and use this code, the minimum requirements are:

* [ESP_IDF](https://github.com/espressif/esp-idf)
* Windows 7 or later (64-bit), Ubuntu 20.04 or later
* [Microsoft VS Code](https://code.visualstudio.com/download) or any other IDE 

### Installation

Clone the project by typing the following command in your Terminal/CommandPrompt

```
git clone https://github.com/tvilight4/Wifi_control_bot.git 
```
Navigate to the 7_linefollowing

```
cd 7_linefollowing
```

### Usage

Once the requirements are satisfied, you can easily download the project and use it on your machine.
After following the above steps, use the following commands:

To activate the IDF

```
get_idf
```

To build the code 

```
idf.py build
```

To flash the code

```
idf.py -p (PORT) flash monitor
```
## Future Work

- [ ] Implementing better algorithms for turning
- [ ] Improve the design and model of the bot
- [ ] Achieve more accuracy in turning by adding the self-balancing feature along with the remote controlling

## Contributors

* [Tvisha Vedant](https://github.com/tvilight4)
* [Kamakshi Ramamurthy](https://github.com/Kamakshi8104)

## Acknowledgements and References
* [SRA VJTI](https://sravjti.in/) WALL-E 2023
* Special thanks to our mentors [Prit Kanadiya](https://github.com/PritK99), [Smeer Gupta](https://github.com/sameergupta4873) and all the seniors at SRA, VJTI for their constant support and guidance throughout the project.
* [Wall-E 2023](https://github.com/SRA-VJTI/Wall-E) Github repository of   Wall-E 2023
* 
* [Resources from mentor](https://github.com/sameergupta4873/Wall-E-test) reference joystick webpage.
## License
[MIT License](https://opensource.org/licenses/MIT)

