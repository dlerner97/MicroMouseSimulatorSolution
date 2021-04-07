# MicroMouseSimulatorSolution

1) Open mms maze file.

  • Find the Final-Project-Group1 directory in a terminal window.
  
  • Once there, type in bin/mms.
  
  ◦ If this doesn’t work, type in 
    
      ```bash  
      sudo chmod +x bin/mms
      ```
      
  and enter password.
      
◦ If the maze user interface still does not start, re-download the mms-master from the
  github page: https://github.com/mackorone/mms#download.
      
2) Once you get the maze simulator up and running, select the following “plus” icon on the right hand side.

    • Type MicroMouseSimulatorSolution into the name category.

    • Then type in absolute_path/MicroMouseSimulatorSolution/ into directory

    • Next, type in the following list into the Build Command :

    ```bash
    g++ src/main.cpp src/LandBasedRobot/LandBasedRobot.cpp src/API/API.cpp
    src/Maze/Maze.cpp src/Algorithm/Algorithm.cpp
    src/LandBasedTracked/LandBasedTracked.cpp
    src/LandBasedWheeled/LandBasedWheeled.cpp
    ```
    • Lastly type 
    ```bash
    ./a.out
    ```
    into the Run command
      
3) Select "Build" and then "Run"
