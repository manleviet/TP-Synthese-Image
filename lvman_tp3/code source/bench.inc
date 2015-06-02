#include "texture.inc"

#declare xB = 2;
#declare yB = 0.43;
#declare yB1 = 0.05;
#declare yB2 = yB - yB1;
#declare zB = 1;
#declare rB = 0.08;
#declare eB = 0.02;

#declare LegBench1 = lathe {
	cubic_spline
	26,
	<0.051,-0.005>,	<0.039,0.000>,	<0.041,0.012>,	<0.049,0.017>,	<0.051,0.026>,
	<0.055,0.042>,	<0.042,0.074>,	<0.057,0.099>,	<0.052,0.109>,	<0.062,0.114>,
	<0.067,0.123>,	<0.063,0.135>,	<0.071,0.141>,	<0.079,0.191>,	<0.072,0.226>,
	<0.063,0.264>,	<0.056,0.292>,	<0.045,0.320>,	<0.044,0.354>,	<0.043,0.376>,
	<0.046,0.390>,	<0.050,0.403>,	<0.060,0.419>,	<0.056,0.438>,	<0.055,0.454>,
	<0.055,0.458>
	scale 0.1/0.454
	scale <2,1,2>
}       
                                               
#declare rLegBench = 0.079*0.1/0.454;
#declare rLegBench = 0.079*1.5*0.1/0.454;

#declare LegBench2 = superellipsoid {
    <0.2,0.2> 
    scale <1,0.5,1> 
    translate y*0.5 
    scale <rLegBench, 0.1, rLegBench>
}

#declare LegBench3 = lathe {
	cubic_spline
	10,
	<0.031,-0.003>,	<0.032,0.000>,	<0.035,0.012>,	<0.038,0.020>,	<0.045,0.029>,
	<0.054,0.044>,	<0.049,0.064>,	<0.029,0.081>,	<0.026,0.085>,	<0.013,0.092>
	scale 0.05/0.085
	scale <0.8,1,0.8>
}            

#declare yLegBench = 0.35;
#declare LegBench = union {
    object { LegBench3 }
    object { LegBench2 translate y*0.05 }
    object { LegBench1 rotate x*180 translate y*0.25 }
    object { LegBench2 translate y*0.25 }
    object { LegBench1 translate y*0.35 }
    scale yLegBench/0.45
    scale <2,1,2>
}                        

#declare Bench = union {
    object {
        superellipsoid { 
            <0.1,0.1> 
            translate -y 
            scale <xB/2,yB1/2,zB/2>
        }
        translate y*yB2
    }
    object { 
        LegBench 
        translate <-xB/2+rB,0,-zB/2+rB>
    }
    object { 
        LegBench 
        translate <-xB/2+rB,0,zB/2-rB>
    }
    object { 
        LegBench 
        translate <xB/2-rB,0,-zB/2+rB>
    }
    object { 
        LegBench 
        translate <xB/2-rB,0,zB/2-rB>
    }
    union{
        object { 
            LegBench 
            scale <1,-1,1> 
            translate y*yLegBench 
            rotate z*90 
            scale <0.9*(xB/2)/yLegBench,0.5,0.5> 
            translate <0,0.07,-zB/2+rB>
        }
        object { 
            LegBench 
            scale <1,-1,1> 
            translate y*yLegBench 
            rotate z*90 
            scale <0.9*(xB/2)/yLegBench,0.5,0.5> 
            translate <0,0.07,-zB/2+rB> 
            scale <-1,1,1>
        }
        object  { 
            LegBench 
            scale <1,-1,1> 
            translate y*yLegBench 
            rotate z*90 
            scale <0.9*(xB/2)/yLegBench,0.5,0.5> 
            translate <0,0.07,zB/2-rB>
        }
        object { 
            LegBench 
            scale <1,-1,1> 
            translate y*yLegBench 
            rotate z*90 
            scale <0.9*(xB/2)/yLegBench,0.5,0.5> 
            translate <0,0.07,zB/2-rB> 
            scale <-1,1,1>
        }
    }
    union {
        object {
            LegBench 
            scale <1,-1,1> 
            translate y*yLegBench 
            rotate x*90 
            scale <0.5,0.5,0.9*(zB/2)/yLegBench> 
            translate <-xB/2+rB,0.07,0>
        }
        object { 
            LegBench 
            scale <1,-1,1> 
            translate y*yLegBench 
            rotate x*90 
            scale <0.5,0.5,0.9*(zB/2)/yLegBench> 
            translate <-xB/2+rB,0.07,0> 
            scale <1,1,-1>
        }
        object { 
            LegBench 
            scale <1,-1,1> 
            translate y*yLegBench 
            rotate x*90 
            scale <0.5,0.5,0.9*(zB/2)/yLegBench> 
            translate <xB/2-rB,0.07,0>
        }
        object { 
            LegBench 
            scale <1,-1,1> 
            translate y*yLegBench 
            rotate x*90 
            scale <0.5,0.5,0.9*(zB/2)/yLegBench> 
            translate <xB/2-rB,0.07,0> 
            scale <1,1,-1>
        }
    }
    texture { 
        Tex_WoodBench 
        scale 0.2
    }
}