#include "pgm.h"
#include <math.h>

// Returns the eqm between two unsigned char images
double eqm(unsigned char **im1, unsigned char **im2,  int nl, int nc) { int i,j;
  double x;

  for (x=i=0; i<nl; i++) for (j=0; j<nc; j++) x+=((int)im1[i][j]-im2[i][j])*((int)im1[i][j]-im2[i][j]);
  return x / (nl*nc);
}

// Returns the psnr between two unsigned char images
double psnr(unsigned char **im1, unsigned char **im2,  int nl, int nc) { double x;
  if ( (x=eqm(im1,im2,nl,nc)) ==0 ) return INFINITY;
  return ( 10. * log10(255*255/x)) ;
}

// Returns the psnr between two double images
double psnr_double(double** im1, double** im2,  int nl, int nc) { double x;
  int i,j;
  for (x=i=0; i<nl; i++) for (j=0; j<nc; j++) x+=((int)im1[i][j]-im2[i][j])*((int)im1[i][j]-im2[i][j]);
  x /= (nl*nc);
  if (x<1E-15) return INFINITY;
  return 10. * log10(255.*255./x);
}

// Returns the eqm between two double images
double eqm_double(double **im1, double **im2,  int nl, int nc) { int i,j;
  double x;

  for (x=i=0; i<nl; i++) for (j=0; j<nc; j++) x+=(im1[i][j]-im2[i][j])*(im1[i][j]-im2[i][j]);
  return x / (nl*nc);
}
