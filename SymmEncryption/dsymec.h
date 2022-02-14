int inputlen();
void getkey();
void fill(int * ptr);
void shiftrow1(int * ptr, int modtotal);
void shiftrow2(int * pta, int modtotal);
void xor1(int * pta, int modtotal);
void xor2(int * pta, int modtotal);

int tempascii[2000] = {0};
int keyexpand[4] = {19, 21, 24, 27};
int key[4] = {0};
int keyxored[4] = {0};
int * ptrascii = NULL;


int inputlen(){
  printf(" [Enter Input]: ");
  int input;
  int sum = 0;
  while((input = getchar()) != EOF){
    tempascii[sum] = input;
    sum++;
  }
  return sum;
}


void getkey(){
  printf(" [Enter Key]: ");
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
  for(int elementno = 0; tempascii[elementno] != 0; elementno++){
    *(pta + elementno) = tempascii[elementno];
  }
}

void shiftrow1(int * pta, int modtotal){
  int swhicher;
  int group = 0;

  while(group <= modtotal){
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
  int swhicher;
  int element = 0;
  int keyelement = 0;

  while(element < modtotal){
    *(pta + element) = *(pta + element) ^ key[keyelement];
    element++;
    if(element % 4 == 0){
      keyelement++;
    }
  }
}

void xor2(int * pta, int modtotal){
  int swhicher;
  int element = 0;
  int keyelement = 0;

  while(element < modtotal){
    *(pta + element) = *(pta + element) ^ keyxored[keyelement];
    element++;
    if(element % 4 == 0){
      keyelement++;
    }
  }
}
