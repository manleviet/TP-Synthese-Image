#include "texture.inc"

#declare TableLeg = union {
    cone { // Cone001
        <0,0,0>, 0.2, <0,0,1>, 0.25
        scale <1.0, 1.0, 9.8>
        translate  0.1*z
    }
    cone { // Cone002
        <0,0,0>, 0.3, <0,0,1>, 0.2752
        scale <1.0, 1.0, 0.5>
    }
    cone { // Cone003
        <0,0,0>, 0.3, <0,0,1>, 0.4
        scale <1.0, 1.0, 0.5>
        translate  9.5*z
    }
    rotate <5.0, 5.0, 0.0>
    translate  <-9.5, 6.0, -10.0>
}

#declare CSG001 = union {
    sphere { // Sphere012
        <0,0,0>,1
        scale 0.25
        translate <9.996616, 6.668411, 0.0>
    }
    cylinder { // Cylndr003
        <0,0,1>, <0,0,0>, 1 
        scale <0.25, 0.25, 20.0>
        rotate -90.0*y
        translate  <10.0, -6.666666, 0.0>
    }
    cylinder { // Cylndr004
        <0,0,1>, <0,0,0>, 1 
        scale <0.25, 0.25, 20.0>
        rotate -90.0*y
        translate <10.0, 6.66667, 0.0>
    }
    cylinder { // Cylndr005
        <0,0,1>, <0,0,0>, 1 
        scale <0.25, 0.25, 13.3333>
        rotate <-90.0, -90.0, 0.0>
        translate <10.0, -6.666666, 0.0>
    }
    cylinder { // Cylndr006
        <0,0,1>, <0,0,0>, 1 
        scale <0.25, 0.25, 13.33333>
        rotate <-90.0, -90.0, 0.0>
        translate <-10.0, -6.666666, 0.0>
    }
    sphere { // Sphere013
        <0,0,0>,1
        scale 0.25
        translate <9.996616, -6.66841, 0.0>
    }
    sphere { // Sphere014
        <0,0,0>,1
        scale 0.25
        translate <-9.99662, 6.668411, 0.0>
    }
    sphere { // Sphere015
        <0,0,0>,1
        scale 0.25
        translate <-9.99662, -6.66841, 0.0>
    }
    material {
        Mat_Glaze
    }
}

#declare Table = union { // mesa
    box { // mesa_up
        <-1, -1, -1>, <1, 1, 1>
        material {
            ParquetWood
        }
        
        photons {
            target
            reflection on
            refraction off
        }
        
        scale <10.0, 6.666666, 0.25>
    }
    object { CSG001 }
    object { TableLeg }
    object { // patamesa2 -> patamesa1
        TableLeg
        scale -1.0
        rotate <180.0, -0.0, -0.0>
    }
    object { // patamesa3 -> patamesa1
        TableLeg
        scale -1.0
        rotate <-180.0, 0.0, 180.0>
    }
    object { // patamesa4 -> patamesa1
        TableLeg
        rotate <0.0, 0.0, 180.0>
    }
    cylinder { // Cylndr001
        <0,0,1>, <0,0,0>, 1 
        scale <0.5, 0.1, 17.5>
        rotate <-90.0, -84.585739, 90.0>
        translate  <8.744163, -5.251681, -1.0>
    }
    cylinder { // Cylndr008
        <0,0,1>, <0,0,0>, 1 
        scale <0.5, 0.1, 10.5>
        rotate <90.0, -85.414261, 0.0>
        translate  <-8.74416, 5.25168, -1.0>
    }
    cylinder { // Cylndr007
        <0,0,1>, <0,0,0>, 1 
        scale <0.5, 0.1, 10.5>
        rotate <-90.0, -84.585739, 180.0>
        translate  <8.744163, 5.25168, -1.0>
    }
    cylinder { // Cylndr002
        <0,0,1>, <0,0,0>, 1 
        scale <0.5, 0.1, 17.5>
        rotate <-90.0, -84.585739, 90.0>
        translate  <8.744163, 5.25168, -1.0>
    }
    material {
        Mat_Glaze
    }
    rotate x*-90
    scale <0.05, 0.05, 0.05>
}