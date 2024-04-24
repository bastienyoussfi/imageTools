#include "pgm.h"
     
/*Calculation of the inverse video of an image. If the output parameter is NULL, we create a new image. 
We iterate through the entire image line by line, column by column, calculate its inverse video, and return the modified image.*/
unsigned char** inverse( unsigned char** sortie,  unsigned char** entree, int nl, int nc) { int i,j;
  if (sortie==NULL) sortie=alloue_image(nl,nc);
  for(i=0; i<nl; i++)
    for(j=0; j<nc; j++)
      sortie[i][j]=255-entree[i][j];
  return sortie;
}

main (int ac, char **av) {  /* av[1] contains the image name, av[2] the result name . */
  int nb,nl,nc, oldnl,oldnc;
  unsigned char **im2=NULL,** im1=NULL;
  double** im4,** im5, ** im6, ** im7, **im8, **im9,**im10;
  
  if (ac < 2) {printf("Usage : %s entree sortie \n",av[0]); exit(1); }
	/* Reading a PGM image whose name is passed on the command line */
  im1=lectureimagepgm(av[1],&nl,&nc);
  if (im1==NULL)  { puts("Lecture image impossible"); exit(1); }
	/* Computation of the inverse video */
  im2=inverse(NULL,im1,nl,nc);
	/* Saving to a file whose name is passed on the command line */
  ecritureimagepgm(av[2],im2,nl,nc);
}