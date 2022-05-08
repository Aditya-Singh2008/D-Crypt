int inputlen();
int filewrite(char *filesname, int * pta, int charlen);
void getkey();
void fill(int * ptr);
void shiftrow1(int * ptr, int modtotal);
void shiftrow2(int * pta, int modtotal);
void xor1(int * pta, int modtotal);
void xor2(int * pta, int modtotal);
void textout(int * pta, int total);

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

void shiftrow1(int * pta, int modtotal){
  int swhicher;
  int group = 0;

  while(group < modtotal){
    int element1 = group + 1;
    int element2 = group + 2;
    swhicher = *(pta + element1);
    *(pta + element1) = *(pta + element2);
    *(pta + element2) = swhicher;
    group = group + 4;
  }
}

void shiftrow2(int * pta, int modtotal){
  int swhicher;
  int group = 0;

  while(group < modtotal){
    int element1 = group;
    int element2 = group + 2;
    swhicher = *(pta + element1);
    *(pta + element1) = *(pta + element2);
    *(pta + element2) = swhicher;
    group = group + 4;
  }
}

void xor1(int * pta, int modtotal){
  int element = 0;
  int keyelement = 0;

  while(element < modtotal){
    *(pta + element) = *(pta + element) ^ key[keyelement];
    element++;
    keyelement++;
    if(keyelement == 4){
      keyelement = 0;
    }
  }
}

void xor2(int * pta, int modtotal){
  int element = 0;
  int keyelement = 0;

  while(element < modtotal){
    *(pta + element) = *(pta + element) ^ keyxored[keyelement];
    element++;
    keyelement++;
    if(keyelement == 4){
      keyelement = 0;
    }
  }
}
