//EarthObject.cpp - Function definitions for earth object
//George Paul Robert, 117928226


#include "EarthObject.h"

//default constructor
EarthObject::EarthObject(){
    initialHeight = 0.00;
    horizontalSpeed = 0.00;
    xPos = 0.00;
    yPos = 0.00;
}

EarthObject::EarthObject(double _initialHeight, double _horizontalSpeed){
    initialHeight = _initialHeight;
    horizontalSpeed = _horizontalSpeed;
}

//setter function defintions
bool EarthObject::setInitialHeight(double iniHeight){
    bool retval = false;
    if (iniHeight >= 0){
        initialHeight = iniHeight;
        retval = true;
    }
    return retval;
}

bool EarthObject::setHorizontalSpeed(double hSpeed){
    bool retval = false;
    if(hSpeed >= 0){
        horizontalSpeed = hSpeed;
        retval = true;
    }
    return retval;
}

//getter function defintions
double EarthObject::getXPos(double time){
    xPos = horizontalSpeed * time;
    return xPos;
}

double EarthObject::getYPos(double time){
    yPos = initialHeight - 0.5 * G_CONST_EARTH * time * time;
    return yPos;
}
