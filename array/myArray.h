#ifndef MYARRAY_H
#define MYARRAY_H

class myArray {
private:
protected:
	int size;
	int * element;//整形数组
public:
	myArray(int size=0);
	~myArray();
	int & operator[](int index);
	
	void set(int index, int value);
	int get(int index);
};

#endif

