/*
 Sonar.h - Library for sonar HC-SR04
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

namespace PRDuino
{
    class Sonar
    {
                
    public:
        
        static const int SCALE_INC = 1;
        static const int SCALE_CM  = 2;
        static const int SCALE_MT  = 3;
        
        Sonar(int triggerPort, int echoPort);
        long scan();
        long getRange(int scale);
        
    private:
        
        int _triggerPort;
        int _echoPort;
        long _duration;
        long _distanceMT;        
        long _distanceCM;
        long _distanceINC;
        
    };
    
}

#endif