#include "woods.inc"
#include "metals.inc"

#declare T_Frame = texture {
    T_Wood6 
    translate x*5
}

#macro PictureFrameEdge(Len,Texture1,Texture2,Texture3)
    #local Length = Len*10;
    difference {
        union {
            box {
                <1.5,-Length/2,0>,<10,Length/2,1>
                texture { Texture1 scale 5 rotate x*90 }
            }
            cylinder {
                <8.5,-Length/2,0>,<8.5,Length/2,0>,1.5
                scale <1,1,0.35>
            }
            box {
                <1.85,-Length/2,0>,<4.5,Length/2,-0.25>
            }
            cylinder {
                <1.85,-Length/2,0>,<1.85,Length/2,0>,0.35
                scale <1,1,0.25/0.35>
            }
            cylinder {
                <4.5,-Length/2,0>,<4.5,Length/2,0>,0.35
                scale <1,1,0.25/0.35>
            }
            cylinder {
                <5.2,-Length/2,0>,<5.2,Length/2,0>,0.3
            }
            cylinder {
                <5.9,-Length/2,0>,<5.9,Length/2,0>,0.3
            }
            cylinder {
                <6.6,-Length/2,0>,<6.6,Length/2,0>,0.3
            }
            cylinder {
                <0.75,-Length/2,0.45>,<0.75,Length/2,0.45>,0.6
                texture {Texture3 rotate x*-90}
            }
        }
        box {
            <-10,-10,-1.5>,<10,10,1.5>
            rotate z*45
            translate <0,Length/2,0>
        }
        box {
            <-10,-10,-1.5>,<10,10,1.5>
            rotate z*-45
            translate <0,-Length/2,0>
        }
        texture {Texture2 scale 5 rotate x*-90}
        scale <0.1,0.1,0.2>
    }  
#end

#macro Picture(Width, Height, PicName, Description, showDescription)
    union {
		union {
		    object {
		        PictureFrameEdge( Height, T_Wood2, T_Frame, T_Gold_4D)
		        translate x*4.5
		    }
		    object {
		        PictureFrameEdge(Height, T_Wood2,T_Frame,T_Gold_4D)
		        scale <-1,1,1>
		        translate x*-4.5
		    }  
		    object {
		        PictureFrameEdge(Width,T_Wood2,T_Frame,T_Gold_4D)
		        rotate z*90
		        translate y*5.45
		    }      
		    object {
		        PictureFrameEdge(Width,T_Wood2,T_Frame,T_Gold_4D)
		        rotate z*-90
		        translate y*-5.45
		    }     
		    box {
		        <-2.5,-3,0>,<2.5,3,0.01>
		        pigment {
		            image_map {jpeg PicName interpolate 2}
		            translate <-0.5,-0.5,0>
		            scale <5,6,1>
		        }
		        scale 1.8
		        //no_shadow
		        finish {
		            ambient 0.2
		            diffuse 0.2
		            reflection .25
		            specular 1
		            roughness .001
		        }
		
		        photons {
		            target
		            reflection on
		            refraction off
		        }
		    }
		    rotate x*-2
		    translate z*-0.12
		}
		#if (showDescription = true)
		difference {
		    object {Round_Box_Union(<-4,-8.25,0.1>,<4,-7.25,0.2>,0.02)}
		    text {ttf "timrom.ttf" Description 0.1,0 scale <1,1,0.2>*0.75 translate <-(Text_Width("timrom.ttf", Description, 0.75, 0))/2,-7.925,0.089> pigment {Black}}
		    texture {T_Brass_3B}
		}
		#end
	}
#end

