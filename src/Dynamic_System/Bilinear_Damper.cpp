#include "Damper.h"
#include "Bilinear_Damper.h"


Bilinear_Damper::Bilinear_Damper(
    double lowspeed_compression_damping_coefficient, 
    double highspeed_compression_damping_coefficient, 
    double lowspeed_rebound_damping_coefficient, 
    double highspeed_rebound_damping_coefficient, 
    double compression_kneespeed,
    double rebound_kneespeed):
        lowspeed_compression_damping_coefficient {lowspeed_compression_damping_coefficient}, 
        highspeed_compression_damping_coefficient {highspeed_compression_damping_coefficient}, 
        lowspeed_rebound_damping_coefficient{lowspeed_rebound_damping_coefficient},
        highspeed_rebound_damping_coefficient {highspeed_rebound_damping_coefficient},
        compression_kneespeed{compression_kneespeed},
        rebound_kneespeed {rebound_kneespeed}{
}


double Bilinear_Damper::get_damper_coefficent(double damper_velocity){
    if (damper_velocity<0) {                                    // True if compression
        if (damper_velocity>(-compression_kneespeed)){          // True if velocity is low speed
            return lowspeed_compression_damping_coefficient;
        }
        else {
            return highspeed_compression_damping_coefficient;
        }
    }    
    else {
        if (damper_velocity<rebound_kneespeed){
            return lowspeed_rebound_damping_coefficient;
        }
        else {
            return highspeed_rebound_damping_coefficient;
        }
    }
}

double Bilinear_Damper::get_damper_force(double damper_velocity){
    if (damper_velocity<0) {                                    // True if compression
        if (damper_velocity>(-compression_kneespeed)){          // True if velocity is low speed
            return -lowspeed_compression_damping_coefficient*damper_velocity;
        }
        else {
            return -(highspeed_compression_damping_coefficient*(damper_velocity + compression_kneespeed)
                    - lowspeed_compression_damping_coefficient *compression_kneespeed);
        }
    }    
    else {
        if (damper_velocity<rebound_kneespeed){
            return -lowspeed_rebound_damping_coefficient*damper_velocity;
        }
        else {
            return -(highspeed_rebound_damping_coefficient*(damper_velocity-rebound_kneespeed)
                    + lowspeed_compression_damping_coefficient * rebound_kneespeed);
        }
    }
}

