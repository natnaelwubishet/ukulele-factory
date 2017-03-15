/*
 * ukulele factory class
 *
 * */

#include "mainwindow.h"

namespace Ui{
	class bodyFactory;
	class neckFactory;
	class ukuleleFactory;	
}

class ukuleleFactory : public QWidget{
	public:
		ukuleleFactory();
		~ukuleleFactory();
		bodyFactory body;
		neckFactory neck;
		isValid();
	private: 
		bool valid;
};

class neckFactory{
	public:
		neckFactory();
		~neckFactory();
}

class bodyFactory{
	public: 
	bodyFactory();
	~bodyFactory();
} 
