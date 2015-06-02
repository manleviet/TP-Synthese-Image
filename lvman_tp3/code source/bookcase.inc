#include "MakeBook"
#include "MakeShelf"
#include "MakeLibrary"
#include "texture.inc"

#declare rd=seed(0); // seed
#declare xLib=1.5; // library width
#declare yLib=4; // library height
#declare zShelf=0.3; // depth of shelves
#declare zLibShelf=0.3; // depth of the side planks (>zShelf)
#declare zLibPanel=0.5; // depth of bottom panels
#declare ePlankShelf=0.025; // thickness of shelf plank
#declare ePlankSide=0.03; // thickness of side plank
#declare ePlankTop=0.06; // thickness of top and main horizontal planks  
#declare yLibPanel=0.8; // height of bottom panel
#declare yPlinth=0.2; // height of bottom plinth
#declare sdyShelf=0.2;  // pseudo standard deviation of shelf height (-sdyShelf*h/2 to +sdShelf*h/2)
#declare xBook=0.08; // Book thickness
#declare sdxBook=0.03;  // pseudo standard deviation of book thickness (-sdxBook*xBook/2 to +sdxBook*xBook/2)
#declare sdyBook=0.08;  // pseudo standard deviation of book height
#declare sdzBook=0.06;  // pseudo standard deviation of book depth
#declare typeShelf=1;     // all different
#declare typeBook=1;     // new books
#declare slackShelf=1;  // some slack

#declare Bookcase = union {
    #declare nShelf = 5; // number of shelves
    #declare nSetMax = 4;     // maximum number of book sets
    #declare slackShelf = 1;  // very slack
    object{mLibrary(xLib*0.9,yLib,zLibShelf,zLibPanel,yLibPanel,yPlinth,nShelf,sdyShelf,ePlankShelf,xBook,sdxBook,sdyBook,sdzBook,typeShelf,typeBook,slackShelf,nSetMax,true,Tex_Wood)}
    
    #declare nShelf=5;
    #declare nSetMax=2;
    #declare slackShelf=2;  // lot of slack
    object{mLibrary(xLib*1.2,yLib,zLibShelf,zLibPanel,yLibPanel,yPlinth,nShelf,sdyShelf,ePlankShelf,xBook,sdxBook,sdyBook,sdzBook,typeShelf,typeBook,slackShelf,nSetMax,true,Tex_Wood) translate x*0.9*xLib}
    
    #declare nShelf=5;
    #declare nSetMax=3;
    #declare slackShelf=0.5;  // almost no slack
    object{mLibrary(xLib*1.3,yLib,zLibShelf,zLibPanel,yLibPanel,yPlinth,nShelf,sdyShelf,ePlankShelf,xBook,sdxBook,sdyBook,sdzBook,typeShelf,typeBook,slackShelf,nSetMax,true,Tex_Wood) translate x*2.1*xLib}
    
    texture{Tex_Wood}        
}

