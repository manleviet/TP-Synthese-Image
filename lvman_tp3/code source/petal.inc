
// $Header: /home/bmh/irtc/still3/RCS/petal.inc,v 1.4 2005/08/05 06:36:12 bmh Exp $

// approx scale 1 pov unit 1 cm

#declare cb1=<-1.4,-4.2,-0.3>;
#declare cb2=<0.9,0.2,0.3>;

#declare xcurl=0.05;	//0.05;	// +ve curl down
#declare zcurl=0.3; //0.3;	// +ve curl down 
#declare xtwist=0.2;	//0.2;
#declare zridge=0.0;
#declare pat=0;

#declare th=0.025;

#declare f3=
function
{
	max((x*x+z*z*16),abs(y/th)) -1
}

#declare f4=
function
{
	f_torus(x,y,z*4,1,th)
}

	// rounded cylinder (merge of torus and cylinder)
#declare f5=
function
{
	min(f3(x,y,z),f4(x,y,z))
}

#declare f6=
function
{
	12-10*cos(x+0.1)
}

	// twist along x axis
#declare xtfunc=
function(x,y,z,xt)
{
	z*x*xt
}

	// curl along the x axis
#declare xcfunc=
function(x,y,z,xc)
{
	clip((x+1)*(x+1)*(x+1),0,10)*xc
}

	// curl along the z axis
#declare zcfunc=
function(x,y,z,zc)
{
	z*z*zc
}

	// ridges along the z axis
#declare zrfunc =
function(x,y,z,p)
{
//	cos(f6(x,y,z)*z*20+f_snoise3d(x*2,p,z*2)*3)/100
	f_snoise3d(f6(x,y,z)*z*3+f_snoise3d(x*2,p,z*2)*1,p*10,x)/35
}

#macro petal(pat,xc,xt,zc,mg)
//union
//{
isosurface
{
	function
	{
		f5
		(
			x+x*x/5,
			y
				+xcfunc(x,y,z,xc)
				+xtfunc(x,y,z,xt)
				+zcfunc(x,y,z,zc)
				+zrfunc(x,y,z,pat)
				+f_snoise3d(x*2,pat,z*5)/6
				,
			z
		)
	}
	contained_by{box {cb1,cb2}}
//#if(detail=2)
	max_gradient 200
//#else
//	evaluate 70, 1.3, 0.7
//#end
	accuracy 0.00001
//}
//box{cb1 cb2 pigment {rgbf <1,0.8,0.8,0.8>}}
	scale <1,0.1,0.8>
	translate <1.5,0,0>
}
#end

#declare test=
intersection
{
	object{petal(1,xcurl,xtwist,zcurl,80) pigment {Green}}
	box{<-2,-2,0><2,2,2> pigment {Red} rotate <0,-45,0>}
}
