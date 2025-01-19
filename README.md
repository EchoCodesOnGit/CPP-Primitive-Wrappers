# C++ Wrapper Classes

## Project Overview
This project is for those who want the similar functionality of primitive data type wrappers in C++, as in the same fashion of the Java programming language.
It uses the same kind of approach that Java uses for its wrapper classes but has subtle differences given the fact that it's simply just a different language.

## Prerequisites
1. For these files to work you need to have the [C++](https://sourceforge.net/projects/mingw/) language installed on your system, the program can be executed using the g++ compiler
2. Some of the build instructions require you to have the Git version control installed, this can be done by using the following commands.
  ### Windows
     
     winget install --id Git.Git -e
  
     #verify installation by running the following
     git --version
     
     #the following is optional for account information
     git config --global user.name "Your Name"
     git config --global user.email "youremail@somesite.com"
     
  ### Linux (Ubuntu/Debian-based)
     
     sudo apt update
     sudo apt install git -y
     
     #verify installation by running the following
     git --version

     #the following is optional for account information
     git config --global user.name "Your Name"
     git config --global user.email "youremail@somesite.com"

  ### MacOS via Homebrew
     #first make sure HomeBrew itself is installed, if not run the following
     /bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"

     #install Git
     brew install git

     #verify installation by running the following
     git --version
     
## Build Instructions
These next few instructions will be dependent on whether or not you wish to make these classes local to projects or you wish to add them to your PATH environment variable to make them "universal"

### Option 1: Using The Header Files Locally via GitHub site
1. Download the .zip files and unzip them into the same directory as _your_ project directory
2. Navigate to the directory they were extracted into
3. Open _your_ project and include the extracted files using the following line:
   ```sh
   #include "your_local_path/Bool/Bool.h"
   #include "your_local_path/Number/<number_data_type>.h"
   ```
### Option 2: Using The Header Files Locally via Git CLI
1. Assuming you meet the prerequisites, open your CMD prompt and change your current directory to your project
   ```sh
   cd 
   ```
2. 
