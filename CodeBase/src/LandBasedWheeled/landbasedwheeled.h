#pragma once
#include "../LandBasedRobot/landbasedrobot.h"

#include <string>

namespace fp{
    class LandBasedWheeled : public LandBasedRobot{
    public:
		/// Default constructor.
		/// \param name  - Name of the robot.
		/// \param x  - X coordinate of the robot in the maze.
		/// \param y - Y coordinate of the robot in the maze.
		LandBasedWheeled(std::string name, int x, int y);

		/// Default constructor with no input.
		LandBasedWheeled();

		/// destructor
		virtual ~LandBasedWheeled();

		/// Move the robot forward faster
		void SpeedUp(int x);

		/// Move the robot forward.
		virtual void MoveForward() override;

		/// Rotate the robot 90°counter-clockwise.
		virtual void TurnLeft(int x, int y) override;

		/// Rotate the robot 90°clockwise.
		virtual void TurnRight(int x, int y) override;

		///--accessor or getter
		/// accessor of x coordinate
		/// \return X coordinate of the robot in the maze.
		virtual int get_x() override {
			return x_;
		}

		/// accessor of y coordinate
		/// \return Y coordinate of the robot in the maze.
		virtual int get_y() override {
			return y_;
		}

		/// accessor of robot name
		/// \return Name of the robot.
		virtual char GetDirection() override {
			return direction_;
		}

		///  accessor of speed
		/// \return speed of robot
		double get_speed() {
			return speed_;
		}
    protected:
		int wheel_number;   /// Number of wheels mounted on the robot.
    };
}
