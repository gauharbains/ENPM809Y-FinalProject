#pragma once

#include <iostream>
#include <array>

#include "../API/api.h"

namespace fp{
    class Maze{
    public:
        /// Basic constructor
        Maze();
        /// destructor
        ~Maze() {}

        /// let robot explore this point at API maze, and change the map of maze if there there is wall between adjacent point
        /// \param x - x coordinate of this spot
        /// \param y - y coordinate of this spot
        /// \param dir - direction of the robot
        void CoordMaze(int x, int y, char dir);

        /// is there a wall at south of this spot
        /// \param x  - x coordinate of this spot
        /// \param y  - y coordinate of this spot
        /// \return - true if there a wall, false otherwise
        bool IsWallSouth(int x, int y) const;

        /// is there a wall at east of this spot
        /// \param x  - x coordinate of this spot
        /// \param y  - y coordinate of this spot
        /// \return - true if there a wall, false otherwise
	    bool IsWallEast(int x, int y) const;

        /// is there a wall at north of this spot
        /// \param x  - x coordinate of this spot
	    /// \param y  - y coordinate of this spot
	    /// \return - true if there a wall, false otherwise
        bool IsWallNorth(int x, int y) const;

        /// is there a wall at west of this spot
        /// \param x  - x coordinate of this spot
        /// \param y  - y coordinate of this spot
        /// \return - true if there a wall, false otherwise
        bool IsWallWest(int x, int y) const;
        
    protected:
        int SouthWall[16][16]; 
        int EastWall[16][16]; 
        int NorthWall[16][16]; 
        int WestWall[16][16]; 
    };
}
