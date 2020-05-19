#include "algorithm.h"

bool fp::Algorithm::CheckNode(std::pair<std::pair<int, int>, char> pose_n, std::vector<std::pair<std::pair<int, int>, char>> check_till){
    for (auto iter : check_till){
        if (pose_n.second == iter.second && pose_n.first.first == iter.first.first && pose_n.first.second == iter.first.second)
            return true;
    }
    return false;
}

bool fp::Algorithm::Planner(std::shared_ptr<fp::LandBasedRobot> robot, fp::Maze& maze)
{    
    char direction = robot->GetDirection(); // current direction of robot
    node_c = {robot->get_x(), robot->get_y()};  // current location of the robot
    pose_c = {{node_c.x, node_c.y}, direction}; // current pose of robot
    maze.CoordMaze(node_c.x, node_c.y, direction);  // let robot explore this point of API maze, and update map of maze

    /// a DFS algorithm that decide the next move of robot
    while (!fp::Algorithm::CheckGoal(node_c.x, node_c.y)){  // while goal is not reached
        if(!fp::Algorithm::CheckNode(pose_c, found_d)){     // if this spot haven't been explored by robot under this pose before
            //--pose of robot is South
            if (direction == 'S') {
                //--Back
                if(maze.IsWallWest(node_c.x, node_c.y) && maze.IsWallSouth(node_c.x, node_c.y) && maze.IsWallEast(node_c.x, node_c.y)){
                    pose_n = {{node_c.x, node_c.y + 1}, 'N'};
                    found_y.push_back(pose_n);
                    node_p.insert({pose_n, pose_c});
                }
                //--Right
                if(node_c.x >= 1 && !maze.IsWallWest(node_c.x, node_c.y) && !CheckNode({{node_c.x - 1, node_c.y}, 'W'}, found_y)){
                    pose_n = {{node_c.x - 1, node_c.y}, 'W'};
                    found_y.push_back(pose_n);
                    node_p.insert({pose_n, pose_c});
                }
		        //--Front
                if(node_c.y >= 1 && !maze.IsWallSouth(node_c.x, node_c.y) && !CheckNode({{node_c.x, node_c.y - 1}, 'S'}, found_y)){
                    pose_n = {{node_c.x, node_c.y - 1}, 'S'};
                    found_y.push_back(pose_n);
                    node_p.insert({pose_n, pose_c});
                }
                //--Left
                if(node_c.x <= 14 && !maze.IsWallEast(node_c.x, node_c.y) && !CheckNode({{node_c.x + 1, node_c.y}, 'E'}, found_y)){
                    pose_n = {{node_c.x + 1, node_c.y}, 'E'};
                    found_y.push_back(pose_n);
                    node_p.insert({pose_n, pose_c});
                }
            }
            //--pose of robot is East
            if (direction == 'E'){
                //--Back
                if(maze.IsWallEast(node_c.x, node_c.y) && maze.IsWallNorth(node_c.x, node_c.y) && maze.IsWallSouth(node_c.x, node_c.y)){
                    pose_n = {{node_c.x - 1, node_c.y}, 'W'};
                    found_y.push_back(pose_n);
                    node_p.insert({pose_n, pose_c});
                }
                //--Right
                if(node_c.y >= 1 && !maze.IsWallSouth(node_c.x, node_c.y) && !CheckNode({{node_c.x, node_c.y - 1}, 'S'}, found_y)){
                    pose_n = {{node_c.x, node_c.y - 1}, 'S'};
                    found_y.push_back(pose_n);
                    node_p.insert({pose_n, pose_c});
                }
		//--Front
                if(node_c.x <= 14 && !maze.IsWallEast(node_c.x, node_c.y) && !CheckNode({{node_c.x + 1, node_c.y}, 'E'}, found_y)){
                    pose_n = {{node_c.x + 1, node_c.y}, 'E'};
                    found_y.push_back(pose_n);
                    node_p.insert({pose_n, pose_c});
                }
                //--Left
                if(node_c.y <= 14 && !maze.IsWallNorth(node_c.x, node_c.y) && !CheckNode({{node_c.x, node_c.y + 1}, 'N'}, found_y)){
                    pose_n = {{node_c.x, node_c.y + 1}, 'N'};
                    found_y.push_back(pose_n);
                    node_p.insert({pose_n, pose_c});
                }
            }
            //--pose of robot is North
            if (direction == 'N'){
                
                //--Back
                if(maze.IsWallWest(node_c.x, node_c.y) && maze.IsWallNorth(node_c.x, node_c.y) && maze.IsWallEast(node_c.x, node_c.y)){
                    pose_n = {{node_c.x, node_c.y - 1}, 'S'};
                    found_y.push_back(pose_n);
                    node_p.insert({pose_n, pose_c});
                }
                
                //--Right
                if(node_c.x <= 14 && !maze.IsWallEast(node_c.x, node_c.y) && !CheckNode({{node_c.x + 1, node_c.y}, 'E'}, found_y)){
                    pose_n = {{node_c.x + 1, node_c.y}, 'E'};
                    found_y.push_back(pose_n);
                    node_p.insert({pose_n, pose_c});
                }
		//--Front
                if(node_c.y <= 14 && !maze.IsWallNorth(node_c.x, node_c.y) && !CheckNode({{node_c.x, node_c.y + 1}, 'N'}, found_y)){
                    pose_n = {{node_c.x, node_c.y + 1}, 'N'};
                    found_y.push_back(pose_n);
                    node_p.insert({pose_n, pose_c});
                }
		//--Left
                if(node_c.x >= 1 && !maze.IsWallWest(node_c.x, node_c.y) && !CheckNode({{node_c.x - 1, node_c.y}, 'W'}, found_y)){
                    pose_n = {{node_c.x - 1, node_c.y}, 'W'};
                    found_y.push_back(pose_n);
                    node_p.insert({pose_n, pose_c});
                }
            }
            //--pose of robot is West
            if (direction == 'W'){
                //--Back
                if(maze.IsWallWest(node_c.x, node_c.y) && maze.IsWallNorth(node_c.x, node_c.y) && maze.IsWallSouth(node_c.x, node_c.y)){
                    pose_n = {{node_c.x + 1, node_c.y}, 'E'};
                    found_y.push_back(pose_n);
                    node_p.insert({pose_n, pose_c});
                }
                
                //--Right
                if(node_c.y <= 14 && !maze.IsWallNorth(node_c.x, node_c.y) && !CheckNode({{node_c.x, node_c.y + 1}, 'N'},found_y)){
                    pose_n = {{node_c.x, node_c.y + 1}, 'N'};
                    found_y.push_back(pose_n);
                    node_p.insert({pose_n, pose_c});
                }
		//--Front
                if(node_c.x >= 1 && !maze.IsWallWest(node_c.x, node_c.y) && !CheckNode({{node_c.x - 1, node_c.y}, 'W'}, found_y)){
                    pose_n = {{node_c.x - 1, node_c.y}, 'W'};
                    found_y.push_back(pose_n);
                    node_p.insert({pose_n, pose_c});
                }
		//--Left
                if(node_c.y >= 1 && !maze.IsWallSouth(node_c.x, node_c.y) && !CheckNode({{node_c.x, node_c.y - 1}, 'S'}, found_y)){
                    pose_n = {{node_c.x, node_c.y - 1}, 'S'};
                    found_y.push_back(pose_n);
                    node_p.insert({pose_n, pose_c});
                }
            }
        }

        if (found_y.size() != 0){   // if there is more to explore
            found_d.push_back(pose_c);
            pose_c = found_y[0];
            node_c = {pose_c.first.first, pose_c.first.second};
            direction = pose_c.second;
            found_y.erase(found_y.begin());
        }
    }
    //--Backtacking
    route.push_back(pose_c);
    while (route.back() != found_d.front()){
        route.push_back(node_p.at(route.back()));
        if (robot->get_x() == 0 && robot->get_y() == 0){
            fp::API::setColor(route.back().first.first, route.back().first.second, 'B');
        }
        else{  
        fp::API::setColor(route.back().first.first, route.back().first.second, 'B');
        }
    }
    std::reverse(route.begin(), route.end());
    
    //--Move robot
    coord cur_cord;
    char dir;
    for (unsigned int i = 1; i < route.size(); i++){
        cur_cord = {robot->get_x(), robot->get_y()};
        dir = robot->GetDirection();
        std::cerr << "Moving to (" << route[i].first.first << ", " << route[i].first.second << ")" << std::endl; 
        //--Robot at north direction
        if (dir == 'N' && route[i].second == 'N' && !maze.IsWallNorth(cur_cord.x, cur_cord.y)){
            robot->MoveForward();
        }
        else if (dir == 'N' && route[i].second == 'W' && !maze.IsWallWest(cur_cord.x, cur_cord.y)){
            robot->TurnLeft(cur_cord.x, cur_cord.y);
            robot->MoveForward();
        }
        else if (dir == 'N' && route[i].second == 'E' && !maze.IsWallEast(cur_cord.x, cur_cord.y)){
            robot->TurnRight(cur_cord.x, cur_cord.y);
            robot->MoveForward();
        }
        else if (dir == 'N' && route[i].second == 'S'){
            robot->TurnLeft(cur_cord.x, cur_cord.y);
            robot->TurnLeft(cur_cord.x, cur_cord.y);
            robot->MoveForward();
        }//--Robot at south direction
        else if (dir == 'S' && route[i].second == 'S' && !maze.IsWallSouth(cur_cord.x, cur_cord.y)){
            robot->MoveForward();
        }
        else if (dir == 'S' && route[i].second == 'E' && !maze.IsWallEast(cur_cord.x, cur_cord.y)){
            robot->TurnLeft(cur_cord.x, cur_cord.y);
            robot->MoveForward();
        }
        else if (dir == 'S' && route[i].second == 'W' && !maze.IsWallWest(cur_cord.x, cur_cord.y)){
            robot->TurnRight(cur_cord.x, cur_cord.y);
            robot->MoveForward();
        }
        else if (dir == 'S' && route[i].second == 'N'){
            robot->TurnLeft(cur_cord.x, cur_cord.y);
            robot->TurnLeft(cur_cord.x, cur_cord.y);
            robot->MoveForward();
        }//--Robot at west direction
        else if (dir == 'W' && route[i].second == 'W' && !maze.IsWallWest(cur_cord.x, cur_cord.y)){
            robot->MoveForward();
        }
        else if (dir == 'W' && route[i].second == 'S' && !maze.IsWallSouth(cur_cord.x, cur_cord.y)){
            robot->TurnLeft(cur_cord.x, cur_cord.y);
            robot->MoveForward();
        }
        else if (dir == 'W' && route[i].second == 'N' && !maze.IsWallNorth(cur_cord.x, cur_cord.y)){
            robot->TurnRight(cur_cord.x, cur_cord.y);
            robot->MoveForward();
        }
        else if (dir == 'W' && route[i].second == 'E'){
            robot->TurnLeft(cur_cord.x, cur_cord.y);
            robot->TurnLeft(cur_cord.x, cur_cord.y);
            robot->MoveForward();
        }//--Robot at east direction
        else if (dir == 'E' && route[i].second == 'E' && !maze.IsWallEast(cur_cord.x, cur_cord.y)){
            robot->MoveForward();
        }
        else if (dir == 'E' && route[i].second == 'N' && !maze.IsWallNorth(cur_cord.x, cur_cord.y)){
            robot->TurnLeft(cur_cord.x, cur_cord.y);
            robot->MoveForward();
        }
        else if (dir == 'E' && route[i].second == 'S' && !maze.IsWallSouth(cur_cord.x, cur_cord.y)){
            robot->TurnRight(cur_cord.x, cur_cord.y);
            robot->MoveForward();
        }
        else if (dir == 'E' && route[i].second == 'W'){
            robot->TurnLeft(cur_cord.x, cur_cord.y);
            robot->TurnLeft(cur_cord.x, cur_cord.y);
            robot->MoveForward();
        }
        
        if (cur_cord.x == robot->get_x() && cur_cord.y == robot->get_y()){
            found_d.clear();
            found_y.clear();
            route.clear();
            node_p.clear();
            fp::API::clearAllColor();
	    fp::API::setColor(0,0,'Y');
	    fp::API::setColor(7,7,'Y');
	    fp::API::setColor(7,8,'Y');
	    fp::API::setColor(8,7,'Y');
	    fp::API::setColor(8,8,'Y');
            return false;
        }
        else{
            maze.CoordMaze(robot->get_x(), robot->get_y(), robot->GetDirection());
	    fp::API::clearColor(cur_cord.x, cur_cord.y);
	    fp::API::clearColor(robot->get_x(), robot->get_y());
        }
    }
    //--Once goal is reached, highlight the goal blocks in green
    fp::API::setColor(7,7,'G');
    fp::API::setColor(7,8,'G');
    fp::API::setColor(8,7,'G');
    fp::API::setColor(8,8,'G');
    std::cerr << "Goal Found!" << std::endl;
    return true;
}

bool fp::Algorithm::CheckGoal(int x, int y){
    if(x == 7 && y == 7) return true;
    if(x == 7 && y == 8) return true;
    if(x == 8 && y == 7) return true;
    if(x == 8 && y == 8) return true;
    std::cout<<"Path Not Found"<<std::endl; //--Print "Path Not Found" if goal is unreachable
    return false;
}


