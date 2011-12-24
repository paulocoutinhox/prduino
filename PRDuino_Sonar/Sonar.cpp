/*
 Sonar.cpp - Library for sonar HC-SR04
 Created by Paulo Coutinho - 2012-12-23
 www.prsolucoes.com
 */

#include "Sonar.h"

namespace PRDuino
{
    
    Sonar::Sonar(int triggerPort, int echoPort)
    {
        pinMode(triggerPort , OUTPUT);
        pinMode(echoPort    , INPUT);
        
        _triggerPort = triggerPort;
        _echoPort    = echoPort;
    }
    
    long Sonar::scan()
    {
        digitalWrite(_triggerPort, LOW);
        delayMicroseconds(2);
        
        digitalWrite(_triggerPort, HIGH);
        delayMicroseconds(10);
        
        digitalWrite(_triggerPort, LOW);
        
        _duration = pulseIn(_echoPort, HIGH);        
        return _duration;
    }
    
    long Sonar::getRange(int scale)
    {
        scan();
        
        _distanceINC = _duration / 74 / 2;
        _distanceCM  = _duration / 29 / 2;
        _distanceMT  = _distanceCM / 100;

        switch (scale) 
        {
            case PRDuino::Sonar::SCALE_MT:
                return _distanceMT;
                break;
                
            case PRDuino::Sonar::SCALE_CM:
                return _distanceCM;
                break;
                
            case PRDuino::Sonar::SCALE_INC:
                return _distanceINC;
                break;
                
            default:
                return 0L;
                break;
        }
    }
    
}