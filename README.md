# Basic setting for ROS

## Usage
1. `mkdir catkin_ws/src -p`
2. `cd catkin_ws/src`
3. `git clone https://github.com/ssarl2/basic-setting-ros.git`
4. `cd ..`
5. `catkin build && source devel/setup.bash`
6. `roslaunch package_name package.launch`
7. Open another terminal and command below
8. `rostopic echo /talker`

## Environment
- Ubuntu 18.04 bionic
- ROS melodic version
  - Install - [`cd scripts`](https://github.com/ssarl2/basic-setting-ros/tree/master/scripts) and `bash install_ros_melodic.sh`

## Dependencies
- ROS
- CMake
- Catkin
- C++
