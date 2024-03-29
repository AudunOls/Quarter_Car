#pragma once

#define _USE_MATH_DEFINES
#include <sciplot/sciplot.hpp>
#include <iostream>
#include <vector>
#include <set>
#include "Spring.h"
#include "Linear_Spring.h"
#include "Damper.h"
#include "Linear_Damper.h"
#include "Quarter_Car.h"
#include "Road_Input.h"
#include "Impulse_Input.h"
#include "Bilinear_Spring.h"
#include "Bilinear_Damper.h"
#include "Sinusoidal_Input.h"
#include "Random_Input.h"
#include <cmath>
#include "Numerical_Solver.h"
#include "Forward_Euler.h"
#include "Continuous_Damper.h"
#include "Dynamic_System.h"
#include "Simulation.h"

#include <math.h>
#include <nlopt.h>


using namespace sciplot;
using namespace std;
