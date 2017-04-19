//
// Created by Natna on 15.04.2017.
//

#ifndef UKULELESUPPLIER_H
#define UKULELESUPPLIER_H

#include <cstdio>
#include <vector>
#include <math.h>
#include <list>

using namespace std;

/*
 * @class _circle
 * @brief A circle constructor class
 * */
class _circle {
public:
    _circle(double r, vector<int> p) : radius(r), center(p) {};

    ~_circle();

    vector<int> center;
private:
    double radius;
};

/*
 * @class _rectangle
 * @brief A rectangle constructor class
 * */
class _rectangle {
public:
    _rectangle(int w, int h) : width(w), height(h) {};

    ~_rectangle();

private:
    int width;
    int height;
};

/*
 * @class _cylinder
 * @brief A cylinder constructor class
 * */
class _cylinder {
public:
    _cylinder(float rad, int len) : radius(rad), length(len) {};

    ~_cylinder();

private:
    float radius;
    int length;

};


/*
 * @class Body
 * @brief A ukulele body component
 * */
class Body {
public:
    Body(double R, double r, vector<int>, vector<int>);

    ~Body();

    bool validate();

    int getAlignment() const { return vAlignment; };
private:
    double radius_large, radius_small;
    int vAlignment;
    _circle *c2, *c1;
};

/*
 * @class Neck
 * @brief A ukulele neck component
 * */
class Neck {
public:
    Neck(int w, int h, vector<int> pos);

    ~Neck();

    bool validate();

private:
    int width, height;
    vector<int> center;
    _rectangle *_neck;
};

/*
 * @class Head
 * @brief A ukulele head component
 * */
class Head {
public:
    Head(int w, int h, vector<int> pos);

    ~Head();

    bool validate();
    //void setProps(int, int);
private:
    int width;
    int height;
    vector<int> center;
    _rectangle* _head;
};

/*
 * @class _string
 * @brief A ukulele string component
 * */
class _string {
public:
    _string(int l);

    ~_string();

    bool validate();
    //void setProps(int, int);
private:
    int length;
    int strings = 4; // number of strings, has a default value of 4
    float thickness = 0.01f; // default value
    list <_cylinder*> __strings;
};



// TODO: Comment code thoroughly

class BodySupplier{
private:
    BodySupplier();

public:
    static Body* getBody(int, int, vector< vector<int> >);
};

class NeckSupplier{
private:
    NeckSupplier();

public:
    static Neck* getNeck(int, int, vector<int>);
};

class HeadSupplier{
private:
    HeadSupplier();

public:
    static Head* getHead(int, int, vector<int>);
};

class _stringSupplier{
private:
    _stringSupplier();

public:
    static _string* getString(int);
};



#endif //UKULELESUPPLIER_H
