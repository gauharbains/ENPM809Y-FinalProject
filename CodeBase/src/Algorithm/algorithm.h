#pragma once

#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <queue>
#include <algorithm>
#include <utility>
#include <bits/stdc++.h> 

#include "../API/api.h"
#include "../LandBasedWheeled/landbasedwheeled.h"
#include "../LandBasedTracked/landbasedtracked.h"
#include "../Maze/maze.h"

namespace fp{
	class Algorithm{
	public:
	    /// check if new_node match up a node in check_till
	    /// \param new_node
	    /// \param check_till
	    /// \return true if there is a node check_till match up new_node. flase otherwise
	    bool CheckNode(std::pair<std::pair<int, int>, char> new_node,std::vector<std::pair<std::pair<int, int>, char>> check_till); 

	    /// DFS Algorithm that guild the robot to a goal in maze
	    /// \param robot - the robot that under control
	    /// \param maze - a map of maze that will keep unpdating while robot explore the maze with API
	    /// \return true if any goal is reachable, false otherwise
	    bool Planner(std::shared_ptr<fp::LandBasedRobot> robot, fp::Maze& maze);

	    /// check if this spot is a goal
	    /// \param x - X coordinate of this spot
	    /// \param y - Y coordinate of this spot
	    /// \return - true if this spot is a goal, flase otherwise
	    bool CheckGoal(int x, int y); 
	private:
	    ///--Coordinates structure
	    struct coord 
	    {
			int x;	/// - x coordinate of the coordinate.
			int y;	/// - y coordinate of the coordinate.
	    };
		
	    coord node_c; 	// location of robot in maze
	    std::pair<std::pair<int, int>, char> pose_c;	// pose of robot in maze before it explore a spot
	    std::pair<std::pair<int, int>, char> pose_n;	// pose of robot im maze after it explore a spot
	    std::vector<std::pair<std::pair<int, int>, char>> found_d; 	// a vector that store all pose of robot in the maze
	    std::vector<std::pair<std::pair<int, int>, char>> found_y;	// a vector that store all possible step
	    std::vector<std::pair<std::pair<int, int>, char>> check_till;	// a vector for the found done and yet to be done nodes
	    std::vector<std::pair<std::pair<int, int>, char>> route;	// a route from current robot location to goal in maze
	    std::map<std::pair<std::pair<int, int>, char>, std::pair<std::pair<int, int>, char>> node_p;   // a map that store all move the robot made
	};
}