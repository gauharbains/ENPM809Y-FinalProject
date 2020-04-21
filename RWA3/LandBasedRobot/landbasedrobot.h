//
// Created by gauha on 4/19/2020.
//

#pragma once
#include <string>
#include <iostream>

namespace rwa3 {
    class LandBasedRobot {

    protected:
        std::string name_; // Name of the robot
        double speed_; // Driving speed of the robot
        double width_; //Width of the base of the robot
        double length_; // Length of the base of the robot
        double height_; // Height of the base of the robot
        double capacity_; //Payload of the arm
        int x_; // X coordinate of the robot in the maze
        int y_; // Y coordinate of the robot in the maze

    public:
        virtual void GoUp(int,int)=0; // Move the robot up in the maze
        virtual void GoDown(int,int)=0; // Move the robot down in the maze
        virtual void TurnLeft(int,int)=0; // Move the robot left in the maze
        virtual void TurnRight(int,int)=0; // Move the robot right in the maze
        virtual void PickUp(std::string)=0; // Arm picks up an object
        virtual void Release(std::string)=0; // Arm releases an object

        // accessors
        std::string get_name() const{
            return name_;
        }

        double get_speed() const{
            return speed_;
        }

        double get_width() const{
            return width_;
        }

        double get_length() const{
            return length_;
        }

        double get_height() const{
            return height_;
        }

        double get_capacity() const{
            return capacity_;
        }

        int get_x() const{
            return x_;
        }

        int get_y() const{
            return y_;
        }

        // mutators

        void set_name(std::string name){
            name_=name;
        }

        void set_speed(double speed){
            speed_=speed;
        }

        void set_width(double width){
            width_=width;
        }

        void set_length(double length){
            length_=length;
        }

        void set_height(double height){
            height_=height;
        }

        void set_capacity(double capacity){
            capacity_=capacity;
        }

        void set_x(int x){
            x_=x;
        }

        void set_y(int y){
            y_=y;
        }


        LandBasedRobot(std::string name, int x, int y){
            name_=name;
            x_=x;
            y_=y;
         }

         ~LandBasedRobot(){}





    };



} // - end of namespace rwa3