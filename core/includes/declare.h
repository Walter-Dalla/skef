#ifndef DECLARE_H
#define DECLARE_H

// Global declarations

    char *f;

    FILE *fp;

    int _LineCounter_;
    int _FileSize_;

// All 'core/' function declaration
void _skf_error_(int __err_number__, char *__err_line__, char *__filename__, int __line_num__);
void __parse__();
void clear();

int _check_f_exist_(char *filename);

char *_RemoveSpace_init_(char *string);
char *_Identify_FunctionCall_(char *string);

#endif