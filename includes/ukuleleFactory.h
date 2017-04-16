/*
 * @file ukuleleFactory.h
 * @brief This header file contains the definitions for a ukulele
 * and ukulele production line classes
 * */
#ifndef ukulele_H
#define ukulele_H

#include "mainwindow.h"
#include "ukuleleSuppliers.h"
#include <list>
#include <cassert>
#include <vector>
#include <cmath>

using namespace std;

/*
 * @namespace ui
 * @brief The namespace Ui defines the main ui for
 * the application
 * */

namespace Ui {

    /*
     * @class ukuleleProductionLine
     * @brief a singleton object that creates a
     * ukulele object
     *
     * */
    class ukuleleProductionLine {
    private:
        /*
         * @brief default constructor
         * */
        ukuleleProductionLine();

    public:
        /*
         * @brief creates a ukulele
         * @param none
         * @return returns a ukulele object
         * */
        ukulele makeUkulele();
    };

    /*
     * @class ukulele
     * @brief A ukulele instrument object
     * */

    class ukulele {
    public:
        /*
         * @brief default constuctor
         * */
        ukulele() {};

        /*
         * @brief default destructor
         * */
        ~ukulele() {};

        /*
         * @brief makeBody method
         * @param
         * */
        Body *makeBody(int, int, vector<vector<int>>) const;

        Neck *makeNeck(int, int, vector<int>) const;

        Head *makeHead(int, int) const;

        _string *makeString(int) const;

        bool isValid();

        friend void
        assemble(ukulele *, vector<vector<int>>, vector<vector<int>>, vector<vector<int>>, vector<vector<int>>);

    private:
        Body *b;
        Neck *n;
        Head *h;
        _string *s;
        bool valid;
    };

    /*
     * @class Body
     * @brief A ukulele body component
     * */
    class Body {
    public:
        Body(int R, int r, vector<int>, vector<int>) : radius_large(R), radius_small(r) {};

        ~Body();

        bool validate();

        int getAlignment() const { return vAlignment; };
    private:
        int radius_large, radius_small;
        int vAlignment;
        _circle c2;
        _circle c1;
    };

    /*
     * @class Neck
     * @brief A ukulele neck component
     * */
    class Neck {
    public:
        Neck(int w, int h, vector<int> pos) : width(w), height(h), center(pos) {};

        ~Neck();

        bool validate();

    private:
        int width, height;
        vector<int> center;
        _rectangle _neck;
    };

    /*
     * @class Head
     * @brief A ukulele head component
     * */
    class Head {
    public:
        Head(int w, int h, vector<int> pos) : width(w), height(h), center(pos) {};

        ~Head();

        bool validate();
        //void setProps(int, int);
    private:
        int width;
        int height;
        vector<int> center;
        _rectangle _head;
    };

    /*
     * @class _string
     * @brief A ukulele string component
     * */
    class _string {
    public:
        _string(int l) : length(l) {};

        ~_string();

        bool validate();
        //void setProps(int, int);
    private:
        int length;
        int strings = 4; // number of strings, has a default value of 4
        float thickness = 0.01f; // default value
        list <_cylinder> __strings;
    };

    /*
     * @class _circle
     * @brief A circle constructor class
     * */
    class _circle {
    public:
        _circle(int r, vector<int> p) : radius(r), center(p) {};

        ~_circle();

        vector<int> center;
    private:
        int radius;
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
}
#endif
