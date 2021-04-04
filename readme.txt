

How to make executable for User Defined Materials

	1.Open a Dos command Windows

Start->Programs->Intel Parallel Studio XE 2013->Command Prompt
->Parallel Studio XE with Intel Compiler XE v13.1->
Intel 64 Visual Studio 2010 mode

        2.Make the executable by default package.

Go to the working directory where you unzip User Defined
Materials package. Type nmake.exe under command line prompt.
See if you can generate the executable by default package.

        3.Modify user defined material subroutine

Modify dyn21.F with notepad or other edit utility.
Copy or insert your own code into dyn21.F.
	
	4.Make the executable

Type "nmake" and press Enter to Compile and link.
Ignore the warning messages caused by multiple-defined 
subroutines in the LIB files.

Compiler and version:

	1.Intel Fortran:

Intel Parallel Studio XE 2013 

	2.Microsoft Visual C++:

Microsoft Visual C++ 2010 x64 cross tools




 

