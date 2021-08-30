#ifdef __cplusplus
extern "C" {
#endif

#ifndef ALARM_H_
#define ALARM_H_

#include <stdbool.h>

#define NA 0
#define ANA 1
#define AA 2

typedef struct alarmTaskData {
    bool* hvilAcknowledged;
    volatile int* hvilAlarmStatus;
    volatile bool* hvilAlarmChanged;
    bool* hvilStatus;
    bool* ocAcknowledged;
    int* overcurrentStatus;
    bool* overcurrentAlarmChanged;
    float* hvCurrent;
    bool* hvoorAcknowledged;
    int* hvoorStatus;
    bool* hvoorAlarmChanged;
    float* hvVoltage;
    volatile bool* ISRFlag;
} alarmData;

void alarmTask (void*);


#endif

#ifdef __cplusplus
}
#endif
