#include <iostream>
#include <string>
using namespace std;

class TextInput
{
public:
	string cur_val;
	TextInput() {cur_val = "";}
    virtual void add(char c) { 
    	cur_val += c;
    	cout << "parent\n";
    }

    virtual std::string getValue() { 
    	return cur_val; 
    }
};

class NumericInput : public TextInput {
public:
    void add(char c) { 
    	if (isdigit(c)){
	    	cur_val += c;
	    	cout << "child\n";
	    }
    }
};

#ifndef RunTests
int main()
{
    TextInput* input = new NumericInput();
    
    input->add('1'); // child
    //std::cout << input->getValue() << endl;
    input->add('a'); // no implement
    //std::cout << input->getValue() << endl;
    input->add('0'); // child
	std::cout << input->getValue() << endl; //'10'

    TextInput input2 = TextInput();
    TextInput input2;
    input2.add('a'); // parent
    std::cout << input2.getValue() << endl; //'a'
    
    TextInput* input3 = new TextInput();
    input3->add('1'); // parent
    input3->add('a'); // parent
    std::cout << input3->getValue() << endl; //'1a'
    return 0;
}
#endif