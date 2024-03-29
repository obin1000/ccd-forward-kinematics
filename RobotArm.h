//
// Created by obin1000 on 10-09-19.
//

#ifndef WEEK_1_ROBOTARM_H
#define WEEK_1_ROBOTARM_H


#include <vector>
#include "ArmSegment.h"

class RobotArm {
private:
    // Use vector as array
    std::vector<ArmSegment *> arm;

public:
    RobotArm();
    void printArm();
    ArmSegment * getSegmentAt(int segment);
    double getGrijperX();
    double getGrijperY();
    void grabAt(double grabX, double grabY, double marginOfError);
    double getError(double handX, double handY, double targetX, double targetY);

};


#endif //WEEK_1_ROBOTARM_H
