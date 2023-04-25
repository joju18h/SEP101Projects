//EarthObject.h - class definition for earth object
//George Paul Robert, 117928226


#ifndef EARTHOBJECT_H_
#define EARTHOBJECT_H_

#define G_CONST_EARTH 9.81 //gravitational constant for earth

class EarthObject {
    private:
        double initialHeight;
        double horizontalSpeed;
        double xPos;
        double yPos;

    public:
        //two constructors
        EarthObject();
        EarthObject(double, double);

        //setter functions
        bool setInitialHeight(double);
        bool setHorizontalSpeed(double);

        //getter functions
        double getXPos(double);
        double getYPos(double);
};

#endif
