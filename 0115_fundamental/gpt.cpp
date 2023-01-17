#include <iostream>
#include <string>
using namespace std;

class TextInput {
 public:
  // Constructor
  TextInput() : value_("") {}

  // Adds the given character to the current value
  virtual void add(char c) { value_ += c; }

  // Returns the current value
  std::string getValue() const { return value_; }

 private:
  std::string value_;
};

class NumericInput : public TextInput {
 public:
  // Overrides the base class method so that each non-numeric character is ignored
  void add(char c) {
    if (isdigit(c)) {
      TextInput::add(c);
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

    // TextInput input2;
    // input2.add('a'); // parent
    // std::cout << input2.getValue() << endl; //'a'
    
    // TextInput* input3 = new TextInput();
    // input3->add('1'); // parent
    // input3->add('a'); // parent
    // std::cout << input3->getValue() << endl; //'1a'
    return 0;
}
#endif