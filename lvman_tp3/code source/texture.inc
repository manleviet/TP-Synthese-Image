//
// Dinh nghia cac texture
//

#include "metals.inc"
#include "functions.inc"

// Textures for Walls and Floor
#declare Tex_Floor = texture {
    pigment { 
        image_map { jpeg "pictures/parquet.jpg" } 
    }
    normal { 
        bump_map { jpeg "pictures/parquet.jpg" } 
        bump_size .3
    } 
    finish { 
        specular 0.8 
        roughness .02 
        diffuse 1 
        ambient 0
        reflection { 0, .4 }
    }
    rotate x*90
    scale 0.8
}
 
#declare Tex_Walls = texture {
    pigment { color rgb <1, 1, .9529> }
    finish  {
        specular .1 
        roughness .005
    }
    normal {
        granite .075
        scale <.75, .75, .75>
    }
}

// Textures for Windows
#declare Tex_Glass = texture { // Glass
	pigment { color rgbf <0.98, 0.98, 0.98, 0.9> } 
	finish  { 
        ambient 0.1
        diffuse 0.1
        phong 1.0
        phong_size 100.0
        specular 0.8
        roughness 0.0003
        reflection 0.1 
    } 
}

#declare Tex_Molding = texture{
    pigment{ color rgb 1 }
    finish{
        phong .8
        phong_size 10
        ambient 0
        diffuse .9
    }
}

// Texture for Carpet
#declare Tex_Carpet = pigment {
    image_map {png "pictures/carpet.png" interpolate 2}
    translate <-0.5,-0.5,0>
    scale <2,2,1>
    rotate y*180
}

// Textures for Chair
#declare Tex_Plastic = texture {
    pigment { color rgb <1, 1, 1> * 0.01 } 
    finish {
        specular 1 
        roughness 0.01 
        diffuse 1 
        ambient 0
        reflection {0, 0.4}
    }
}                      

#declare Tex_Cushion = texture {
    pigment { color rgb <58, 98, 124> / 255} 
    finish {
        specular 1 
        roughness 0.02 
        diffuse 1 
        ambient 0
    }
}

// Textures and materials for Table
#declare Mat_Glaze = material {   
    texture {      
        pigment { color rgb <0.114567, 0.114567, 0.114567> }      
        finish {
            ambient 0.0
            specular 1.0
            roughness 0.025
        }
    }
}

#declare Tex_Table_Map = texture {   
    pigment {
        marble
        color_map
        {
            [ 0.0     rgbft <0.54, 0.35, 0.25, 0.0, 0.0> ]
            [ 0.2     rgbft <0.54, 0.35, 0.25, 0.0, 0.0> ]
            [ 0.4     rgbft <0.57, 0.37, 0.24, 0.0, 0.0> ]
            [ 0.6     rgbft <0.54, 0.35, 0.25, 0.0, 0.0> ]
            [ 0.8     rgbft <0.57, 0.37, 0.24, 0.0, 0.0> ]
            [ 0.9     rgbft <0.54, 0.35, 0.25, 0.0, 0.0> ]
            [ 1.0     rgbft <0.54, 0.35, 0.25, 0.0, 0.0> ]
        }
        turbulence 0.25
        ramp_wave
        scale  <9.0, 9.0, 1.0>
    }   
    finish
    {
         ambient 0.0
         diffuse 1.2
         reflection {0.01} // moi them
    }
}
texture {   
    pigment {
        wood
        color_map
        {
            [ 0.0     rgbft <0.4, 0.21, 0.15, 0.0, 0.0> ]
            [ 0.05    rgbft <0.4, 0.21, 0.15, 0.7, 0.0> ]
            [ 0.2     rgbft <0.4, 0.24, 0.14, 1.0, 0.0> ]
            [ 0.747331  rgbft <0.4, 0.24, 0.14, 0.8, 0.0> ]
            [ 0.747331  rgbft <0.3, 0.14, 0.02, 0.7, 0.0> ]
            [ 0.843416  rgbft <0.3, 0.14, 0.02, 1.0, 0.0> ]
            [ 0.9     rgbft <0.3, 0.14, 0.02, 0.7, 0.0> ]
            [ 1.0     rgbft <0.25, 0.13, 0.09, 0.7, 0.0> ]
        }
        turbulence 0.5
        ramp_wave
        scale <3.0, 1.0, 3.75>
    }   
    finish {
        ambient 0.0
        diffuse 0.9
        reflection {0.01} // moi them
    }
}

#declare ParquetWood = material {   
      texture { Tex_Table_Map }   
      scale  < 0.025, 0.025, 0.1 >
      rotate -90.0 * y
}

// Texture for Bookcase
#declare C_Wood = rgb<149,115,45>/255;
#declare Tex_Wood = texture {
    pigment {
        wood         
        turbulence 0.2
        lambda 3
        rotate x*-80
        rotate z*-20
        scale 0.1*<1,8,1>*0.4
        color_map {
            [0 C_Wood*1.1]
            [1 C_Wood*0.6]
        }
                    
    }        
    finish {
        ambient 0.01 
        diffuse 0.6 
        specular 0.4 
        roughness 0.01
    }
}

// Texture for Sideboard
#declare Tex_SideWood = texture {
    pigment {
        granite
        color_map {
            [0 color LightWood]
            [1 color MediumWood] 
        }
        scale <1, 0.05, 0.05> 
    }
    finish { 
        ambient 0
        reflection 0.01 
    }
}

// Textures for candle
#declare Tex_Candle = texture { 
    pigment{ rgb <1, 1, 0.95> * 1.2 }
    normal { 
        bumps 0.15 
        scale <0.05, 0.1, 0.05> * 2 }
    finish { 
        reflection { 0.02 }
    }
}

#declare Tex_Candle_Wax_Liquid = texture { 
    pigment{ rgbf <1, 0.9, 0.7, 0.1> * 1.3 }
    normal { 
        bumps 0.15 
        scale <0.05, 0.1, 0.05> * 2 }
    finish { 
        reflection { 0.02 } 
    }
}

// Textures for lamp
#declare Tex_Lamp_Shade_On = texture {
    pigment {
        bozo 
        turbulence 0.6
        color_map {
            [0 rgbf <1, 0.8, 0, 0.3>]
            [1 rgbf <1, 0.8, 0, 0.7>]
        }
    }
    finish {
        ambient 0 
        diffuse 0.8 
        specular 0.05 
        roughness 0.01}
}

#declare Tex_Lamp_Shade_Off = texture {
    pigment {
        bozo 
        turbulence 0.6
        color_map {
            [0 rgb <1, 0.6, 0>]
            [1 rgb <1, 0.8, 0>]
        }
    }
    finish {
        ambient 0 
        diffuse 0.8 
        specular 0.05 
        roughness 0.01}
}

#declare Tex_Lamp_Iron = texture {
    pigment { rgb <0.8, 0.8, 0.9> * 0.5 } 
    normal {
        agate 
        bump_size 0.3 
        scale 0.01
    }
    finish { 
        metallic 
        brilliance 3 
        ambient 0 
        diffuse 1 
        specular 1 
        roughness 0.05
        reflection { 0, 0.2 }
    }
}

#declare Tex_Lamp_Douille = texture {
    T_Brass_3A 
    finish { 
        ambient 0
    }
}

// Textures for Island
#declare Tex_Grass = texture {
    pigment {
        bozo
        color_map {
            [0.3 color rgb <0.20, 0.35, 0.1> * 0.9 ]
            [0.8 color rgb <0.12, 0.35, 0.1> * 0.7 ]
        }
        scale 4
    }
    finish {
        ambient 0.0
        diffuse 0.5
        brilliance 0.8
        specular 0.1
    }
    normal {
        granite 0.4
    }
}

#declare Tex_Stone = texture {
    pigment {
        color rgb <0.6, 0.6, 0.6>
    }
    finish {
        ambient 0.1
        diffuse 0.45
        specular 0.15
    }
}

#declare Tex_Terrain = texture {
  slope -z
  texture_map {
    [0.34 Tex_Grass ]
    [0.34 Tex_Stone ]
  }
}

// Textures for Bench
#declare C_WoodBench = rgb 0.8*<105, 41, 5>/255;
#declare Tex_WoodBench = texture {
    pigment {
        granite
        color_map {
            [0 C_WoodBench*0.7]
            [0.11 C_WoodBench]
            [0.6 C_WoodBench*1.5]
            [1 C_WoodBench*0.4]
        }
    }
    finish {
        ambient 0 
        diffuse 1 
        specular 1 
        roughness 1/30
    }
}

// Textures and materials for Chess
#declare Tex_ChessGlass = texture {
    pigment { rgbf <0.98, 1.0, 0.98, 1> }
    finish {
        specular 1
        roughness 0.001
        ambient 0
        diffuse 0
        reflection {
            0,1
            fresnel
        }
    }
}

#declare Tex_ChessPiece = texture {
   pigment { rgbt <0.9, 0.9, 0.6, 0.6> }
   finish { reflection 0.3 }
}

#declare Mat_ChessSkyGlass = material {
    texture {
        pigment {rgbt < 0.95, 0.95, 1, 1> }
        finish {
            diffuse 0.2
            ambient 0.05
            specular 1.5
            roughness 0.01
            brilliance 0.01
            reflection {
                0,1
                fresnel
            }
        }
        normal { // from a water by Jon S. Brandt.
            bozo
            normal_map {
                [ 0.30 waves   translate -0.5 scale <1, 0.05, 1>*100000 frequency 100000]
                [ 0.70 ripples translate -0.5 scale <1, 0.70, 1>*100000 frequency 100000]
                [ 0.85 ripples translate -0.5 scale <1, 0.60, 1>*100000 frequency 100000]
                [ 1.00 ripples translate -0.5 scale 100000 frequency 100000]
            }
            scale 0.6
        }
    }
    interior { ior 1.33 }
}
