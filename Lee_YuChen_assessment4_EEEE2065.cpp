// z = (z ^ 2) + c at line 594

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
	
	Complex add(Complex);          
	Complex subtract(Complex);     
	Complex multiply(Complex);
	Complex divide(Complex);
	Complex square();
	double abs();
	
	
	Complex operator + (Complex);
	Complex operator - (Complex);
	Complex operator * (Complex);
	Complex operator / (Complex);
	Complex operator ^ (int);            // operators overloading for the Complex type
	
	
	
	
	
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
	
	double getXmin() const;
	double getXstep() const;
	double getXmax() const;
	
	double getYmin() const;
	double getYstep() const;
	double getYmax() const;
	
	int getNx() const;
	int getNy() const;         // getter functions to check the values of the private variables, set as constant functions since they only intended to return values
	
	
	
	void printDetails();   // print out the details such as the ranges of X and Y, the Nx and Ny and the size of MBS array(Nx * Ny), before calculating MBS
	
	void calcMBS();
	
	void printMBS();
	
	void setRange(double, double, double, double, double, double);
	
	
	
	Mandelbrot(double, double, double, double, double, double);      // constructor, parameterized and dynamic
	~Mandelbrot();                                                   // dynamic destructor
	
};





int main(){
	
	
	/*
	Complex a(25,-5);
	Complex b(-9, 43);
	
	Complex ans;
	
	ans = a.add(b);
	
	cout << a.getX() << '\t' << a.getY() << endl;
	cout << b.getX() << '\t' << b.getY() << endl;
	cout << ans.getX() << '\t' << ans.getY() << endl << endl;
	
	
	
	ans = a.subtract(b);
	
	cout << a.getX() << '\t' << a.getY() << endl;
	cout << b.getX() << '\t' << b.getY() << endl;
	cout << ans.getX() << '\t' << ans.getY() << endl << endl;
	
	
	ans = a.multiply(b);
	
	cout << a.getX() << '\t' << a.getY() << endl;
	cout << b.getX() << '\t' << b.getY() << endl;
	cout << ans.getX() << '\t' << ans.getY() << endl << endl;
	
	
	
	ans = a.square();
	
	cout << a.getX() << '\t' << a.getY() << endl;
	cout << b.getX() << '\t' << b.getY() << endl;
	cout << ans.getX() << '\t' << ans.getY() << endl << endl;
	
	
	
	ans = b.square();
	
	cout << a.getX() << '\t' << a.getY() << endl;
	cout << b.getX() << '\t' << b.getY() << endl;
	cout << ans.getX() << '\t' << ans.getY() << endl << endl;
	
	
	ans = a.divide(b);   // answer should get x = -44/193 and y = -103/193, for a(25,-5) and b(-9,43)
	
	cout << a.getX() << '\t' << a.getY() << endl;
	cout << b.getX() << '\t' << b.getY() << endl;
	cout << ans.getX() << '\t' << ans.getY() << endl << endl;
	
	
	
	ans = a+b;
	
	cout << a.getX() << '\t' << a.getY() << endl;
	cout << b.getX() << '\t' << b.getY() << endl;
	cout << ans.getX() << '\t' << ans.getY() << endl << endl;
	
	ans=a-b;
	
	cout << a.getX() << '\t' << a.getY() << endl;
	cout << b.getX() << '\t' << b.getY() << endl;
	cout << ans.getX() << '\t' << ans.getY() << endl << endl;
	
	
	ans=a * b;
	
	cout << a.getX() << '\t' << a.getY() << endl;
	cout << b.getX() << '\t' << b.getY() << endl;
	cout << ans.getX() << '\t' << ans.getY() << endl << endl;
	
	
	ans=a / b;
	
	cout << a.getX() << '\t' << a.getY() << endl;
	cout << b.getX() << '\t' << b.getY() << endl;
	cout << ans.getX() << '\t' << ans.getY() << endl << endl;
	
	
	
	
	ans = a^0;
	
	cout << a.getX() << '\t' << a.getY() << endl;
	cout << b.getX() << '\t' << b.getY() << endl;
	cout << ans.getX() << '\t' << ans.getY() << endl << endl;
	
	
	ans = a^1;
	
	cout << a.getX() << '\t' << a.getY() << endl;
	cout << b.getX() << '\t' << b.getY() << endl;
	cout << ans.getX() << '\t' << ans.getY() << endl << endl;
	
	ans = a^2;
	
	cout << a.getX() << '\t' << a.getY() << endl;
	cout << b.getX() << '\t' << b.getY() << endl;
	cout << ans.getX() << '\t' << ans.getY() << endl << endl;
	
	ans = a^3;
	
	cout << a.getX() << '\t' << a.getY() << endl;
	cout << b.getX() << '\t' << b.getY() << endl;
	cout << ans.getX() << '\t' << ans.getY() << endl << endl;
	
	ans = a^-1;
	
	cout << a.getX() << '\t' << a.getY() << endl;
	cout << b.getX() << '\t' << b.getY() << endl;
	cout << ans.getX() << '\t' << ans.getY() << endl << endl;
	
	ans = a^-2;
	
	cout << a.getX() << '\t' << a.getY() << endl;
	cout << b.getX() << '\t' << b.getY() << endl;
	cout << ans.getX() << '\t' << ans.getY() << endl << endl;
	*/
	
	
	
	
	// the whole program containing region 0-5 will take a long time to run
	// it is recommended to comment out the lines a.calcMBS(); and a.printMBS(); for other regions, leaving only one region when you're checking it
	
	// Region 0
	cout << "Region 0" << endl;
	
	Mandelbrot a(-2,0.02,1,-1,0.02,1);
	a.printDetails();
	a.calcMBS();
	a.printMBS();
	
	
	
	// Region 1
	cout << endl << endl << endl << "Region 1" << endl;
	
	a.setRange(-1.4, 0.005, -0.735, -0.3, 0.005, 0.3);
	a.printDetails();
	a.calcMBS();
	a.printMBS();
	
	
	
	// Region 2
	cout << endl << endl << endl << "Region 2" << endl;
	
	a.setRange(-1.4, 0.001, -1.245, -0.08, 0.001, 0.08);
	a.printDetails();
	a.calcMBS();
	a.printMBS();
	
	
	
	// Region 3
	cout << endl << endl << endl << "Region 3" << endl;
	
	a.setRange(-0.3, 0.002, 0.1, -0.84, 0.002, -0.64);
	a.printDetails();
	a.calcMBS();
	a.printMBS();
	
	
	
	// Region 4
	cout << endl << endl << endl << "Region 4" << endl;
	
	a.setRange(0.23, 0.001, 0.37, -0.59, 0.001, -0.48);
	a.printDetails();
	a.calcMBS();
	a.printMBS();
	
	
	
	// Region 5
	cout << endl << endl << endl << "Region 5" << endl;
	
	a.setRange(0.22, 0.001, 0.4, -0.05, 0.001, 0.05);
	a.printDetails();
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



// return the summation of the internal complex number and the passed in complex number, in Complex type
Complex Complex::add(Complex c){
	double x;
	double y;
	
	x = this->X + c.getX();
	y = this->Y + c.getY();
	
	Complex a(x,y);
	
	return a;
}


// return the answer of internal complex number minus the passed in complex number, in Complex type
Complex Complex::subtract(Complex c){
	double x;
	double y;
	
	x = this->X - c.getX();
	y = this->Y - c.getY();
	
	Complex a(x,y);
	
	return a;
}


// return the multiplication between the intenal complex number and the passed in complex number, in Complex type
Complex Complex::multiply(Complex c){
	double x;
	double y;
	
	x = (this->X * c.getX()) - (this->Y * c.getY());
	y = (this->Y * c.getX()) + (this->X * c.getY());
	
	Complex a(x,y);
	
	return a;
}



// return the division of the internal complex number over the passed in complex number, in Complex type
Complex Complex::divide(Complex c){
	
	
	Complex internal(X,Y);                       // the internal complex number
	Complex conjugate(c.getX(), c.getY() * -1);  // the conjugate of the passed in complex number, c
	
	Complex nume;    // numerator
	Complex deno;    // denominator
	
	nume = internal.multiply(conjugate);
	
	deno = c.multiply(conjugate);          // the denominator should have 0 value for Y, since the passed in complex number, c is multiplied with its own conjugate
	
	
	double x = nume.getX() / deno.getX();
	double y = nume.getY() / deno.getX();
	
	Complex a(x,y);
	
	return a;
}



// return the square of the passed in complex number, in Complex type
Complex Complex::square(){
	double x;
	double y;
	
	x = (this->X * this->X) - (this->Y * this->Y);
	y = this->X * this->Y * 2;
	
	Complex a(x,y);
	
	return a;
}


// return the absolute value (or magnitude) of the internal complex number
double Complex::abs(){
	double x2 = this->X * this->X;
	double y2 = this->Y * this->Y;
	
	double mag = sqrt(x2+y2);
	
	return mag;
}



// + operator overloading for Complex type
Complex Complex::operator + (Complex c){
	
	Complex internal(X,Y);
	
	Complex ans = internal.add(c);
	return ans;
}


// - operator overloading for Complex type
Complex Complex::operator - (Complex c){
	
	Complex internal(X,Y);
	
	Complex ans = internal.subtract(c);
	return ans;
}


// * operator overloading for Complex type
Complex Complex::operator * (Complex c){
	
	Complex internal(X,Y);
	
	Complex ans = internal.multiply(c);
	return ans;
}


// / operator overloading for Complex type
Complex Complex::operator / (Complex c){
	
	Complex internal(X,Y);
	
	Complex ans = internal.divide(c);
	return ans;
}


// ^ operator overloading for Complex type, only allow power of integer (both positive and negative integers)
Complex Complex::operator ^ (int n){
	
	Complex internal(X,Y);
	Complex ans(1,0);
	
	if(n>=0){
	
		for(int i=0; i<n; i++){
			ans = ans * internal;
		}
		// when n=0, this for loop will not iterate, therefore ans = (1,0)
		// when n=1, this for loop will iterate 1 time, therefore ans = internal
		// when n=2, this for loop will iterate 2 times, therefore ans = internal * internal
		// and so on
	}
	else if(n<0){      // some extra works, including the power of negative integer
		
		for(int i=0; i>n; i--){
			ans = ans / internal;
		}
	}
	
	return ans;
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


double Mandelbrot::getXmin() const{return xMin;}
double Mandelbrot::getXstep() const{return xStep;}
double Mandelbrot::getXmax() const{return xMax;}

double Mandelbrot::getYmin() const{return yMin;}
double Mandelbrot::getYstep() const{return yStep;}
double Mandelbrot::getYmax() const{return yMax;}

int Mandelbrot::getNx() const{return Nx;}
int Mandelbrot::getNy() const{return Ny;}   // getter functions in Mandelbrot class to check the values of the private variables, set as constant so that they will not "accidentally" change their values


// print out the details such as the ranges of X and Y, Nx, Ny and the size of MBS array (Nx*Ny)
void Mandelbrot::printDetails(){
	cout << "x = [" << xMin << " : " << xStep << " : " << xMax << "]" << endl;
	cout << "y = [" << yMin << " : " << yStep << " : " << yMax << "]" << endl << endl;
	
	cout << "Nx = " << Nx << endl;
	cout << "Ny = " << Ny << endl;
	cout << "Size = " << Nx * Ny << endl << endl;
}


void Mandelbrot::calcMBS(){
	
	int I=0;
	
	// for every values of X and Y (real and imaginary), calculate whether it falls within the Mandelbrot set
	for(double i=yMin; i<=yMax; i=i+yStep){
		
		for(double j=xMin; j<=xMax; j=j+xStep){
			
			Complex c(j,i);    // create a complex number c with X=j, Y=i
			Complex z;         // create a complex number z with X and Y equal 0 (0+0i)
			
			
			for(int k=0; k<1000; k++){   // perform 1000 iterations to check whether the |z| diverges
				z = (z ^ 2) + c;
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


// set range of the values of X and Y and re-calculate Nx, Ny and size of MBS array
void Mandelbrot::setRange(double xMin, double xStep, double xMax, double yMin, double yStep, double yMax){
	
	this->xMin = xMin;
	this->xStep = xStep;
	this->xMax = xMax;
	this->yMin = yMin;
	this->yStep = yStep;
	this->yMax = yMax;          // store the values into respective internal variables
	
	
	Nx=0;
	Ny=0;
	
	for(double i=xMin; i<=xMax; i=i+xStep){     // re-calculate Nx with the new xMin, xStep, xMax
		Nx++;
	}
	
	for(double i=yMin; i<=yMax; i=i+yStep){     // re-calculate Ny with the new yMin, yStep, yMax
		Ny++;
	}
	
	delete[] MBS;     // clear the old MBS array
	
	MBS = new int[Nx*Ny];   // re-allocate MBS with new Nx and Ny values
}

