#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
int main(int argc, char const *argv[]) {
  int i=0,j=0;
  bool done=0,prob=0;
  char ch,word[40];

  if(argc==1){printf("Minimal argument encountered! Please provide file name.\n"); return 0;}
  FILE *fileptr = fopen(argv[1],"r");
  if(fileptr==NULL){printf("Faild to open! No file selected.\n"); return 0;}

  FILE *output = fopen("OUT.c","w");
  char data[][10] = {"scanf","printf","auto","break","case","char","const","continue","default","do","double","else","enum","extern","float","for","goto","if","#include","int","long","register","return","short","signed","sizeof","static","struct","switch","typedef","union","unsigned","void","volatile","while"};
  char match[][40] = {"लो","छापो","स्व", "तोेडे",  "मामला","अक्षर","अफर", "जारी",     "मूल",    "करो","बडा",  "अन्य", "गणना","बाहर",  "अपूर्णांक","लिये","जाओ","अगर","शामिल","संख्या","लंबा","पंजी",     "भेजो",   "कम",   "चिह्न",   "माप",   "स्थिर",   "रचना",  "देखो",   "नाम",    "संघ",  "नचिह्न",    "खाली", "परिवर्तनशील","जबतक"};


  while(ch != EOF){
    ch = fgetc(fileptr);
    if(ch!=' ' && ch!=';' && ch!=EOF && ch!='\n' && ch!='\t'){
      word[i]=ch; word[i+1]='\0'; i++;
    }
    else{
      i=0;
      if(word[0]<0 || word[0]>128){
        for(j=0;j<36;j++){
          if(!strcmp(word,match[j])){
            fputs(data[j],output);
            done = 1;
            break;
          } else done=0;
        }
        if(!done) prob=1;
      }
      else
        fputs(word,output);
      if(ch==';') fputs(";",output);
      else if(ch == ' ') fputs(" ",output);
      else if(ch == '\t') fputs("\t",output);
      else fputs("\n",output);
      word[0]='\0';
    }
  }
  fclose(output);
  fclose(fileptr);

  if(prob) printf("Probably u entered wrong hindi keyword!\n");
  else{
    printf("Translated sucessfully\n-----------------------\n");
    printf("Enter 1 to compile & 0 to exit\n");
    scanf("%d",&done);
    if(done)
    if(!system("gcc -o output OUT.c")){
      printf("Executing code...\n");
      system("output.exe");
    }
    else
      printf("Solve the error & try again\n");
  }
  return 1;
}
