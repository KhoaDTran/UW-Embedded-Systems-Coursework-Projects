#include "SOC.h"

void socTask(void* sData) {
    /****************
    * Function name: socTask
    * Function inputs: void* pointer to the socData struct
    * Function outputs: none
    * Function description: Updates all state of charge status once per second
    * Author(s): Yasin Alissa
    *****************/
    socData* data = (socData*) sData;
    // The charge values we cycle through
    float charges[3] = {0, 50, 100};
    // Update once per second
    *data->charge = charges[*data->seconds % 3];
}
