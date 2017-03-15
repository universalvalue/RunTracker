/* #include <iostream> */
#include "RunningAppFunctions.h"


////////////////////////////////////////////////////////////////////////////////////////////////////
//		Global variables
////////////////////////////////////////////////////////////////////////////////////////////////////

const std::string TITLE =	"    ___                 _             ___\n"
			"   / _ \\__ _____  ___  (_)__  ___ _  / _ | ___  ___\n"
		      	"  / , _/ // / _ \\/ _ \\/ / _ \\/ _ `/ / __ |/ _ \\/ _ \\\n"
			" /_/|_|\\_,_/_//_/_//_/_/_//_/\\_, / /_/ |_/ .__/ .__/\n"
			"                            /___/       /_/  /_/    ";


const std::string HEADER =   "\nWhat do you want to do ?\n\n"
			"\t1. A dd a new run ? \n"
			"\t2. Add a new  T rack ? \n"
			"\t3. S ort a student record ? \n"
			"\t4. V iew all in memory at present ? \n"
			"\t5. U pdate file with data currently in memory ? \n"
			"\t6. L oad in data from file ? \n"
			"\t7. E xit program without saving? \n";
			"\t8. Save and e X it program ? \n\n\n\n";


void PrintMainMenu(){
	std::cout << TITLE;
	std::cout << HEADER;
	std::cout << ">>";
}
