#pragma once

#include <iostream>



#include "offsets.h"

#define M_PI 3.14159265358979323846264338327950288

float getEntDist(Vec3* local, Vec3* target)
{
	std::cout << "\n\ncalled 3dVec\n\n";
	float xdiff{};
	float ydiff{};
	float zdiff{};

	(local->x > target->x) ? (xdiff = local->x - target->x) : (xdiff = target->x - local->x);
	(local->y > target->y) ? (ydiff = local->y - target->y) : (ydiff = target->y - local->y);
	(local->z > target->z) ? (zdiff = local->z - target->z) : (zdiff = target->z - local->z);

#if _DEBUG
	std::cout << "xdiff = " << xdiff << "\nydiff = " << ydiff << "\nzdiff = " << zdiff;
#endif
	float xsqr = std::pow(xdiff, 2);
	float ysqr = std::pow(ydiff, 2);
	float zsqr = std::pow(zdiff, 2);
#if _DEBUG
	std::cout << "\nxsqr = " << xsqr << "\nysqr = " << ysqr << "\nzsqr = " << zsqr;
#endif





	float finalVal = (xsqr + ysqr + zsqr);
#if _DEBUG
	std::cout << "\nMagnitude = " << sqrt(finalVal) << " or sqrt(" << finalVal << ")\n\n";
#endif
	return sqrt(finalVal);

}

template <typename T>
T RadToDegree(T Radians)
{
	
	T Degrees = Radians / (180 / M_PI);
	return Degrees;
}

Vec3 calcAngleB(Vec3* local, Vec3* target)
{

	
	
	Vec3 angle{};
	angle.x = RadToDegree(-atan2f(target->x - local->x, target->y - local->y) / (float)M_PI * 180 + 180);
	angle.y = RadToDegree(asinf((target->z - local->z) / (getEntDist(local, target)) * 180 / (float)M_PI));	//may have to dencrease value by 90, because AC may not use 0 -> 180, could use -90 -> 90
	angle.z = 0;
o

	/*
	
	other math method

	yaw = arctan(y/x)
	pitch arccos(z/hyp) hyp being mag 
	x,y,z all delta's
	
	*/


	std::cout << "\n[DEBUG] - Anglex " << angle.x << " Angley - " << angle.y << "\n";

	return angle;
}


