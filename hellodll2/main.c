#include<windows.h>
#include<stdio.h>

typedef int(*FOO)(char*str);

int main()
{
        HMODULE mod;
        FOO     foo;

        mod =LoadLibrary("lib.dll");

        printf("from main\n");

        if((foo =(FOO)GetProcAddress(mod,"foo"))!= NULL){
                foo("hello world");
        }

        FreeLibrary(mod);

        return 0;
}