# Robot Navigation.
Objective of this project is to  navigate a robot through a maze to reach the center of the maze.
This robot navigation system was tested using [Micromouse Simulator](https://github.com/mackorone/mms). 
Depth-first Search algorithm is being applied to implement the path planning algorithm.



## Authors: 
@ Gauhar Bains
@ Ghanem Jamal Eddine
@ Moumita Paul
@ William Hewlett
@ Cheng Chen



## Dependencies:
```
1. Ubuntu 16.04
2. Doxygen 1.18.18
3. CodeLite 14.0
4. micromousesimulator
5. QT

```

## Installation of Dependencies:
```
1. Create a directory on your desktop:
 $ cd ~/Desktop/FinalProject

2. Clone the micromouse simulator in the directory you just created:
 $ git clone https://github.com/mackorone/mms.git

3. Clone a set of maze files:
 $ git clone https://github.com/micromouseonline/mazefiles.git

4. Clone a C ++ program which simply turns the robot left and right:
 $ git clone https://github.com/mackorone/mms-cpp.git

5. Compile the simulator:
 a). Install QT:
      $ sudo apt-get install qt5-default
 b) Build the simulator:
      $ cd mms/src
      $ qmake && make
 c) run the simulator:
      $ ../../mms/bin/mms


```
## To Run the Code:
```
Clone this repository

Start the simulator

Set Directory to the path of src
	ex: /Final-Project-Group5/FP/src

Set "Build Command" to:
	g++ -std=c++11 API/api.cpp Maze/maze.cpp Algorithm/algorithm.cpp LandBasedRobot/landbasedrobot.cpp LandBasedTracked/landbasedtracked.cpp LandBasedWheeled/landbasedwheeled.cpp ../main.cpp

Set "Run Command" to:
	./a.out

Build the project and run it

```

## Doxy Output:
```
run the index.html file in Documentation/html/ folder

```



