#include "SOC.h"

void socTask(void* sData) {
    /****************
    * Function name: socTask
    * Function inputs: void* pointer to the socData struct
    * Function outputs: none
    * Function description: Sets SOC state to 0
    * Author(s): Yasin Alissa, Khoa Tran
    *****************/
    socData* data = (socData*) sData;
    // The charge value is always 0
    *data->charge = 0;
}
