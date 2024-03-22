#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;



class CoordXY{
	protected:
	double X;
	double Y;
	
	
	public:
	double getX() const;   // X and Y getter functions, set as constant functions since they only intend to return X and Y values
	double getY() const;   
	void setX(double );    // X and Y setter fucntions
	void setY(double );    
	
	CoordXY();                  // default constructor
	CoordXY(double, double);    // parameterized constructor	
};



class Complex: public CoordXY{
	public:
	
	void add(Complex);          
	void subtract(Complex);     
	void multiply(Complex);
	void square();
	double abs();
	
	Complex();                  // default constructor, will call the CoordXY default constructor
	Complex(double, double);    // parameterized constructor, will call the CoordXY parameterized constructor
};

class Mandelbrot{
	private:
	double xMin, xStep, xMax;
	double yMin, yStep, yMax;              // min means the smallest value, max means the largest value, step means the increment (similar with the concept of for loop)
	
	int Nx;
	int Ny;        // the dimensions of X and Y (rows and columns) of the Mandelbrot pattern, are to be determined in the constructor depending on x/y min,step,max
	
	int *MBS;      // an array used to store the Mandelbrot pattern, formed with 0s and 1s
	
	
	
	
	public:
	
	double getXmin();
	double getXstep();
	double getXmax();
	
	double getYmin();
	double getYstep();
	double getYmax();
	
	int getNx();
	int getNy();               // getter functions to check the values of the private variables
	
	
	
	void calcMBS();
	
	void printMBS();
	
	
	
	Mandelbrot(double, double, double, double, double, double);      // constructor, parameterized and dynamic
	~Mandelbrot();                                                   // dynamic destructor
	
};





int main(){
	
	/*
	// testing add, subtract, multiply, square, abs fucntions
	
	Complex a;      // default value is (0,0)
	Complex b(3,4);
	
	cout << a.getX() << '\t' << a.getY() << endl;
	cout << b.getX() << '\t' << b.getY() << endl << endl;
	
	a.add(b);
	
	cout << "a = a + b" << endl;
	cout << a.getX() << '\t' << a.getY() << endl;
	cout << b.getX() << '\t' << b.getY() << endl << endl;
	
	
	Complex c(2,5);
	a.subtract(c);
	
	cout << "a = a - c" << endl;
	cout << a.getX() << '\t' << a.getY() << endl;
	cout << b.getX() << '\t' << b.getY() << endl;
	cout << c.getX() << '\t' << c.getY() << endl << endl;
	
	Complex d(-1,-1);
	b.subtract(d);
	
	cout << "b = b - d" << endl;
	cout << a.getX() << '\t' << a.getY() << endl;
	cout << b.getX() << '\t' << b.getY() << endl;
	cout << c.getX() << '\t' << c.getY() << endl;
	cout << d.getX() << '\t' << d.getY() << endl << endl;
	
	
	b.multiply(c);
	
	cout << "b = b * c" << endl;
	cout << a.getX() << '\t' << a.getY() << endl;
	cout << b.getX() << '\t' << b.getY() << endl;
	cout << c.getX() << '\t' << c.getY() << endl;
	cout << d.getX() << '\t' << d.getY() << endl << endl;
	
	
	b.multiply(a);
	
	cout << "b = b * a" << endl;
	cout << a.getX() << '\t' << a.getY() << endl;
	cout << b.getX() << '\t' << b.getY() << endl;
	cout << c.getX() << '\t' << c.getY() << endl;
	cout << d.getX() << '\t' << d.getY() << endl << endl;
	
	
	Complex e(5,6);
	
	cout << "e" << endl;
	cout << e.getX() << '\t' << e.getY() << endl << endl;
	
	e.square();
	
	cout << "e^2" << endl;
	cout << e.getX() << '\t' << e.getY() << endl << endl;
	
	
	
	cout << "|e| or magnitude/absolute of e" << endl;
	cout << e.abs() << endl << endl;
	*/
	
	
	
	
	Mandelbrot a(-2,0.02,1,-1,0.02,1);
	//Mandelbrot a(-1.4,0.01,0.5,-0.9,0.02,0.9);     // another set of parameters to have a closer view to the main pattern of the Mandelbrot set
	
	
	cout << "x = [" << a.getXmin() << " : " << a.getXstep() << " : " << a.getXmax() << "]" << endl;
	cout << "y = [" << a.getYmin() << " : " << a.getYstep() << " : " << a.getYmax() << "]" << endl << endl;
	
	cout << "Nx = " << a.getNx() << endl;
	cout << "Ny = " << a.getNy() << endl;
	cout << "Size = " << a.getNx()*a.getNy() << endl << endl;
	
	
	
	a.calcMBS();
	
	a.printMBS();
	

	return 0;

}








// default constructor of CoordXY class, if there is no X and Y value provided, set them as 0
CoordXY::CoordXY(){
	//cout << "default CoordXY" << endl;
	X=0;
	Y=0;
}



// parameterized constructor of CoordXY class
CoordXY::CoordXY(double x, double y){
	//cout << "parameterized CoordXy" << endl;
	X=x;
	Y=y;
}



// X getter function
double CoordXY::getX() const{     
		return X;
	}

// Y getter function
double CoordXY::getY() const{     
		return Y;
	}


// X setter function
void CoordXY::setX(double x){
	X=x;
}


// Y setter function
void CoordXY::setY(double y){
	Y=y;
}




// default constructor of Complex class, do nothing but to call the default constructor of CoordXY
Complex::Complex(){
	//cout << "default Complex" << endl;
}



// parameterized constructor of Complex class, do nothing but pass x and y values to the parameterized constructor of CoordXY class
Complex::Complex(double x, double y): CoordXY(x,y){
	//cout << "parameterized Complex" << endl;
}



// add the complex number c to the internal complex number
void Complex::add(Complex c){
	this->X = this->X + c.getX();
	this->Y = this->Y + c.getY();
}


// subtract the complex number c from the internal complex number
void Complex::subtract(Complex c){
	this->X = this->X - c.getX();
	this->Y = this->Y - c.getY();
}


// multiply the complex number c with the internal complex number
void Complex::multiply(Complex c){
	double x = this->X;
	double y = this->Y;    // temporary store the values of X and Y before multiplying
	
	this->X = (x * c.getX()) - (y * c.getY());
	this->Y = (y * c.getX()) + (x * c.getY());
}


// square the internal complex number
void Complex::square(){
	double x = this->X;
	double y = this->Y;    // temporary store the values of X and Y before multiplying
	
	this->X = (x*x) - (y*y);
	this->Y = x*y*2;
}


// return the absolute value (or magnitude) of the internal complex number
double Complex::abs(){
	double x2 = this->X * this->X;
	double y2 = this->Y * this->Y;
	
	double mag = sqrt(x2+y2);
	
	return mag;
}



// constructor of the Mandelbrot class (parameterized and dynamic)
Mandelbrot::Mandelbrot(double xMin, double xStep, double xMax, double yMin, double yStep, double yMax){
	this->xMin = xMin;
	this->xStep = xStep;
	this->xMax = xMax;
	this->yMin = yMin;
	this->yStep = yStep;
	this->yMax = yMax;          // store the values into respective internal variables
	
	
	Nx=0;
	Ny=0;
	
	for(double i=xMin; i<=xMax; i=i+xStep){     // calculate Nx
		Nx++;
	}
	
	for(double i=yMin; i<=yMax; i=i+yStep){     // calculate Ny
		Ny++;
	}
	
	
	MBS = new int[Nx*Ny];                    // create a dynamic array with size of Nx * Ny (1D array)
}


// destructor of the Mandelbrot class
Mandelbrot::~Mandelbrot(){
	delete[] MBS;
}


double Mandelbrot::getXmin(){return xMin;}
double Mandelbrot::getXstep(){return xStep;}
double Mandelbrot::getXmax(){return xMax;}

double Mandelbrot::getYmin(){return yMin;}
double Mandelbrot::getYstep(){return yStep;}
double Mandelbrot::getYmax(){return yMax;}

int Mandelbrot::getNx(){return Nx;}
int Mandelbrot::getNy(){return Ny;}                  // getter functions in Mandelbrot class to check the values of the private variables




void Mandelbrot::calcMBS(){
	
	int I=0;
	
	// for every values of X and Y (real and imaginary), calculate whether it falls within the Mandelbrot set
	for(double i=yMin; i<=yMax; i=i+yStep){
		
		for(double j=xMin; j<=xMax; j=j+xStep){
			
			Complex c(j,i);    // create a complex number c with X=j, Y=i
			Complex z;         // create a complex number z with X and Y equal 0 (0+0i)
			
			
			for(int k=0; k<1000; k++){   // perform 1000 iterations to check whether the |z| diverges
				
				z.square();
				z.add(c);
			}
			
			if(z.abs()<10){      
			
				MBS[I]=1;   
			}
			else{
				MBS[I]=0;   
			}
			/*
			   - after 1000 iterations, there are two extremes to the absolute value of z : either very large(inf or NAN) or very small(less than 1)
	           - however, most of the diverged value goes to NAN(not a number) after 1000 iterations and NAN is neither larger not smaller than an integer like 10
			   - comparing NAN with 10 will never give a 1, no matter it is (NAN>10) or (NAN<10)
			   - therefore the condition of the if statement should be :
			   
					if(z.abs()<10){
						MBS[I]=1;
					} 
					else{
						MBS[I]=0;
					}	
				   
			   instead of 
			   
					if(z.abs()>10){
						MBS[I]=0;
					}
					else{
						MBS[I]=1;
					}
					
			   so that those small value could be detected instead of those NAN
			*/
			
			I++;
		}	
		
	}
}


// print out the Mandelbrot pattern
void Mandelbrot::printMBS(){
	
	int I=0;
	
	
	for(int i=0; i<(Nx*Ny); i++){
		
		cout << MBS[i];        // print out every element in MBS one by one
		
		I++;
		
		
		if(I%Nx==0){           // go to the next line everytime when it reach multiples of Nx
			cout << endl;
		}
		else{
			I=I;         // do nothing, just a habit
		}
	}
	
}
