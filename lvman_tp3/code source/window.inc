#include "texture.inc"

#macro Window_Frame (OW, OH, IW, IH, D, FTex, GTex, Cent, Orient, ifbars, ifglass)
    #local mol_pc = prism {
	    cubic_spline
	    -.5,.5,19,
	    <0.864606,0.006176>,
	    <1.019000,0.006176>,
	    <1.080757,0.037055>,
	    <1.080757,0.253206>,
	    <1.019000,0.314964>,
	    <0.988121,0.500236>,
	    <0.988121,0.654630>,
	    <0.988121,0.778145>,
	    <0.957242,0.839903>,
	    <0.957242,0.963418>,
	    <0.926364,0.994297>,
	    <0.833727,0.994297>,
    	<0.833727,0.932539>,
    	<0.833727,0.747267>,
    	<0.833727,0.438479>,
    	<0.833727,0.067933>,
    	<0.864606,0.006176>,
    	<1.019000,0.006176>,
    	<1.080757,0.037055>
    }  

    #local mol = object { 
        mol_pc 
        scale <(OH-IH)/2,1,(OH-IH)/2> 
        rotate -90*x 
        rotate 90*y 
        rotate 180*z 
        translate <0,(OH-IH)/2,2.1> 
    }
    
    #local frame = union {
        box { <-.5,0,0> <.5,.5,D> translate .008*y}
        box { <-.5,0,D/2+.5> <.5,-1,D/2-.5> }
        object { mol }
    } 
       
    #local fortyfive_deg_cut = box { <0,0,1> <20,20,-6> rotate -45*z }
  
    #local frame_top = difference {
        object { frame scale <OW,1,1> translate ((IH/2)+.02)*y }
        object { fortyfive_deg_cut rotate 180*z translate <-IW/2,IH/2+.02,0> }
        object { fortyfive_deg_cut translate <IW/2,IH/2+.02,0> }
    }
          
    #local frame_bottom = object { frame_top scale <1,-1,1> }
  
    #local frame_right = difference {
        object { frame rotate -90*z scale <1,OH,1> translate ((IW/2)+.02)*x }
        object { fortyfive_deg_cut rotate -90*z translate <IW/2+.02,-IH/2,0> } 
        object { fortyfive_deg_cut rotate 90*z translate <IW/2+.02,IH/2,0> } 
    }

    #local frame_left = object { frame_right scale <-1,1,1> }
  
    #local frame_t= union {
        object { frame_top }
        object { frame_bottom }
        object { frame_right }
        object { frame_left } 
    }
   
    #local bar = union {
        box { <-.5,-.5,-3/16> <.5,.5,3/16> }
        cylinder { <-.5,0,-.2> <.5,0,-.2>, .3 }
        cylinder { <-.5,0,.2> <.5,0,.2>, .3 }
    }
  
    #local frame_all = difference   {
        union {
            object { frame_t }
            object { bar scale <(IW-.05),1,1> translate <0,0,D/2> }
            object { bar rotate 90*z scale <1,(IH-.05),1> translate <0,0,D/2> }
        }
        box { <-OW/2,-OH/2,D/2-.13> <OW/2,OH/2,D/2+.13>}
    }

    union {  
        object { frame_all texture { FTex } rotate Orient*y translate Cent } 
  
        #if (ifglass = true)
            box { 
                <-IW/2+.25,-IH/2+.25,-.125> <IW/2+.25,IH/2+.25,.125>
                hollow
                interior {
                    //ior 1.5 
                    media { 
                        scattering{ 1, 0.17 extinction 0.01}
                        samples 100, 500
                    }
                }
                
                photons {
                    pass_through
                }
                
                texture { GTex }
                
                translate D/2*z 
                rotate Orient*y 
                translate Cent 
            }
        #end
    }      
#end

#macro Window (haveGlass)
    union {
        object { Window_Frame(52, 40, 47, 35, 6, Tex_Molding, Tex_Glass, <-15, 50/12+1.5, 0> * 12, 0, true, haveGlass) }
        superellipsoid { 
            <.05,.1>
            texture{ Tex_Molding }
             
            scale <24, .25, 2.5> 
            translate <-15, 50.5/12, -.2> * 12 
        }    
    }
#end