#include "point.h"
vector<point> allPoints;
vector<point> boundary;
point maxDistance(point leftMost,point rightMost,vector<point> setOfPoints)
{
	point maxPoint,vec=rightMost-leftMost;
	double dist;
	if(setOfPoints.size()>0)
	{
		maxPoint = setOfPoints[0];
		dist=dis(vec,maxPoint-leftMost);
	}
	for (int i = 0; i < setOfPoints.size(); ++i)
	{
		if(dist<dis(vec,setOfPoints[i]-leftMost))
		{
			dist=dis(vec,setOfPoints[i]-leftMost);
			maxPoint=setOfPoints[i];
		}
		cout<<"Distance ="<<dis(vec,setOfPoints[i])<<" point x="<<setOfPoints[i].getx()<<" y="<<setOfPoints[i].gety()<<endl;
	}
	cout << "most distance "<<dist<<" x="<<maxPoint.getx()<<" y="<<maxPoint.gety()<<endl;
	return maxPoint;
}
vector<point> genSubset(point leftMost,point rightMost,vector<point> setOfPoints,int direction)
{
	vector<point> subset;
	point vec=rightMost-leftMost;
	for (int i = 0; i < setOfPoints.size(); ++i)
	{
		if(direction==UP && dis(vec,setOfPoints[i]-leftMost)>0)
		{
			subset.push_back(setOfPoints[i]);
		}
		else if(direction==DOWN && dis(vec,setOfPoints[i]-leftMost)<0)
		{
			subset.push_back(setOfPoints[i]);
		}
	}
	return subset;
}
void makeHull(point leftMost,point rightMost,vector<point> upperPoints)
{
	if(upperPoints.size()==0)
		return;
	else
	{
		point mostDistPoint=maxDistance(leftMost,rightMost,upperPoints);
		// cout<<"max point: x="<<mostDistPoint.getx()<<" y="<<mostDistPoint.gety()<<endl;
		boundary.push_back(mostDistPoint);
		makeHull(leftMost,mostDistPoint,genSubset(leftMost,mostDistPoint,upperPoints,UP));
		makeHull(mostDistPoint,rightMost,genSubset(mostDistPoint,rightMost,upperPoints,UP));
	}
}
int main(int argc, char const *argv[])
{
	point leftMost,rightMost;
	double minx,maxx;
	int numOfpoints;
	FILE *f= fopen("in.txt","r");
	fscanf(f,"%d",&numOfpoints);
	for (int i = 0; i < numOfpoints; ++i)
	{
		double x,y;
		fscanf(f,"%lf%lf",&x,&y);
		point p=point(x,y);
		if(i==0)
		{
			minx=x;
			maxx=x;
			leftMost=p;
			rightMost=p;
		}
		else
		{
			if(minx>x)
			{
				leftMost=p;
				minx=x;
			}
			if(maxx<x)
			{
				rightMost=p;
				maxx=x;
			}
		}
		allPoints.push_back(p);
	}
	cout<<"leftMost x="<<rightMost.getx()<<" y="<<rightMost.gety()<<endl;
	boundary.push_back(leftMost);
	

	// maxDistance(leftMost,rightMost,allPoints);
	makeHull(leftMost,rightMost,genSubset(leftMost,rightMost,allPoints,UP));
	boundary.push_back(rightMost);
	makeHull(rightMost,leftMost,genSubset(rightMost,leftMost,allPoints,UP));
	for (int i = 0; i < boundary.size(); ++i)
	{
		
		cout<<"x: "<<boundary[i].getx()<<" y: "<<boundary[i].gety()<<endl;
	}


	return 0;
}