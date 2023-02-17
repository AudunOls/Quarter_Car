# Quarter_Car


(WIP - note not all is implemented yet)
Quarter_Car is a quarter-car simulation based on a state space model with road velocity as input. It models a quarter car with a sprung and unsprung mass. The quarter car has both an unsprung and sprung spring, and a sprung and unsprung damper. Where the springs can have either a linear or bilinear spring rate. Additionally, the dampers can be either linear or 4-way adjustable with high/low-speed compression and rebound. Three road inputs are available, impulse road input, sinusoidal road input and random road input.

## Springs

The quarter car has two types of springs, linear and bilinear. Both spring types have the option of adding a preload. The equilibrium point of the quarter car simulation is at static ride. To account for the static forces on the suspension spring and the tyre spring, preload should be added when initialising the tyre and suspension spring. The preload on the sprung spring should be the gravitational force of the sprung mass. The preload on the tyre should be the gravitational force from both the sprung and unsprung mass. 

The bilinear spring class has four inputs: spring preload, initial spring rate, max travel fn the initial spring rate, and secondary spring rate. If modelling a spring with a bumpstop, the initial spring rate will be the main spring rate, and the secondary spring rate will be the sum of the main spring rate AND the bumpstop rate. The max travel of the initial spring rate will then be the distance from the static ride position of the spring to the point in which the bumpstop engages. If modelling a tender spring is wanted, the initial spring rate will be the main spring and tender spring in series, whilst the secondary spring rate will be the rate of the main spring. The max travel of the initial spring rate will then be the distance from static to when the tender spring collapses. 

## Dampers

The quarter car has two types of dampers, linear and bilinear (4-way adjustable). The linear damper has one input: damper_coefficient. The linear damper has the same damper coefficient in both rebound and compression. The bilinear damper has six inputs: lowspeed_compression, highspeed_compression, lowspeed_rebound, highspeed_rebound, kneeespeed_compression, kneespeed_rebound. 

## Sign convention

The sign convention used in this quarter car model is z-axis pointing upwards, with zero set to the equilibrium point of the masses. This means that a positive position will be a position above the equilibrium point (positive z). The force is also defined as positive when acting in the postive z-direction.

Spring preload: insert positive value, i.e 981N sprung preload for a quarter car with sprung mass of 100kg 
Spring rate(s): insert positive value(s)
max_travel_initial_spring_rate: insert positive value

Damper coefficient(s): insert positive value(s)
Knee speeds: insert a positive value