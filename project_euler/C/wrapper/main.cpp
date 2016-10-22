/* 1.0.0 */
/*****************************************************************************************************************************************************************\
* Module Name       : Main File
* Description       : Execute specified project
* Original Author   : Jake Nabozny
* Date Created      : 10/16/2012
\*****************************************************************************************************************************************************************/

#include "cmn_hdr.h"
#include "proj_def.h"


int main(void)
{
    void (* const * fp2_vd_hook)(void);

    fp2_vd_hook = &fp_vd_EULER_PROJ_TASK[__ACT_PROJ__];
    if((*fp2_vd_hook) != (void *)NULL)
    {
        (*fp2_vd_hook)();
    }
    else
    {
        cout << "NULL pointer encountered...\n\n";
    }

    system("pause");
    return(1);
}
