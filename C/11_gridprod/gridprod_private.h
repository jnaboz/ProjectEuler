/* 1.0.0 */
/*****************************************************************************************************************************************************************\
* Module Name       : Grid Product
* Description       : Euler Project 11
* Original Author   : Jake Nabozny
* Date Created      : 10/22/2012
\*****************************************************************************************************************************************************************/

#ifndef GRIDPROD_PRIVATE_H
#define GRIDPROD_PRIVATE_H


/*******************************************************************************\
* Include Files
\*******************************************************************************/
#include "cmn_hdr.h"
#include "gridprod_public.h"


/*******************************************************************************\
* Type Definitions
\*******************************************************************************/


/*******************************************************************************\
* Macro Definitions
\*******************************************************************************/
#define GRIDPROD_ROW_LENGTH     (20)
#define GRIDPROD_COL_LENGTH     (20)


/*******************************************************************************\
* Constant Data
\*******************************************************************************/
static const U1 u1_sp_GRID[GRIDPROD_ROW_LENGTH][GRIDPROD_COL_LENGTH] = 
{
    {   (U1)8,  (U1)2,  (U1)22, (U1)97, (U1)38, (U1)15, (U1)0,  (U1)40, (U1)0,  (U1)75, (U1)4,  (U1)5,  (U1)7,  (U1)78, (U1)52, (U1)12, (U1)50, (U1)77, (U1)91, (U1)8   },
    {   (U1)49, (U1)49, (U1)99, (U1)40, (U1)17, (U1)81, (U1)18, (U1)57, (U1)60, (U1)87, (U1)17, (U1)40, (U1)98, (U1)43, (U1)69, (U1)48, (U1)4,  (U1)56, (U1)62, (U1)0   },
    {   (U1)81, (U1)49, (U1)31, (U1)73, (U1)55, (U1)79, (U1)14, (U1)29, (U1)93, (U1)71, (U1)40, (U1)67, (U1)53, (U1)88, (U1)30, (U1)3,  (U1)49, (U1)13, (U1)36, (U1)65  },
    {   (U1)52, (U1)70, (U1)95, (U1)23, (U1)4,  (U1)60, (U1)11, (U1)42, (U1)69, (U1)24, (U1)68, (U1)56, (U1)1,  (U1)32, (U1)56, (U1)71, (U1)37, (U1)2,  (U1)36, (U1)91  },
    {   (U1)22, (U1)31, (U1)16, (U1)71, (U1)51, (U1)67, (U1)63, (U1)89, (U1)41, (U1)92, (U1)36, (U1)54, (U1)22, (U1)40, (U1)40, (U1)28, (U1)66, (U1)33, (U1)13, (U1)80  },
    {   (U1)24, (U1)47, (U1)32, (U1)60, (U1)99, (U1)3,  (U1)45, (U1)2,  (U1)44, (U1)75, (U1)33, (U1)53, (U1)78, (U1)36, (U1)84, (U1)20, (U1)35, (U1)17, (U1)12, (U1)50  },
    {   (U1)32, (U1)98, (U1)81, (U1)28, (U1)64, (U1)23, (U1)67, (U1)10, (U1)26, (U1)38, (U1)40, (U1)67, (U1)59, (U1)54, (U1)70, (U1)66, (U1)18, (U1)38, (U1)64, (U1)70  },
    {   (U1)67, (U1)26, (U1)20, (U1)68, (U1)2,  (U1)62, (U1)12, (U1)20, (U1)95, (U1)63, (U1)94, (U1)39, (U1)63, (U1)8,  (U1)40, (U1)91, (U1)66, (U1)49, (U1)94, (U1)21  },
    {   (U1)24, (U1)55, (U1)58, (U1)5,  (U1)66, (U1)73, (U1)99, (U1)26, (U1)97, (U1)17, (U1)78, (U1)78, (U1)96, (U1)83, (U1)14, (U1)88, (U1)34, (U1)89, (U1)63, (U1)72  },
    {   (U1)21, (U1)36, (U1)23, (U1)9,  (U1)75, (U1)0,  (U1)76, (U1)44, (U1)20, (U1)45, (U1)35, (U1)14, (U1)0,  (U1)61, (U1)33, (U1)97, (U1)34, (U1)31, (U1)33, (U1)95  },
    {   (U1)78, (U1)17, (U1)53, (U1)28, (U1)22, (U1)75, (U1)31, (U1)67, (U1)15, (U1)94, (U1)3,  (U1)80, (U1)4,  (U1)62, (U1)16, (U1)14, (U1)9,  (U1)53, (U1)56, (U1)92  },
    {   (U1)16, (U1)39, (U1)5,  (U1)42, (U1)96, (U1)35, (U1)31, (U1)47, (U1)55, (U1)58, (U1)88, (U1)24, (U1)0,  (U1)17, (U1)54, (U1)24, (U1)36, (U1)29, (U1)85, (U1)57  },
    {   (U1)86, (U1)56, (U1)0,  (U1)48, (U1)35, (U1)71, (U1)89, (U1)7,  (U1)5,  (U1)44, (U1)44, (U1)37, (U1)44, (U1)60, (U1)21, (U1)58, (U1)51, (U1)54, (U1)17, (U1)58  },
    {   (U1)19, (U1)80, (U1)81, (U1)68, (U1)5,  (U1)94, (U1)47, (U1)69, (U1)28, (U1)73, (U1)92, (U1)13, (U1)86, (U1)52, (U1)17, (U1)77, (U1)4,  (U1)89, (U1)55, (U1)40  },
    {   (U1)4,  (U1)52, (U1)8,  (U1)83, (U1)97, (U1)35, (U1)99, (U1)16, (U1)7,  (U1)97, (U1)57, (U1)32, (U1)16, (U1)26, (U1)26, (U1)79, (U1)33, (U1)27, (U1)98, (U1)66  },
    {   (U1)88, (U1)36, (U1)68, (U1)87, (U1)57, (U1)62, (U1)20, (U1)72, (U1)3,  (U1)46, (U1)33, (U1)67, (U1)46, (U1)55, (U1)12, (U1)32, (U1)63, (U1)93, (U1)53, (U1)69  },
    {   (U1)4,  (U1)42, (U1)16, (U1)73, (U1)38, (U1)25, (U1)39, (U1)11, (U1)24, (U1)94, (U1)72, (U1)18, (U1)8,  (U1)46, (U1)29, (U1)32, (U1)40, (U1)62, (U1)76, (U1)36  },
    {   (U1)20, (U1)69, (U1)36, (U1)41, (U1)72, (U1)30, (U1)23, (U1)88, (U1)34, (U1)62, (U1)99, (U1)69, (U1)82, (U1)67, (U1)59, (U1)85, (U1)74, (U1)4,  (U1)36, (U1)16  },
    {   (U1)20, (U1)73, (U1)35, (U1)29, (U1)78, (U1)31, (U1)90, (U1)1,  (U1)74, (U1)31, (U1)49, (U1)71, (U1)48, (U1)86, (U1)81, (U1)16, (U1)23, (U1)57, (U1)5,  (U1)54  },
    {   (U1)1,  (U1)70, (U1)54, (U1)71, (U1)83, (U1)51, (U1)54, (U1)69, (U1)16, (U1)92, (U1)33, (U1)48, (U1)61, (U1)43, (U1)52, (U1)1,  (U1)89, (U1)19, (U1)67, (U1)48  }
};


#endif // GRIDPROD_PRIVATE_H

