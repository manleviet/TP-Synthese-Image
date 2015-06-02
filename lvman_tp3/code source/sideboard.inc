#include "texture.inc"

// Ba chai ruou
#declare Cork = lathe {
    bezier_spline
    20, //nr points
    /*0*/ <0, 567.00001>, <10, 567.00001>, <10,569.00001>, <21.000001,569.00001>,
    /*1*/ <21.000001, 569.00001>, <23.000001, 569.00001>, <24.000001,568.00001>, <24.000001,566.00001>,
    /*2*/ <24.000001, 566.00001>, <24.000001, 563.95957>, <24.000001,507.00001>, <24.000001,505.00001>,
    /*3*/ <24.000001, 505.00001>, <24.000001, 503.00001>, <23.000223,501.96417>, <21.000001,501.96968>,
    /*4*/ <21.000001, 501.96968>, <10, 502.00001>, <10,504.00001>, <0,504.00001>
    pigment { color MediumWood }
    finish { ambient 0 } 
}

#declare Wine = lathe {
    bezier_spline
    28, //nr points
    /*0*/ <0, 480.00001>, <5.0000001, 480.00001>, <20.000001,480.00001>, <24.000001,480.00001>,
    /*1*/ <24.000001, 480.00001>, <24.000001, 478.00001>, <24.000001,477.00001>, <24.000001,475.00001>,
    /*2*/ <24.000001, 475.00001>, <24.000008, 433.00001>, <36.000001,430.00001>, <50.000001,419.00001>,
    /*3*/ <50.000001, 419.00001>, <65.104684, 407.13205>, <74.000002,394.00001>, <74.000002,370.00001>,
    /*4*/ <74.000002, 370.00001>, <74.000002, 364.79897>, <74.000002,24.999983>, <74.000002,14.999983>,
    /*5*/ <74.000002, 14.999983>, <74.000002, 10.999983>, <70.000002,10.999983>, <65.000002,10.999983>,
    /*6*/ <65.000002, 10.999983>, <41.000001, 10.999983>, <35.000001,45.999983>, <0,45.999983> 
}

#declare Wrapper = lathe {
    bezier_spline
    16, //nr points
    /*0*/ <0, 569.00001>, <6.0000002, 569.00001>, <21.054425,569.34242>, <25.000001,570.00001>,
    /*1*/ <25.000001, 570.00001>, <37.000001, 572.00001>, <35.000001,566.04989>, <35.000001,556.00001>,
    /*2*/ <35.000001, 556.00001>, <35.000001, 548.00001>, <32.000001,550.00001>, <31.000001,541.00001>,
    /*3*/ <31.000001, 541.00001>, <29.026632, 523.23969>, <31.000001,491.00001>, <30.000001,482.00001> 
}

#declare WineBottle = lathe {
    bezier_spline
    60, //nr points
    /*   0*/ <0, 44.999983>, <35.000001, 44.999983>, <40.000001,9.9999826>, <65.000002,9.9999826>,
    /*   1*/ <65.000002, 9.9999826>, <70.000002, 9.9999826>, <75.000002,9.9999826>, <75.000002,14.999983>,
    /*   2*/ <75.000002, 14.999983>, <75.000002, 27.747583>, <75.000002,307.97561>, <75.000002,370.00001>,
    /*   3*/ <75.000002, 370.00001>, <75.000002, 395.00001>, <64.422207,409.18335>, <50.000001,420.00001>,
    /*   4*/ <50.000001, 420.00001>, <30.000001, 435.00001>, <25.000001,440.00001>, <25.000001,475.00001>,
    /*   5*/ <25.000001, 475.00001>, <25.000001, 495.00001>, <25.000001,515.00001>, <25.000001,535.00001>,
    /*   6*/ <25.000001, 535.00001>, <25.000002, 565.00001>, <25.000001,570.00001>, <30.000001,570.00001>,
    /*   7*/ <30.000001, 570.00001>, <35.000001, 570.00001>, <35.000001,566.90336>, <35.000001,560.00001>,
    /*   8*/ <35.000001, 560.00001>, <35.000001, 545.00001>, <30.000001,550.00001>, <30.000001,535.00001>,
    /*   9*/ <30.000001, 535.00001>, <30.000001, 527.50001>, <30.000001,500.00001>, <30.000001,475.00001>,
    /*  10*/ <30.000001, 475.00001>, <30.000001, 450.95578>, <32.111457,438.41642>, <50.000001,425.00001>,
    /*  11*/ <50.000001, 425.00001>, <70.000002, 410.00001>, <80.000002,395.00001>, <80.000002,370.00001>,
    /*  12*/ <80.000002, 370.00001>, <80.000002, 349.99999>, <80.000002,35.495083>, <80.000002,9.9999826>,
    /*  13*/ <80.000002, 9.9999826>, <80.000002, 4.9999826>, <75.000002,-1.7382812e-05>, <70.000002,-1.7382812e-05>,
    /*  14*/ <70.000002, -1.7382812e-05>, <30.000001, -1.7382812e-05>, <30.000001,34.999983>, <0,34.999983> 
}

#declare FullRed = union {
    object {
        WineBottle scale 0.001
        pigment { color rgbf<0.6, 0.75, 0.1, 1> }
        finish { ambient 0 diffuse 0 reflection { 0.2 exponent 0.8 } }
        interior { ior 1.5 }
        photons { target reflection on refraction on collect off } 
    }
    object { Cork scale 0.001 }
    object {
        Wine scale 0.001
        pigment { color rgbf<0.5,0,0,1> }
        finish { ambient 0 diffuse 0 }
        interior { ior 1.33 }
        photons { target reflection on refraction on collect off } 
    }
    object {
        Wrapper scale 0.001
        pigment { color Navy }
        finish { ambient 0 reflection { 0.2 exponent 0.8 } } 
    }
    difference {
        cylinder { <0, 0.1, 0>, <0, 0.3, 0>, 0.0801 }
        cylinder { <0, 0, 0>, <0, 0.4, 0>, 0.08009 }
        plane { <0, 0, -1>, 0 rotate <0, 20, 0> }
        plane { <0, 0, -1>, 0 rotate <0, -20, 0> }
        pigment {
            image_map { jpeg "pictures/label1.jpg" interpolate 2 once }
            scale <7/18, 1, 1>
            warp { cylindrical }
            rotate <0, 160, 0> scale 0.2 translate <0, 0.1, 0> }
        finish { ambient 0 } 
    } 
}
        
#declare FullWhite = union {
    object {
        WineBottle scale 0.001
        pigment { color rgbf<1, 1, 1, 1> }
        finish { ambient 0 diffuse 0 reflection { 0.2 exponent 0.8 } }
        interior { ior 1.5 }
        photons { target reflection on refraction on collect off } 
    }
    object { Cork scale 0.001 }
    object {
        Wine scale 0.001
        pigment { color rgbf<0.9,1,0,1> }
        finish { ambient 0 diffuse 0 }
        interior { ior 1.33 }
        photons { target reflection on refraction on collect off } 
    }
    object {
        Wrapper scale 0.001
        pigment { color Gray10 }
        finish { ambient 0 reflection { 0.2 exponent 0.8 } } 
    }
    difference {
        cylinder { <0, 0.1, 0>, <0, 0.3, 0>, 0.0801 }
        cylinder { <0, 0, 0>, <0, 0.4, 0>, 0.08009 }
        plane { <0, 0, -1>, 0 rotate <0, 20, 0> }
        plane { <0, 0, -1>, 0 rotate <0, -20, 0> }
        pigment {
            image_map { jpeg "pictures/label4.jpg" interpolate 2 once }
            scale <7/18, 1, 1>
            warp { cylindrical }
            rotate <0, 160, 0> scale 0.2 translate <0, 0.1, 0> }
        finish { ambient 0 } 
    } 
}

// --- sideboard ---  
#macro RoundedBox (P0, P1, P2, P3)
    Round_Box(<-P0,-P1,-P2>, <P0, P1, P2>, P3, 0)
#end

#declare SideKnob = union {
    torus { 0.1, 0.02 rotate <90, 0, 0> }
    cylinder { <0, 0, 0.02>, <0, 0, -0.02>, 0.1 }
    #declare a = 0;
    #while (a < 180)
        sphere { <0, 0, 0>, 1 scale <0.02, 0.1, 0.04> rotate <0, 0, a> }
        #declare a = a + 30;
    #end
    cylinder { <0, 0, -0.02>, <0, 0, -0.1>, 0.03 }
    torus { 0.06, 0.02 rotate <90, 0, 0> translate <0, 0, -0.09> }
    sphere { <0, 0, -0.12>, 0.08 }
    #declare a = 0;
    #while (a < 180)
        sphere { <0, 0, 0>, 1 scale <0.02, 0.085, 0.04> translate <0, 0, -0.1> rotate <0, 0, a> }
        #declare a = a + 15;
    #end
    sphere { <0, 0, -0.19>, 0.02 }
    pigment { color Black }
    finish { ambient 0 diffuse 0.4 reflection { 1 } } 
}

#declare SideDoor = union {
    object { RoundedBox(0.11, 0.02, 0.01, 0.001) translate <0, 0.13, 0> texture { Tex_SideWood } }
    object { RoundedBox(0.11, 0.02, 0.01, 0.001) translate <0, -0.13, 0> texture { Tex_SideWood } }
    object { RoundedBox(0.02, 0.13, 0.01, 0.001) translate <-0.09, 0, 0> texture { Tex_SideWood rotate <0, 0, 90> } }
    object { RoundedBox(0.02, 0.13, 0.01, 0.001) translate <0.09, 0, 0> texture { Tex_SideWood rotate <0, 0, 90> } }
    object { Cube scale <0.09, 0.13, 0.005> texture { Tex_SideWood rotate <0, 0, 90> } } 
}

#declare SideDrawer = union {
    object { RoundedBox(0.175, 0.045, 0.01, 0.001) }
    object { SideKnob scale 0.1 translate <0, 0, -0.01> } 
}

#declare SideFoot = union {
    object { RoundedBox(0.02, 0.05, 0.02, 0.001) translate <0, 0.05, 0> }
    object { RoundedBox(0.025, 0.025, 0.025, 0.001) translate <0, 0.025, 0> }
    texture { Tex_SideWood rotate <0, 0, 90> } 
}

#declare Sideboard = union {
    object { RoundedBox(0.5, 0.01, 0.2, 0.001) translate <0, 0.1, 0> texture { Tex_SideWood } }
    object { RoundedBox(0.5, 0.01, 0.2, 0.001) translate <0, 0.4, 0> texture { Tex_SideWood } }
    union {
        object { RoundedBox(0.025, 0.15, 0.025, 0.001) translate <-0.47, 0.25, -0.17> }
        object { RoundedBox(0.025, 0.15, 0.025, 0.001) translate <-0.47, 0.25, 0.17> }
        object { RoundedBox(0.025, 0.15, 0.025, 0.001) translate <0.47, 0.25, -0.17> }
        object { RoundedBox(0.025, 0.15, 0.025, 0.001) translate <0.47, 0.25, 0.17> }
        object { Cube scale <0.02, 0.15, 0.17> translate <-0.47, 0.25, 0> }
        object { Cube scale <0.02, 0.15, 0.17> translate <0.47, 0.25, 0> }
        object { Cube scale <0.47, 0.15, 0.02> translate <0, 0.25, 0.17> }
        object { RoundedBox(0.025, 0.15, 0.025, 0.001) translate <-0.2, 0.25, -0.17> }
        object { RoundedBox(0.025, 0.15, 0.025, 0.001) translate <0.2, 0.25, -0.17> }
        texture { Tex_SideWood rotate <0, 0, 90> } }
    object { SideDoor translate <-0.335, 0.25, -0.18> }
    object { SideDoor translate <0.335, 0.25, -0.18> }
    object { SideKnob scale 0.1 translate <-0.245, 0.25, -0.19> }
    object { SideKnob scale 0.1 translate <0.245, 0.25, -0.19> }
    object { SideDrawer translate <0, 0.11 + 0.28/6, -0.18> texture {  } }
    object { SideDrawer translate <0, 0.25, -0.18> texture { Tex_SideWood } }
    object { SideDrawer translate <0, 0.11 + 5*0.28/6, -0.18> texture { Tex_SideWood } }
    object { SideFoot translate <-0.47, 0, -0.17> }
    object { SideFoot translate <-0.47, 0, 0.17> }
    object { SideFoot translate <0.47, 0, -0.17> }
    object { SideFoot translate <0.47, 0, 0.17> } 
}
 
#declare SideboardObjects = union {
    object { Sideboard }
    object { FullRed scale 0.333 translate <0.23, 0.41, 0.1> }
    object { FullRed scale 0.333 rotate <0, 30, 0> translate <0.17, 0.41, 0.1> }
    object { FullWhite scale 0.333 translate <0.1, 0.41, 0.12> } 
}
