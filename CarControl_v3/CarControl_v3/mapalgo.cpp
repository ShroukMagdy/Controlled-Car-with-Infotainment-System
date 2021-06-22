#include "mainwindow.h"
#include "math.h"
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
    int distance=0;

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
            qDebug()<<"current between road"<<
                      MapIntersections[intersection_counter].road1_index<<" and road"<<
                      MapIntersections[intersection_counter].road2_index;

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
                qDebug()<<"current road is "<< road_counter;
                break;
            }
        }
    }				//if not intersection
    //loop till reaching the destination
    while ((current_x != dest_x) || (current_y != dest_y))
    {

        /**************************************check if destination in current road****************************************/
        /*
        if ((dest_x >= MapRoads[current_road].x_start) &&
                (dest_y >= MapRoads[current_road].y_start) &&
                (dest_x <= MapRoads[current_road].x_end) &&
                (dest_y <= MapRoads[current_road].y_end))
        {
            in_destroad = 1;
            //calculate distance
            distance=sqrt(pow((dest_x-current_x),2)+pow((dest_y-current_y),2));
            qDebug()<<"distance="<<distance;

            //real moving
            Move_Forward();
            delay(1000*distance*CARSPEED);

            //update of current position
            current_x = dest_x;
            current_y = dest_y;

            qDebug()<<"new point, x="<< current_x<<"y="<< current_y;
        }
        */
        /****************************************************Moving************************************************************/

        if (in_destroad == 0)
        {
            /*************************************decide moving foraward or reverse*******************************************/
            if (MapRoads[current_road].orientation == ORIENTATION_HORIZENTAL)
            {
                if (current_x < dest_x)
                {
                    qDebug()<<"horizental,forward";
                    current_x += 1;
                    qDebug()<<"new point, x="<< current_x<<"y="<< current_y;
                    if(currentloc_isintersection==1){
                        if(moving_flag==MOVING_FORWARD){
                            Move_Right();
                        }
                        else{
                            Move_Left();
                        }
                        delay(1000);
                        StopFront();
                        currentloc_isintersection=0;
                    }
                    moving_flag = MOVING_FORWARD;
                }
                else
                {
                    qDebug()<< "horizental,reverse";
                    current_x -= 1;
                    qDebug()<< "new point, x="<< current_x<<"y="<<current_y;
                    if(currentloc_isintersection==1){
                        if(moving_flag==MOVING_FORWARD){
                            Move_Left();
                        }
                        else{
                            Move_Right();
                        }
                        delay(1000);
                        StopFront();
                        currentloc_isintersection=0;
                    }
                    moving_flag = MOVING_REVERSE;

                }
            }
            else if (MapRoads[current_road].orientation == ORIENTATION_VERTICAL)
            {
                if (current_y < dest_y)
                {
                    qDebug()<< "vertical,forward";
                    current_y += 1;
                    qDebug()<< "new point, x="<< current_x<<"y="<<current_y;
                    if(currentloc_isintersection==1){
                        if(moving_flag==MOVING_FORWARD){
                            Move_Left();
                        }
                        else{
                            Move_Right();
                        }
                        delay(1000);
                        StopFront();
                        currentloc_isintersection=0;
                    }
                    moving_flag = MOVING_FORWARD;
                }
                else
                {
                    qDebug()<< "vertical,reverse";
                    current_y -= 1;
                    qDebug()<< "new point, x="<< current_x<<"y="<<current_y;
                    if(currentloc_isintersection==1){
                        if(moving_flag==MOVING_FORWARD){
                            Move_Right();
                        }
                        else{
                            Move_Left();
                        }
                        delay(1000);
                        StopFront();
                        currentloc_isintersection=0;
                    }
                    moving_flag = MOVING_REVERSE;
                }
            }
            //real moving
            Move_Forward();
            delay(1000*1*CARSPEED);

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
                    currentloc_isintersection = 1;
                    qDebug()<<"current between road"<<
                              MapIntersections
                              [intersection_counter].road1_index<<"and road"<<
                              MapIntersections[intersection_counter].road2_index;
                    /********************switch to the other road*************/
                    current_road =
                            MapIntersections[intersection_counter].road1_index
                            ==
                            current_road ?
                                MapIntersections[intersection_counter].road2_index :
                                MapIntersections[intersection_counter].road1_index;
                    qDebug()<<"current road="<< current_road;
                    break;
                }
            }


        }			//if not in dest road
        /**********************************************************************************************************************/

    }				//while
    StopFront();
    StopRear();
}
