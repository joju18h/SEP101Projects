//MoonObject.h - class definition for moon object
//George Paul Robert, 117928226

#ifndef MOONOBJECT_H
#define MOONOBJECT_H

#define G_CONST_MOON 1.625 //gravitational constant for moon

class MoonObject {
    private:
        double initialHeight;
        double horizontalSpeed;
        double initialVerticalSpeed;
        double xPos;
        double yPos;

    public:
        //two constructors
        MoonObject();
        MoonObject(double, double, double);

        //setter functions
        bool setInitialHeight(double);
        bool setInitialVerticalSpeed(double);
        bool setHorizontalSpeed(double);

        //getter functions
        double getXPos(double);
        double getYPos(double);
};

#endif
