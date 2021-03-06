//
// Created by lijiahao on 9/10/16.
//

#ifndef CA_CELLCAR_H
#define CA_CELLCAR_H

// Absolute Direction

enum { FORWARD, BACK, LEFT, RIGHT };

// Relative Direction

enum RelativeDir { GOAHEAD, GOLEFT, GORIGHT, WAIT };

#define CONGESTGAP 5
/***************/
//#define SAFEGAP 1
//#define SPEEDLIMIT 100
//#define ACC 2.0
/***************/
#include <vector>
#include "settings.h"
#include "cell.h"
#include "cellblock.h"

class CellCar : public Cell {
    double speed;
    int _dir;
    double tgx, tgy;
    RelativeDir status;

    void turn(int direction);
    void syncSpeed(std::vector<CellCar>::const_iterator oldbegin, std::vector<CellCar>::const_iterator oldend,
                   std::vector<CellBlock>::const_iterator cbbegin, std::vector<CellBlock>::const_iterator cbend);
    RelativeDir lineJudge(std::vector<CellCar>::const_iterator oldbegin, std::vector<CellCar>::const_iterator oldend,
                          std::vector<CellBlock>::const_iterator cbbegin, std::vector<CellBlock>::const_iterator cbend,
                          int lcnt, int rcnt, int mcnt, char mgc);
    RelativeDir lineJudge(std::vector<CellCar>::const_iterator oldbegin, std::vector<CellCar>::const_iterator oldend,
                          char type);
    void crab();

public:
    CellCar(int x, int y, Settings &s);
    CellCar(int x, int y, double speed, Settings &s);
    int SAFEGAP;
    int SPEEDLIMIT;
    double ACC;
    int FPS;

    void moveOn(std::vector<CellCar>::const_iterator oldbegin, std::vector<CellCar>::const_iterator oldend,
                std::vector<CellBlock>::const_iterator cbbegin, std::vector<CellBlock>::const_iterator cbend);

    void turn();

    const double getSpeed() const ;
};

#endif //CA_CELLCAR_H
