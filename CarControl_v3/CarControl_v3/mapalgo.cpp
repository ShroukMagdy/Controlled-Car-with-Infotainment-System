#include "mainwindow.h"
void
MainWindow::PathPlan (int current_x, int current_y, int dest_x, int dest_y)
{
    //know the current road
    int road_counter;
    int current_road=0;
    int currentloc_isintersection = 0;
    int intersection_counter;
    int moving_flag=0;
    int in_destroad = 0;

    AvailableDirections Current_AvailableDirections = {0,0,0,0};
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
            /******************road1_horizental/road2_vertical***********************************/

            if (MapRoads
                    [MapIntersections[intersection_counter].
                    road1_index].orientation == ORIENTATION_HORIZENTAL)
            {
                /**********road1**************/
                if (current_x ==
                        MapRoads[MapIntersections
                        [intersection_counter].road1_index].x_start)
                {
                    Current_AvailableDirections.Forward_Horizental = 1;
                }

                else if (current_x ==
                         MapRoads[MapIntersections
                         [intersection_counter].road1_index].x_end)
                {
                    Current_AvailableDirections.Reverse_Horizental = 1;

                }
                else
                {
                    Current_AvailableDirections.Forward_Horizental = 1;
                    Current_AvailableDirections.Reverse_Horizental = 1;
                }
                /**********road2**************/


                if (current_y ==
                        MapRoads[MapIntersections
                        [intersection_counter].road2_index].y_start)
                {
                    Current_AvailableDirections.Forward_Vertical = 1;
                }

                else if (current_y ==
                         MapRoads[MapIntersections
                         [intersection_counter].road2_index].y_end)
                {
                    Current_AvailableDirections.Reverse_Vertical = 1;

                }
                else
                {
                    Current_AvailableDirections.Forward_Vertical = 1;
                    Current_AvailableDirections.Reverse_Vertical = 1;
                }

            }
            /*******************check orientation of each road*******************************/
            /******************road1_vertical/road2_horizental***********************************/

            else
                if (MapRoads
                        [MapIntersections[intersection_counter].
                        road1_index].orientation == ORIENTATION_VERTICAL)
                {
                    /**********road1**************/
                    if (current_y ==
                            MapRoads[MapIntersections
                            [intersection_counter].road1_index].y_start)
                    {
                        Current_AvailableDirections.Forward_Vertical = 1;
                    }

                    else if (current_y ==
                             MapRoads[MapIntersections
                             [intersection_counter].road1_index].y_end)
                    {
                        Current_AvailableDirections.Reverse_Vertical = 1;

                    }
                    else
                    {
                        Current_AvailableDirections.Forward_Vertical = 1;
                        Current_AvailableDirections.Reverse_Vertical = 1;
                    }
                    /**********road2**************/

                    if (current_x ==
                            MapRoads[MapIntersections
                            [intersection_counter].road2_index].x_start)
                    {
                        Current_AvailableDirections.Forward_Horizental = 1;
                    }

                    else if (current_x ==
                             MapRoads[MapIntersections
                             [intersection_counter].road2_index].x_end)
                    {
                        Current_AvailableDirections.Reverse_Horizental = 1;

                    }
                    else
                    {
                        Current_AvailableDirections.Forward_Horizental = 1;
                        Current_AvailableDirections.Reverse_Horizental = 1;
                    }
                }			//check orientation of each road

            /***********************************************************************************************************/
            if (((current_x < dest_x)
                 && (Current_AvailableDirections.Forward_Horizental == 1))
                    || ((current_x > dest_x)
                        && (Current_AvailableDirections.Reverse_Horizental == 1)))
            {
                /********************choose the road*************/
                current_road =
                        MapRoads[MapIntersections[intersection_counter].
                        road1_index].orientation ==
                        ORIENTATION_HORIZENTAL ?
                            MapIntersections[intersection_counter].road1_index :
                            MapIntersections[intersection_counter].road2_index;

            }
            else
            {
                current_road =
                        MapRoads[MapIntersections[intersection_counter].
                        road1_index].orientation ==
                        ORIENTATION_VERTICAL ?
                            MapIntersections[intersection_counter].road1_index :
                            MapIntersections[intersection_counter].road2_index;

            }

            /**********************************************************/
            break;

        }			//check if intersection found
    }				//for loop intersections

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
    }				//if not intersection
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
            if (MapRoads[current_road].orientation == ORIENTATION_HORIZENTAL)
            {
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
            }
            else if (MapRoads[current_road].orientation == ORIENTATION_VERTICAL)
            {
                if (current_y < dest_y)
                {
                    moving_flag = MOVING_FORWARD;
                    printf ("\nvertical,forward");
                    current_y += 1;
                    printf ("\nnew point, x=%d,y=%d", current_x, current_y);
                }
                else
                {
                    moving_flag = MOVING_REVERSE;
                    printf ("\nvertical,reverse");
                    current_y -= 1;
                    printf ("\nnew point, x=%d,y=%d", current_x, current_y);
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
                            MapIntersections[intersection_counter].y_intersection))
                {
                    /***********raise flag for intersection*************/
                    // currentloc_isintersection = 1;
                    printf ("\ncurrent between road %d and road %d",
                            MapIntersections
                            [intersection_counter].road1_index,
                            MapIntersections[intersection_counter].road2_index);
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

    }				//while
}
