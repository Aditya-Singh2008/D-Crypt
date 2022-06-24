int inputlen();
int filewrite(char *filesname, int *pta, int charlen);
void getkey();
void fill(int *pta, int charc);
void shiftrow1(int *pta);
void shiftrow2(int *pta);
void xor1(int *pta);
void xor2(int *pta);
void textout(int *pta, int total);

int keyexpand[4] = {2, 3, 6, 9};
int key[4] = {0};
int keyxored[4] = {0};
int charlen;
int * tempascii = NULL;
int * ptrascii = NULL;

int inputfilelen(char *filesname){
  FILE * readfile = fopen(filesname, "r");
  int input;
  int sum = 0;

  if(readfile == NULL){
    printf("Enter a valid file name");
    exit(1);
  }

  while((input = fgetc(readfile)) != EOF){
    *(tempascii + sum) = input;
    sum++;
  }
  fclose(readfile);
  return sum;
}

int filewrite(char *filesname, int * pta, int charlen){
  FILE * writefile = fopen(filesname, "w");
  if(writefile == NULL){
    printf("Enter a valid file name");
    exit(1);
  }
  int input;
  for(int element = 0; element < charlen; element++){
    fputc(*(pta + element), writefile);
  }
  fclose(writefile);
}

int inputlen(){
  printf("[Enter Input]: ");
  int input;
  int sum = 0;
  while((input = getchar()) != EOF){
    *(tempascii + sum) = input;
    sum++;
  }
  return sum;
}

void getkey(){
  printf("[Enter Key]: ");
  int keyinput;
  int element = 0;
  int expendno = 0;

  while((keyinput = getchar()) != '\n'){
    key[element] = keyinput;
    keyxored[element] = key[element] ^ keyexpand[expendno];
    expendno++;
    if(expendno == 4){
      expendno = 0;
    }
    element++;
  }
}

void fill(int * pta){
  for(int elementno = 0; *(tempascii + elementno) != 0; elementno++){
    *(pta + elementno) = *(tempascii + elementno);
  }
}

void shiftrow1(int *pta){
  int swicher;
  int *sw1 = pta;
  int *sw2 = (pta + 1);

  swicher = *sw1;
  *sw1 = *sw2;
  *sw2 = swicher;

  while(*(sw1 += 2) != -1 && *(sw2 += 2) != -1){
    swicher = *sw1;
    *sw1 = *sw2;
    *sw2 = swicher;
  }
}

void shiftrow2(int *pta){
  int swicher;
  int *sw1 = (pta + 1);
  int *sw2 = (pta + 2);

  swicher = *sw1;
  *sw1 = *sw2;
  *sw2 = swicher;

  while(*(sw1 += 2) != -1 && *(sw2 += 2) != -1){
    swicher = *sw1;
    *sw1 = *sw2;
    *sw2 = swicher;
  }
}

void xor1(int *pta){
  int *xr = pta;
  int keyelement = 0;

  *xr = *xr ^ key[keyelement];

  while((*++xr ^ key[keyelement++]) >= 0){
    *xr = *xr ^ key[keyelement];
    if(keyelement == 3){
        keyelement = 0;
    }
  }
}

void xor2(int *pta){
  int *xr = pta;
  int keyelement = 0;

  *xr = *xr ^ keyxored[keyelement];

  while((*++xr ^ keyxored[keyelement++]) >= 0){
    *xr = *xr ^ keyxored[keyelement];
    if(keyelement == 3){
        keyelement = 0;
    }
  }
}
