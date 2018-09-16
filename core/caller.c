#include "includes/includes.h"

typedef struct {
    char* _LineAUX_;
    char* _LineFunction_;
    int _LineCounter_;
} Skf_FileObject;

void __parse__(){

    fp = fopen(f, "r");
    fseek(fp, 0L, SEEK_END);
    _FileSize_ = ftell(fp);
    fseek(fp, 0L, SEEK_SET);

    Skf_FileObject *FileObject = (Skf_FileObject*)malloc(2*_FileSize_);

    FileObject->_LineAUX_ = (char*)malloc(2*_FileSize_);
    FileObject->_LineFunction_ = (char*)malloc(2*_FileSize_);
    FileObject->_LineCounter_ = 0;

    // _check_first_()

    //char *_LineAUX_ = malloc(2*_FileSize_);
    //char *_LineFunction_ = malloc(2*_FileSize_);

    while ( fgets(FileObject->_LineAUX_, 2*_FileSize_, fp) != NULL ){
        FileObject->_LineCounter_ ++;

        if ( *FileObject->_LineAUX_ == '\0' || *FileObject->_LineAUX_ == '\n' ){
            continue;
        }

        if ( *FileObject->_LineAUX_ == EOF ){
            free(FileObject->_LineAUX_);
            exit(0);
        }

        FileObject->_LineAUX_ = _RemoveSpace_init_(FileObject->_LineAUX_);

        if ( *FileObject->_LineAUX_ == '\n' ){ continue; }

        FileObject->_LineFunction_ = _Identify_FunctionCall_(FileObject->_LineAUX_);

        if ( strcmp("[NAME_NOT_FOUND]", FileObject->_LineFunction_) == 0 ){
            __skf_error__(2, FileObject->_LineAUX_, f, FileObject->_LineCounter_);
            exit(1);
        }

        if ( strcmp("print", FileObject->_LineFunction_) == 0 ){
            __SKF_print__(FileObject->_LineAUX_, FileObject->_LineCounter_);
            //__
            continue;
        }

    }
    free(FileObject->_LineAUX_);
    //free(FileObject->_LineFunction_);
}