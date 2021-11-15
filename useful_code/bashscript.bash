#!/bin/bash

### First, define path of where you are creating this robot folder

checking_directory(){
   echo "Please double check this is where you want robot folder to be created (usually src folder of a workspace)."
   echo "directory: $PWD"
   select yn in "Yes" "No"; do
    case $yn in
        Yes ) robot_name_prompt exit;;
        No ) exit;;
    esac
   done

}
robot_name_prompt(){
   read -p "Enter robot name: " robot_name
   echo "Confirm '${robot_name}' is your robot name?"
   select yn in "Yes" "No"; do
    case $yn in
        Yes ) break;;
        No ) robot_name_prompt exit;;
    esac
   done
}

making_directory(){
   echo "Do you want to build with catkin(ROS1) or colcon(ROS2)"
    select yn in "catkin" "colcon"; do
    case $yn in
        catkin ) catkin_directories exit;;
        colcon ) colcon_directories exit;;
    esac
   done
   
   mkdir -p ${robot_name}/${robot_name}
   mkdir -p ${robot_name}/${robot_name}_bringup
   mkdir -p ${robot_name}/${robot_name}_description
   mkdir -p ${robot_name}/${robot_name}_navigation
   mkdir -p ${robot_name}/${robot_name}_slam
   mkdir -p ${robot_name}/${robot_name}_teleop

}




creating_directory
