#ifdef __cplusplus
extern "C" {
#endif

#ifndef ALARM_H_
#define ALARM_H_

typedef struct alarmTaskData {
    char** hvilAlarmStatus;
    char** overcurrentStatus;
    char** hvOutOfRangeStatus;
    int* seconds;
} alarmData;

void alarmTask (void*);


#endif

#ifdef __cplusplus
}
#endif
