#include <iostream>
using namespace std;

double * read_poly(int &n){
  cout << "the degree: ";
  cin >> n;
  double * c=new double[n+1];
  for(int i=0;i<=n;i++){
    cout << "coefficient of degree " << i << ": ";
    cin >> c[i];
  }
  return c;
}

void print_poly(double *c, int n){
  int i;
  cout << c[0];
  if(n>0)
    cout << " + ";
  for(i=1;i<n;i++)
    cout << c[i] << "*x^" << i << " + ";
  if(n>0)
    cout << c[n] << "*x^" << i;
  cout << endl;
}

double pol_value(double *c, int n,double x){
  double val_at_x,x_temp;
  val_at_x = c[0];
  for (int i =1;i<=n;i++){
    x_temp = x;
    if (i >=2){
      for (int m=2;m<=i;m++){x_temp =x_temp*x_temp;};
    }
    val_at_x = val_at_x +c[i]*x_temp;
  }
  return val_at_x;
}

double * poli_sum (double * p1, int d1, double * p2, int d2, int & dr){
  if (d1 ==d2){
    dr =d1;
    double * c=new double[dr+1]; 
    for (int i=0;i<=dr;i++){
      c[i] = p1[i] +p2[i];
    }
    return c;
  }
  else{ 
    dr = max(d1,d2);
    double * c=new double[dr+1]; 
    for (int i =0;i<=min(d1,d2);i++){
      c[i] = p1[i] +p2[i];
    }
    if (d1 == max(d1,d2)){
      for (int n = min(d1,d2)+1;n<=d1;n++){
        c[n] = p1[n];}
    }
    else{
      for (int n = min(d1,d2)+1;n<=d2;n++){
        c[n] = p2[n];
      }
    }
    return c;
  }
}

double * poli_multi(double * p1, int d1, double * p2, int d2, int & dr2){
  // add something what happens when one poly is bigger than the other
  dr2 = d1+d2;
  double * c=new double[dr2+1];
  for (int i=0;i<=d1;i++){
    for (int n=0;n<=d2;n++){
      c[i+n]+=p1[i]*p2[n];}
    }
  return c;
}


int main()
{
  double *p1,*p2,x,val_at_x,*p3,*p4;
  int g1,g2,dr,dr2;

  cout<<"Create the first polynomial"<<endl;
  p1=read_poly(g1);
  print_poly(p1,g1);

  // Calculation of the polynomial value for a certain position x
  cout<<" Let´s calculate a y-value for a x-vale"<<endl;
  cout <<"Please choose an x where you want to let the y-value be calculated"<<endl;
  cin>>x;
  val_at_x = pol_value(p1,g1,x);
  cout<<"Value at x: "<< val_at_x<<endl;

  //sum of two polynomials
  cout<<"Create the second polynomial"<<endl;
  p2=read_poly(g2);
  print_poly(p2,g2);
  p3 =poli_sum (p1, g1, p2, g2, dr);
  print_poly(p3,dr);

  // product of two polynomials 
  cout << "product of 2 polynomials"<<endl;
  p4 = poli_multi(p1, g1, p2, g2, dr2);
  print_poly(p4,dr2);

  delete [] p4;
  delete [] p3;
  delete [] p2;
  delete[] p1;
  return 0;
}