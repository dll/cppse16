#ifndef RINGCIRCLE_H
#define RINGCIRCLE_H
namespace RingCircle{
	double const PI = 3.14159;  // 定义一个double型常量PI
	class Circle {
	private:
		double radius;
	public:
		Circle (double r):radius (r){}
		double calcPerimeter ()  {      // 计算圆周长
			return 2 * PI * radius;
		}
		double calcArea ()  {              // 计算圆面积
			return PI * radius * radius;
		}
	};
	
	class Ring  {
	private:
		Circle inner,outer; // 两个Circle类型数据
	public:
		Ring (double inr = 0,double our = 0):inner (inr),outer (our){
			//				if(inr>our){
			//					inner=Circle(our);
			//					outer=Circle(inr);
			//				}
		}
		double   calcPerimeter () {   // 计算环的总周长
			return outer.calcPerimeter () + inner.calcPerimeter ();
		}
		double  calcArea ()  { // 计算环的面积
			return outer.calcArea () - inner.calcArea ();
		}
	};
}
#endif

