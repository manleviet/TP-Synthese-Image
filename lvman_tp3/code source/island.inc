// Persistence of Vision Ray Tracer Include File
// File: terrain.inc
// Vers: 3.5
// Desc: terrain for 'balcony.pov' demonstration scene
// Date: July/August 2001
// Auth: Christoph Hormann

#include "texture.inc"

#declare Terrain = object {
    height_field {
        function 300,300 {
            pigment {
                function { 1-(min(pow(x*x + z*z,1.3), 1) -0.0001) }
                color_map {
                    [0.0 color rgb 0.0]
                    [1.0 color rgb 1.0]
                }
                scale 0.35
                translate <0.5,0,0.5>
            
                warp { turbulence 0.3 }
            
                scale 3
                warp { turbulence 0.4 lambda 2.2 octaves 8 }
                scale 1/3
            
                rotate -90*x
                translate -0.5*y
                scale <1, -1, 1>
                translate 0.5*y
            }
        }

        water_level 0.02

        rotate 90*x
        rotate -10*z

        scale <4, 4, 1>
        scale 30
    }
}

#declare Island = union {
    object {
        Terrain
        translate <130, 368, -10>
    }

    object {
        Terrain
        rotate -180*z
        scale 0.3
        translate <90, 97, -6>
    }
    texture { Tex_Terrain }
}
