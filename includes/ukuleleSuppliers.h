//
// Created by Natna on 15.04.2017.
//

#ifndef UKULELESUPPLIER_H
#define UKULELESUPPLIER_H

#include "ukuleleFactory.h"

// TODO: Comment code thoroughly
namespace Ui{
    class BodySupplier;

    class NeckSupplier;

    class HeadSupplier;

    class _stringSupplier;
}

class BodySupplier{
private:
    BodySupplier();

public:
    Body getBody(int, int, vector<vector<int>>);
};

class NeckSupplier{
private:
    NeckSupplier();

public:
    Neck getNeck(int, int, vector<int>);
};

class HeadSupplier{
private:
    HeadSupplier();

public:
    Head getHead(int, int, vector<int>);
};

class _stringSupplier{
private:
    _stringSupplier();

public:
    _string getString(int);
};
#endif //UKULELESUPPLIER_H
