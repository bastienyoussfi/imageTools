#include "pgm.h"

/* Example code with input-output and simple image transformations	*/
main (int ac, char **av) {  /* av[1] contains the image name, av[2] the result name . */
  int nb,nl,nc, oldnl,oldnc;
  unsigned char **im2=NULL,** im1=NULL;
  double** im4,** im5, ** im6, ** im7, **im8, **im9,**im10;
  
  if (ac < 3) {printf("Usage : %s entree sortie \n",av[0]); exit(1); }
	/* Reading a PGM image whose name is passed on the command line */
  im1=lectureimagepgm(av[1],&nl,&nc);
  if (im1==NULL)  { puts("Lecture image impossible"); exit(1); }
	/* Calculation of its inverse video */
  double**im3=imuchar2double(im1,nl,nc);
  oldnl=nl; oldnc=nc;
	/*  The FFT requires powers of 2. We pad with zeros, but the dimensions nl and nc change */ 
  im7=padimdforfft(im3,&nl,&nc);
	/* Creating images for the real and imaginary parts of the FFT  */
  im4=alloue_image_double(nl,nc); im5=alloue_image_double(nl,nc); im6=alloue_image_double(nl,nc);
  fft(im7,im4,im5,im6,nl,nc);
	/* Creating images for the real and imaginary parts of the inverse FFT */
  im9=alloue_image_double(nl,nc); im10=alloue_image_double(nl,nc); 
  ifft(im5,im6,im9,im10,nl,nc);
	/* Conversion to 8-bit integer of the real part of the inverse FFT,
    Removal of the padding zeros using the crop function,
    Saving in PGM format of this image which should be identical to the inverse video
    because we performed the sequence fftinv(fft(image))*/
  ecritureimagepgm(av[2],crop(imdouble2uchar(im9,nl,nc),0,0,oldnl,oldnc),oldnl,oldnc);
}