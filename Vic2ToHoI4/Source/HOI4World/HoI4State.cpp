/*Copyright (c) 2016 The Paradox Game Converters Project

Permission is hereby granted, free of charge, to any person obtaining
a copy of this software and associated documentation files (the
"Software"), to deal in the Software without restriction, including
without limitation the rights to use, copy, modify, merge, publish,
distribute, sublicense, and/or sell copies of the Software, and to
permit persons to whom the Software is furnished to do so, subject to
the following conditions:

The above copyright notice and this permission notice shall be included
in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.*/



#include "HoI4State.h"
#include <fstream>
#include "../Configuration.h"
#include "Log.h"
#include "OSCompatibilityLayer.h"



HoI4State::HoI4State(int _ID, string _ownerTag, string _name, float _Manpower, double _CivFactories, int _MilFactories, string _catagory, int _stateworkers, int _countryworkers )
{
	ID			= _ID;
	ownerTag	= _ownerTag;
	name		= _name;
	if (name == "")
	{
		name = "Foo";
	}
	manpower	= _Manpower;
	civFactories = _CivFactories;
	milFactories = _MilFactories;
	catagory = _catagory;
	stateworkers = _stateworkers;
	countryworkers = _countryworkers;
}


void HoI4State::output(string _filename)
{
	string filename("Output/" + Configuration::getOutputName() + "/history/states/" + _filename);
	ofstream out;
	out.open(filename);
	{
		if (!out.is_open())
		{
			LOG(LogLevel::Error) << "Could not open \"output/input/history/states/" + _filename;
			exit(-1);
		}
		//out << civFactories << "  " << milFactories << endl;
		out << "state={" << endl;
		out << "\tid=" << ID << endl;
		out << "\tname= \"" << name << "\"" << endl;
		out << "\tmanpower = " << to_string(manpower) << endl;
		out << endl;
		out << "\tstate_category = "<< catagory << endl;
		out << "" << endl;
		out << "\thistory={" << endl;
		out << "\t\towner = " << ownerTag << endl;
		//out << "	victory_points = { 3838 1 }" << endl;
		out << "	buildings = {" << endl;
		out << "	infrastructure = 10" << endl;
		out << "	industrial_complex = "<< civFactories << "#stateworkers = " << stateworkers << " out of employed workers = " << countryworkers<< endl;
		out << "	arms_factory = " << milFactories << endl;
		//out << "	air_base = 1" << endl;
		//out << "	3838 = {" << endl;
		//out << "	naval_base = 3" << endl;
		out << "}" << endl;
		//out << "}" << endl;
		//out << "	add_core_of = FRA" << endl;
		out << "\t}" << endl;
		out << endl;
		out << "\tprovinces={" << endl;
		out << "\t\t";
		for (auto provnum : provinces)
		{
			out << provnum << " ";
		}
		out << endl;
		out << "\t}" << endl;
		out << "}" << endl;

		out.close();
	}
}