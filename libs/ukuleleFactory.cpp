#include "../includes/ukuleleFactory.h"

// ukulele production line
ukuleleProductionLine::ukuleleProductionLine(){
    // private constructor
}

ukulele ukuleleProductionLine::makeUkulele(){
    // create a ukulele
    // ukulele* _ukuleleInstance = new ukulele();

    // TODO: add ukulele components specs
    // FIXME: fix linter errors
    // ukulele spec
    // vector<vector<int>> bodySpec;
}

// empty class constructor
ukulele::ukulele(){};

// class destructor
~ukulele::ukulele(){
	delete b;
	delete n;
	delete h;
	delete s;	
};

// body factory
Body *ukulele::makeBody(int r1, int r2, vector<vector<int>> centers){
	return new Body(r1, r2, centers[0], centers[1]);
};

Neck *ukulele::makeNeck(int w, int h, vector<int> pos1, vector<int> pos2){
	return new Neck(w, h, pos1, pos2);
};

Head *ukulele::makeHead(int w, int h, vector<int> pos){
	return new Head(w, h, pos);
};

_string *ukulele::makeString(int len){
	return new _string(len);
};



/*
 * ukulele assemble function
 * params: a list of values representing the properties of
 * each component.
 * body param: body dimensions
 * neck params: neck dimensions
 * head params: head dimensions
 * string params: string length
 * 
 * */

void assemble(ukulele* thisUkulele, vector<vector<int>> bodyParams,
			      vector<vector<int>> neckParams,
			      vector<vector<int>> headParams,
			      vector<vector<int>> stringParams){
	// create ukulele components
	b = thisUkulele->makeBody(bodyParams[0][0], bodyParams[0][1],
			  bodyParams[1], bodyParams[2]);
	n = thisUkulele->makeNeck(neckParams[0][0], neckParams[0][1],
			   neckParams[1]);
	h = thisUkulele->makeHead(headParams[0][0], headParams[0][0],
			   headParams[1]);
	s = thisUkulele->makeString(stringParams[0], stringParams[1][0]);

	// set properties of the ukulele components
};

bool ukulele::isValid(){
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
_string::_string(int len){
	for (int count = 0; count < this->strings; ++count){
		this->__strings.push_back(
				new _cylinder(this->thickness, len)
				);
	}
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
