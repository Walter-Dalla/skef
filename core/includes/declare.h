#ifndef DECLARE_H
#define DECLARE_H

// Global declarations

    char *f;

    FILE *fp;

    //int _LineCounter_;
    int _FileSize_;

// All 'core/' function declaration

void __skf_error__(int __err_number__, char *__err_line__, char *__filename__, int __line_num__);
void __parse__();
void clear();

int _CheckFileExistence_(char *filename);

char *_RemoveSpace_init_(char *string);
char *_Identify_FunctionCall_(char *string);

// stdskf
void __SKF_print__(char *__string__, int __line__);

#endif