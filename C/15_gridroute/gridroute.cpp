/* 1.0.0 */
/*****************************************************************************************************************************************************************\
* Module Name       : GridRoute
* Description       : Euler Project 15 Source Code
* Original Author   : Jake Nabozny
* Date Created      : 10/25/2012
\*****************************************************************************************************************************************************************/


/*******************************************************************************\
* Include Files
\*******************************************************************************/
#include "gridroute_private.h"


/*******************************************************************************\
* Macro Definitions
\*******************************************************************************/
#define GRIDROUTE_ROWS      (20)
#define GRIDROUTE_COLS      (20)
// Answer: 137,846,528,820


/*******************************************************************************\
* Static Variables
\*******************************************************************************/
static U8 u8_s_grid[GRIDROUTE_COLS+1][GRIDROUTE_ROWS+1];


/*******************************************************************************\
* Static Functions
\*******************************************************************************/
static U8 u8_s_GridRoute_GetNumRoutes(void);


/*******************************************************************************\
* Function Definitions
\*******************************************************************************/


/*****************************************************************************************************************************************************************\
* Function name     : vd_g_GridRoute_Main
* Called by         : main
* Argument(s)       : void
* Return            : void
* Description       : Entry Point for Euler Project 15 GridRoute
\*****************************************************************************************************************************************************************/
void vd_g_GridRoute_Main(void)
{
    U8 u8_t_ans;

    cout << "How many routes from top-left to bottom-right of a " << GRIDROUTE_COLS << "x" << GRIDROUTE_ROWS << " grid?\n\n";

    u8_t_ans = u8_s_GridRoute_GetNumRoutes();

    cout << "Answer:\t" << u8_t_ans << "\n\n";
}


/*****************************************************************************************************************************************************************\
* Function name     : u8_s_GridRoute_GetNumRoutes
* Called by         : vd_g_GridRoute_Main
* Argument(s)       : void
* Return            : U8
* Description       : GetNumRoutes
\*****************************************************************************************************************************************************************/
static U8 u8_s_GridRoute_GetNumRoutes(void)
{
    U8 u8_t_routes;
    U4 u4_t_row;
    U4 u4_t_col;

    u8_t_routes = (U8)0;

    /* Initialize Origin */
    u8_s_grid[0][0] = (U8)0;

    /* Initialize top row */
    for(u4_t_col = (U4)1; u4_t_col <= (U4)GRIDROUTE_COLS; u4_t_col++)
    {
        u8_s_grid[u4_t_col][0] = (U8)1;
    }

    /* Initialize left column */
    for(u4_t_row = (U4)1; u4_t_row <= (U4)GRIDROUTE_ROWS; u4_t_row++)
    {
        u8_s_grid[0][u4_t_row] = (U8)1;
    }
    
    /* Set all other cell locations */
    for(u4_t_row = (U4)1; u4_t_row <= (U4)GRIDROUTE_ROWS; u4_t_row++)
    {
        for(u4_t_col = (U4)1; u4_t_col <= (U4)GRIDROUTE_COLS; u4_t_col++)
        {
            u8_s_grid[u4_t_col][u4_t_row] = u8_s_grid[u4_t_col-1][u4_t_row] + u8_s_grid[u4_t_col][u4_t_row-1];
        }
    }

    u8_t_routes = u8_s_grid[GRIDROUTE_COLS][GRIDROUTE_ROWS];

    return(u8_t_routes);
}
