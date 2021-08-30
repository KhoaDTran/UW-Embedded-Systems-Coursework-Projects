#include "Accelerometer.h"
#include <math.h>

int xOffset = 0;
int yOffset = 0;
int zOffset = 0;

float acceleration(const byte pin, int cmOffs) {
    /****************
    * Function name: accelerometerTask
    * Function inputs: void* pointer to the accelerometerData struct
    * Function outputs: none
    * Function description: Updates the accelerometer measurements
    * Author(s): Yasin Alissa, Khoa Tran
    *****************/
    long totBits = 0;
    for (int i = 0; i < 100.0; i++) {
        totBits += analogRead(pin);
    }
    int avgBits = (int) (totBits / 100.0);
    int voltage = (map(avgBits, 0, 1023, 0, 5000));
    float gs = (voltage - 1650) / 800.0;
    return (gs * 980) + cmOffs;
}

float integrate(float fa, float fb, float c, float dt) {
    /****************
    * Function name: integrate
    * Function inputs: the previous value of the function, the current value of the function, the c value to add to the
    * integarl
    * Function outputs: none
    * Function description: Updates the accelerometer measurements
    * Author(s): Yasin Alissa, Khoa Tran
    *****************/
    return (((fa + fb) / 2) * dt) + c;
}

float magnitude(float x, float y, float z) {
    /****************
    * Function name: magnitude
    * Function inputs: the acceleration in the x-axis, the acceleration in the y-axis, and the acceleration in the z-axis
    * Function outputs: the magnitude of the vector that is equal to x*i + y*j + z*k
    * Function description: The calculates the magnitude of acceleration of the accelerometer
    * Author(s): Yasin Alissa, Khoa Tran
    *****************/
    return sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
}

int getToCalibrate(const byte pin, int offs, float correctValue) {
    /****************
    * Function name: getToCalibrate
    * Function inputs: the pin of the axis we're calibrating, the axis' current offset, and
    * the correct value we're trying to get to
    * Function outputs: the value we need to add to the offset to get the correct value
    * Function description: Calculates the value we need for calibration for the given axis
    * Author(s): Yasin Alissa, Khoa Tran
    *****************/
    float totAcc = 0;
    for (int i = 0; i < 25; i++) {
        totAcc += acceleration(pin, offs);
    }
    float avgAcc = totAcc / 25.0;
    avgAcc = correctValue - avgAcc;
    return round(avgAcc);
}

void calibrate(const byte xPin, const byte yPin, const byte zPin) {
    /****************
    * Function name: calibrate
    * Function inputs: the pin for the x-axis acceleration, the pin for the y-axis acceleration, and
    * the pin for the z-axis acceleration,
    * Function outputs: none
    * Function description: Calibrates the accelerometer
    * Author(s): Yasin Alissa, Khoa Tran
    *****************/
    int xToCalibrate = -1;
    int yToCalibrate = -1;
    int zToCalibrate = -1;
    // Keep calibrating until the values are rounded to 0 cm/s^2
    while(xToCalibrate != 0 || yToCalibrate != 0 || zToCalibrate != 0) {
        // Get the values at each axis that we need to add to the offsets
        xToCalibrate = getToCalibrate(xPin, xOffset, 0);
        yToCalibrate = getToCalibrate(yPin, yOffset, 0);
        // The z-axis is pointing in the same direction as gravity, so it has a value of -980 cm/s^2
        zToCalibrate = getToCalibrate(zPin, zOffset, -980);
        // Add the values to the offsets
        xOffset += xToCalibrate;
        yOffset += yToCalibrate;
        zOffset += zToCalibrate;
    }
}

float getAngle(float acc) {
    /****************
    * Function name: getAngle
    * Function inputs: the acceleration of the axis whose angle we're trying to find
    * Function outputs: the angle of the given axis in degrees
    * Function description: Calculates the angle with respect to gravity of the axis whose acceleration is given
    * Author(s): Yasin Alissa, Khoa Tran
    *****************/
    float ang = 180 * acos(acc / -980) / M_PI;
    if (isnan(ang)) {
        if (acc > 0) {
            ang = 180;
        } else {
            ang = 0;
        }
    }
    return ang;
}

void accelerometerTask(void* aData) {
    /****************
    * Function name: accelerometerTask
    * Function inputs: void* pointer to the accelerometerData struct
    * Function outputs: none
    * Function description: Updates the accelerometer measurements
    * Author(s): Yasin Alissa, Khoa Tran
    *****************/
    accelerometerData* data = (accelerometerData*) aData;

    // Get the acceleration at each axis from the accelerometer
    float newXAcc = acceleration(*data->xPin, xOffset);
    float newYAcc = acceleration(*data->yPin, yOffset);
    float newZAcc = acceleration(*data->zPin, zOffset);

    // Get the velocity at each axis through integration
    float newXVel = integrate(*data->currXAcc, newXAcc, *data->currXVel, *data->timeBase);
    float newYVel = integrate(*data->currYAcc, newYAcc, *data->currYVel, *data->timeBase);
    float newZVel = integrate(*data->currZAcc, newZAcc + 980, *data->currZVel, *data->timeBase);

    // Get the position at each axis through integration
    float newXPos = integrate(*data->currXVel, newXVel, *data->currXPos, *data->timeBase);
    float newYPos = integrate(*data->currYVel, newYVel, *data->currYPos, *data->timeBase);
    float newZPos = integrate(*data->currZVel, newZVel, *data->currZPos, *data->timeBase);

    // Find the change of position at each axis
    float dx = newXPos - *data->currXPos;
    float dy = newYPos - *data->currYPos;
    float dz = newZPos - *data->currZPos;
    // Calculate the distance travelled this iteration
    float newDist = magnitude(dx, dy, dz);

    // Set the current positions, velocities, and accelerations at each axis to the newly measured values
    *data->currXPos = newXPos;
    *data->currYPos = newYPos;
    *data->currZPos = newZPos;
    *data->currXVel = newXVel;
    *data->currYVel = newYVel;
    *data->currZVel = newZVel;
    *data->currXAcc = newXAcc;
    *data->currYAcc = newYAcc;
    *data->currZAcc = newZAcc;

    // Add the distance travelled this iteration to the total distance travelled
    *data->totalDist += newDist;

    // Calculate the static angle of each axis with respect to gravity
    *data->currXAng = getAngle(newXAcc);
    *data->currYAng = getAngle(newYAcc);
    *data->currZAng = getAngle(newZAcc);
}