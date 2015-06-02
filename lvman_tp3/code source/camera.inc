//
//
// camera.inc
// 
// Dinh nghia cac camera
//
// LE Viet Man
// 28/01/2011
//
//

// 0 - goc chinh thu nhat
#declare Camera0 = camera {
    location    <-1, 1.1, 2>
    look_at     <-3, 0.8, 3>
    right       x*image_width/image_height
    angle       100   
}

// 1 - nhin tam hinh
#declare Camera1 = camera {
    location    <-1, 1.8, 2.8>
    look_at     <-3 + 0.007, 3 - 1.5, 3 - 0.9>
    right       x*image_width/image_height
    angle       40
}

// 2 - nhin bong hoa va ly ruou
#declare Camera2 = camera {
    location    <-1, 1.1, 2>
    look_at     <-3, 0.8, 3>
    right       x*image_width/image_height
    angle       40
}

// 3 - nhin bong hoa va ly ruou voi focal bur
#declare Camera3 = camera {
    location    <-1, 1.1, 2>
    look_at     <-3, 0.8, 3>
    right       x*image_width/image_height
    angle       40
    
    focal_point <-2.8, 1, 3>    // pink sphere in focus
    aperture 0.4     // a nice compromise
    blur_samples 8//20
}

// 4 - nhin cay den cay
#declare Camera4 = camera {
    location    <-1, 1.1, 2>
    look_at     <-3 + 0.52, 0.75, 3 - 1.3>
    right       x*image_width/image_height
    angle       40
}

// 5 - goc nhin chinh thu hai
#declare Camera5 = camera {
    location <0.7, 0.7, -0.7>
    look_at <4, 0.3, -4>
    right       x*image_width/image_height
    angle       90
} 

// 6 - nhin ban co
#declare Camera6 = camera {
    location <0.7, 0.7, -0.7>
    look_at <1.7, 0.3, -1.7>
    right       x*image_width/image_height
    angle       40
}

// 7 - nhin tu giua phong ve goc chinh thu nhat
#declare Camera7 = camera {
    location    <0, 1.1, 0>
    look_at     <-3, 0.8, 3>
    right       x*image_width/image_height
    angle       100   
}

// 8 - nhin tu giua phong ve goc chinh thu hai
#declare Camera7 = camera {
    location    <0, 1.1, 0>
    look_at     <4, 0.3, -4>
    right       x*image_width/image_height
    angle       100   
}

