// POV-Ray 3.6/3.7  include file "Candle_2.inc"                                                                                                                                                // PoVRay 3.6 include File "wheel_000.inc"
// author: Friedrich A, Lohmueller, Oct-2008
// homepage: http://www.f-lohmueller.de/
// email: Friedrich.Lohmueller_aT_t-online.de
//----------------------------------------------------------------------------------------
#include "texture.inc"

#macro Candle ( ShiningOn,  // Light on
                  FlameShadow, // 1 = on ; 0 = off
                  C_Height,    // Candle_Height,
                  C_Intensity, // Candle_Intensity,
                  C_Scale,      // Candle_Flame_Scale
                  Fade_Distance, //  3 ~ 5
                  Fade_Power //   2,3,4
                )
    #local D = 0.00001;
    
    #local Flame_Shape = merge { // egg
        intersection {
            sphere { <0, 0, 0>, 1 }  
            box { <-1, -D, -1>, < 1, 1, 1> }
            scale <1, 2.5, 1> 
        }
        intersection {
            sphere { <0, 0, 0>, 1 }  
            box { <-1, -1, -1>, <1, 0+0.01, 1> }
        }
    }
    
    #local C_Flame = object {
        Flame_Shape
        hollow
        #if( FlameShadow = 0)
            no_shadow
        #end
        pigment { color rgbf <1, 1, 1, 1> } // fully transparent
        finish { ambient 0 diffuse 0 }
        interior {
            media {
                #if( FlameShadow > 0)
                    absorption rgb <0.51, 0.85, 0.95> * 5 * FlameShadow
                #end
                emission color rgb <1.0, 0.85, 0.1> * 2.75 * C_Intensity
                intervals 9 * 1 / C_Scale
                samples 5, 20
                confidence 0.9999
                variance 1 / 100
                density { 
                    spherical
                    ramp_wave
                    turbulence 0.15
                    color_map {
                        [0.0 color rgb <0.0, 0.0, 0.0>]
                        [0.6 color rgb <0.8, 0.3, 0.0>]
                        [0.9 color rgb <1.0, 0.8, 0.3>]
                        [1.0 color rgb <1.0, 1.0, 0.1>]
                    }
                    scale <1, 2.5, 1>
                } // end density
            }//end of media

            media {
                emission color rgb <1.0, 0.8, 0.1> * 2.75 * C_Intensity
                intervals 5
                samples 30,50
                method 3
                aa_threshold 0.1 aa_level 5
                density { 
                    crackle  
                    turbulence 0.3
                    scale 1.75 
                    translate <0, 14, 0>
                    color_map {
                        [0.00 rgb 0]
                        [0.07 rgb 1]
                        [0.10 rgb 1]
                        [0.12 rgb 0]
                        [1.00 rgb 0]
                    }
                } // end density
                density { 
                    spherical
                    color_map {
                        [0 rgb 0]
                        [0.7 rgb 1]
                        [1 rgb 1]
                    }
                } // end density
                scale <1, 1.5, 1> * 0.5
                translate <0, 0.01, 0>
            }// end media
        }//end of interior
        scale <1, 1.5, 1> * 0.5
    }

    #local C_Candle = union {
        difference {
            union {
                object { Round_Cylinder ( <0, 0, 0>, <0, C_Height+0.02, 0>, 0.5, 0.02, 0) }
                sphere { 
                    <0, 0, 0>, 0.5  
                    scale <1, 0.35, 1>  
                    translate <0, C_Height, 0> 
                }
                texture { Tex_Candle }

            }
            sphere {
                <0,0,0>, 0.455 
                scale <1, 0.5, 1> 
                translate <0, C_Height+0.05, 0>
                texture { Tex_Candle_Wax_Liquid }
            }
        }

        // wax lake
        cylinder { 
            <0, 0, 0>, <0, C_Height-0.075, 0>, 0.45
            texture{ Tex_Candle_Wax_Liquid }
        }
 
        // wick - Docht
        union {
            cylinder {
                <0, -0.5, 0>, <0, 0.10, 0>, 0.05 
                pigment{ rgb 0 } 
            }
            cylinder {
                <0, 0.1, 0>, <0, 0.25, 0>, 0.05 
                pigment { rgb <1, 0.2, 0.1> * 1.3 }
            }
            scale C_Scale
            translate <0, C_Height, 0>
        }
    }

    union {
        object { C_Candle }
        
        // shining of the flame
        #if(ShiningOn>0)
            object { 
                C_Flame 
                translate <0, 0.5, 0> 
                scale 0.75
                scale C_Scale  
                translate <0, C_Height+0.15, 0> 
            }
            light_source { 
                <0,0,0>
                color rgb <0.8, 0.3, 0.0> * 0.5 * ShiningOn
                area_light // kind of light source (Art der Lichtquelle)
                <-0.25, -0.25, 0> <0.25, 0.5, 0> // lights spread out across this distance (x * z)
                4, 15                // total number of lights in grid (4x*4z = 16 lights)
                adaptive 1          // 0,1,2,3...
                //jitter              // adds random softening of light
                translate <0, C_Height+0.25+0.350, 0>
                fade_distance Fade_Distance  // 3
                fade_power Fade_Power // 4
                
                media_interaction off
                
                photons {
                    reflection off
                    refraction on
                }
            }

            /*light_source { 
                <0, 0, 0>
                color rgb <0.8, 0.3, 0.0> * 0.5 * Shining__On
                area_light            // kind of light source (Art der Lichtquelle)
                <0, -0.25,-0.25> <0, 0.5, 0.25> // lights spread out across this distance (x * z)
                4, 15                // total number of lights in grid (4x*4z = 16 lights)
                adaptive 1          // 0,1,2,3...
                //jitter              // adds random softening of light
                translate <0, C_Height+0.25+0.350, 0>
                fade_distance  Fade_Distance  // 3
                fade_power Fade_Power // 4
                photons {
                    reflection off
                    refraction on
                }
            }*/
        #end
    }
#end