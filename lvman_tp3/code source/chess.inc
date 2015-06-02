#include "chesspiece.inc"

// chessboard
#declare Chess = union {
    height_field {
        function 256, 256 {
            pigment {
                checker
                color rgb 1
                color rgb 0
                scale 1/8
            }
        }
        smooth
        translate <-0.5, 0.0,-0.5>
        scale < 12,-0.5, 12>
        rotate < 0, 270, 0>
        texture {Tex_ChessGlass}
        interior { ior 1.2 }
        
        photons {
            target
            reflection on
            refraction off
        }
    }

    union {
        difference {
            box {<-7,-0.25,-7>, < 7,-0.001, 7>}
            box {<-6,-0.30,-6>, < 6, 0, 6>}
            pigment {rgb < 0, 0, 0.5>}
        }
        box {
            <-6,-0.2,-6>, < 6,-0.501, 6>
            texture {
                pigment {
                    checker color rgb 1 color rgb < 0, 0, 1>
                    scale 1.5
                    translate < 1.5, 0, 0>
                }
            }
        }
        no_shadow
    }
    // end chessboard

    // The pieces
    difference {
        superellipsoid {
            < 0.05, 0.05>
            translate < 0, 1, 0>
            scale < 0.5, 0.9, 0.5>
            pigment {rgbf 0.9}
            texture {Glass}
            interior {
                ior 1.5
                fade_distance 2
                fade_power 2
            } 
        }
        object {
            Paard
            rotate < 0,-90, 0>
            texture{Tex_ChessPiece}
        }        
        photons {
            target
            reflection on
            refraction off
        }
        no_shadow
        rotate < 0, 68, 0>
        translate < 2.2*1.5, 0, -3.5*1.5>
    }

    difference {
        superellipsoid {
            < 0.05, 0.05>
            translate < 0, 1, 0>
            scale < 0.5, 0.9, 0.5>
            texture {Glass}
            interior {
                ior 1.5
                fade_distance 2
                fade_power 2
            }
        }
        object {
            Loper
            texture{Tex_ChessPiece}
        }
        photons {
            target
            reflection on
            refraction off
        }
        no_shadow
        translate < 1.5*1.5, 0,-1.5>
    }

    difference {
        superellipsoid {
            < 0.05, 0.05>
            translate < 0, 1, 0>
            scale < 0.5, 0.75, 0.5>
            texture {Tex_ChessGlass}
            interior {
                ior 1.5
                fade_distance 2
                fade_power 2
            }
        }
        object {
            Toren
            texture{Tex_ChessPiece}
        }
        photons {
            target
            reflection on
            refraction off
        }
        no_shadow
        translate < 3.5*1.5, 0,-3.5*1.5>
    }
    // end pieces
}