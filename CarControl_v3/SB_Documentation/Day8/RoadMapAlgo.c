/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>

#define ROADS_NO                    3
#define INTERSECTIONS_NO            2

#define ORIENTATION_VERTICAL        0
#define ORIENTATION_HORIZENTAL      1

#define MOVING_FORWARD              0
#define MOVING_REVERSE              1

#define INTERSECTION_ROADS_NO       2

typedef struct
{
  int x_start;
  int y_start;
  int x_end;
  int y_end;
  int orientation;
} Road;

typedef struct
{
  int x_intersection;
  int y_intersection;
  int road1_index;
  int road2_index;
} Intersection;

typedef struct
{
  int Forward_Horizental;
  int Reverse_Horizental;
  int Forward_Vertical;
  int Reverse_Vertical;
} AvailableDirections;

Road MapRoads[] = {
  [0] = {.x_start = 0,.y_start = 0,.x_end = 0,.y_end = 5,.orientation =
	 ORIENTATION_VERTICAL},
  [1] = {.x_start = 0,.y_start = 5,.x_end = 10,.y_end = 5,.orientation =
	 ORIENTATION_HORIZENTAL},
  [2] = {.x_start = 10,.y_start = 5,.x_end = 10,.y_end = 10,.orientation =
	 ORIENTATION_VERTICAL},
};

Intersection MapIntersections[] = {
  [0] = {.x_intersection = 0,.y_intersection = 5,
	 .road1_index = 0,.road2_index = 1},
  [1] = {.x_intersection = 10,.y_intersection = 5,
	 .road1_index = 1,.road2_index = 2}
};


void PathPlan (int current_x, int current_y, int dest_x, int dest_y);

int
main ()
{
  PathPlan (10, 7, 0, 0);

  return 0;
}

void
PathPlan (int current_x, int current_y, int dest_x, int dest_y)
{
//know the current road
  int road_counter;
  int current_road;
  int currentloc_isintersection = 0;
  int intersection_counter;
  int moving_flag;
  int in_destroad = 0;
  int road_intersection_counter=0;

  AvailableDirections Current_AvailableDirections = { 0];
    for (intersection_counter = 0; intersection_counter < INTERSECTIONS_NO;
	 intersection_counter++)
      {
	if ((current_x ==
	     MapIntersections[intersection_counter].x_intersection)
	    && (current_y ==
		MapIntersections[intersection_counter].y_intersection))
	  {
				     /*********************raise flag for intersection*********************/
	    currentloc_isintersection = 1;
	    printf ("current between road %d and road %d",
		    MapIntersections[intersection_counter].road1_index,
		    MapIntersections[intersection_counter].road2_index);

		  /******************************choose road***********************/
		  
		  /************check available movements***********************/
		/**************************zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz*************/
		  if( MapRoads[MapIntersections[intersection_counter].road1_index].orientation==ORIENTATION_HORIZENTAL){
		       if ((current_x == MapRoads[MapIntersections[intersection_counter].road1_index].x_start){
		           Current_AvailableDirections.Forward_Horizental=1;
		       }
	
		else if(current_x == MapRoads[MapIntersections[intersection_counter].road1_index].x_end) )
	      {
	          Current_AvailableDirections.Reverse_Horizental=1;
	          
	      }
	      else{
	          Current_AvailableDirections.Forward_Horizental=1;
	          Current_AvailableDirections.Reverse_Horizental=1;
	      }
	      
		  }//check orientation of each road
		  /***********************************************************************************************************/
	    if (current_x < dest_x)
	      {
		moving_flag = MOVING_FORWARD;
		printf ("\nhorizental,forward");
		current_x += 1;
		printf ("\nnew point, x=%d,y=%d", current_x, current_y);
	      }
	    else
	      {
		moving_flag = MOVING_REVERSE;
		printf ("\nhorizental,reverse");
		current_x -= 1;
		printf ("\nnew point, x=%d,y=%d", current_x, current_y);
	      }



		  /**********************************************************/
	    break;
	  }
      }
    if (currentloc_isintersection == 0)
      {
	for (road_counter = 0; road_counter < ROADS_NO; road_counter++)
	  {
	    if ((current_x >= MapRoads[road_counter].x_start) &&
		(current_y >= MapRoads[road_counter].y_start) &&
		(current_x <= MapRoads[road_counter].x_end) &&
		(current_y <= MapRoads[road_counter].y_end))
	      {
		current_road = road_counter;
		printf ("current road is %d", road_counter);
		break;
	      }
	  }
//loop till reaching the destination
	while ((current_x != dest_x) || (current_y != dest_y))
	  {
    /**************************************check if destination in current road****************************************/
	    if ((dest_x >= MapRoads[current_road].x_start) &&
		(dest_y >= MapRoads[current_road].y_start) &&
		(dest_x <= MapRoads[current_road].x_end) &&
		(dest_y <= MapRoads[current_road].y_end))
	      {
		in_destroad = 1;
		current_x = dest_x;
		current_y = dest_y;
		printf ("\nnew point, x=%d,y=%d", current_x, current_y);
	      }
	    /****************************************************Moving************************************************************/

	    if (in_destroad == 0)
	      {
		/*************************************decide moving foraward or reverse*******************************************/
		if (MapRoads[current_road].orientation ==
		    ORIENTATION_HORIZENTAL)
		  {
		    if (current_x < dest_x)
		      {
			moving_flag = MOVING_FORWARD;
			printf ("\nhorizental,forward");
			current_x += 1;
			printf ("\nnew point, x=%d,y=%d", current_x,
				current_y);
		      }
		    else
		      {
			moving_flag = MOVING_REVERSE;
			printf ("\nhorizental,reverse");
			current_x -= 1;
			printf ("\nnew point, x=%d,y=%d", current_x,
				current_y);
		      }
		  }
		else if (MapRoads[current_road].orientation ==
			 ORIENTATION_VERTICAL)
		  {
		    if (current_y < dest_y)
		      {
			moving_flag = MOVING_FORWARD;
			printf ("\nvertical,forward");
			current_y += 1;
			printf ("\nnew point, x=%d,y=%d", current_x,
				current_y);
		      }
		    else
		      {
			moving_flag = MOVING_REVERSE;
			printf ("\nvertical,reverse");
			current_y -= 1;
			printf ("\nnew point, x=%d,y=%d", current_x,
				current_y);
		      }
		  }
		/*****************************************check to change road**********************************************/
		for (intersection_counter = 0;
		     intersection_counter < INTERSECTIONS_NO;
		     intersection_counter++)
		  {
		    if ((current_x ==
			 MapIntersections
			 [intersection_counter].x_intersection)
			&& (current_y ==
			    MapIntersections
			    [intersection_counter].y_intersection))
		      {
						     /***********raise flag for intersection*************/
			// currentloc_isintersection = 1;
			printf ("\ncurrent between road %d and road %d",
				MapIntersections
				[intersection_counter].road1_index,
				MapIntersections
				[intersection_counter].road2_index);

			      /********************switch to the other road*************/
			current_road =
			  MapIntersections[intersection_counter].road1_index
			  ==
			  current_road ?
			  MapIntersections[intersection_counter].road2_index :
			  MapIntersections[intersection_counter].road1_index;

			printf ("\ncurrent road=%d", current_road);

			break;
		      }
		  }


	      }			//if not in dest road
/**********************************************************************************************************************/

	  }			//while 
	//if not intersection
      }


  }

