#include "sideboard.inc"

#declare MirrorBall = union {
    object {
        RoundedBox(0.05, 0.025, 0.05, 0.005) 
        translate <0, 0.025, 0>
        pigment {
            granite
            color_map {
                [0 color Orange]
                [1 color Brown] 
            }
            scale <0.05, 1, 0.05> 
        }
        finish { 
            ambient 0 
            reflection { 0.2 exponent 0.8 } 
        } 
    }
    sphere {
        <0, 0.11, 0>, 0.07
        pigment { color Black }
        finish { 
            ambient 0 
            reflection { 1 } 
        }
        
        photons {
            target
            reflection on
            refraction off
        } 
    } 
}