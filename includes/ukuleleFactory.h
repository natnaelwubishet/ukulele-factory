/*
 * ukulele factory class
 *
 * */
#ifndef UKULELEFACTORY_H
#define UKULELEFACTORY_H

#include "mainwindow.h"
#include <list>
#include <cassert>
#include <vector>
#include <cmath>

namespace Ui{
	class ukuleleFactory;	
	class Body;
	class Neck;
	class Head;
	class _String;

	// utils
	class _circle;
	class _rectangle;
	class _cylinder;
}

class ukuleleFactory{
	public:

        ukuleleFactory();

        ~ukuleleFactory();

        Body *makeBody(int, int, list<vector<int>>)const;

        Neck *makeNeck(int, int)const;

        Head *makeHead(int, int)const;

        _String *makeString(int) const;

        bool isValid();

        void assemble(list<vector<int>>, list<vector<int>>
				,list<vector<int>>, list<vector<int>>);
	private:
	        Body *b;
		Neck *n;
		Head *h;
		_String *s;	
		bool valid;
};

class Body{
	public:
		Body(int R, int r, vector<int>, vector<int>): radius_large(R), radius_small(r);
		~Body();
		bool validate();
		int getAlignment()const {return vAlignment;};
	private:
		int radius_large, radius_small;
		int vAlignment;
		_circle c1, _circle c2;
};

class Neck{
	public:
		Neck(int w, int h, vector<int> pos): width(w), height(h)
						     ,center(pos);
		~Neck();
		bool validate();
	private:
		int width, height;
		vector<int> center;
		_rectangle _neck;
};

class Head{
	public:
		Head(int w, int h, vector<int> pos): width(w), height(h)
						     , center(pos);
		~Head();
		bool validate();
		//void setProps(int, int);
	private:
		int width;
		int height;
		vector<int> center;
		_rectangle _head;
};

class _String(){
	public:
		_String(int l, int num): length(l), strings(num);
		~_String();
		bool validate();
		//void setProps(int, int);
	private:
		int length;
		int strings = 4; // number of strings, has a default value of 4
		float thickness = 0.01f; // default value
		list<_cylinder> __strings;
}

// utils
class _circle{
	public:
		_circle(int r, vector<int> p): radius(r), center(p);
		~_circle();
		vector<int> center;
	private:
		int radius;
};

class _rectangle{
	public:
		_rectangle(int w, int h): width(w), height(h);
		~_rectangle();
	private:
		int width;
		int height;
};

class _cylinder{
	public:
		_cylinder(float rad, int len): radius(rad), length(len);
		~_cylinder();
	private:
		float radius;
		int length;

}

#endif
