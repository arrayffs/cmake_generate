#include <stdio.h>
#include <fstream>
#include <cstring>
#include <string>
#include <sys/stat.h>
#include <stdlib.h>

bool genCMakeLists(std::string path)
{
  std::string final = path + "/CMakeLists.txt";
  std::ofstream f(final);

  if (!f.is_open())
    return false;
  
  f << "cmake_minimum_required(VERSION 3.28)\n";
  f << "project (app)\n\n";
  f << "file (GLOB_RECURSE SOURCES \"src/*.cpp\" \"src/*.hpp\" \"src/*.h\" \"src/*.c\")\n\n";
  f << "add_executable(app ${SOURCES})";
  f.close();

  return true;
}

bool genSrcFolder(std::string path)
{
  std::string sSrcFolder = path + "/src/";

  if (mkdir(sSrcFolder.c_str(), 0777) == -1)
    return false;
  return true;
}

bool genMain(std::string path)
{
  std::string final = path + "/src/main.c";
  std::ofstream f(final);

  if (!f.is_open())
    return false;
  
  f << "#include <stdio.h>\n\n";
  f << "int main(int argc, char* argv[])\n";
  f << "{\n";
  f << "  if (argc < 2)\n";
  f << "  {\n";
  f << "    printf(\"usage: app <name>.\\n\");\n";
  f << "    return 1;\n";
  f << "  }\n\n";
  f << "  printf(\"Hello, \%s.\\n\", argv[1]);\n";
  f << "  return 0;\n";
  f << "}\n";

  f.close();

  return true;
}

bool genScripts(std::string path)
{
  std::string sClean = path + "/clean";
  std::string sBuild = path + "/compile";
  
  std::ofstream clean(sClean);
  clean << "#!/bin/bash\n";
  clean << "rm build/ -rf\n";


  std::ofstream build(sBuild);
  build << "#!/bin/bash\n";
  build << "mkdir build/\n";
  build << "cd build/\n";
  build << "cmake .. && make\n";
  build.close();
  clean.close();

  std::string sSystemClean = "chmod +x " + sClean;
  std::string sSystemBuild = "chmod +x " + sBuild;
  system(sSystemClean.c_str());
  system(sSystemBuild.c_str());
  return true;
}

int main(int argc, char* argv[])
{
  if (argc < 2)
  {
    printf("[!] Usage: cmake_generate <path>");
    return 1;
  }

  // path /home/autismo/code/cmake_generate/testfolder/
  if (genCMakeLists(argv[1]))
    printf("[+] Generated CMakeLists.txt\n");
  else
    printf("[!] Unable to write CMakeLists.txt, check the path you provided, if correct check if you have permission to create files in the target folder.\n");

  if (genSrcFolder(argv[1]))
    printf("[+] Generated the SRC folder.\n");
  else
    printf("[!] Unable to create the SRC Folder, it may already exist, if not try again.\n");
  
  if (genMain(argv[1]))
    printf("[+] Generated the main.c file.\n");
  else
    printf("[!] Unable to write main.c, check the path you provided, if correct check if you have permission to create files in the target folder.\n");

  if (genScripts(argv[1]))
    printf("[+] Generated build and clean scripts.\n");
  else 
    printf("[!] Unable to generate scripts, check the provided paths.\n");

  return 0;
}
