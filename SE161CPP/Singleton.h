#ifndef SINGLETON_H
#define SINGLETON_H

class Singleton {
private:
	static Singleton* singleton;
protected:
public:
	static Singleton* getSingleton(){
		if(nullptr == singleton)//�ж��Ƿ��һ�ε��� ?
			singleton = new Singleton();
		return singleton;
	}
};

#endif

