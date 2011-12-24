/*
 PRSonar.h - Library for sonar HC-SR04
 Created by Paulo Coutinho - 2012-12-23
 www.prsolucoes.com
 */

#ifndef Sonar_h
#define Sonar_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"	// for digitalRead, digitalWrite, etc
#else
#include "WProgram.h"
#endif

#define MT  2
#define CM  1
#define INC 0

namespace PRDuino
{
    
    class Sonar
    {
        
        //enum scale { INC, CM, MT };
        
    public:
        
        Sonar(int triggerPort, int echoPort);
        long scan();
        long getRange(int scale);
        
    private:
        
        int _triggerPort;
        int _echoPort;
        long _duration;
        long _distanceCM;
        long _distanceINC;
        
    };
    
}

#endif