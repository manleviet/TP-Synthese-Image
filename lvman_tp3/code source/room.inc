#include "texture.inc"

// the room
#macro Room(Room_Height, Room_Width, Wall_Deep, Atmospheric) 
    union {
        // walls and ceiling
        difference{ 
            box { 
                <-Room_Width - Wall_Deep, .0, -Room_Width - Wall_Deep>,
                < Room_Width + Wall_Deep, Room_Height + Wall_Deep, Room_Width + Wall_Deep>   
                hollow 
                texture { Tex_Walls }
                no_shadow 
            }
            box { 
                <-Room_Width, .0, -Room_Width>,
                < Room_Width, Room_Height,  Room_Width>   
                hollow 
                texture { Tex_Walls }
                no_shadow 
            }
        
            // the door hole
            box { 
                <-.5, .0, -.01>,
                <.5, 2.0,  Wall_Deep + .01>   
                texture { Tex_Walls }
                no_shadow
     
                translate<-1.5, 0, -Room_Width - Wall_Deep> 
            }
        
            // the window hole
            box { 
                <-1.0, .8, -.01>,
                <1.0, 2.0,  Wall_Deep + .01>   
                texture { Tex_Walls }
                no_shadow
     
                translate<-1.5, 0, Room_Width> 
            }
        
        }
        
        #if (Atmospheric = on)
            box { 
                <-Room_Width, .0, -Room_Width>,
                < Room_Width, Room_Height,  Room_Width>
                pigment { rgbt 1 } 
                hollow
                interior {
                    media {
                        scattering { 1, 0.17 extinction 0.01 }
                        samples 100, 500
                    } 
                }

				photons {
					pass_through
				}
            }
        #end
            
        // floor
        box { 
            <-Room_Width - Wall_Deep, .0, -Room_Width - Wall_Deep>,
            <Room_Width + Wall_Deep, .001, Room_Width + Wall_Deep>   
            hollow 
            texture { Tex_Floor }
            
            photons {
                target
                reflection on
                refraction off
            }  
        }
    }
#end
