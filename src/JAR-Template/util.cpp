#include "vex.h"
#include <cmath>
#include <vector>

// There is probably a more efficient way to reduce angles than the ones specified below,
// but these work without question, and you really only have to reduce them once or twice at 
// a max.

float reduce_0_to_360(float angle) {
  while(!(angle >= 0 && angle < 360)) {
    if( angle < 0 ) { angle += 360; }
    if(angle >= 360) { angle -= 360; }
  }
  return(angle);
}

float reduce_negative_180_to_180(float angle) {
  while(!(angle >= -180 && angle < 180)) {
    if( angle < -180 ) { angle += 360; }
    if(angle >= 180) { angle -= 360; }
  }
  return(angle);
}

float reduce_negative_90_to_90(float angle) {
  while(!(angle >= -90 && angle < 90)) {
    if( angle < -90 ) { angle += 180; }
    if(angle >= 90) { angle -= 180; }
  }
  return(angle);
}

float to_rad(float angle_deg){
  return(angle_deg/(180.0/M_PI));
}

float to_deg(float angle_rad){
  return(angle_rad*(180.0/M_PI));
}

float clamp(float input, float min, float max){
  if( input > max ){ return(max); }
  if(input < min){ return(min); }
  return(input);
}

bool is_reversed(double input){
  if(input<0) return(true);
  return(false);
}

float to_volt(float percent){
  return(percent*12.0/100.0);
}

int to_port(int port){
  if(port>8){
    return(0);
  }
  return(port-1);
} // To_port just keeps a number over 7 from being passed as a threewire port.

float deadband(float input, float width){
  if (fabs(input)<width){
    return(0);
  }
  return(input);
}

float dist(Point p1, Point p2) {
  return std::hypot(p2.x - p1.x, p2.y - p1.y);
}

std::vector<Point> line_circle_intersections(Point center, float radius, Point p1, Point p2) {
  std::vector<Point> intersections = {};

	// Subtract the circle's center to offset the system to origin.
	Point offset_1 = Point {p1.x - center.x, p1.y - center.y};
	Point offset_2 = Point {p2.x - center.x, p2.y - center.y};

	double dx = offset_2.x - offset_1.x;
	double dy = offset_2.y - offset_1.y;
	double dr = dist(offset_1, offset_2);
	double D = (offset_1.x * offset_2.y) - (offset_1.y * offset_2.x); // Cross product of offset 1 and 2
	double discriminant = std::pow(radius, 2) * std::pow(dr, 2) - std::pow(D, 2);

	// If our discriminant is greater than or equal to 0, the line formed as a slope of
	// point_1 and point_2 intersects the circle at least once.
	if (discriminant >= 0) {
		// https://mathworld.wolfram.com/Circle-LineIntersection.html
		Point solution_1 = Point {
			(D * dy + sign(dy) * dx * std::sqrt(discriminant)) / std::pow(dr, 2) + center.x,
			(-D * dx + fabs(dy) * std::sqrt(discriminant)) / std::pow(dr, 2) + center.y
    };
		Point solution_2 = Point {
			(D * dy - sign(dy) * dx * std::sqrt(discriminant)) / std::pow(dr, 2) + center.x,
			(-D * dx - fabs(dy) * std::sqrt(discriminant)) / std::pow(dr, 2) + center.y
    };


		// Find the bounded intersections.
		// solution_1 and solution_2 are assumed to be true when the line formed as a slope between point_1 and point_2
		// extends infinitely, however we only want to consider intersections that are part of a line segment *between*
		// point_1 and point_2.

    // Find the minimum coordinates for each line (p1 and p2 being the start and end of the segment)
		double min_x = std::min(p1.x, p2.x);
		double max_x = std::max(p1.x, p2.x);
		double min_y = std::min(p1.y, p2.y);
		double max_y = std::max(p1.y, p2.y);

		// Solution 1 intersects the circle within the bounds of point_1 and point_2
		if ((solution_1.x >= min_x && solution_1.x <= max_x) && (solution_1.y >= min_y && solution_1.y <= max_y)) {
			intersections.push_back(solution_1);
		}

		// Solution 2 intersects the circle within the bounds of point_1 and point_2
		if ((solution_2.x >= min_x && solution_2.x <= max_x) && (solution_2.y >= min_y && solution_2.y <= max_y)) {
			intersections.push_back(solution_2);
		}
	}

	return intersections;
}