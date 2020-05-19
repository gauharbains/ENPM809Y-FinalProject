#pragma once
#include <string>


namespace fp{
    class LandBasedRobot
    {
    public:
		/// Default constructor.
		/// \param name  - Name of the robot.
    	/// \param x  - X coordinate of the robot in the maze.
    	/// \param y  - Y coordinate of the robot in the maze.
		LandBasedRobot(std::string name, int x, int y);

		/// Default constructor no input
		LandBasedRobot();

		/// Default destructor
		~LandBasedRobot();

		/// virtual functions
		/// Move the robot forward.
		virtual void MoveForward() = 0;

		/// Rotate the robot 90°counter-clockwise.
		virtual void TurnLeft(int x, int y) = 0;

		/// Rotate the robot 90°clockwise.
		virtual void TurnRight(int x, int y) = 0;

		///--accessor or getter
		/// accessor of x coordinate
		/// \return X coordinate of the robot in the maze.
		virtual int get_x() = 0;

		/// accessor of y coordinate
		/// \return Y coordinate of the robot in the maze.
		virtual int get_y() = 0;

		/// Get the direction of the robot in the maze.
		/// \return direction of the robot in the maze.
		virtual char GetDirection() = 0;

		///  accessor of speed
		/// \return speed of robot
		virtual double get_speed() = 0;
    protected:
		std::string name_; /// Name of the robot.
		double speed_; /// Driving speed of the robot.
		double width_; /// Width of the base of the robot.
		double length_; /// Length of the base of the robot.
		double height_; /// Height of the base of the robot.
		double capacity_; /// Payload of the arm.
		int x_; /// X coordinate of the robot in the maze.
		int y_; /// Y coordinate of the robot in the maze.
		char direction_; /// direction that the robot is facing in the maze. The different possibilities are 'N' (north), 'E' (east), 'W' (west), 'S' (south).
    };
}
