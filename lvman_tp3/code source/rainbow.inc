// rainbow  
#declare r_violet1 = color rgbf <1.0, 0.5, 1.0, 1.0>;
#declare r_violet2 = color rgbf <1.0, 0.5, 1.0, 0.8>;
#declare r_indigo  = color rgbf <0.5, 0.5, 1.0, 0.8>;
#declare r_blue    = color rgbf <0.2, 0.2, 1.0, 0.8>;
#declare r_cyan    = color rgbf <0.2, 1.0, 1.0, 0.8>;
#declare r_green   = color rgbf <0.2, 1.0, 0.2, 0.8>;
#declare r_yellow  = color rgbf <1.0, 1.0, 0.2, 0.8>;
#declare r_orange  = color rgbf <1.0, 0.5, 0.2, 0.8>;
#declare r_red1    = color rgbf <1.0, 0.2, 0.2, 0.8>;
#declare r_red2    = color rgbf <1.0, 0.2, 0.2, 1.0>;

rainbow {
    angle 35//42.5
    width 5
    arc_angle 100//120
    falloff_angle 30
    distance 1.0e7
    direction <-0.2, -0.2, 1>
    jitter 0.01
    color_map {
        [0.000 color r_violet1 transmit 0.98]
        [0.100 color r_violet2 transmit 0.96]
        [0.214 color r_indigo  transmit 0.94]
        [0.328 color r_blue    transmit 0.92]
        [0.442 color r_cyan    transmit 0.90]
        [0.556 color r_green   transmit 0.92]
        [0.670 color r_yellow  transmit 0.94]
        [0.784 color r_orange  transmit 0.96]
        [0.900 color r_red1    transmit 0.98]
    }
}