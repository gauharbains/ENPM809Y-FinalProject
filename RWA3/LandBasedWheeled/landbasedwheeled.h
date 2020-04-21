//
// Created by gauha on 4/19/2020.
//

#pragma once
#include<string>
#include<iostream>
#include <memory>
#include "../LandBasedRobot/landbasedrobot.h"

namespace rwa3{
    class LandBasedWheeled: public LandBasedRobot {
    public:
        virtual void GoUp(int,int) override; // Move the robot up in the maze
        virtual void GoDown(int,int) override; // Move the robot down in the maze
        virtual void TurnLeft(int,int) override; // Move the robot left in the maze
        virtual void TurnRight(int,int) override; // Move the robot right in the maze
        virtual void PickUp(std::string) override; // Arm picks up an object
        virtual void Release(std::string) override; // Arm releases an object

        LandBasedWheeled(std::string name,int x,int y): LandBasedRobot(name,x,y){

        }


    protected:
        std::shared_ptr<std::string> wheel_type; // Type of wheels mounted on robot
        int wheel_number; // Number of wheels mounted on the robot.


    };


}

