//
// Created by Natna on 15.04.2017.
//

#include "../includes/ukuleleSuppliers.h"
#include "../includes/ukuleleFactory.h"

BodySupplier::BodySupplier() {
    // private constructor
}

Body BodySupplier::getBody(int r1, int r1, list <vector<int>> c) {
    return new Body(r1, r2, c[0], c[1]);
}

NeckSupplier::NeckSupplier() {
    // private constructor
}

Neck NeckSupplier::getNeck(int a, int b, vector<int> c) {
    return new Neck(a, b, c);
}

HeadSupplier::HeadSupplier() {
    // private constructor
}

Head HeadSupplier::getHead(int w, int h, vector<int> pos) {
    return new Head(w, h, pos);
}

_stringSupplier::_stringSupplier() {
    // private constructor
}

_string _stringSupplier::getString(int len) {
    return new _string(len);
}