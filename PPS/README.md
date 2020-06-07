# A library that provides a Primordial Particle System

## Explanation of the idea

A primordial particle is a particle with a position (x,y) in 2D space, a speed v, and an angle phi. 
This angle represents its direction. 
At each time step, the particle move in the direction of the angle with speed v: 
x = x + v*cos(phi);
y = y + v*sin(phi);

Before the particle is moved however, the angle phi is updated: 

phi += alpha + beta * N * sign(R-L); 

with alpha, beta as parameters. 
N is the no of other particles within circle of a certain radius centered on the particle. 
R is the no of particles on the right half of the circle. L is for the left side.  


#### Note:

The parameters v, alpha, beta, and radius are parameters of the particles themselves 
I did it this way, so that in the future I can try a system with multiple different parameters at the same time
