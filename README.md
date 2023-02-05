# 42-CPP02    [![Project Status: WIP – Initial development is in progress, but there has not yet been a stable, usable release suitable for the public.](https://www.repostatus.org/badges/latest/wip.svg)](https://www.repostatus.org/#wip) <img src="https://badgen.net/badge/Platform/macOS/grey?icon=default" /> <img align=right src="https://badgen.net/badge/Grade/100/green?icon=default" />

This proyect implement usefull fixed class for a computer graphics and use it in bsp (Binary space partitioning) function.

Fixed Class:
  - Overflow protected;
  - Flag error is implemented. check and clean flag with good() and clean() functions.
  - Flag error is hereditary in all aritmetic/comparison operations.
  - Static member functions min() and max() return min_fixed and max_fixed possible value.
  - +inf/NaN/-inf is seted to max_fixed/0/min_fixed respectively. When occurs flag error is seted.

Point Class
  -  The good() function check if de Fixed instances inside class are flag error.

Vector Class
  - This class is an alias of Point class
  - Vector class implements usefull functions to deal vector ops. none is normalized!!
  
Segment Class
  - Constructed with 3 Points instances: first two define the direction of the segment,
    and the third is used to define the normal of segment looking to that point.
  - the isLookingPoint return Fixed intance value where => value > 0 segment looking to point, value < 0 segment not looking to point
    and value == 0 the point is on the edge of segment.

BspNode Class
  - This is a recursive class to make a wonderfull basic bspTree from one array of convex segments pased by parameter. 


  
   
