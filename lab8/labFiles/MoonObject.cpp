//MoonObject.cpp - Function definitions for moon object
//George Paul Robert, 117928226

#include "MoonObject.h"

//default constructor
MoonObject::MoonObject(){
    initialHeight = 0.00;
    horizontalSpeed = 0.00;
    initialVerticalSpeed = 0.00;
    xPos = 0.00;
    yPos = 0.00;
}

MoonObject::MoonObject(double _initialHeight, double _inVerticalSpeed, double _horizontalSpeed){
    initialHeight = _initialHeight;
    horizontalSpeed = _horizontalSpeed;
    initialVerticalSpeed = _inVerticalSpeed;
}

//setter fucntion defintions
bool MoonObject::setInitialHeight(double iniHeight){
    bool retval = false;
    if (iniHeight >= 0){
        initialHeight = iniHeight;
        retval = true;
    }
    return retval;
}

bool MoonObject::setHorizontalSpeed(double hSpeed){
    bool retval = false;
    if(hSpeed >= 0){
        horizontalSpeed = hSpeed;
        retval = true;
    }
    return retval;
}

bool MoonObject::setInitialVerticalSpeed(double iniVSpeed){
    bool retval = false;
    if(iniVSpeed >= 0){
        initialVerticalSpeed = iniVSpeed;
        retval = true;
    }
    return retval;
}

//getter function defintions
double MoonObject::getXPos(double time){
    xPos = horizontalSpeed * time;
    return xPos;
}

double MoonObject::getYPos(double time){
    yPos = initialHeight + initialVerticalSpeed * time - 0.5 * G_CONST_MOON * time * time;
    return yPos;
}
