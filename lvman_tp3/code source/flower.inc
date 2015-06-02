#include "glass.inc"
#include "petal.inc"

#declare vh = 10.0;		// vase height
#declare vor = 1.5;		// vase outside radius
#declare vir = 1.2;		// vase inside radius
#declare vcen = (vor + vir) / 2;
#declare vth = (vor - vir);
#declare vrad = (vth / 2);
#declare vih = 6;			// water height
#declare vbrad = 0.35;	// radius of base torus

#declare wr=0.133;
#declare sr=0.11;
#declare sv=<0.42,0,0>;

//------------------------------------------------
// Stem
//------------------------------------------------
#declare stem_shape = sphere_sweep {
	cubic_spline
	9
	<0, 1, 0>, sr*1.05
	<0, 1.6, 0>, sr*1
	<0.1, 4, 0>, sr*0.95
	<0.4, 7, 0>, sr*0.95
	<0.75, 8.5, 0>, sr*0.95
	<1.1, 10, 0>, sr*1
	<1.4, 11, 0>, sr*1.1
	<1.8, 12, 0>, sr*3.5
	<2.5, 13, 0>, sr*6
}

#declare stem = object
{
	stem_shape
	pigment { rgb <0.33, 0.45, 0.17> * 1.25}
	normal {
		bozo 0.5
		scale <1/40, 1/4, 1/40>
	}
}

// spline for stem bubbles - must match spline
// in sphere sweep
#declare sspl = spline {
	cubic_spline
	1   ,<0.0,1,0>
	1.6	,<0.0,1.6,0>
	4	,<0.1,4,0>
	7	,<0.4,7,0>
	8.5	,<0.75,8.5,0>
	10	,<1.1,10,0>
	11	,<1.4,11,0>
	12	,<1.8,12,0>
	13	,<2.5,13,0>
}

//------------------------------------------------
// Water
//------------------------------------------------
// water curves up to sides of glass and stem
#declare top_shape = union {
	torus {vir-wr, wr}
	difference {
		cylinder { <0,-wr,0> <0,wr,0> vir-wr}
		cylinder { 
		    <0,-wr,0> <0,wr,0> sr+wr 
		    translate sv
		}
	}
	torus { 
	    sr+wr,wr 
	    translate sv
	}
	
	scale 0.995
	translate <0,vih+vir,0>
}

// water in vase
#declare inside_shape = intersection
{
	sphere { 
	    0, vir 
	    scale <1,4,1> 
	    scale 0.99 
	    translate <0,vih,0>
	}
	cylinder { 0, <0,vir+vih,0> vir }
}

#declare water_shape = difference {
	object { inside_shape }
	object { top_shape }

	// bubbles
    #local i = 1.7;
    #while (i<vih+1)
        #local ang=f_snoise3d(i*20,i*50,i*4)*20;
        #local vec1=sspl(i+f_snoise3d(i,0,1)*0.1);
        #local vec2=<sin(ang),0,cos(ang)>;
        #local si=trace(stem_shape,vec1+vec2, -vec2);
        #if(vlength(si)>0)
            sphere {si, 0.04+f_snoise3d(3,ang,i)*0.025}
        #end
        #local vec1=<0,i+f_snoise3d(i,0,1)*0.1,0>;
        #local wi=trace(inside_shape,vec1+3*vec2, -vec2);
        #if(vlength(wi)>0)
        	sphere {wi-vec2*0.02, 0.035+f_snoise3d(3,ang,i)*0.025}
        #end
        #local i=i+0.035;
    #end
}

#declare water = object {
	water_shape
	
	pigment { rgbf 1 filter 0.98}
	//finish { F_Glass7 }
	finish{
        reflection {
            0.01, 1
            fresnel on
        }
        conserve_energy 
        ambient 0 
        diffuse 0 
        specular 0.4 
        roughness 1/1000
    }
	interior
	{
		ior 1.33
		fade_distance 10
		fade_power 2
		fade_colour <0.95,1,0.95> // slight green tint to water
	}
	photons
	{
		target
		reflection on
		refraction on
		//collect off
	}
}

//------------------------------------------------
// Vase
//------------------------------------------------
#declare vase_shape = difference {
    // outside
	merge
	{
		cylinder { <0, vbrad, 0>,<0, vh, 0> vor}
		torus { 
		    vcen, vrad 
		    scale <1, 1, 1> 
		    translate <0, vh, 0>
		}
		torus {
		    vor - vbrad, vbrad 
		    translate <0, vbrad, 0>
		}
		cylinder { 0,<0, vor - vbrad, 0> vor - vbrad}
	}
	// inside
	union
	{
		cylinder {<0, vih, 0>, <0, vh + 0.1, 0> vir}
		sphere { 
		    0, vir 
		    scale <1, 4, 1> 
		    translate <0, vih, 0>
		}
	}
}

#declare vase = object {
	vase_shape
	pigment { rgbt <0.99,1,0.995,0.99> }
	finish { F_Glass7 } // moi them
	interior
	{
		ior 1.525
		fade_distance 10
		fade_power 2
		fade_colour <0.9,1,0.95> // slight blue/green tint to glass
	}
	photons
	{
		target
		reflection on
		refraction on
		//collect off
	}
	normal
	{
		average
		normal_map
		{
			[1.0 bozo 0.012 scale <1.5,0.25,1.5>]
			[1.0 bozo 0.025 scale <20,2,20>]
		}
	}
}

//------------------------------------------------
// Vase
//------------------------------------------------
#declare f = array[14][4]
{
//	xcurl	xtwist	zcurl	maxg
	{0.34	,-1.0	,2.0	,77	},
	{0.42	,0.7	,2.2	,88	},
	{0.37	,0.3	,3.0	,85	},
	{0.45	,0.0	,3.1	,96	},
	{0.6	,0.8	,3.2	,120},
	{0.14	,0.3	,3.3	,55	},
	{0.33	,0.1	,2.8	,76	},
	{0.2	,-0.1	,3.5	,78	},
	{0.42	,-0.3	,3.1	,147},
	{0.35	,-0.5	,2.8	,146},
	{0.5	,-0.8	,3.8	,200},
	{0.55	,-0.7	,2.7	,201},
	{0.6	,-0.5	,2.6	,172},
	{0.33	,-0.0	,3.1	,90}
}

#declare flower = union {
    #local i=0;
    #local pn=0;
    #while(i<360)
	    object
	    {
		    petal(i,f[pn][0],f[pn][1],f[pn][2],f[pn][3])
    		normal
    		{
    			bozo
    			scale <1/100,1/300,1/300>
    		}
    		pigment
    		{
    			function{clip((x-1.6)*(x-1.3)+f_snoise3d(x*2,i,z*10)*0.3,0,1)}
    			pigment_map
    			{
    				[0.0 rgb 0.9]
    				[0.2 rgb <0.8710,0.8554,0.8710>]
    				[0.6 rgb <0.7460,0.6679,0.7148>]
    				[0.8 rgb <0.5859,0.4414,0.5234>]
    				[1.0 rgb <0.2851,0.1875,0.2851>]
    			}
    		}
    		// petal up
            #if (i=1)
            		rotate <0,0,20>
            #else
            		rotate <0,0,20+f_bozo(i,10,0)*20>
            #end
			// petal twist and rotate around center
		    rotate <f_bozo(i,20,0)*2,i-15+f_bozo(i,30,0)*10,0>
	    }
        #local i=i+(360/14);
        #local pn=pn+1;
    #end
	
	rotate <0,0,-21>
	translate <1.8,12,0>
}

// individual parts of the center of the flower
// age 0->1 0=flat, 1= raised/coloured
#macro cent(age,num)
    intersection
    {
    	union
    	{
    		sphere {0, 1 scale <0.15,0.8+age/5,0.15>}
            #local i=0;
            #while (i<360)
        		sphere {0, 1 scale <0.1,0.9,0.1> rotate <6+4*age,0,0>
        		rotate <0,i,0>}
                #local i=i+(360/5);
            #end
    		
    		pigment
    		{
    			function{clip(y+f_snoise3d(mod(num,360)/360,0,0)/5,0,1)}
    			pigment_map
    			{
    				[0.0 rgb <0.81,0.81,0.78>]
    				[0.66 rgb <0.81,0.81,0.78>]
    				[0.78 rgb <0.777,0.649,0.285>/0.75]
    				[0.88 rgb <0.711,0.379,0.000>/0.72]
    				[0.92 rgb <0.254,0.129,0.094>]
    				[0.95 rgb <0.254,0.129,0.094>/2]
    			}
    		}
    	}
    	cylinder {0,<0,1,0>,0.3 pigment {Red}}
    }
#end

#declare center = union {
    #local d=0.3;
    #local ang=60;
    #while(ang <360*6)
        #local r=d*ang/360;
        #local ang=ang+degrees(atan(d/r));
        #local a=(clip(f_bozo(ang/10,r,1),0.4,0.6)-0.4)*5;
    	object
    	{
    		cent(a,ang)
    		scale<0.66,0.5,0.66>
    		rotate <0,f_snoise3d(ang,r,10)*40,0>
    		translate <0,0.5+f_snoise3d(ang,r,20)/10,0>
    		rotate <0,0,ang/30+f_snoise3d(ang,r,50)>
    		rotate <0,ang+f_snoise3d(ang,r,70),0>
    	}
    #end
	scale 0.55
	rotate <0,180,-21>
	translate <1.8,12,0>
}

#declare Flower = union {
	object{vase}
	object{water}
	object{stem}
	object{flower}
	object{center}
}