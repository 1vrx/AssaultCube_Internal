
#pragma once
#include "offsets.h"
#include "mem.h"

int GetDist(Vec3 local, Vec3 enemy)
{
	std::cout << "\n\nGetDist() called\n\n";
	float xdiff{};
	float ydiff{};
	float zdiff{};

	

	(local.x > enemy.x) ? (xdiff = local.x - enemy.x) : (xdiff = local.x - enemy.x);
	(local.y > enemy.y) ? (ydiff = local.y - enemy.y) : (ydiff = local.y - enemy.y);
	(local.z > enemy.z) ? (zdiff = local.z - enemy.z) : (zdiff = local.z - enemy.z);

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