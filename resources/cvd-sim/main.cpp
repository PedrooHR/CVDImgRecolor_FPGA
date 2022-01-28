#include <iostream>
#include <CImg.h>
#include <vector>
#include <string>

float Proto[3][3] = {{0.152286, 1.052583, -0.204868}, 
                    {0.114503, 0.786281, 0.099216}, 
                    {-0.003882, -0.048116, 1.051998}};

float Deuto[3][3] = {{0.367322, 0.860646, -0.227968}, 
                    {0.280085, 0.672501, 0.047413}, 
                    {-0.011820, 0.042940, 0.968881}};

float Trito[3][3] = {{1.255528, -0.076749, -0.178779}, 
                    {-0.078411, 0.930809, 0.147602}, 
                    {0.004733, 0.691367	, 0.303900}};


int main(){
    std::string imgPath;

    while(std::cin >> imgPath){

        cimg_library::CImg<unsigned int> image(("../imgs/" + imgPath + ".jpg").c_str());
        cimg_library::CImg<float> img_deuto(image.width(), image.height(), 1, 3, 0);
        cimg_library::CImg<float> img_proto(image.width(), image.height(), 1, 3, 0);
        cimg_library::CImg<float> img_trito(image.width(), image.height(), 1, 3, 0);


        cimg_forXY(image,x,y) {
            img_deuto(x,y, 0) = Deuto[0][0]*image(x,y,0) + Deuto[0][1] * image(x,y,1) + Deuto[0][2]*image(x,y,2);
            img_deuto(x,y, 1) = Deuto[1][0]*image(x,y,0) + Deuto[1][1] * image(x,y,1) + Deuto[1][2]*image(x,y,2);
            img_deuto(x,y, 2) = Deuto[2][0]*image(x,y,0) + Deuto[2][1] * image(x,y,1) + Deuto[2][2]*image(x,y,2);

            img_proto(x,y, 0) = Proto[0][0]*image(x,y,0) + Proto[0][1] * image(x,y,1) + Proto[0][2]*image(x,y,2);
            img_proto(x,y, 1) = Proto[1][0]*image(x,y,0) + Proto[1][1] * image(x,y,1) + Proto[1][2]*image(x,y,2);
            img_proto(x,y, 2) = Proto[2][0]*image(x,y,0) + Proto[2][1] * image(x,y,1) + Proto[2][2]*image(x,y,2);

            img_trito(x,y, 0) = Trito[0][0]*image(x,y,0) + Trito[0][1] * image(x,y,1) + Trito[0][2]*image(x,y,2);
            img_trito(x,y, 1) = Trito[1][0]*image(x,y,0) + Trito[1][1] * image(x,y,1) + Trito[1][2]*image(x,y,2);
            img_trito(x,y, 2) = Trito[2][0]*image(x,y,0) + Trito[2][1] * image(x,y,1) + Trito[2][2]*image(x,y,2);
        };

        img_deuto.normalize(0, 255);
        img_proto.normalize(0, 255);
        img_trito.normalize(0, 255);
        
        img_deuto.save_jpeg((imgPath + "_deuto.jpg").c_str(), 100);
        img_proto.save_jpeg((imgPath + "_proto.jpg").c_str(), 100);
        img_trito.save_jpeg((imgPath + "_trito.jpg").c_str(), 100);
        std::cout << imgPath << " done..." << std::endl;
    }


    return 0;
}