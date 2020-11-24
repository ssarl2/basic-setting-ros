#!/bin/bash

catkin clean -y
catkin build
source devel/setup.bash
roslaunch package_name a.launch
