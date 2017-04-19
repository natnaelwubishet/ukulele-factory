/*
 * @file ukuleleFactory.h
 * @brief This header file contains the definitions for a ukulele
 * and ukulele production line classes
 * */
#ifndef ukulele_H
#define ukulele_H

#include "../src/ui/mainwindow.h"
#include "ukuleleSuppliers.h"
#include <list>
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
        static ukulele* makeUkulele();
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
        ukulele();

        /*
         * @brief destructor
         * */
        ~ukulele();

        /*
         * @brief makeBody method
         * @param
         * */
        Body *makeBody(int, int, vector<int>, vector<int>);

        Neck *makeNeck(int, int, vector<int>);

        Head *makeHead(int, int, vector<int>);

        _string *makeString(int);

        bool isValid();

        friend void assemble(ukulele *, vector< vector<int> >, vector< vector<int> >, vector< vector<int> >, vector< vector<int> >);

    private:
        Body *b;
        Neck *n;
        Head *h;
        _string *s;
        bool valid;
    };
};

#endif
