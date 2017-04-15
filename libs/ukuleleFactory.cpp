#include "../includes/ukuleleFactory.h"

// empty class constructor
ukuleleFactory::ukuleleFactory(){};

// class destructor
~ukuleleFactory::ukuleleFactory(){
	delete b;
	delete n;
	delete h;
	delete s;	
};

// body factory
Body *ukuleleFactory::makeBody(int r1, int r2, list<vector<int>> centers){
	return new Body(r1, r2, centers[0], centers[1]);
};

Neck *ukuleleFactory::makeNeck(int w, int h, vector<int> pos){
	return new Neck(w, h, pos);
};

Head *ukuleleFactory::makeHead(int w, int h, vector<int> pos){
	return new Head(w, h, pos);
};

_String *ukuleleFactory::makeString(int len){
	return new _String(len);
};



/*
 * ukuleleFactory assemble function
 * params: a list of values representing the properties of
 * each component.
 * body param: body dimensions
 * neck params: neck dimensions
 * head params: head dimensions
 * string params: string length
 * 
 * */

bool ukuleleFactory::assemble(list<vector<int>> bodyParams, 
			      list<vector<int>> neckParams,
			      list<vector<int>> headParams,
			      list<vector<int>> stringParams){
	// create ukulele components
	b = this->makeBody(bodyParams[0][0], bodyParams[0][1], 
			  bodyParams[1], bodyParams[2]);
	n = this->makeNeck(neckParams[0][0], neckParams[0][1],
			   neckParams[1]);
	h = this->makeHead(headParams[0][0], headParams[0][0],
			   headParams[1]);
	s = this->makeString(stringParams[0], stringParams[1][0]);

	// set properties of the ukulele components
};

bool ukuleleFactory::isValid(){
	// validate each component and return response
	this->valid = (this->b->validate()) &&
		      (this->n->validate()) &&
		      (this->h->validate()) &&
		      (this->s->validate());
	return valid;
};


Body::Body(int R, int r, vector<int> p1, vector<int> p2){
	c1 = new _circle(R, p1);
	c2 = new _circle(r, p2);
};

/*
 * Body component validation method
 * */
bool Body::validate(){
	int valid = 0;
	// condition 1: the distance between the two circles must be less than
	// the sum of their radius
	int dist = pow(this->c1->center[0] - this->c2->center[0], 2) + 
		pow(this->c1->center[1] - this->c2->center[1], 2);
	if(sqrt(dist) < this->radius_large + this-> radius_small){
		valid++;
		printf("Body test: Test failed! circles are not overlapping");
	}

	// condition 2: the smaller circle should not be completely
	// contained in the bigger circle
	if(sqrt(dist) > this.radius_large){
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
     _neck = new _rectangle(w, h);
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
	_head = new _rectangle(w, h);
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
_String::_String(int len, int num){
	for (int count = 0; count < this->strings; ++count){
		this->__strings.push_back(
				new _cylinder(this->thickness, len)
				);
	}
};

/*
 * String component validation method
 * */

bool _String::validate(){
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
