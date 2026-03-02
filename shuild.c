#define SHUILD_IMPLEMENTATION
#include "shuild/shuild.h"

int main(int argc, char **argv)
{
    SHU_CompilerTryConfigure("gcc");
    SHU_UtilAutomate(argc, argv);

    SHU_ModuleBegin("CodeToNote", NULL);
    SHU_ModuleAddSourceFile("src");
    SHU_ModuleAddIncludeDirectory("include");
    SHU_ModuleCompile("build", SHUM_MODULE_EXECUTABLE);
}
