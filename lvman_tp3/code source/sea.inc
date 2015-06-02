// Persistence Of Vision Ray Tracer Include File
// File: water.inc
// Vers: 3.5
// Desc: water for 'balcony.pov' demonstration scene
// Date: July/August 2001
// Auth: Christoph Hormann

#include "texture.inc"
#include "functions.inc"

#declare RMF1 = function{ f_ridged_mf(x, y, z, 0.07, 2.2,  7, 0.6, 0.9, 1)}

// Material for Sea
#declare Mat_Sea = material {
    texture {
        pigment {
            color rgbt <0.2, 0.22, 0.21, 0.94>
        }
        finish {
            diffuse 0.0
            ambient -0.2
        
            reflection {
                0.0, 0.95
                fresnel on
            }
        
            conserve_energy
        
            specular 0.4
            roughness 0.007
        }
        normal {
            function { RMF1(x, y, z) } 0.8
            scale 0.3
        }
    }
    interior {
        ior 1.31
        fade_distance 5
        fade_power 1001.0
        fade_color <0.02, 0.20, 0.06>
    }
}

#declare Sea = union {
    plane {
        y, -1
        material {
            Mat_Sea
        }
        hollow on
    }
    
    plane {
        y, -12.0
    
        texture {
            pigment { color rgb 0 }
            finish { 
                ambient 0.0 
                diffuse 0.0 
            }
        }
        hollow on
    }
}
