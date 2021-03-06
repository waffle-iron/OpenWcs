//
//  Picture.cpp
//  terminal/src
//
//  Created by Konstantin Papesh and Lorenz Kofler.
//  Copyright 2016 OpenWcs.
//
//  Distributed under the Apache License, Version 2.0.
//  See the accompanying file LICENSE or http://www.apache.org/licenses/LICENSE-2.0.html
//


#include "opencv2/opencv.hpp"
#include "Poco/Exception.h"

#include "Overlay.h"
#include "Picture.h"
#include "DateTimeString.h"

Picture::Picture() //initializes the camera
{

    _cap  = 0; // open the default camera TODO: Choose Camera...
    if(!_cap.isOpened())
    {
        throw Poco::ApplicationException("Camera could not be opened!");
    }
}

void Picture::snap() //makes a photo
{
    echoIfVerbose("Snapping picture...");
    _cap >> _frame;
}

void Picture::echoIfVerbose(std::string msg)
{
    if (verbose) {
        std::cout << msg << std::endl;
    }
}

void Picture::save(std::string path, std::string name) //saves the picture
{
    std::string imagename;
    if(_frame.empty())
        throw Poco::LogicException("Frame is empty!");

    if (name.empty()) {
        DateTimeString dateTimeString;
        name = dateTimeString.getISO(true, true);
        imagename = path + "IMG_" + name + ".jpg";
    }
    else{
        imagename = path + name + ".jpg";
    }
    imwrite(imagename, _frame);
    echoIfVerbose("Saved " + name + " to " + path + " successfully!");
}

void Picture::displayDate() //enables displaying the date on the picture
{
    Overlay overlay;
    overlay.putDateOnPicture(_frame);
}

void Picture::setVerbose(bool verbose) //Echos steps to the console
{
    this->verbose = verbose;
}

cv::Mat Picture::get() 
{
    return _frame;
}







