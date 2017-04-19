//
// Created by Natna on 15.04.2017.
//


#include "../includes/ukuleleSuppliers.h"

Body::Body(double R, double r, vector<int> p1, vector<int> p2){
    c1 = new _circle(R, p1);
    c2 = new _circle(r, p2);
    this->radius_large = R;
    this->radius_small = r;
};

/*
 * Body component validation method
 * */
bool Body::validate(){
    int valid = 0;
    // condition 1: the distance between the two circles must be less than
    // the sum of their radius
    double dist = pow(this->c1->center[0] - this->c2->center[0], 2) +
               pow(this->c1->center[1] - this->c2->center[1], 2);
    if(sqrt(dist) < this->radius_large + this-> radius_small){
        valid++;
        printf("Body test: Test failed! circles are not overlapping");
    }

    // condition 2: the smaller circle should not be completely
    // contained in the bigger circle
    if(sqrt(dist) > this->radius_large){
        valid++;
        printf("Body test: Test failed! small circle is completely inside larger circle.");
    }

    // condition 3: check if both circles are aligned vertically
    if(this->c1->center[1] == this->c2->center[1]){
        valid++;
        printf("Body test: Test failed! circles not aligned vertically.");
    }
    this->vAlignment = this->c1->center[1];

    return (bool)(valid == 0);
};


/*
 * Neck constructor
 * */
Neck::Neck(int w, int h, vector<int> pos){
    this->_neck = new _rectangle(w, h);
    this->width = w;
    this->height = h;
    this->center = pos;
};

/*
 * Neck component validation method
 * */

bool Neck::validate(){
    int valid = 0;

    // condition 1: the width of the neck must be bigger than the height
    if ((width/height) > 10){
        valid++;
        printf("Neck test: Test failed! the width:height ratio must be"
                       " greater than 10.");
    }
    return (bool)(valid == 0);
};

/*
 * Head constructor
 * */
Head::Head(int wid, int h, vector<int> pos){
    this->_head = new _rectangle(wid, h);
    this->width = wid;
    this->height = h;
    this->center = pos;
};

/*
 * Head component validation method
 * */

bool Head::validate(){
    int valid = 0;
    // condition 1: the ratio between the width and height should be between
    // 1.25 and 1.3
    float ratio = (float)this->width / (float)this->height;
    if (ratio < 1.25 || ratio > 1.3){
        valid++;
        printf("Head test: Test failed! the width:height ratio must be "
                       "between 1.25 and 1.3.");
    };

    return (bool)(valid == 0);
};

/*
 * String constructor
 * */
_string::_string(int len){
    for (int count = 0; count < this->strings; ++count){
        this->__strings.push_back(
                new _cylinder(this->thickness, len)
        );
    }
    this->length = len;
};

/*
 * String component validation method
 * */

bool _string::validate(){
    int valid = 0;
    // condition 1: the strings must have the correct multiplicity, i.e. there
    // should be four
    if (this->strings != 4){
        valid++;
        printf("String test: Test failed! There should be a correct "
                       "number of strings");
    }

    return (bool)(valid == 0);
};


BodySupplier::BodySupplier() {
    // private constructor
}

Body* getBody(int r1, int r2, vector< vector<int> > c) {
    return new Body(r1, r2, c[0], c[1]);
}

NeckSupplier::NeckSupplier() {
    // private constructor
}

Neck* NeckSupplier::getNeck(int a, int b, vector<int> c) {
    return new Neck(a, b, c);
}

HeadSupplier::HeadSupplier() {
    // private constructor
}

Head* HeadSupplier::getHead(int w, int h, vector<int> pos) {
    return new Head(w, h, pos);
}

_stringSupplier::_stringSupplier() {
    // private constructor
}

_string* _stringSupplier::getString(int len) {
    return new _string(len);
}

