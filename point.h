#include<iostream>
#include<cstdio>
#include<cmath>
#include <cstdlib>
#include <vector>
#define UP 1
#define DOWN 0
using namespace std;
class point
{
	double x,y;

public:
	point(){}
	point(double x,double y)
	{
		this->x=x;
		this->y=y;
	}

	
	point operator-(point p)
	{
		double tempX,tempY;
		tempX=this->x-p.getx();
		tempY=this->y-p.gety();
		return point(tempX,tempY);

	}
	double getx(){ return this->x;}
	double gety(){ return this->y;}
	double val(){return sqrt((this->x)*(this->x)+(this->y)*(this->y));}
	
};


double cross(point v1,point v2)
{
	
	return v1.getx()*v2.gety()-v1.gety()*v2.getx();
}
double dis(point line,point p)
{
	return cross(line,p)/line.val();
}