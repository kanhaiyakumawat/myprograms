#include <iostream>

using namespace std;

class Robot
{
public:
Robot(const M, const int N, const int curr_x, const int curr_y, const char curr_dir):x(curr_x),y(curr_y),dir(curr_dir)
{
}
void command(char cmd);
void print_current_direction()
{
cout<<"current direction is "<<dir<<endl;
}
void print_current_position()
{
cout<<"current position of robot is ("<<x<<", "<<y")"<<endl;
}
private:
void increment_x();
void incremnet_y();
void decrement_x();
void decrement_y();
void left();
void right();
void move();
char dir;
int x;
int y;
};

void Robot::command(char cmd)
{
if(cmd == 'L')
{
left();
}
else if(cmd == 'R')
{
right();
}
else if(cmd == 'M')
{
move();
}
else
{
cout<<"ERROR--INVALID COMMAND\n";
}
}

void Robot::left()
{
if(dir == 'E')
{
dir = 'N';
}
else if(dir == 'N')
{
dir = 'W';
}
else if(dir == 'W')
{
dir = 'S';
}
else if(dir == 'S')
{
dir = 'E';
}
}
void Robot::right()
{
if(dir == 'E')
{
dir = 'S';
}
else if(dir == 'N')
{
dir = 'E';
}
else if(dir == 'W')
{
dir = 'N';
}
else if(dir == 'S')
{
dir = 'W';
}
}

void Robot::move()
{
if(dir == 'E')
{
increment_x();
}
else if(dir == 'N')
{
increment_y();
}
else if(dir == 'W')
{
decrement_x();
}
else if(dir == 'S')
{
decrement_y();
}

void Robot::increment_x()
{
if((x + 1) < M)
{
x++;
}
}

void Robot::increment_y()
{
if((y + 1) < N)
{
y++;
}
}
void Robot::derement_x()
{
if((x - 1) >= 0)
{
x--;
}
}
void Robot::derement_y()
{
if((y - 1) >= 0)
{
y--;
}
}
