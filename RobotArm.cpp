//
// Created by obin1000 on 10-09-19.
//
#include <iostream>
#include "RobotArm.h"

RobotArm::RobotArm() {
    // Create size number of arm segment with default values
    arm.push_back(new ArmSegment(nullptr,10,10,0,360));
    arm.push_back(new ArmSegment(arm[0],10,10,0,360));
    arm.push_back(new ArmSegment(arm[1],10,10,0,360));
}

void RobotArm::printArm() {
    for (auto & i : arm) {
        i->print();
    }
    std::cout << " \t\tHandLocation X: " << getGrijperX() << " Y: " << getGrijperY() << std::endl;
}

ArmSegment * RobotArm::getSegmentAt(int segment) {
    if(segment > arm.size()-1){
        return nullptr;
    }
    return arm[segment];
}

double RobotArm::getGrijperX() {
    return getSegmentAt((int) arm.size()-1)->getX();
}

double RobotArm::getGrijperY() {
    return getSegmentAt((int) arm.size()-1)->getY();
}

void RobotArm::grabAt(std::vector<double> grabLocation, double marginOfError) {
    std::cout << "Ik ga je pakken ;) ... als je op " << grabLocation[0] << " " << grabLocation[1] << " bent" << std::endl;
    double error = 999999;
    int loops = 0;
    int currentSegment = (int) arm.size()-1;
    ArmSegment * tempSeg;
    std::vector<double> vectorHand;
    printArm();
    // Loop till the arm reaches an acceptable distance from the target
    while(true){
        if (loops++ == 100) break;
        while(currentSegment >= 0) {
            arm[currentSegment]->rotateTo(grabLocation,getGrijperX(),getGrijperY());
            currentSegment--;
            printArm();
        }
        currentSegment = arm.size()-1;
        error = getError(getGrijperX(),getGrijperY(),grabLocation[0],grabLocation[1]);

    }

    std::cout << "HAHAHA Hebbes!! " << getGrijperX() << " " << getGrijperY();

}

double RobotArm::getError(double handX, double handY, double targetX, double targetY) {
    return (double) (handX - targetX) + (handY - targetY);
}
