#ifndef SINGLETON_H
#define SINGLETON_H

class Singleton {
private:
	static Singleton* singleton;
protected:
public:
	static Singleton* getSingleton(){
		if(nullptr == singleton)//判断是否第一次调用 ?
			singleton = new Singleton();
		return singleton;
	}
};

#endif

